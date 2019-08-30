#include <node_api.h>

#include "index.h"

napi_value Hello(napi_env env, napi_callback_info args) {
  napi_value greeting;
  napi_status status;

  status = napi_create_string_utf8(env, "world", NAPI_AUTO_LENGTH, &greeting);
  if (status != napi_ok) return nullptr;

  return greeting;
}

napi_value init(napi_env env, napi_value exports) {
  napi_value hello;
  napi_status status;

  status = napi_create_function(env, nullptr, 0, Hello, nullptr, &hello);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "hello", hello);
  if (status != napi_ok) return nullptr;

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init);