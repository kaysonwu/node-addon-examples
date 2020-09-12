#include "pet.h"

void Pet::Init(Napi::Env env) {
  Napi::Function func = DefineClass(env, "Pet", {
    InstanceMethod("getName", &Pet::GetName)
  });

  Napi::FunctionReference* constructor = new Napi::FunctionReference(Persistent(func));
  env.SetInstanceData(constructor);
}

Napi::Object Pet::New(Napi::Env env, Napi::Value arg) {
  return env.GetInstanceData<Napi::FunctionReference>()->New({ arg });
}

Pet::Pet(const Napi::CallbackInfo& info):
  Napi::ObjectWrap<Pet>(info),
  Name(info[0].As<Napi::String>().Utf8Value().c_str()) {

}

Napi::Value Pet::GetName(const Napi::CallbackInfo& info) {
  return Napi::String::New(info.Env(), this->Name);
}
