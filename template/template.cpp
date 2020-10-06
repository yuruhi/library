#pragma once
#include "./constans.cpp"
#include "./Input.cpp"
#include "./Output.cpp"
#include "./Step.cpp"
#include "./Ruby.cpp"
#if __has_include("./../dump.hpp")
#include "./../dump.hpp"
#else
#define dump(...) ((void)0)
#endif