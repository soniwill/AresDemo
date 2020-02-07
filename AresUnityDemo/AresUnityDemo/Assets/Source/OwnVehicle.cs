using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OwnVehicle : NetworkObject
{
    // Start is called before the first frame update
    new void Start()
    {
        GameManagerNetwork.Instance.RegisterNetworkObject(this);
        base.Start();
    }

    // Update is called once per frame
    new void Update()
    {    
        base.Update();   
    }

    public override void ProcessMessages(string[] msg)
    {
        Debug.Log("A mensagem que chegou foi: " + msg[0]);
    }

    public override void Write(ref System.Net.Sockets.Socket networkSender)
    {
        //networkSender.Send()
    }
}
