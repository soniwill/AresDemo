using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameConnectionButton : MonoBehaviour
{
    
    public Text m_serverIpAdress;
    public Text m_serverPort;
    public Text m_statusConn;

    public RectTransform m_statusPanel;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void OnbuttonClick()
    {

         if((m_serverIpAdress.text.Length==0) || (m_serverPort.text.Length==0))
        {
            Debug.Log("One or all Server address fields might be empty. Please fix it.");
            m_statusConn.text = "One or all Server address fields might be empty. Please fix it.";
            m_statusPanel.gameObject.SetActive(true);                
            return;
        }
        string serverIpAdress = m_serverIpAdress.text;
        int serverPort = int.Parse(m_serverPort.text);
        GameManagerNetwork.Instance.OnConnect(serverIpAdress,serverPort);
    }
}
