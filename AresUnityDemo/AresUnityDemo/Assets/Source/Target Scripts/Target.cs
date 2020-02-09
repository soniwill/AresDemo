using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Target : MonoBehaviour
{
    enum MovementPattern {HORIZONTAL,CIRCULAR,SINUSWAVE}

    // Start is called before the first frame update
    void Start()
    {
        Random.InitState(System.DateTime.Now.Millisecond); 
        int index = Random.Range(0,2);
        MovementPattern pattern = (MovementPattern)index;

        switch(pattern)
        {
            case MovementPattern.CIRCULAR:
                gameObject.AddComponent<TargetCircularPattern>();
                break;
            case MovementPattern.HORIZONTAL:
                gameObject.AddComponent<TargetHorizontalPattern>();
                break;
            case MovementPattern.SINUSWAVE:
                gameObject.AddComponent<TargetSinusWavePattern>();
                break;
                default:
                 gameObject.AddComponent<TargetHorizontalPattern>();
                 break;
        }       
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
