using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TargetSinusWavePattern : TargetMovementPattern
{
    // Start is called before the first frame update
     public float m_frequency = 1.0f;  // Speed of sine movement
     public float m_magnitude = 0.5f;   // Size of sine movement

     public float m_horMagnitude = 3.0f;

     public float m_minSineRange = 0.0f;
     public float m_maxSineRange = 10.0f;

     public float m_minHorRange = -5.0f;
     public float m_maxHorRange = 5.0f;
   
    new void Start()
    {
        m_pos = transform.position;        
        m_axis = transform.up;  // May or may not be the axis you want
    }
    public override void move()
    {
        float horValue = Mathf.PingPong(Time.time*m_speed, m_horMagnitude);
        horValue = normalizeRange(horValue, 0,m_horMagnitude,m_minHorRange,m_maxHorRange);
        m_pos = transform.forward *  horValue; 
        float sinWaveValue =  Mathf.Sin (Time.time * m_frequency) * m_magnitude; 
        sinWaveValue = normalizeRange(sinWaveValue,-m_magnitude,m_magnitude,2,m_magnitude);       
        transform.position = m_pos + m_axis * sinWaveValue;
        
        Debug.Log ("Sin Value: "+ sinWaveValue);
    }

    
}
