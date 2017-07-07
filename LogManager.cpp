#include "LogManager.h"

LogManager::LogManager(void):m_LogLevel(LOG_LEVEL_DEBUG)
{
    BaseLogger *stdOutLog = new StdOutLogger();
    m_loggers.insert(pair<unsigned int, BaseLogger *>(stdOutLog->GetLogType(), stdOutLog));
}


LogManager::~LogManager(void)
{
    map<unsigned int, BaseLogger *>::iterator it = m_loggers.begin();
    for(;it!=m_loggers.end();++it)
    {
        //fprintf(stdout, "Desctruct::~LogManager(): %u\n", it->first);
        delete it->second;
        it->second = NULL;
    }
}

LogManager::LogManager(LogManager &manager)
{
}

void LogManager::LogDebug(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_DEBUG, info, file, line, function);
}
void LogManager::LogInfo(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_INFO, info, file, line, function);
}
void LogManager::LogNotice(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_NOTICE, info, file, line, function);
}
void LogManager::LogWarn(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_WARN, info, file, line, function);
}
void LogManager::LogError(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_ERROR, info, file, line, function);
}
void LogManager::LogCrit(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_CRIT, info, file, line, function);
}
void LogManager::LogAlert(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_ALERT, info, file, line, function);
}
void LogManager::LogEmerg(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_EMERG, info, file, line, function);
}

void LogManager::Log(E_LOG_LEVEL level, const char * strMsg, const char * file, const unsigned long line, const char * function)
{
    if(m_Instance == NULL || m_LogLevel < level)
    {
        //skipped
    }
    else
    {
        map<unsigned int, BaseLogger *>::iterator it = m_loggers.begin();
        for(;it!=m_loggers.end();++it)
        {
            //dynamic_cast<StdOutLogger *>(it->second)->Log(level, strMsg, file, line, function);
            it->second->Log(level, strMsg, file, line, function);
        }
    }
}

// unique manager instance
const LogManager * LogManager::m_Instance = new LogManager();

LogManager * LogManager::GetInstance()
{
    if(m_Instance == NULL) return NULL;
    return const_cast<LogManager *>(m_Instance);
}

void LogManager::FreeInstance()
{
    //fprintf(stdout, "Desctruct::FreeInstance(): Log Instance\n");
    delete m_Instance;
    m_Instance = NULL;
}

void LogManager::AppendLoger(BaseLogger *log)
{
    m_loggers.insert(pair<unsigned int, BaseLogger *>(log->GetLogType(), log));
}

void LogManager::SetLogLevel(E_LOG_LEVEL level)
{
    m_LogLevel = level;
}
E_LOG_LEVEL LogManager::GetLogLevel()
{
    return m_LogLevel;
}