#pragma once
#include "baselogger.h"
#ifndef WIN32
#include <syslog.h>
#endif
class SyslogLogger :
    public BaseLogger
{
public:
    SyslogLogger(void);
    ~SyslogLogger(void);
    void SetFacilityCode(int facilityCode);
    void SetLogOpt(int logOpt);
    void Log(E_LOG_LEVEL level, const char * strMsg, const char * file, const unsigned long line, const char * function);
private:
    int m_FacilityCode;
    int m_LogOpt;
};

