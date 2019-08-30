#include <node.h>

#include "index.h"

void Hello(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  args.GetReturnValue().Set(v8::String::NewFromUtf8(
    isolate, "world", v8::NewStringType::kNormal).ToLocalChecked());
}

void Initialize(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "hello", Hello);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)