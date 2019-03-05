#pragma once
#ifndef _H_XCONTROLLER_HPP_
#define _H_XCONTROLLER_HPP_

#include "XController.h"
#include <XUtil/XUtil.hpp>

class XControllerImpl : public XController
{
private:
    std::map<std::string,void*> map_modules_;
    std::map<std::string,void*> map_handlers_;
    std::map<std::string,void*> map_datas_;
    std::recursive_mutex mutex_;
public:
    // void RegisterModule(const char* path)
    // {
    //     //
    // }

    void Start() 
    {

    }
    void Stop()
    {

    }
    
    void SetHandler(const char* name, void* handler)
    {
        std::unique_lock <std::mutex> lock(mutex_);
        if (handler) {
            map_handlers_.erase(name);
        } else {
            map_handlers_[name] = handler;
        }
    }

    void* GetHandler(const char* name)
    {
        std::unique_lock <std::mutex> lock(mutex_);
        auto it = map_handlers_.find(name);
        if(it != map_handlers_.end()) {
            return it->second;
        }
        return nullptr;
    }

    void SetThreadHandler(const char* name, void* handler, size_t threadid)
    {

    }

    void* GetThreadHandler(const char* name, size_t threadid)
    {
        return nullptr;
    }

    void SetData(const char* name, void* data)
    {

    }
    void* GetData(const char* name)
    {
        return nullptr;
    }

    void SetThreadData(const char* name, void* data, size_t threadid)
    {

    }
    void* GetThreadData(const char* name, size_t threadid)
    {
        return nullptr;
    }
};

#endif//_H_XCONTROLLER_HPP_