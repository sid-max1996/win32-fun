#include "win32_fun.h"
#include "diskusage.h"
#include "screen.h"
#include <windows.h>

using namespace std;

Napi::Object win32_fun::getDiskUsage(const Napi::CallbackInfo& info) 
{
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "expected param path").ThrowAsJavaScriptException();
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "path not a string").ThrowAsJavaScriptException();
  } 

  // Napi::String first = info[0].As<Napi::String>();
  string str = info[0].ToString().Utf8Value();
  const char* path = str.c_str();
  

  DiskUsage m_info = GetDiskUsage(path);

  Napi::Object obj = Napi::Object::New(env);
  obj.Set("free", m_info.free);
  obj.Set("total", m_info.total);
  obj.Set("available", m_info.available);
  return obj;
}

Napi::Value win32_fun::screenSleep(const Napi::CallbackInfo& info) 
{
  Napi::Env env = info.Env();
  ScreenSleep();
  return env.Null();
}

Napi::Value win32_fun::screenWakeUp(const Napi::CallbackInfo& info) 
{
  Napi::Env env = info.Env();
  ScreenWakeUp();
  return env.Null();
}

Napi::Object win32_fun::Init(Napi::Env env, Napi::Object exports) 
{
  exports.Set("getDiskUsage", Napi::Function::New(env, win32_fun::getDiskUsage));
  exports.Set("screenSleep", Napi::Function::New(env, win32_fun::screenSleep));
  exports.Set("screenWakeUp", Napi::Function::New(env, win32_fun::screenWakeUp));
  return exports;
}
