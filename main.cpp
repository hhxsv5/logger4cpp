#include "LogManager.h"
#include "StdOutLogger.h"
#include "FileLogger.h"
#include "SyslogLogger.h"

int main(void)
{
    //BaseLogger *p = new StdOutLogger();
    //p->LogInfo("Info", __FILE__, __LINE__, __FUNCTION__);
    //p->LogWarn("Warn", __FILE__, __LINE__, __FUNCTION__);
    //p->LogError("Error", __FILE__, __LINE__, __FUNCTION__);
    //p->LogDebug("Debug", __FILE__, __LINE__, __FUNCTION__);
    //delete p;

    //p = new FileLogger();
    //p->LogInfo("Info", __FILE__, __LINE__, __FUNCTION__);
    //p->LogWarn("Warn", __FILE__, __LINE__, __FUNCTION__);
    //p->LogError("Error", __FILE__, __LINE__, __FUNCTION__);
    //p->LogDebug("Debug", __FILE__, __LINE__, __FUNCTION__);
    //delete p;

    //LogManager *manager = LogManager::GetInstance();
    //manager->SetLogLevel(E_LOG_LEVEL::LOG_LEVEL_NOTSET);
    //manager->AppendLoger(new StdOutLogger());
    //manager->LogInfo("Hello Info", __FILE__, __LINE__, __FUNCTION__);
    //manager->LogWarn("Hello Warn", __FILE__, __LINE__, __FUNCTION__);
    //manager->LogError("Hello Error", __FILE__, __LINE__, __FUNCTION__);
    //manager->FreeInstance();

    LOG_INSTANCE->AppendLoger(new FileLogger());
    //LOG_INSTANCE->SetLogLevel(E_LOG_LEVEL::LOG_LEVEL_WARN);
    SyslogLogger *sysLog = new SyslogLogger();
    //sysLog->SetFacilityCode(LOG_USER);
    LOG_INSTANCE->AppendLoger(sysLog);
    INFO("Hello Info");
    WARN("Hello Warn");
    ERROR("Hello Error");

    LOG_FREE();

    INFO("Hello Info");
    WARN("Hello Warn");
    ERROR("Hello Error");

    getchar();
    return 0;
}