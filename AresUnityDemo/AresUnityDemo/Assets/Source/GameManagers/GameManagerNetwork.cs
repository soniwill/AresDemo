
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

    public delegate void CheckMsgsSubscriptionHandler (string [] msgItems);

    public event sendNetworkMessagesHandler MessageSent;      

    public event ServerConnectionHandler ConnectionDone;

    public event CheckMsgsSubscriptionHandler MsgsSubscriptionChecking;



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
           // this.m_socket.Connect("127.0.0.1", 54003);
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
                //this.m_socket.Connect("127.0.0.1", 54003);
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
				Debug.Log("Establishing Connection to 127.0.0.1");
				bool isConnectionFailed1 = this.m_socket.Poll(1000, SelectMode.SelectWrite);					
				bool isConnectionFailed2 = this.m_socket.Poll(1000, SelectMode.SelectWrite);
				bool isConnectionFailed3 = this.m_socket.Poll(1000, SelectMode.SelectWrite);
				Debug.Log("isConnectionFailed1: " + isConnectionFailed1) ;
				Debug.Log("isConnectionFailed2: " + isConnectionFailed2);
				Debug.Log("isConnectionFailed3: " + isConnectionFailed3);	
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
       
       if(this.m_socket.Connected)
        {
            byte[] b2 = Encoding.ASCII.GetBytes("CLIENT_READY");		  
            int i = m_socket.Send(b2);            
            StopCoroutine(connectionCoroutine);
        }
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
        // byte[] bytes = new byte[256];
		// try
		// {
		// 	int i = this.m_socket.Receive(bytes);

		// 	string strTest = Encoding.UTF8.GetString(bytes);
		// 	Debug.Log(strTest);
		// 	//string[] result = strTest.Split( new char[] {';'},StringSplitOptions.None);
		// 	// if(result[0]=="MOVEMENT_PLAYER")
		// 	// {
		// 	// 	Rigidbody rB =  playerObject.GetComponent<Rigidbody>();
		// 	// 	rB.AddRelativeForce(.0f,.0f,float.Parse(result[1]));
		// 	// 	rB.AddRelativeForce(.0f,.0f,-float.Parse(result[2]));
		// 	// 	Debug.Log("PRIMEIRA FORÇA: "+float.Parse(result[1]));
		// 	// 	Debug.Log("SEGUNDA FORÇA: "+float.Parse(result[2]));
		// 	// }			
			
		// }
		// catch(SocketException e){}
        if(this.m_socket!=null && this.m_socket.Connected)
        {
            GetNetworkMessages();
            OnNetworkMessagesSent(); 
        }
    }

    void OnNetworkMessagesSent()
    {
        MessageSent(ref m_socket);
    }
    void GetNetworkMessages()
    {
        string msg ="";
		try
		{
            Array.Clear(m_bytes,0,m_bytes.Length);
			int i = this.m_socket.Receive(m_bytes);
            if(i>0) msg = Encoding.UTF8.GetString(m_bytes,0,i);
            string[] result = msg.Split( new char[] {';'},StringSplitOptions.None);
            Debug.Log("mensagem: " + result[0]);
            if(result[0]=="START_DEMO")
            {
                int p = 7;
            }
            CheckMsgsSubscription(result);
		}
		catch(SocketException e)
        {
            //Debug.Log(e.Message);
        }
    }

    void CheckMsgsSubscription(string[] msg)
    {
        //acho que seria melhor usar aqui o delegate/event. Objeto chamaria de forma independente a checagem
        //eu não precisaria fazer esse loop e ainda não deixaria o método dentro do loop exposto de forma publica.
        //vou primeiro verificar se tudo esta funcionando dessa forma e se sim tento usando delegates.
        // foreach (NetworkObject nGO in m_networkObjects) 
        // {
        //     nGO.CheckMsgSubscription(msg);
        // }

        MsgsSubscriptionChecking(msg);
    }    

    public void RegisterNetworkObject(NetworkObject nObj)
    {
        if(!m_networkObjects.Contains(nObj)) m_networkObjects.Add(nObj);        
    }
}
