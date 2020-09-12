#include "hero.h"
#include "pet.h"

Napi::Object Hero::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(env, "Hero", {
    InstanceMethod("getPet", &Hero::GetPet),
    InstanceMethod("getName", &Hero::GetName)
  });

  Napi::FunctionReference* constructor = new Napi::FunctionReference(Persistent(func));
  env.SetInstanceData(constructor);

  Pet::Init(env);
  exports.Set("Hero", func);

  return exports;
}

Hero::Hero(const Napi::CallbackInfo& info): 
  Napi::ObjectWrap<Hero>(info),
  Name(info[0].As<Napi::String>().Utf8Value().c_str()),
  Pet(Pet::New(info.Env(), info[1].As<Napi::String>())) {

}

Napi::Value Hero::GetPet(const Napi::CallbackInfo& info) {
  return this->Pet;
}

Napi::Value Hero::GetName(const Napi::CallbackInfo& info) {
  return Napi::String::New(info.Env(), this->Name);
}
