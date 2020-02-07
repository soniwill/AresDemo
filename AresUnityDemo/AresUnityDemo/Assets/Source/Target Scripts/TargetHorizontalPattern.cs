using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TargetHorizontalPattern : TargetMovementPattern
{
     public float m_horMagnitude = 3.0f;
     public float m_minHorRange = -5.0f;
     public float m_maxHorRange = 5.0f;

    // Start is called before the first frame update
    new void Start()
    {
        
    }

    public override void move()
    {
        float horValue = Mathf.PingPong(Time.time*m_speed, m_horMagnitude);
        horValue = normalizeRange(horValue, 0,m_horMagnitude,m_minHorRange,m_maxHorRange);        
        transform.position += transform.forward*Time.deltaTime*horValue;
    }
    
}
