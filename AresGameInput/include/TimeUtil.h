#ifndef TIMEUTIL_H
#define TIMEUTIL_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <ratio>


using namespace std::chrono;

class TimeUtil
{
    public:
        /** Default constructor */
        TimeUtil();
        /** Default destructor */
        virtual ~TimeUtil();

        static const std::string GetTime();
        static const std::string GetDate();
        static const std::string GetStrElapsedTime();

        static void StartChronometer();
        static void StopChronometer();
        static double GetElapsedTime();


    protected:

    private:
        static system_clock::time_point m_startTime, m_endTime;
        static bool m_isChronometerRunning;
        static duration<double> m_elapsedTime;
};

#endif // TIMEUTIL_H
