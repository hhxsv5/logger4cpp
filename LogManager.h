#pragma once

//LogManager Unique Instance£»
#define LOG_INSTANCE (LogManager::GetInstance())

//Log Level=DEBUG
#define DEBUG(strinfo)\
{\
    if(LOG_INSTANCE != NULL)\
    {\
    LOG_INSTANCE->LogDebug(strinfo, __FILE__, __LINE__, __FUNCTION__);\
    }\
}

//Log Level=INFO
#define INFO(strinfo)\
{\
    if(LOG_INSTANCE != NULL)\
    {\
    LOG_INSTANCE->LogInfo(strinfo, __FILE__, __LINE__, __FUNCTION__);\
    }\
}

//Log Level=NOTICE
#define NOTICE(strinfo)\
{\
    if(LOG_INSTANCE != NULL)\
    {\
    LOG_INSTANCE->LogNotice(strinfo, __FILE__, __LINE__, __FUNCTION__);\
    }\
}

//Log Level=WARN
#define WARN(strinfo)\
{\
    if(LOG_INSTANCE != NULL)\
    {\
    LOG_INSTANCE->LogWarn(strinfo, __FILE__, __LINE__, __FUNCTION__);\
    }\
}

//Log Level=Error
#define ERROR(strinfo)\
{\
    if(LOG_INSTANCE != NULL)\
    {\
    LOG_INSTANCE->LogError(strinfo, __FILE__, __LINE__, __FUNCTION__);\
    }\
}

//Log Level=CRIT
#define CRIT(strinfo)\
{\
    if(LOG_INSTANCE != NULL)\
    {\
    LOG_INSTANCE->LogCrit(strinfo, __FILE__, __LINE__, __FUNCTION__);\
    }\
}

//Log Level=ALERT
#define ALERT(strinfo)\
{\
    if(LOG_INSTANCE != NULL)\
    {\
    LOG_INSTANCE->LogAlert(strinfo, __FILE__, __LINE__, __FUNCTION__);\
    }\
}

//Log Level=EMERG
#define EMERG(strinfo)\
{\
    if(LOG_INSTANCE != NULL)\
    {\
    LOG_INSTANCE->LogEmerg(strinfo, __FILE__, __LINE__, __FUNCTION__);\
    }\
}

//Free Log Resource
#define LOG_FREE()\
{\
    LOG_INSTANCE->FreeInstance();\
}

#include "BaseLogger.h"
#include "StdOutLogger.h"
#include <map>
using namespace std;

class LogManager
{
public:
    ~LogManager(void);
    static LogManager * GetInstance();
    static void FreeInstance();

    void AppendLoger(BaseLogger *log);

    void LogDebug(const char * info, const char * file, const unsigned long line, const char * function);
    void LogInfo(const char * info, const char * file, const unsigned long line, const char * function);
    void LogNotice(const char * info, const char * file, const unsigned long line, const char * function);
    void LogWarn(const char * info, const char * file, const unsigned long line, const char * function);
    void LogError(const char * info, const char * file, const unsigned long line, const char * function);
    void LogCrit(const char * info, const char * file, const unsigned long line, const char * function);
    void LogAlert(const char * info, const char * file, const unsigned long line, const char * function);
    void LogEmerg(const char * info, const char * file, const unsigned long line, const char * function);
    void Log(E_LOG_LEVEL level, const char * strMsg, const char * file, const unsigned long line, const char * function);
    void SetLogLevel(E_LOG_LEVEL level);
    E_LOG_LEVEL GetLogLevel();
private:
    map<unsigned int, BaseLogger *> m_loggers;
    E_LOG_LEVEL m_LogLevel;
    LogManager(void);
    LogManager(LogManager &manager);
    static const LogManager *m_Instance;
};