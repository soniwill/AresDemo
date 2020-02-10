using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
public class GameManager : Singleton<GameManager>
{
    public Text m_timerText;
    public int m_secondsLeft;
    TimerUtil m_timer;

    bool m_isGameOver = false;

    private int m_numFireShots;
    private int m_numHits;
    private int m_numTargetsDead;

    private bool isGameStarted = false;

    void Awake()
    {        
        DontDestroyOnLoad(gameObject);
    }

   
    // Start is called before the first frame update
    void Start()
    {                       
        GameManagerNetwork.Instance.ConnectionDone += LoadScene;
        SceneManager.sceneLoaded+=OnSceneLoaded;
        LoadScene("Main_menu");       
    }

    // Update is called once per frame
    void Update()
    {
        if(m_timer!=null)
        m_timerText.text = m_timer.GetTimeLeftString();

        CheckEndGame();

        if(m_isGameOver) 
        {
            Debug.Log("Targets hit: "+ m_numHits);
            Debug.Log("Fire shots: "+ m_numFireShots);
            m_isGameOver =false;
            m_timerText.enabled =false;
            LoadScene("GameOver_scene");                        
        }
    }

    public void LoadScene(string sceneName = "World_scene")
    {
        SceneManager.LoadScene(sceneName, LoadSceneMode.Single);
    }

    public void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        if(scene.name=="World_scene")
        {
            m_timer = new TimerUtil();
            m_timer.Interval = (double)m_secondsLeft;
            m_timerText.text = m_timer.GetMinutesString(0.0);
            m_timer.Elapsed += OnElapsedTimer;
            m_timer.Start();
            m_timer.Enabled = true;
            m_timer.AutoReset = false;                        
            GameManagerResourcers.Instance.spawnTargets();
            GameManagerResourcers.Instance.SpawnOwnVehicle();
            isGameStarted = true;
        }
    }

    public void OnElapsedTimer (object sender, System.Timers.ElapsedEventArgs e)
    {
        //m_timer.Stop();
        //this.m_timerText.enabled =false;
        this.m_isGameOver = true;
                        
    }

    public void countFireShots()
    {
        ++m_numFireShots;
    }

    public void countTargetsHit()
    {
        ++m_numHits;
    }

    public bool IsGameStarted
    {
        get{return isGameStarted;}
        set{isGameStarted = value;}
    }
    public void CheckEndGame()
    {
        if(isGameStarted)
        {
            foreach(Target tt in GameManagerResourcers.Instance.m_targetsPfabs)
            {
                if(tt.IsTargetDead) m_numTargetsDead++;

            }
            if(m_numTargetsDead==GameManagerResourcers.Instance.m_targetsInstantiated.Count)
            {
                m_isGameOver = true;
                isGameStarted = false;
            }
        }
    }



    
}
