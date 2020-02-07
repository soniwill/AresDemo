using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class TargetMovementPattern : MonoBehaviour
{
    // Start is called before the first frame update
    public float m_speed = 0.5f;
    protected Vector3 m_axis;
    protected Vector3 m_pos;
    public virtual void Start()
    {
        
    }

    // Update is called once per frame
    public virtual void Update()
    {
        move();
    }

    public float normalizeRange(float rawVal, float min, float max, float newMin, float newMax)
    {
        float result = (rawVal - min) / (max - min)*(newMax-newMin)+newMin;
        return result;
    }

    public abstract void move();
}
