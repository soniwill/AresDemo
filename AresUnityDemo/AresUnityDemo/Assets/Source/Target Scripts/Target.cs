using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Target : MonoBehaviour
{
    enum MovementPattern {HORIZONTAL,CIRCULAR,SINUSWAVE}
    Rigidbody m_rB;
    TargetMovementPattern m_pattern;

    bool isTargetDead = false;

    // Start is called before the first frame update
    void Start()
    {
        Random.InitState(System.DateTime.Now.Millisecond*GetInstanceID()); 
        int index = Random.Range(0,3);
        MovementPattern pattern = (MovementPattern)index;
        m_rB = GetComponent<Rigidbody>();

        switch(pattern)
        {
            case MovementPattern.CIRCULAR:
                m_pattern = gameObject.AddComponent<TargetCircularPattern>();
                break;
            case MovementPattern.HORIZONTAL:
                m_pattern = gameObject.AddComponent<TargetHorizontalPattern>();
                break;
            case MovementPattern.SINUSWAVE:
                m_pattern = gameObject.AddComponent<TargetSinusWavePattern>();
                break;
                default:
                 m_pattern = gameObject.AddComponent<TargetHorizontalPattern>();
                 break;
        }       
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void OnCollisionEnter(Collision collision)
    {
       if (collision.gameObject.name=="Floor" && isTargetDead==true)
        gameObject.SetActive(false);
    }

    public void Die(RaycastHit hit, Vector3 dir)
    {
        GameManager.Instance.countTargetsHit();
        m_rB.isKinematic = false;
        m_rB.useGravity =true;
        m_rB.AddForceAtPosition(dir*10,hit.point,ForceMode.VelocityChange);        
        m_pattern.enabled = false;
        Animator animator = GetComponentInChildren<Animator>();
        if(animator!=null) animator.enabled = false;
        isTargetDead = true;        
    }

    public bool IsTargetDead
    {
        get{return isTargetDead;}
    }
}
