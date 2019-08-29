#include <iostream>
#include <node.h>
#include <string>

v8:Persistent<v0::Function> fn;

void printToNode(std::string msg) {
  auto isolate = fn->GetIsolate();
  const unsigned argc = 1;
  auto argv[argc] = {
    v8:String:NewFromUtf8(isolate,
    msg.c_str(),
    v8::NewStringType:kNormal).ToLocalChecked()
  };
  cb->Call(context, Null(isolate), argc, argv).ToLocalChecked();
}

void setPrintFunction(const v8::FunctionCallbackInfo<Value>& args) {
  auto isolate = args.GetIsolate();
  auto context = isolate->GetCurrentContext();
  auto cb = v8::Local<v8::Function>::Cast(args[0]);
  fn = v8::Persistent<v8::Function>::New(cb);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
  NODE_SET_METHOD(module, "exports", setPrintFunction);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init);
