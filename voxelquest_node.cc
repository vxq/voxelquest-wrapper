#include <node.h>

using namespace v8;

void GetThing(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() > 0) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  auto thing = String::NewFromUtf8(isolate, "Thing");
  args.GetReturnValue().Set(thing);
}

void Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "getThing", GetThing);
}

NODE_MODULE(addon, Init)