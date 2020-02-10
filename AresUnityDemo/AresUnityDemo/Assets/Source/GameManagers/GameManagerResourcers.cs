using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManagerResourcers :  Singleton<GameManagerResourcers>
{
    
    public Transform m_projectilePfabs;

    public OwnVehicle m_ownVehiclePfabs;

    public Target [] m_targetsPfabs;

    public List<Target> m_targetsInstantiated;

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

    public void spawnTargets()
    {
        float x, y, z;
        
        int i = 0;
        foreach (Target target in m_targetsPfabs)
        {
            ++i;
            Random.InitState(System.DateTime.Now.Millisecond*i);
            x = Random.Range(-40.0f,40.0f);
            y = Random.Range( 1.40f,8.0f);
            z = Random.Range(-40.0f,40.0f);

            Vector3 pos = new Vector3(x,y,z);
            m_targetsInstantiated.Add(Instantiate(target,pos,Quaternion.identity));
        }
    }

     public void SpawnOwnVehicle()
    {
        Random.InitState(System.DateTime.Now.Millisecond);
        float x, y, z;
        x = Random.Range(-40.0f,40.0f);
        y = 1.39f;
        z = Random.Range(-40.0f,40.0f);

        Vector3 pos = new Vector3(x,y,z);

        Instantiate(m_ownVehiclePfabs,pos, Quaternion.identity);
    }

}
