#pragma once
#include "BaseLogger.h"

#define MAX_FILE_NAME_LENGTH 255

#define LOG_PATH "./log/"

class FileLogger :
    public BaseLogger
{
public:
    FileLogger(void);
    ~FileLogger(void);
    void Log(E_LOG_LEVEL level, const char * strMsg, const char * file, const unsigned long line, const char * function);
private:
    void _WriteLogToFile(const char * strMsg, const char * filename);
};

