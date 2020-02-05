using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class moveTest : MonoBehaviour
{
    public Rigidbody cube1;
    public Rigidbody cube2;

    public float z1 = 10.0f;
    public float z2 = 10.0f;

    // Start is called before the first frame update
    void Start()
    {
        //cube1.AddForceAtPosition()
    }

    // Update is called once per frame
    void Update()
    {
        cube1.AddRelativeForce(0.0f,0.0f,z1);
        cube2.AddRelativeForce(0.0f,0.0f,z2);
        //cube1.velocity = new Vector3(0.0f,0.0f,z1);
        //cube2.velocity = new Vector3(0.0f,0.0f,z2);
        //cube1.AddForce(0.0f,0.0f,z1);
        //cube2.AddForce(0.0f,0.0f,z2);
    }
}

