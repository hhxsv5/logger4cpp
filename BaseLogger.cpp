#include "BaseLogger.h"

BaseLogger::BaseLogger(void)
{
}
BaseLogger::~BaseLogger(void)
{
}

E_LOG_TYPE BaseLogger::GetLogType()
{
    return m_LogType;
}
void BaseLogger::LogDebug(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_DEBUG, info, file, line, function);
}
void BaseLogger::LogInfo(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_INFO, info, file, line, function);
}
void BaseLogger::LogNotice(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_NOTICE, info, file, line, function);
}
void BaseLogger::LogWarn(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_WARN, info, file, line, function);
}
void BaseLogger::LogError(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_ERROR, info, file, line, function);
}
void BaseLogger::LogCrit(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_CRIT, info, file, line, function);
}
void BaseLogger::LogAlert(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_ALERT, info, file, line, function);
}
void BaseLogger::LogEmerg(const char * info, const char * file, const unsigned long line, const char * function)
{
    Log(LOG_LEVEL_EMERG, info, file, line, function);
}

const char * BaseLogger::GetSystemTime(const char * format)
{
    time_t rawtime;
    time(&rawtime);    
#ifdef WIN32
    struct tm timeinfo;
    localtime_s(&timeinfo, &rawtime);
    sprintf_s(
        m_CurrentTime, sizeof(m_CurrentTime),
        format,
        1900 + timeinfo.tm_year, 1 + timeinfo.tm_mon, timeinfo.tm_mday, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
#else
    struct tm *timeinfo;
    timeinfo = localtime(&rawtime);
    snprintf(
        m_CurrentTime, sizeof(m_CurrentTime),
        format,
        1900 + timeinfo->tm_year, 1 + timeinfo->tm_mon, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
#endif
    return m_CurrentTime;
}

const char* BaseLogger::LEVEL_STRING[] = {"EMERG","ALERT","CRIT","ERROR","WARN","NOTICE","INFO","DEBUG"};
char BaseLogger::m_CurrentTime[] = "\0";