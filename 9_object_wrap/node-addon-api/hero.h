#pragma once

#include <napi.h>


class Hero : public Napi::ObjectWrap<Hero> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Hero(const Napi::CallbackInfo& info);

 private:
  const char* Name;
  Napi::Object Pet;
  Napi::Value GetPet(const Napi::CallbackInfo& info);
  Napi::Value GetName(const Napi::CallbackInfo& info);
};
