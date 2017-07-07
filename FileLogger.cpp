#include "FileLogger.h"

FileLogger::FileLogger(void):BaseLogger()
{
    m_LogType = LOG_TYPE_FILE;
}


FileLogger::~FileLogger(void)
{
}

void FileLogger::Log(E_LOG_LEVEL level, const char * strMsg, const char * file, const unsigned long line, const char * function)
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
    _WriteLogToFile(logMsg, file);
}

void FileLogger::_WriteLogToFile(const char * strMsg, const char * filename)
{
    char logfile[MAX_FILE_NAME_LENGTH];
    memset(logfile, 0, sizeof(logfile));
#ifdef WIN32
#ifdef LOG_PATH
    strcpy_s(logfile, sizeof(logfile), LOG_PATH);
#else
    strcpy_s(logfile, sizeof(logfile), "./log/");
#endif
#else
#ifdef LOG_PATH
    strncpy(logfile, LOG_PATH, sizeof(LOG_PATH));
#else
    strncpy(logfile, "./log/", sizeof("./log/");
#endif
#endif
    const char *ext = ".log";
    const char *pos = NULL;
    const char *newpos = NULL;
#ifdef WIN32
    pos = strrchr(filename, '\\');
#else
    pos = strrchr(filename, '/');
#endif
    if(pos != NULL){
        newpos = pos;
    }else{
        newpos = filename;
    }
    newpos = pos != NULL ? (pos+1) : filename;
    FILE * fp;
#ifdef WIN32
    // 检查log父目录
    if(_access(logfile, 0) == -1){
        // 创建log父目录
        _mkdir(logfile);
    }
    strcat_s(logfile, sizeof(logfile), newpos);
    strcat_s(logfile, sizeof(logfile), ext);
    fopen_s(&fp, logfile, "at+");
#else
    // 检查log父目录
    if(access(logfile, 0) == -1){
        // 创建log父目录
        mkdir(logfile, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
    strcat(logfile, newpos);
    strcat(logfile, ext);
    fp = fopen(logfile, "at+");
#endif
    if (NULL == fp)
    {
        printf("Open file \"%s\" failed.", filename);
        return;
    }
    fprintf(fp, "%s", strMsg);
    fflush(fp);
    fclose(fp);
}
