#include "XController.hpp"
#include <XUtil/XUtil.hpp>

extern "C" {

// void XController_RegisterModule(const char* path)
// {

// }

void XController_Start(int argc, const char* argv)
{
    XController::Instance().Start(argc, argv);
}

void XController_Stop()
{
    XController::Instance().Stop();
}

void XController_SetHandler(const char* name, void* handler)
{
    XController::Instance().SetHandler(name, handler);
}

void* XController_GetHandler(const char* name)
{
    return XController::Instance().GetHandler(name);
}

void XController_SetThreadHandler(const char* name, void* handler, size_t threadid)
{
    XController::Instance().SetThreadHandler(name, handler, threadid);
}

void* XController_GetThreadHandler(const char* name, size_t threadid)
{
    return XController::Instance().GetThreadHandler(name, threadid);
}

void XController_SetData(const char* name, void* data)
{
    XController::Instance().SetData(name, data);
}

void* XController_GetData(const char* name)
{
   return XController::Instance().GetData(name);
}

void XController_SetThreadData(const char* name, void* data, size_t threadid)
{
    XController::Instance().SetThreadData(name, data, threadid);
}

void* XController_GetThreadData(const char* name, size_t threadid)
{
    return XController::Instance().GetThreadData(name, threadid);
}

}

XController& XController::Instance()
{
    static XControllerImpl _inst;
    return _inst;
}
