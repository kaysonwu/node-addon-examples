#pragma once

#include <napi.h>

class Pet : public Napi::ObjectWrap<Pet> {
 public:
  static void Init(Napi::Env env);
  static Napi::Object New(Napi::Env env, Napi::Value arg);
  Pet(const Napi::CallbackInfo& info);

 private:
  const char* Name;
  Napi::Value GetName(const Napi::CallbackInfo& info);
};
