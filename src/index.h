#include <node_api.h>

#ifndef INDEX_H

#define INDEX_H

napi_value Hello(napi_env env, napi_callback_info args);

napi_value Initialize(napi_env env, napi_value exports);

#endif
