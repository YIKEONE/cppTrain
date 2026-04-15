#include<iostream>
#include<dlfcn.h>

typedef int (*AddFunc)(int, int);
typedef int (*SubtractFunc)(int, int);
typedef void (*PrintMessageFunc)();

int main() {
    void* handle = dlopen("./libMathLib.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }

    dlerror();

    auto addFunc = (AddFunc)dlsym(handle, "add");
    auto subtractFunc = (SubtractFunc)dlsym(handle, "subtract");
    auto printMessageFunc = (PrintMessageFunc)dlsym(handle, "printMessage");

    if (!addFunc || !subtractFunc || !printMessageFunc) {
        std::cerr << "Failed to get functions" << std::endl;
        dlclose(handle);
        return 1;
    }

    printMessageFunc();

    dlclose(handle);
    return 0;
}