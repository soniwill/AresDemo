
using System;
using System.Text;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class GameManagerNetwork : Singleton<GameManagerNetwork>
{

    //public Text m_statusConn;

    //public RectTransform m_statusPanel;

    public List<NetworkObject> m_networkObjects;

    private Queue m_messagesPool;
    
    private Socket m_socket;

    byte[] m_bytes = new byte[256];

    public delegate void sendNetworkMessagesHandler( ref Socket networkSender);    
    public delegate void ServerConnectionHandler();
    public event sendNetworkMessagesHandler MessageSent;      
    public event ServerConnectionHandler ConnectionDone;



    private IEnumerator connectionCoroutine;

    private IEnumerator Connection(string serverIpAdress, int serverPort)
	{
        
		this.m_socket = new Socket( AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp );	

		int myError = 0;
		try
		{
			this.m_socket = new Socket( AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp );
			this.m_socket.Blocking = false;			
        	this.m_socket.Connect(serverIpAdress, serverPort);        	
		}

		catch (SocketException e)
		{
			myError = e.ErrorCode;
			Debug.Log(e.Message);			
		}

		while (!this.m_socket.Connected)
		{
            //event Trying connection;
            //m_statusPanel.gameObject.SetActive(true);
			Debug.Log("Could not connect. is the server ready? trying again in 3 seconds");
            //m_statusConn.text = "Trying connection";
			yield return new WaitForSeconds(3.0f);
			try
			{
				this.m_socket.Connect(serverIpAdress, serverPort);
			}
			catch(SocketException e)
			{
				Debug.Log(e.Message);			
			}				
		}

		while(true)
		{							
			if(myError == 10035 )
			{
				
                //event connected;
                //m_statusConn.text = "Connected";
                //m_statusPanel.gameObject.SetActive(false);
                OnServerConnection();												
			}
			else
			{
				Debug.Log("the Error number is: " + myError);
				break;
			}
			yield return new WaitForSeconds(1.0f);
		}				
	}                 
    public void OnConnect(string serverIpAdress, int serverPort)
    {
        connectionCoroutine = Connection(serverIpAdress,serverPort);
        StartCoroutine(connectionCoroutine);
    }

	private void OnDisable()
	{
		this.m_socket.Shutdown( SocketShutdown.Both );				
	}
    
    void OnServerConnection()
    {
        ConnectionDone();
        if(this.m_socket.Connected) StopCoroutine(connectionCoroutine);
    }

    void Awake()
    {
        DontDestroyOnLoad(gameObject);
    }

    void Start()
    {
        m_networkObjects = new List<NetworkObject>();
    }

    // Update is called once per frame
    void Update()
    {
        if(this.m_socket!=null && this.m_socket.Connected)
        {
            GetNetworkMessages();
            //OnNetworkMessagesSent(); 
        }
    }

    void OnNetworkMessagesSent()
    {
        MessageSent(ref m_socket);
    }
    void GetNetworkMessages()
    {
        
		try
		{
            Array.Clear(m_bytes,0,m_bytes.Length);
			int i = this.m_socket.Receive(m_bytes);
            string msg = Encoding.UTF8.GetString(m_bytes);
            string[] result = msg.Split( new char[] {';'},StringSplitOptions.None);
            CheckMsgsSubscription(result);
		}
		catch(SocketException e){}
    }

    void CheckMsgsSubscription(string[] msg)
    {
        foreach (NetworkObject nGO in m_networkObjects)
        {
            nGO.CheckMsgSubscription(msg);
        }
    }    
}
