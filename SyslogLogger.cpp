#include "SyslogLogger.h"


SyslogLogger::SyslogLogger(void):BaseLogger()
{
    m_LogType = LOG_TYPE_SYSLOG;
#ifdef WIN32
    fprintf(stderr, "syslog supports linux only.");
    return;
#else
    m_FacilityCode = LOG_USER;//default LOG_USER
    m_LogOpt = LOG_PID;
#endif
}


SyslogLogger::~SyslogLogger(void)
{
}

void SyslogLogger::SetFacilityCode(int facilityCode)
{
    m_FacilityCode = facilityCode;
}
void SyslogLogger::SetLogOpt(int logOpt)
{
    m_LogOpt = logOpt;
}


void SyslogLogger::Log(E_LOG_LEVEL level, const char * strMsg, const char * file, const unsigned long line, const char * function)
{
    char logMsg[MAX_LOG_LENGTH];
    memset(logMsg, 0, sizeof(logMsg));

#ifdef WIN32
    fprintf(stderr, "syslog supports linux only.");
    return;
#else
    snprintf(logMsg, MAX_LOG_LENGTH, "[%s] %s, File: %s, Line: %lu, Function: %s\n",
        //GetSystemTime(),
        BaseLogger::LEVEL_STRING[level], strMsg,
        file, line, function);
    //int logmask;
    openlog(file, m_LogOpt, m_FacilityCode);
    syslog(level, logMsg);
    //syslog(LOG_DEBUG,"debug message, should appear");   /*记录该日志信息。*/
    //logmask = setlogmask(LOG_UPTO(LOG_NOTICE));     /*设置屏蔽低于NOTICE级别的日志信息。*/
    //syslog(LOG_DEBUG, "debug message, should not appear");  /*该日志信息被屏蔽，不记录。*/
    closelog();
#endif
}

