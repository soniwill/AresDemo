#ifndef LOGGER_H
#define LOGGER_H

#include <string>


/**< Abstract class for loggers implementations */
class Logger
{
    public:
        /** Default destructor */
        virtual ~Logger(){}
        virtual void write (const std::string& ) = 0;

    protected:

    private:
};

#endif // LOGGER_H
