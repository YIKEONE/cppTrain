#include"hello.h"

int main() {
    auto* hellClass = new Hello();
    hellClass->SayHello();
    delete hellClass;
}