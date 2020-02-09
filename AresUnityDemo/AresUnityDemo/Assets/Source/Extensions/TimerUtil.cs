using System;
using System.Collections;
using System.Collections.Generic;


public class TimerUtil : System.Timers.Timer
{
    private DateTime m_dueTime;

    public TimerUtil() : base()
    {
        this.Elapsed += this.ElapsedAction;
    }

    protected new void Dispose()
    {
        this.Elapsed -= this.ElapsedAction;
        base.Dispose();
    }

    public double TimeLeft
    {
        get
        {
            return (this.m_dueTime - DateTime.Now).TotalMilliseconds;
        }
    }

    public new void Start()
    {
        this.m_dueTime = DateTime.Now.AddMilliseconds(this.Interval);
        base.Start();
    }

    public string GetTimeLeftString()
    {                
        System.TimeSpan timespan = System.TimeSpan.FromMilliseconds(TimeLeft);
        
        return timespan.ToString(@"mm\:ss");
    
    }
    public string GetMinutesString(double totalSeconds)
    {                
        System.TimeSpan timespan = System.TimeSpan.FromSeconds(totalSeconds);
        
        return timespan.ToString(@"mm\:ss");
    
    }

    private void ElapsedAction(object sender, System.Timers.ElapsedEventArgs e)
    {
        if (this.AutoReset)
        {
            this.m_dueTime = DateTime.Now.AddMilliseconds(this.Interval);
        }
    }
}

   
    

    // public System.Timers.Timer Timer
    // {
        
    //     get{return m_timer;}
    // }   


