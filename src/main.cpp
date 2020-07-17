#include <napi.h>
#include "win32_fun.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return win32_fun::Init(env, exports);
}

NODE_API_MODULE(win32_fun, InitAll)
