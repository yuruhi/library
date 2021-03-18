---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':warning:'
    path: template_no_Ruby.cpp
    title: template_no_Ruby.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/IO_2Dvector_and_Ruby_push_back_Transpose_Map_Sum.test.cpp
    title: test/IO_2Dvector_and_Ruby_push_back_Transpose_Map_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/IO_vector_and_Ruby_Reverse.test.cpp
    title: test/IO_vector_and_Ruby_Reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Input2DVector.test.cpp
    title: test/Input2DVector.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Input2DVector_read.test.cpp
    title: test/Input2DVector_read.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Input_Output.test.cpp
    title: test/Input_Output.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Input_column.test.cpp
    title: test/Input_column.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template.test.cpp
    title: test/template.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template_no_Ruby.test.cpp
    title: test/template_no_Ruby.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Scanner.cpp\"\n#include <iostream>\n#include <vector>\n\
    #include <string>\n#include <utility>\n#include <tuple>\n#include <type_traits>\n\
    \n#ifdef _WIN32\n#define getchar_unlocked _getchar_nolock\n#define putchar_unlocked\
    \ _putchar_nolock\n#define fwrite_unlocked fwrite\n#define fflush_unlocked fflush\n\
    #endif\nclass Scanner {\n\tstatic int gc() {\n\t\treturn getchar_unlocked();\n\
    \t}\n\tstatic char next_char() {\n\t\tchar c;\n\t\tscan(c);\n\t\treturn c;\n\t\
    }\n\ttemplate <class T> static void scan(T& v) {\n\t\tstd::cin >> v;\n\t}\n\t\
    static void scan(char& v) {\n\t\twhile (std::isspace(v = gc()))\n\t\t\t;\n\t}\n\
    \tstatic void scan(bool& v) {\n\t\tv = next_char() != '0';\n\t}\n\tstatic void\
    \ scan(std::vector<bool>::reference v) {\n\t\tbool b;\n\t\tscan(b);\n\t\tv = b;\n\
    \t}\n\tstatic void scan(std::string& v) {\n\t\tv.clear();\n\t\tfor (char c = next_char();\
    \ !std::isspace(c); c = gc()) v += c;\n\t}\n\tstatic void scan(int& v) {\n\t\t\
    v = 0;\n\t\tbool neg = false;\n\t\tchar c = next_char();\n\t\tif (c == '-') {\n\
    \t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; std::isdigit(c); c = gc())\
    \ v = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void scan(long\
    \ long& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\t\tchar c = next_char();\n\t\
    \tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; std::isdigit(c);\
    \ c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void\
    \ scan(double& v) {\n\t\tv = 0;\n\t\tdouble dp = 1;\n\t\tbool neg = false, after_dp\
    \ = false;\n\t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\
    \t\t\tc = gc();\n\t\t}\n\t\tfor (; std::isdigit(c) || c == '.'; c = gc()) {\n\t\
    \t\tif (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\t\t} else if (after_dp) {\n\t\
    \t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else {\n\t\t\t\tv = v * 10 + (c -\
    \ '0');\n\t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t}\n\tstatic void scan(long double&\
    \ v) {\n\t\tv = 0;\n\t\tlong double dp = 1;\n\t\tbool neg = false, after_dp =\
    \ false;\n\t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\
    \t\tc = gc();\n\t\t}\n\t\tfor (; std::isdigit(c) || c == '.'; c = gc()) {\n\t\t\
    \tif (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\t\t} else if (after_dp) {\n\t\t\
    \t\tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else {\n\t\t\t\tv = v * 10 + (c - '0');\n\
    \t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t}\n\ttemplate <class T, class U> static\
    \ void scan(std::pair<T, U>& v) {\n\t\tscan(v.first);\n\t\tscan(v.second);\n\t\
    }\n\ttemplate <class T, std::enable_if_t<!std::is_same_v<bool, T>, std::nullptr_t>\
    \ = nullptr>\n\tstatic void scan(std::vector<T>& v) {\n\t\tfor (auto& e : v) scan(e);\n\
    \t}\n\ttemplate <class T, std::enable_if_t<std::is_same_v<bool, T>, std::nullptr_t>\
    \ = nullptr>\n\tstatic void scan(std::vector<T>& v) {\n\t\tfor (auto e : v) scan(e);\n\
    \t}\n\ttemplate <std::size_t N = 0, class T> static void scan_tuple_impl(T& v)\
    \ {\n\t\tif constexpr (N < std::tuple_size_v<T>) {\n\t\t\tscan(std::get<N>(v));\n\
    \t\t\tscan_tuple_impl<N + 1>(v);\n\t\t}\n\t}\n\ttemplate <class... T> static void\
    \ scan(std::tuple<T...>& v) {\n\t\tscan_tuple_impl(v);\n\t}\n\n\tstruct Read2DVectorHelper\
    \ {\n\t\tstd::size_t h, w;\n\t\tRead2DVectorHelper(std::size_t _h, std::size_t\
    \ _w) : h(_h), w(_w) {}\n\t\ttemplate <class T> operator std::vector<std::vector<T>>()\
    \ {\n\t\t\tstd::vector vector(h, std::vector<T>(w));\n\t\t\tscan(vector);\n\t\t\
    \treturn vector;\n\t\t}\n\t};\n\tstruct ReadVectorHelper {\n\t\tstd::size_t n;\n\
    \t\tReadVectorHelper(std::size_t _n) : n(_n) {}\n\t\ttemplate <class T> operator\
    \ std::vector<T>() {\n\t\t\tstd::vector<T> vector(n);\n\t\t\tscan(vector);\n\t\
    \t\treturn vector;\n\t\t}\n\t\tauto operator[](std::size_t m) {\n\t\t\treturn\
    \ Read2DVectorHelper(n, m);\n\t\t}\n\t};\n\npublic:\n\ttemplate <class T> T read()\
    \ const {\n\t\tT result;\n\t\tscan(result);\n\t\treturn result;\n\t}\n\ttemplate\
    \ <class T> auto read(std::size_t n) const {\n\t\tstd::vector<T> result(n);\n\t\
    \tscan(result);\n\t\treturn result;\n\t}\n\ttemplate <class T> auto read(std::size_t\
    \ h, std::size_t w) const {\n\t\tstd::vector result(h, std::vector<T>(w));\n\t\
    \tscan(result);\n\t\treturn result;\n\t}\n\tstd::string read_line() const {\n\t\
    \tstd::string v;\n\t\tfor (char c = gc(); c != '\\n' && c != '\\0'; c = gc())\
    \ v += c;\n\t\treturn v;\n\t}\n\ttemplate <class T> operator T() const {\n\t\t\
    return read<T>();\n\t}\n\tint operator--(int) const {\n\t\treturn read<int>()\
    \ - 1;\n\t}\n\tauto operator[](std::size_t n) const {\n\t\treturn ReadVectorHelper(n);\n\
    \t}\n\tauto operator[](const std::pair<std::size_t, std::size_t>& nm) const {\n\
    \t\treturn Read2DVectorHelper(nm.first, nm.second);\n\t}\n\tvoid operator()()\
    \ const {}\n\ttemplate <class H, class... T> void operator()(H&& h, T&&... t)\
    \ const {\n\t\tscan(h);\n\t\toperator()(std::forward<T>(t)...);\n\t}\n\nprivate:\n\
    \ttemplate <template <class...> class, class...> struct Column;\n\ttemplate <template\
    \ <class...> class V, class Head, class... Tail>\n\tstruct Column<V, Head, Tail...>\
    \ {\n\t\ttemplate <class... Args> using vec = V<std::vector<Head>, Args...>;\n\
    \t\tusing type = typename Column<vec, Tail...>::type;\n\t};\n\ttemplate <template\
    \ <class...> class V> struct Column<V> { using type = V<>; };\n\ttemplate <class...\
    \ T> using column_t = typename Column<std::tuple, T...>::type;\n\ttemplate <std::size_t\
    \ N = 0, class T> void column_impl(T& t) const {\n\t\tif constexpr (N < std::tuple_size_v<T>)\
    \ {\n\t\t\tauto& vec = std::get<N>(t);\n\t\t\tusing V = typename std::remove_reference_t<decltype(vec)>::value_type;\n\
    \t\t\tvec.push_back(read<V>());\n\t\t\tcolumn_impl<N + 1>(t);\n\t\t}\n\t}\n\n\
    public:\n\ttemplate <class... T> auto column(std::size_t h) const {\n\t\tcolumn_t<T...>\
    \ result;\n\t\twhile (h--) column_impl(result);\n\t\treturn result;\n\t}\n} in;\n\
    #define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n#define\
    \ ini(...) inputs(int, __VA_ARGS__)\n#define inl(...) inputs(long long, __VA_ARGS__)\n\
    #define ins(...) inputs(std::string, __VA_ARGS__)\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <string>\n\
    #include <utility>\n#include <tuple>\n#include <type_traits>\n\n#ifdef _WIN32\n\
    #define getchar_unlocked _getchar_nolock\n#define putchar_unlocked _putchar_nolock\n\
    #define fwrite_unlocked fwrite\n#define fflush_unlocked fflush\n#endif\nclass\
    \ Scanner {\n\tstatic int gc() {\n\t\treturn getchar_unlocked();\n\t}\n\tstatic\
    \ char next_char() {\n\t\tchar c;\n\t\tscan(c);\n\t\treturn c;\n\t}\n\ttemplate\
    \ <class T> static void scan(T& v) {\n\t\tstd::cin >> v;\n\t}\n\tstatic void scan(char&\
    \ v) {\n\t\twhile (std::isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic void scan(bool&\
    \ v) {\n\t\tv = next_char() != '0';\n\t}\n\tstatic void scan(std::vector<bool>::reference\
    \ v) {\n\t\tbool b;\n\t\tscan(b);\n\t\tv = b;\n\t}\n\tstatic void scan(std::string&\
    \ v) {\n\t\tv.clear();\n\t\tfor (char c = next_char(); !std::isspace(c); c = gc())\
    \ v += c;\n\t}\n\tstatic void scan(int& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\
    \t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\
    \t\t}\n\t\tfor (; std::isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg)\
    \ v = -v;\n\t}\n\tstatic void scan(long long& v) {\n\t\tv = 0;\n\t\tbool neg =\
    \ false;\n\t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\
    \t\tc = gc();\n\t\t}\n\t\tfor (; std::isdigit(c); c = gc()) v = v * 10 + (c -\
    \ '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void scan(double& v) {\n\t\tv = 0;\n\
    \t\tdouble dp = 1;\n\t\tbool neg = false, after_dp = false;\n\t\tchar c = next_char();\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; std::isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\
    \t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else\
    \ {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t\
    }\n\tstatic void scan(long double& v) {\n\t\tv = 0;\n\t\tlong double dp = 1;\n\
    \t\tbool neg = false, after_dp = false;\n\t\tchar c = next_char();\n\t\tif (c\
    \ == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; std::isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\
    \t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else\
    \ {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t\
    }\n\ttemplate <class T, class U> static void scan(std::pair<T, U>& v) {\n\t\t\
    scan(v.first);\n\t\tscan(v.second);\n\t}\n\ttemplate <class T, std::enable_if_t<!std::is_same_v<bool,\
    \ T>, std::nullptr_t> = nullptr>\n\tstatic void scan(std::vector<T>& v) {\n\t\t\
    for (auto& e : v) scan(e);\n\t}\n\ttemplate <class T, std::enable_if_t<std::is_same_v<bool,\
    \ T>, std::nullptr_t> = nullptr>\n\tstatic void scan(std::vector<T>& v) {\n\t\t\
    for (auto e : v) scan(e);\n\t}\n\ttemplate <std::size_t N = 0, class T> static\
    \ void scan_tuple_impl(T& v) {\n\t\tif constexpr (N < std::tuple_size_v<T>) {\n\
    \t\t\tscan(std::get<N>(v));\n\t\t\tscan_tuple_impl<N + 1>(v);\n\t\t}\n\t}\n\t\
    template <class... T> static void scan(std::tuple<T...>& v) {\n\t\tscan_tuple_impl(v);\n\
    \t}\n\n\tstruct Read2DVectorHelper {\n\t\tstd::size_t h, w;\n\t\tRead2DVectorHelper(std::size_t\
    \ _h, std::size_t _w) : h(_h), w(_w) {}\n\t\ttemplate <class T> operator std::vector<std::vector<T>>()\
    \ {\n\t\t\tstd::vector vector(h, std::vector<T>(w));\n\t\t\tscan(vector);\n\t\t\
    \treturn vector;\n\t\t}\n\t};\n\tstruct ReadVectorHelper {\n\t\tstd::size_t n;\n\
    \t\tReadVectorHelper(std::size_t _n) : n(_n) {}\n\t\ttemplate <class T> operator\
    \ std::vector<T>() {\n\t\t\tstd::vector<T> vector(n);\n\t\t\tscan(vector);\n\t\
    \t\treturn vector;\n\t\t}\n\t\tauto operator[](std::size_t m) {\n\t\t\treturn\
    \ Read2DVectorHelper(n, m);\n\t\t}\n\t};\n\npublic:\n\ttemplate <class T> T read()\
    \ const {\n\t\tT result;\n\t\tscan(result);\n\t\treturn result;\n\t}\n\ttemplate\
    \ <class T> auto read(std::size_t n) const {\n\t\tstd::vector<T> result(n);\n\t\
    \tscan(result);\n\t\treturn result;\n\t}\n\ttemplate <class T> auto read(std::size_t\
    \ h, std::size_t w) const {\n\t\tstd::vector result(h, std::vector<T>(w));\n\t\
    \tscan(result);\n\t\treturn result;\n\t}\n\tstd::string read_line() const {\n\t\
    \tstd::string v;\n\t\tfor (char c = gc(); c != '\\n' && c != '\\0'; c = gc())\
    \ v += c;\n\t\treturn v;\n\t}\n\ttemplate <class T> operator T() const {\n\t\t\
    return read<T>();\n\t}\n\tint operator--(int) const {\n\t\treturn read<int>()\
    \ - 1;\n\t}\n\tauto operator[](std::size_t n) const {\n\t\treturn ReadVectorHelper(n);\n\
    \t}\n\tauto operator[](const std::pair<std::size_t, std::size_t>& nm) const {\n\
    \t\treturn Read2DVectorHelper(nm.first, nm.second);\n\t}\n\tvoid operator()()\
    \ const {}\n\ttemplate <class H, class... T> void operator()(H&& h, T&&... t)\
    \ const {\n\t\tscan(h);\n\t\toperator()(std::forward<T>(t)...);\n\t}\n\nprivate:\n\
    \ttemplate <template <class...> class, class...> struct Column;\n\ttemplate <template\
    \ <class...> class V, class Head, class... Tail>\n\tstruct Column<V, Head, Tail...>\
    \ {\n\t\ttemplate <class... Args> using vec = V<std::vector<Head>, Args...>;\n\
    \t\tusing type = typename Column<vec, Tail...>::type;\n\t};\n\ttemplate <template\
    \ <class...> class V> struct Column<V> { using type = V<>; };\n\ttemplate <class...\
    \ T> using column_t = typename Column<std::tuple, T...>::type;\n\ttemplate <std::size_t\
    \ N = 0, class T> void column_impl(T& t) const {\n\t\tif constexpr (N < std::tuple_size_v<T>)\
    \ {\n\t\t\tauto& vec = std::get<N>(t);\n\t\t\tusing V = typename std::remove_reference_t<decltype(vec)>::value_type;\n\
    \t\t\tvec.push_back(read<V>());\n\t\t\tcolumn_impl<N + 1>(t);\n\t\t}\n\t}\n\n\
    public:\n\ttemplate <class... T> auto column(std::size_t h) const {\n\t\tcolumn_t<T...>\
    \ result;\n\t\twhile (h--) column_impl(result);\n\t\treturn result;\n\t}\n} in;\n\
    #define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n#define\
    \ ini(...) inputs(int, __VA_ARGS__)\n#define inl(...) inputs(long long, __VA_ARGS__)\n\
    #define ins(...) inputs(std::string, __VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Scanner.cpp
  requiredBy:
  - template_no_Ruby.cpp
  - template.cpp
  timestamp: '2021-03-18 11:27:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/IO_vector_and_Ruby_Reverse.test.cpp
  - test/IO_2Dvector_and_Ruby_push_back_Transpose_Map_Sum.test.cpp
  - test/Input_Output.test.cpp
  - test/Input_column.test.cpp
  - test/Input2DVector_read.test.cpp
  - test/Input2DVector.test.cpp
  - test/template.test.cpp
  - test/template_no_Ruby.test.cpp
documentation_of: Utility/Scanner.cpp
layout: document
redirect_from:
- /library/Utility/Scanner.cpp
- /library/Utility/Scanner.cpp.html
title: Utility/Scanner.cpp
---
