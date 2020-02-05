#ifndef LOGGERFILE_H
#define LOGGERFILE_H

#include <string>
#include <fstream>
#include "Logger.h"
#include "TimeUtil.h"


class LoggerFile : public Logger
{
    public:
        /** Default constructor */
        LoggerFile();
        /** Default destructor */
        virtual ~LoggerFile();
        void write(const std::string& msg);

    protected:

    private:
        std::ofstream m_file;
};

#endif // LOGGERFILE_H
