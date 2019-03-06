#include "XController.hpp"
#include <XUtil/XUtil.hpp>

extern "C"
{
    // void XController_RegisterModule(const char* path)
    // {
    // }

    void XController_Start(int argc, const char *argv)
    {
        XController::Instance().Start(argc, argv);
    }

    void XController_Stop()
    {
        XController::Instance().Stop();
    }

    void XController_SetHandler(const char *name, void *handler)
    {
        XController::Instance().SetHandler(name, handler);
    }

    void *XController_GetHandler(const char *name)
    {
        return XController::Instance().GetHandler(name);
    }

    void XController_SetThreadHandler(const char *name, void *handler)
    {
        XController::Instance().SetThreadHandler(name, handler);
    }

    void *XController_GetThreadHandler(const char *name)
    {
        return XController::Instance().GetThreadHandler(name);
    }

    void XController_SetData(const char *name, void *data)
    {
        XController::Instance().SetData(name, data);
    }

    void *XController_GetData(const char *name)
    {
        return XController::Instance().GetData(name);
    }

    void XController_SetThreadData(const char *name, void *data)
    {
        XController::Instance().SetThreadData(name, data);
    }

    void *XController_GetThreadData(const char *name)
    {
        return XController::Instance().GetThreadData(name);
    }
}

XController &XController::Instance()
{
    static XControllerImpl _inst;
    return _inst;
}

thread_local std::map<std::string, void *> _map_handlers;
thread_local std::map<std::string, void *> _map_datas;
//boost::thread_specific_ptr<std::map<std::string, void *>> _p_map_datas;

void XControllerImpl::Start(int argc, const char *argv)
{

}

void XControllerImpl::Stop()
{

}

void XControllerImpl::SetHandler(const char *name, void *handler)
{
    std::unique_lock<std::recursive_mutex> lock(mutex_);
    if (handler)  {
        map_handlers_.erase(name);
    } else {
        map_handlers_[name] = handler;
    }
}

void *XControllerImpl::GetHandler(const char *name)
{
    std::unique_lock<std::recursive_mutex> lock(mutex_);
    auto it = map_handlers_.find(name);
    if (it != map_handlers_.end())  {
        return it->second;
    }
    return nullptr;
}

void XControllerImpl::SetThreadHandler(const char *name, void *handler)
{
    // if(!_p_map_handlers.get()) {
    //     std::unique_lock<std::recursive_mutex> lock(mutex_);
    //     _p_map_handlers.reset(&map_thread_handlers_[std::this_thread::get_id()]);
    // }
    // auto & _map_handlers = *_p_map_handlers.get();
    if (handler) {
        _map_handlers.erase(name);
    } else {
        _map_handlers[name] = handler;
    }
}

void *XControllerImpl::GetThreadHandler(const char *name)
{
    // auto p = _p_map_handlers.get();
    // if(p) {
    //     auto & _map_handlers = *p;
        auto it = _map_handlers.find(name);
        if (it != _map_handlers.end()) {
            return it->second;
        }
    // }
    return nullptr;
}

void XControllerImpl::SetData(const char *name, void *data)
{
    std::unique_lock<std::recursive_mutex> lock(mutex_);
    if (data) {
        map_datas_.erase(name);
    } else {
        map_datas_[name] = data;
    }
}

void *XControllerImpl::GetData(const char *name)
{
    std::unique_lock<std::recursive_mutex> lock(mutex_);
    auto it = map_datas_.find(name);
    if (it != map_datas_.end()) {
        return it->second;
    }
    return nullptr;
}

void XControllerImpl::SetThreadData(const char *name, void *data)
{
    // if(!_p_map_datas.get()) {
    //     std::unique_lock<std::recursive_mutex> lock(mutex_);
    //     _p_map_datas.reset(&map_thread_datas_[std::this_thread::get_id()]);
    // }
    // auto & _map_datas = *_p_map_datas.get();
    if (data) {
        _map_datas.erase(name);
    } else {
        _map_datas[name] = data;
    }
}

void *XControllerImpl::GetThreadData(const char *name)
{
    // auto p = _p_map_datas.get();
    // if(p) {
    //     auto & _map_datas = *p;
        auto it = _map_datas.find(name);
        if (it != _map_datas.end()) {
            return it->second;
        }
    // }
    return nullptr;
}
