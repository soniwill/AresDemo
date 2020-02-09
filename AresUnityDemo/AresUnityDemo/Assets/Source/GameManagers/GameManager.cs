using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : Singleton<GameManager>
{
    void Awake()
    {
        DontDestroyOnLoad(gameObject);
    }

    // Start is called before the first frame update
    void Start()
    {
        GameManagerNetwork.Instance.ConnectionDone += LoadScene;
        SceneManager.sceneLoaded+=OnSceneLoaded;
        SceneManager.LoadScene("Main_menu", LoadSceneMode.Single);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void LoadScene()
    {
        SceneManager.LoadScene("World_scene", LoadSceneMode.Single);
    }

    public void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        if(scene.name=="World_scene")
        {
            GameManagerResourcers.Instance.spawnTargets();
            GameManagerResourcers.Instance.SpawnOwnVehicle();
        }
    }

    
}
