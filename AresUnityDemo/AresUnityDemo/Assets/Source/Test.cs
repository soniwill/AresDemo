using UnityEngine;
using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Collections;

public class Test : MonoBehaviour 
{
	public Transform playerObject;

	private Socket socket;
	private byte[] buffer;
	private IPEndPoint serverEndPoint;

	private IEnumerator connectionCoroutine;

	private void Start()
	{
		connectionCoroutine = Connection();
        StartCoroutine(connectionCoroutine);
	}

	private IEnumerator Connection()
	{
		this.socket = new Socket( AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp );		
		int myError = 0;
		try
		{
			this.socket = new Socket( AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp );
			this.socket.Blocking = false;
			//Debug.Log("Establishing Connection to 127.0.0.1");
        	this.socket.Connect("127.0.0.1", 54003);
        	//Debug.Log("Connection established");
		}
		catch (SocketException e)
		{
			myError = e.ErrorCode;
			Debug.Log(e.Message);			
		}		
		while (!this.socket.Connected)
		{
			Debug.Log("Could not connect. is the server ready? trying again in 3 seconds");			
			yield return new WaitForSeconds(3.0f);
			try
			{
				this.socket.Connect("127.0.0.1", 54003);
			}
			catch(SocketException e)
			{
				Debug.Log(e.Message);			
			}
			//this.socket.Connect("127.0.0.1", 54003);		
		}
		while(true)
		{							
			if(myError == 10035 )
			{
				Debug.Log("Establishing Connection to 127.0.0.1");
				bool isConnectionFailed1 = this.socket.Poll(1000, SelectMode.SelectWrite);					
				bool isConnectionFailed2 = this.socket.Poll(1000, SelectMode.SelectWrite);
				bool isConnectionFailed3 = this.socket.Poll(1000, SelectMode.SelectWrite);
				Debug.Log("isConnectionFailed1: " + isConnectionFailed1) ;
				Debug.Log("isConnectionFailed2: " + isConnectionFailed2);
				Debug.Log("isConnectionFailed3: " + isConnectionFailed3);	
				StopCoroutine(connectionCoroutine);
				
				//yield return new WaitForSeconds(1.0f);
			}
			else
			{
				Debug.Log("the Error number is: " + myError);
				break;
			}
			yield return new WaitForSeconds(1.0f);
		}		
		//this.buffer = new byte[sizeof(float) * 3];
		//this.serverEndPoint = new IPEndPoint( IPAddress.Loopback, 9999 );		
	}

	private void OnEnable()
	{
		
	}

	private void OnDisable()
	{
		this.socket.Shutdown( SocketShutdown.Both );
		this.buffer = null;
		this.serverEndPoint = null;
	}

	private void Update()
	{		
		//Debug.Log("Establishing Connection to 127.0.0.1");
		// // get input
		// byte input = 0;

		// if( Input.GetKey( KeyCode.W ) )
		// {
		// 	input |= 0x1;
		// }
		// if( Input.GetKey( KeyCode.S ) )
		// {
		// 	input |= 0x2;
		// }
		// if( Input.GetKey( KeyCode.A ) )
		// {
		// 	input |= 0x4;
		// }
		// if( Input.GetKey( KeyCode.D ) )
		// {
		// 	input |= 0x8;
		// }System.Text

         
		// send to server
        //byte[] b2 = Encoding.ASCII.GetBytes("Text work");
		//this.buffer[0] = input;
		//this.socket.SendTo( b2, 1, SocketFlags.None, this.serverEndPoint );
        //int i = this.socket.Send(b2);
        //Debug.Log("Sent bytes: " + i);

		// wait for state packet
		//EndPoint remoteEP = new IPEndPoint( 0, 0 );
		//this.socket.ReceiveFrom( this.buffer, ref remoteEP );
        byte[] bytes = new byte[256];
		try
		{
			int i = this.socket.Receive(bytes);

			string strTest = Encoding.UTF8.GetString(bytes);
			Debug.Log(strTest);
			string[] result = strTest.Split( new char[] {';'},StringSplitOptions.None);
			if(result[0]=="MOVEMENT_PLAYER")
			{
				Rigidbody rB =  playerObject.GetComponent<Rigidbody>();
				rB.AddRelativeForce(.0f,.0f,float.Parse(result[1]));
				rB.AddRelativeForce(.0f,.0f,-float.Parse(result[2]));
				Debug.Log("PRIMEIRA FORÇA: "+float.Parse(result[1]));
				Debug.Log("SEGUNDA FORÇA: "+float.Parse(result[2]));
			}			
			
		}
		catch(SocketException e){}
	
        
        
		//Encoding.UTF8.GetString(bytes)
		// unpack game state
		Vector3 playerPosition = new Vector3( 0.0f, 0.0f, 0.0f );

		// int readIndex = 0;
		// playerPosition.x = BitConverter.ToSingle( this.buffer, readIndex );
		// readIndex += sizeof( float );

		// playerPosition.z = BitConverter.ToSingle( this.buffer, readIndex );
		// readIndex += sizeof( float );

		// float playerFacing = BitConverter.ToSingle( this.buffer, readIndex );

		// this.playerObject.position = playerPosition;
		// this.playerObject.rotation = Quaternion.Euler( 0.0f, playerFacing * Mathf.Rad2Deg, 0.0f );
	}
}