#include "TimeUtil.h"


system_clock::time_point TimeUtil::m_startTime, TimeUtil::m_endTime;
bool TimeUtil::m_isChronometerRunning;
duration<double> TimeUtil::m_elapsedTime(0);

TimeUtil::TimeUtil()
{
    //ctor


}

TimeUtil::~TimeUtil()
{
    //dtor
}
const std::string TimeUtil::GetTime()
{
    std::ostringstream oss;

     std::time_t currTime = system_clock::to_time_t(system_clock::now());
     struct tm * timeinfo = localtime ( &currTime );
     oss<< timeinfo->tm_hour<< ":" << timeinfo->tm_min << ":" <<timeinfo->tm_sec;
     return oss.str();
}

const std::string TimeUtil::GetDate()
{
    std::ostringstream oss;

     std::time_t currDate = system_clock::to_time_t(system_clock::now());
     struct tm * timeinfo = localtime ( &currDate );
     oss<< timeinfo->tm_mday<< "-" << timeinfo->tm_mon + 1<< "-" <<timeinfo->tm_year +  1900;
     return oss.str();
}

void TimeUtil::StartChronometer()
{
    std::chrono::duration<double> noTime(0);
    m_elapsedTime = noTime;

    m_startTime = system_clock::now();
    m_isChronometerRunning = true;
}

void TimeUtil::StopChronometer()
{
    if(!m_isChronometerRunning)
    {
        std::chrono::duration<double> noTime(0);
        m_elapsedTime = noTime;

    }
    else
    {
        m_endTime = system_clock::now();
        m_elapsedTime = m_endTime - m_startTime;
    }
    m_isChronometerRunning = false;

}

double TimeUtil::GetElapsedTime()
{
    return m_elapsedTime.count();
}

const std::string TimeUtil::GetStrElapsedTime()
{
    std::ostringstream oss;

    oss<< m_elapsedTime.count();

    return oss.str();
}


