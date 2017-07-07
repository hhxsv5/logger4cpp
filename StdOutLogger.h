#pragma once
#include "BaseLogger.h"

class StdOutLogger :
    public BaseLogger
{
public:
    StdOutLogger(void);
    ~StdOutLogger(void);
    void Log(E_LOG_LEVEL level, const char * strMsg, const char * file, const unsigned long line, const char * function);
};

