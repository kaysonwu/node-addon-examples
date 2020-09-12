#include <napi.h>
#include "hero.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  return Hero::Init(env, exports);
}

NODE_API_MODULE(addon, Init)
