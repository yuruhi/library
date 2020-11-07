---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/Input.cpp
    title: template/Input.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"test/Input_multiple.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n#line 2 \"template/Input.cpp\"\n#include <iostream>\n#include <vector>\n#include\
    \ <string>\n#include <utility>\n#include <tuple>\nusing namespace std;\n\n#ifdef\
    \ _WIN32\n#define getchar_unlocked _getchar_nolock\n#define putchar_unlocked _putchar_nolock\n\
    #define fwrite_unlocked fwrite\n#define fflush_unlocked fflush\n#endif\nclass\
    \ Input {\n\tstatic int gc() {\n\t\treturn getchar_unlocked();\n\t}\n\ttemplate\
    \ <class T> static void i(T& v) {\n\t\tcin >> v;\n\t}\n\tstatic void i(char& v)\
    \ {\n\t\twhile (isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic void i(bool& v) {\n\
    \t\tv = in<char>() != '0';\n\t}\n\tstatic void i(string& v) {\n\t\tv.clear();\n\
    \t\tchar c;\n\t\tfor (i(c); !isspace(c); c = gc())\n\t\t\tv += c;\n\t}\n\tstatic\
    \ void i(int& v) {\n\t\tbool neg = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c);\
    \ c = gc())\n\t\t\tv = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic\
    \ void i(long long& v) {\n\t\tbool neg = false;\n\t\tv = 0;\n\t\tchar c;\n\t\t\
    i(c);\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor\
    \ (; isdigit(c); c = gc())\n\t\t\tv = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\
    \t}\n\tstatic void i(double& v) {\n\t\tdouble dp = 1;\n\t\tbool neg = false, adp\
    \ = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\tneg\
    \ = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c) || c == '.'; c = gc())\
    \ {\n\t\t\tif (c == '.')\n\t\t\t\tadp = true;\n\t\t\telse if (adp)\n\t\t\t\tv\
    \ += (c - '0') * (dp *= 0.1);\n\t\t\telse\n\t\t\t\tv = v * 10 + (c - '0');\n\t\
    \t}\n\t\tif (neg) v = -v;\n\t}\n\tstatic void i(long double& v) {\n\t\tlong double\
    \ dp = 1;\n\t\tbool neg = false, adp = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.')\n\t\t\t\tadp = true;\n\t\t\telse\
    \ if (adp)\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\telse\n\t\t\t\tv = v *\
    \ 10 + (c - '0');\n\t\t}\n\t\tif (neg) v = -v;\n\t}\n\ttemplate <class T, class\
    \ U> static void i(pair<T, U>& v) {\n\t\ti(v.first);\n\t\ti(v.second);\n\t}\n\t\
    template <class T> static void i(vector<T>& v) {\n\t\tfor (auto& e : v)\n\t\t\t\
    i(e);\n\t}\n\ttemplate <size_t N = 0, class T> static void input_tuple(T& v) {\n\
    \t\tif constexpr (N < tuple_size_v<T>) {\n\t\t\ti(get<N>(v));\n\t\t\tinput_tuple<N\
    \ + 1>(v);\n\t\t}\n\t}\n\ttemplate <class... T> static void i(tuple<T...>& v)\
    \ {\n\t\tinput_tuple(v);\n\t}\n\tstruct InputV {\n\t\tint n, m;\n\t\tInputV(int\
    \ _n) : n(_n), m(0) {}\n\t\tInputV(const pair<int, int>& nm) : n(nm.first), m(nm.second)\
    \ {}\n\t\ttemplate <class T> operator vector<T>() {\n\t\t\tvector<T> v(n);\n\t\
    \t\ti(v);\n\t\t\treturn v;\n\t\t}\n\t\ttemplate <class T> operator vector<vector<T>>()\
    \ {\n\t\t\tvector<vector<T>> v(n, vector<T>(m));\n\t\t\ti(v);\n\t\t\treturn v;\n\
    \t\t}\n\t};\n\npublic:\n\tstatic string read_line() {\n\t\tstring v;\n\t\tchar\
    \ c;\n\t\tfor (i(c); c != '\\n' && c != '\\0'; c = gc())\n\t\t\tv += c;\n\t\t\
    return v;\n\t}\n\ttemplate <class T> static T in() {\n\t\tT v;\n\t\ti(v);\n\t\t\
    return v;\n\t}\n\ttemplate <class T> operator T() const {\n\t\treturn in<T>();\n\
    \t}\n\tint operator--(int) const {\n\t\treturn in<int>() - 1;\n\t}\n\tInputV operator[](int\
    \ n) const {\n\t\treturn InputV(n);\n\t}\n\tInputV operator[](const pair<int,\
    \ int>& n) const {\n\t\treturn InputV(n);\n\t}\n\tvoid operator()() const {}\n\
    \ttemplate <class H, class... T> void operator()(H&& h, T&&... t) const {\n\t\t\
    i(h);\n\t\toperator()(forward<T>(t)...);\n\t}\n\nprivate:\n\ttemplate <template\
    \ <class...> class, class...> struct Multiple;\n\ttemplate <template <class...>\
    \ class V, class Head, class... Tail> struct Multiple<V, Head, Tail...> {\n\t\t\
    template <class... Args> using vec = V<vector<Head>, Args...>;\n\t\tusing type\
    \ = typename Multiple<vec, Tail...>::type;\n\t};\n\ttemplate <template <class...>\
    \ class V> struct Multiple<V> { using type = V<>; };\n\ttemplate <class... T>\
    \ using multiple_t = typename Multiple<tuple, T...>::type;\n\ttemplate <size_t\
    \ N = 0, class T> void in_multiple(T& t) const {\n\t\tif constexpr (N < tuple_size_v<T>)\
    \ {\n\t\t\tauto& vec = get<N>(t);\n\t\t\tusing V = typename remove_reference_t<decltype(vec)>::value_type;\n\
    \t\t\tvec.push_back(in<V>());\n\t\t\tin_multiple<N + 1>(t);\n\t\t}\n\t}\n\npublic:\n\
    \ttemplate <class... T> auto multiple(int H) const {\n\t\tmultiple_t<T...> res;\n\
    \t\twhile (H--)\n\t\t\tin_multiple(res);\n\t\treturn res;\n\t}\n} in;\n#define\
    \ input(T) Input::in<T>()\n#define INT input(int)\n#define LL input(long long)\n\
    #define STR input(string)\n#define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\
    \tin(__VA_ARGS__)\n#define ini(...) inputs(int, __VA_ARGS__)\n#define inl(...)\
    \ inputs(long long, __VA_ARGS__)\n#define ins(...) inputs(string, __VA_ARGS__)\n\
    #line 4 \"test/Input_multiple.test.cpp\"\nusing namespace std;\n\nint main() {\n\
    \tint t = in;\n\tauto [a, b] = in.multiple<long long, long long>(t);\n\tfor (int\
    \ i = 0; i < t; ++i) {\n\t\tcout << a[i] + b[i] << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"./../template/Input.cpp\"\n#include <iostream>\nusing namespace std;\n\nint\
    \ main() {\n\tint t = in;\n\tauto [a, b] = in.multiple<long long, long long>(t);\n\
    \tfor (int i = 0; i < t; ++i) {\n\t\tcout << a[i] + b[i] << '\\n';\n\t}\n}\n"
  dependsOn:
  - template/Input.cpp
  isVerificationFile: true
  path: test/Input_multiple.test.cpp
  requiredBy: []
  timestamp: '2020-11-06 17:54:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Input_multiple.test.cpp
layout: document
redirect_from:
- /verify/test/Input_multiple.test.cpp
- /verify/test/Input_multiple.test.cpp.html
title: test/Input_multiple.test.cpp
---
