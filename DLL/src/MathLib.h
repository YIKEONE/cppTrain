#pragma once

// linux
#ifdef MATHLIB_EXPORTS
// 在编译动态库时，每个函数/变量都是符号，可见性可以谁可以访问，是否可以从外部调用
#define MATHLIB_API __attribute__((visibility("default"))) // 在编译，default 外部可以调用 hidden internal protected
#else
#define MATHLIB_API // 使用方不需要标记
#endif

extern "C" {
    MATHLIB_API int add(int a, int b);
    MATHLIB_API int subtract(int a, int b);
    MATHLIB_API void printMessage();
}