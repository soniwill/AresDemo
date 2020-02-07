using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LoadDemoScene : NetworkObject
{
    // Start is called before the first frame update
    void awake()
    {
        
    }

    // Update is called once per frame

    new void Update()
    {    
        base.Update();   
    }
   

    public override void ProcessMessages(string[] msg)
    {
        if(msg[0]=="START_DEMO")
        {
            GameManager.Instance.LoadScene();
        }
    }

    public override void Write(ref System.Net.Sockets.Socket networkSender)
    {

    }
}
