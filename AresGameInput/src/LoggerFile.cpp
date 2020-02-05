#include "LoggerFile.h"

LoggerFile::LoggerFile()
{
    std::string namefile = TimeUtil::GetDate() + " " + TimeUtil::GetTime() + ".log";
    m_file.open( namefile.c_str()  , std::ios::app );
    m_file.seekp( std::ios::beg );

    if (!m_file.good()) return;
    m_file << "  ===============================================\n"
          << "    Begin Output log ( "
          << TimeUtil::GetDate()
          << " at "
          << TimeUtil::GetTime()
          << " ):\n"
          << "    TIMESTAMP\t\tMESSAGE\n"
          << "\n  ===============================================\n\n";

    m_file.flush();
}

LoggerFile::~LoggerFile()
{
    if (!m_file.good()) return;
    m_file << "\n  ===============================================\n"
          << "    End   Output log ( "
          << TimeUtil::GetDate()
          << " at "
          << TimeUtil::GetTime()
          << " ): "
          << "\n  ===============================================\n\n";
    m_file.flush();
    m_file.close();
}

void LoggerFile::write(const std::string& msg)
{
    std::string timestamp = TimeUtil::GetDate() + " " + TimeUtil::GetTime();
    m_file <<timestamp<<"\t"<<msg<<"\n";
    m_file.flush();
}
