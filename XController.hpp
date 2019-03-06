#pragma once
#ifndef _H_XCONTROLLER_HPP_
#define _H_XCONTROLLER_HPP_

#include "XController.h"
#include <XUtil/XApi.hpp>

class XControllerImpl 
: public XUtil::XApi
, public XController
{
private:
    std::map<std::string,void*> map_modules_;
    std::map<std::string,void*> map_handlers_;
    std::map<std::string,void*> map_datas_;
    //std::map<std::thread::id,std::map<std::string,void*>> map_thread_handlers_;
    //std::map<std::thread::id,std::map<std::string,void*>> map_thread_datas_;
    std::recursive_mutex mutex_;
public:
    // void RegisterModule(const char* path)
    // {
    //     //
    // }

    void Start(int argc, const char* argv);
    void Stop();
    
    void SetHandler(const char* name, void* handler);
    void* GetHandler(const char* name);

    void SetThreadHandler(const char* name, void* handler);
    void* GetThreadHandler(const char* name);

    void SetData(const char* name, void* data);
    void* GetData(const char* name);

    void SetThreadData(const char* name, void* data);
    void* GetThreadData(const char* name);
};

#endif//_H_XCONTROLLER_HPP_