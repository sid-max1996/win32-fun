#include <napi.h>

namespace win32_fun {
  Napi::Value screenSleep(const Napi::CallbackInfo& info);
  Napi::Value screenWakeUp(const Napi::CallbackInfo& info);
  Napi::Object getDiskUsage(const Napi::CallbackInfo& info);
  Napi::Object Init(Napi::Env env, Napi::Object exports);
}
