using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TargetCircularPattern : TargetMovementPattern
{
    // Start is called before the first frame update

    public float m_radius = 5.0f;
    public Vector3 center;
    private Vector3 xyz;
    new void Start()
    {
        xyz = new Vector3();
    }

    public override void move()
    {
        xyz.x = 0;
        xyz.y = Mathf.Sin(Time.time*m_speed);
        xyz.z = Mathf.Cos(Time.time*m_speed);
       transform.position = center + xyz*m_radius;
    }
}
