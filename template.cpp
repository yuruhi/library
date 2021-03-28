#pragma once
#include "./Utility/constants.cpp"
#include "./Utility/Scanner.cpp"
#include "./Utility/Printer.cpp"
#include "./Utility/Step.cpp"
#include "./Utility/Ruby.cpp"
#include "./Utility/functions.cpp"
#if __has_include(<library/dump.hpp>)
#include <library/dump.hpp>
#define LOCAL
#else
#define dump(...) ((void)0)
#define dump2(...) ((void)0)
#endif
#include "./Utility/oj_local.cpp"
#include <bits/stdc++.h>
