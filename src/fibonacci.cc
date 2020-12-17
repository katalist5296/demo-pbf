#include <napi.h>
#include <vector>
#include <algorithm>

std::vector<double> Fibonacci(int max) {
	std::vector<double> retval = {0, 1};
	for(int i = 2; i <= max; i++) {
		retval.push_back(retval[i-1] + retval[i-2]);
	}

	return retval;
}

napi_value getFibonacciArray(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	if (info.Length() != 1) {
		Napi::TypeError::New(env, "Wrong number of arguments")
			.ThrowAsJavaScriptException();
		return env.Null();
	}

	if (!info[0].IsNumber()) {
		Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
		return env.Null();
	}

	double length = info[0].As<Napi::Number>().DoubleValue();
	Napi::Array outputArray = Napi::Array::New(env, length);
	std::vector<double> fibonacciArray = Fibonacci(length);

	for (int i = 0; i < length; i++) {
		outputArray[i] = Napi::Number::New(env, double(fibonacciArray[i]));
	}

	return outputArray;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(Napi::String::New(env, "get"), Napi::Function::New(env, getFibonacciArray));
	return exports;
}

NODE_API_MODULE(addon, Init)
