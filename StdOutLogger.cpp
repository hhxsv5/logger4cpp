#include "StdOutLogger.h"

StdOutLogger::StdOutLogger(void):BaseLogger()
{
    m_LogType = LOG_TYPE_STDOUT;
}


StdOutLogger::~StdOutLogger(void)
{
}

void StdOutLogger::Log(E_LOG_LEVEL level, const char * strMsg, const char * file, const unsigned long line, const char * function)
{
    char logMsg[MAX_LOG_LENGTH];
    memset(logMsg, 0, sizeof(logMsg));

#ifdef WIN32
    sprintf_s(logMsg, MAX_LOG_LENGTH, "[%s] [%s] %s, File: %s, Line: %lu, Function: %s\n",
        GetSystemTime(),
        BaseLogger::LEVEL_STRING[level], strMsg,
        file, line, function);
#else
    snprintf(logMsg, MAX_LOG_LENGTH, "[%s] [%s] %s, File: %s, Line: %lu, Function: %s\n",
        GetSystemTime(),
        BaseLogger::LEVEL_STRING[level], strMsg,
        file, line, function);
#endif
    fprintf(stdout, logMsg);
}
