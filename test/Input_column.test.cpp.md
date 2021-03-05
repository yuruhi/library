---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/Scanner.cpp
    title: Utility/Scanner.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"test/Input_column.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n#line 2 \"Utility/Scanner.cpp\"\n#include <iostream>\n#include <vector>\n#include\
    \ <string>\n#include <utility>\n#include <tuple>\n\n#ifdef _WIN32\n#define getchar_unlocked\
    \ _getchar_nolock\n#define putchar_unlocked _putchar_nolock\n#define fwrite_unlocked\
    \ fwrite\n#define fflush_unlocked fflush\n#endif\nclass Scanner {\n\tstatic int\
    \ gc() {\n\t\treturn getchar_unlocked();\n\t}\n\tstatic char next_char() {\n\t\
    \tchar c;\n\t\tscan(c);\n\t\treturn c;\n\t}\n\ttemplate <class T> static void\
    \ scan(T& v) {\n\t\tstd::cin >> v;\n\t}\n\tstatic void scan(char& v) {\n\t\twhile\
    \ (std::isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic void scan(bool& v) {\n\t\t\
    v = next_char() != '0';\n\t}\n\tstatic void scan(std::string& v) {\n\t\tv.clear();\n\
    \t\tfor (char c = next_char(); !std::isspace(c); c = gc()) v += c;\n\t}\n\tstatic\
    \ void scan(int& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\t\tchar c = next_char();\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; std::isdigit(c);\
    \ c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void\
    \ scan(long long& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\t\tchar c = next_char();\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; std::isdigit(c);\
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
    }\n\ttemplate <class T> static void scan(std::vector<T>& v) {\n\t\tfor (auto&\
    \ e : v) scan(e);\n\t}\n\ttemplate <size_t N = 0, class T> static void scan_tuple_impl(T&\
    \ v) {\n\t\tif constexpr (N < std::tuple_size_v<T>) {\n\t\t\tscan(std::get<N>(v));\n\
    \t\t\tscan_tuple_impl<N + 1>(v);\n\t\t}\n\t}\n\ttemplate <class... T> static void\
    \ scan(std::tuple<T...>& v) {\n\t\tscan_tuple_impl(v);\n\t}\n\tstruct ReadVectorHelper\
    \ {\n\t\tsize_t n;\n\t\tReadVectorHelper(std::size_t _n) : n(_n) {}\n\t\ttemplate\
    \ <class T> operator std::vector<T>() {\n\t\t\tstd::vector<T> v(n);\n\t\t\tscan(v);\n\
    \t\t\treturn v;\n\t\t}\n\t};\n\tstruct Read2DVectorHelper {\n\t\tstd::size_t n,\
    \ m;\n\t\tRead2DVectorHelper(const std::pair<std::size_t, std::size_t>& nm)\n\t\
    \t    : n(nm.first), m(nm.second) {}\n\t\ttemplate <class T> operator std::vector<std::vector<T>>()\
    \ {\n\t\t\tstd::vector<std::vector<T>> v(n, std::vector<T>(m));\n\t\t\tscan(v);\n\
    \t\t\treturn v;\n\t\t}\n\t};\n\npublic:\n\tstd::string read_line() const {\n\t\
    \tstd::string v;\n\t\tfor (char c = gc(); c != '\\n' && c != '\\0'; c = gc())\
    \ v += c;\n\t\treturn v;\n\t}\n\ttemplate <class T> T read() const {\n\t\tT result;\n\
    \t\tscan(result);\n\t\treturn result;\n\t}\n\ttemplate <class T> std::vector<T>\
    \ read(std::size_t n) const {\n\t\tstd::vector<T> result(n);\n\t\tscan(result);\n\
    \t\treturn result;\n\t}\n\ttemplate <class T> operator T() const {\n\t\treturn\
    \ read<T>();\n\t}\n\tint operator--(int) const {\n\t\treturn read<int>() - 1;\n\
    \t}\n\tReadVectorHelper operator[](std::size_t n) const {\n\t\treturn ReadVectorHelper(n);\n\
    \t}\n\tRead2DVectorHelper operator[](const std::pair<std::size_t, std::size_t>&\
    \ nm) const {\n\t\treturn Read2DVectorHelper(nm);\n\t}\n\tvoid operator()() const\
    \ {}\n\ttemplate <class H, class... T> void operator()(H&& h, T&&... t) const\
    \ {\n\t\tscan(h);\n\t\toperator()(std::forward<T>(t)...);\n\t}\n\nprivate:\n\t\
    template <template <class...> class, class...> struct Column;\n\ttemplate <template\
    \ <class...> class V, class Head, class... Tail>\n\tstruct Column<V, Head, Tail...>\
    \ {\n\t\ttemplate <class... Args> using vec = V<std::vector<Head>, Args...>;\n\
    \t\tusing type = typename Column<vec, Tail...>::type;\n\t};\n\ttemplate <template\
    \ <class...> class V> struct Column<V> { using type = V<>; };\n\ttemplate <class...\
    \ T> using column_t = typename Column<std::tuple, T...>::type;\n\ttemplate <size_t\
    \ N = 0, class T> void column_impl(T& t) const {\n\t\tif constexpr (N < std::tuple_size_v<T>)\
    \ {\n\t\t\tauto& vec = std::get<N>(t);\n\t\t\tusing V = typename std::remove_reference_t<decltype(vec)>::value_type;\n\
    \t\t\tvec.push_back(read<V>());\n\t\t\tcolumn_impl<N + 1>(t);\n\t\t}\n\t}\n\n\
    public:\n\ttemplate <class... T> auto column(std::size_t h) const {\n\t\tcolumn_t<T...>\
    \ result;\n\t\twhile (h--) column_impl(result);\n\t\treturn result;\n\t}\n} in;\n\
    #define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n#define\
    \ ini(...) inputs(int, __VA_ARGS__)\n#define inl(...) inputs(long long, __VA_ARGS__)\n\
    #define ins(...) inputs(std::string, __VA_ARGS__)\n#line 4 \"test/Input_column.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tint t = in;\n\tauto [a, b] = in.column<long\
    \ long, long long>(t);\n\tfor (int i = 0; i < t; ++i) {\n\t\tcout << a[i] + b[i]\
    \ << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"./../Utility/Scanner.cpp\"\n#include <iostream>\nusing namespace std;\n\n\
    int main() {\n\tint t = in;\n\tauto [a, b] = in.column<long long, long long>(t);\n\
    \tfor (int i = 0; i < t; ++i) {\n\t\tcout << a[i] + b[i] << '\\n';\n\t}\n}\n"
  dependsOn:
  - Utility/Scanner.cpp
  isVerificationFile: true
  path: test/Input_column.test.cpp
  requiredBy: []
  timestamp: '2021-03-05 18:10:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Input_column.test.cpp
layout: document
redirect_from:
- /verify/test/Input_column.test.cpp
- /verify/test/Input_column.test.cpp.html
title: test/Input_column.test.cpp
---
