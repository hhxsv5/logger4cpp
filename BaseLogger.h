#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#ifdef __cplusplus
}
#endif
#ifdef WIN32
#include <io.h>
#include <direct.h>
#else
#ifdef __cplusplus
extern "C" {
#endif
#include <unistd.h>
#include <sys/stat.h>
#ifdef __cplusplus
}
#endif
#endif
enum E_LOG_LEVEL
{
    /** emerg */	LOG_LEVEL_EMERG		= 000, 
    /** alert */	LOG_LEVEL_ALERT		, 
    /** crit */	    LOG_LEVEL_CRIT		, 
    /** error */	LOG_LEVEL_ERROR     , 
    /** warn */   	LOG_LEVEL_WARN	    , 
    /** notice */	LOG_LEVEL_NOTICE	, 
    /** info */     LOG_LEVEL_INFO      ,
    /** debug */	LOG_LEVEL_DEBUG
};

enum E_LOG_TYPE
{
    /** stdout */	LOG_TYPE_STDOUT		= 000, 
    /** file */	    LOG_TYPE_FILE		, 
    /** syslog */	LOG_TYPE_SYSLOG
};

#define MAX_LOG_LENGTH 4096

class BaseLogger
{
public:
    BaseLogger(void);
    virtual ~BaseLogger(void) = 0;
    void LogDebug(const char * info, const char * file, const unsigned long line, const char * function);
    void LogInfo(const char * info, const char * file, const unsigned long line, const char * function);
    void LogNotice(const char * info, const char * file, const unsigned long line, const char * function);
    void LogWarn(const char * info, const char * file, const unsigned long line, const char * function);
    void LogError(const char * info, const char * file, const unsigned long line, const char * function);
    void LogCrit(const char * info, const char * file, const unsigned long line, const char * function);
    void LogAlert(const char * info, const char * file, const unsigned long line, const char * function);
    void LogEmerg(const char * info, const char * file, const unsigned long line, const char * function);
    
    virtual void Log(E_LOG_LEVEL level, const char * strMsg, const char * file, const unsigned long line, const char * function) = 0;
    E_LOG_TYPE GetLogType();
    const static char * GetSystemTime(const char * format = "%4d-%02d-%02d %02d:%02d:%02d");//only declare default params in head file
    static const char * LEVEL_STRING[11];
protected:
    E_LOG_TYPE m_LogType;
    //void sprintf_cp(_Out_writes_z_(_SizeInBytes) char * _DstBuf, _In_ size_t _SizeInBytes, _In_z_ _Printf_format_string_ const char * _Format, ...);//cross-platform
private:
    static char m_CurrentTime[512];
};
