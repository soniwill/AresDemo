using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManagerResourcers :  Singleton<GameManagerResourcers>
{
    public TargetMovementPattern [] m_targetMovementPatterns;

    void Awake()
    {
        DontDestroyOnLoad(gameObject);
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
