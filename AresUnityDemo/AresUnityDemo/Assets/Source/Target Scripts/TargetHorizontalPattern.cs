using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TargetHorizontalPattern : TargetMovementPattern
{
     public float m_horMagnitude = 3.0f;
     public float m_minHorRange = -5.0f;
     public float m_maxHorRange = 5.0f;

     private Vector3 lastPos;
     private Vector3 movDir;     

    // Start is called before the first frame update
    new void Start()
    {
        lastPos = transform.position;
        movDir = transform.forward;
    }

    public override void move()
    {                
        float horValue = Mathf.PingPong(Time.time*m_speed, m_horMagnitude);
        horValue = normalizeRange(horValue, 0,m_horMagnitude,m_minHorRange,m_maxHorRange);        
        transform.position += Vector3.forward*Time.deltaTime*horValue;
        movDir = (transform.position - lastPos).normalized;
        lastPos = transform.position;
        Quaternion newRotation = Quaternion.LookRotation(movDir,transform.up);
        transform.rotation = Quaternion.Slerp(transform.rotation,newRotation,Time.deltaTime);        
    }
    
}
