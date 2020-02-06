using System.Collections;
using System.Collections.Generic;
using System.Net.Sockets;
using UnityEngine;

public abstract class NetworkObject : MonoBehaviour
{
    public string [] m_subscribedMessages;

    private Queue m_messagesPool;
    // Start is called before the first frame update
    void Start()
    {
        GameManagerNetwork.Instance.MessageSent += Write;
    }

    // Update is called once per frame
    void Update()
    {
        while(m_messagesPool.Count>0)
        {
            string[] msg = (string[])m_messagesPool.Dequeue();
            ProcessMessages(msg);
        }        
    }

    public abstract void Write(ref Socket networkSender);

    public abstract void ProcessMessages(string [] msg);
    

    private void AddMsgToPool(string [] msg)
    {
        m_messagesPool.Enqueue(msg);
    }

    public void CheckMsgSubscription(string [] msg)
    {
        foreach (string msgID in m_subscribedMessages)
            {
                if(msgID == msg[0])
                {
                    AddMsgToPool(msg);
                }                
            }
    }
}
