using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using UnityEngine;

public class OwnVehicle : NetworkObject
{
    // Start is called before the first frame update
    public Transform m_barrel;
    public Transform m_turret;


    public float m_barrelSensibility = 3.0f;
    public float m_turretSensibility = 0.5f;

    private float m_turretAngle;
    private float m_barrelAngle;
    
    private float m_zAxis, m_xAxis;        
    
    
    private bool m_canProcessBarrelAngle;
    private bool m_canProcessTurretlAngle;

    private bool m_canFireWeapon;

    new void Start()
    {
        GameManagerNetwork.Instance.RegisterNetworkObject(this);
        m_canProcessBarrelAngle = false;
        m_canProcessTurretlAngle = false;
        m_canFireWeapon = false;      
        base.Start();
    }

    // Update is called once per frame
    new void Update()
    {    
        if(m_canProcessBarrelAngle)
        {
            ProcessBarrelMovement();
            //m_canProcessBarrelAngle = fa

        }
        ProcessTurretMovement();
        ProcessVehicleMovement(); 
        if(m_canFireWeapon)
        {
            FireWeapon();
            m_canFireWeapon = false;
        }  
        base.Update();   
    }   

    public override void ProcessMessages(string[] msg)
    {
        if(msg[0]=="WEAPON_ROTATION")
        {
            m_turretAngle = float.Parse(msg[1], CultureInfo.InvariantCulture);
            m_canProcessTurretlAngle = true;            
                    
        }
        else if(msg[0]=="WEAPON_ELEVATION")
        {
            m_barrelAngle = float.Parse(msg[1], CultureInfo.InvariantCulture);
            m_canProcessBarrelAngle = true;            
        }
        else if(msg[0]=="MOVEMENT_PLAYER")
        {             
            if(m_zAxis!=0) m_xAxis  += float.Parse(msg[2],CultureInfo.InvariantCulture);
            m_zAxis  += float.Parse(msg[1],CultureInfo.InvariantCulture);

            m_xAxis = Mathf.Clamp(m_xAxis,-1.0f,1.0f);
            m_zAxis = Mathf.Clamp(m_zAxis,-1.0f,1.0f);                        
        }
        else if(msg[0]=="FIRE_WEAPON")
        {             
            m_canFireWeapon = true;                
        }
        //Debug.Log("A mensagem que chegou foi: " + msg[0]);
    }

    void ProcessBarrelMovement()
    {
        
       
        m_barrel.localRotation = Quaternion.Slerp(m_barrel.localRotation,Quaternion.Euler(Vector3.right*m_barrelAngle),Time.deltaTime*m_barrelSensibility);        
    }

    void ProcessTurretMovement()
    {

        m_turret.localRotation = Quaternion.Slerp(m_turret.localRotation,Quaternion.Euler(Vector3.up*m_turretAngle),Time.deltaTime*m_turretSensibility);
    }

    void ProcessVehicleMovement()
    {
        
                
        Vector3 newPos = new Vector3(m_xAxis,0.0f,m_zAxis) + transform.position;        
        Vector3 newdir = transform.TransformDirection(newPos - transform.position).normalized;


        if(m_zAxis!=0)
        {           
            Quaternion newRotation = Quaternion.LookRotation(newdir,transform.up);            
            transform.Translate(newdir*Time.deltaTime*Mathf.Abs(m_zAxis), Space.World);
            transform.rotation = Quaternion.Slerp(transform.rotation,newRotation,m_zAxis*Time.deltaTime);                    
        }
        else m_xAxis = 0.0f;
                
    }

    public override void Write(ref System.Net.Sockets.Socket networkSender)
    {
        //networkSender.Send()
    }

    public void FireWeapon()
    {
        RaycastHit hit;
        Camera cam = Camera.main;
        GameManager.Instance.countFireShots();
        if(Physics.Raycast(cam.transform.position,cam.transform.forward, out hit, 1000.0f))
        {
            Target target = hit.transform.GetComponent<Target>();

            if(target!=null)
            {
                Debug.Log(hit.transform.name);
                target.Die(hit,cam.transform.forward);
            }
            
        }
    }
}
