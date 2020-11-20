---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/Input.cpp
    title: template/Input.cpp
  - icon: ':heavy_check_mark:'
    path: template/Output.cpp
    title: template/Output.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"test/Input_Output.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n#line 2 \"template/Input.cpp\"\n#include <iostream>\n#include <vector>\n#include\
    \ <string>\n#include <utility>\n#include <tuple>\nusing namespace std;\n\n#ifdef\
    \ _WIN32\n#define getchar_unlocked _getchar_nolock\n#define putchar_unlocked _putchar_nolock\n\
    #define fwrite_unlocked fwrite\n#define fflush_unlocked fflush\n#endif\nclass\
    \ Input {\n\tstatic int gc() {\n\t\treturn getchar_unlocked();\n\t}\n\ttemplate\
    \ <class T> static void i(T& v) {\n\t\tcin >> v;\n\t}\n\tstatic void i(char& v)\
    \ {\n\t\twhile (isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic void i(bool& v) {\n\
    \t\tv = in<char>() != '0';\n\t}\n\tstatic void i(string& v) {\n\t\tv.clear();\n\
    \t\tchar c;\n\t\tfor (i(c); !isspace(c); c = gc()) v += c;\n\t}\n\tstatic void\
    \ i(int& v) {\n\t\tbool neg = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\t\
    if (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c);\
    \ c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void\
    \ i(long long& v) {\n\t\tbool neg = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c);\
    \ c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void\
    \ i(double& v) {\n\t\tdouble dp = 1;\n\t\tbool neg = false, adp = false;\n\t\t\
    v = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\t\
    c = gc();\n\t\t}\n\t\tfor (; isdigit(c) || c == '.'; c = gc()) {\n\t\t\tif (c\
    \ == '.')\n\t\t\t\tadp = true;\n\t\t\telse if (adp)\n\t\t\t\tv += (c - '0') *\
    \ (dp *= 0.1);\n\t\t\telse\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t}\n\t\tif (neg)\
    \ v = -v;\n\t}\n\tstatic void i(long double& v) {\n\t\tlong double dp = 1;\n\t\
    \tbool neg = false, adp = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c\
    \ == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.')\n\t\t\t\tadp = true;\n\t\t\telse\
    \ if (adp)\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\telse\n\t\t\t\tv = v *\
    \ 10 + (c - '0');\n\t\t}\n\t\tif (neg) v = -v;\n\t}\n\ttemplate <class T, class\
    \ U> static void i(pair<T, U>& v) {\n\t\ti(v.first);\n\t\ti(v.second);\n\t}\n\t\
    template <class T> static void i(vector<T>& v) {\n\t\tfor (auto& e : v) i(e);\n\
    \t}\n\ttemplate <size_t N = 0, class T> static void input_tuple(T& v) {\n\t\t\
    if constexpr (N < tuple_size_v<T>) {\n\t\t\ti(get<N>(v));\n\t\t\tinput_tuple<N\
    \ + 1>(v);\n\t\t}\n\t}\n\ttemplate <class... T> static void i(tuple<T...>& v)\
    \ {\n\t\tinput_tuple(v);\n\t}\n\tstruct InputV {\n\t\tint n, m;\n\t\tInputV(int\
    \ _n) : n(_n), m(0) {}\n\t\tInputV(const pair<int, int>& nm) : n(nm.first), m(nm.second)\
    \ {}\n\t\ttemplate <class T> operator vector<T>() {\n\t\t\tvector<T> v(n);\n\t\
    \t\ti(v);\n\t\t\treturn v;\n\t\t}\n\t\ttemplate <class T> operator vector<vector<T>>()\
    \ {\n\t\t\tvector<vector<T>> v(n, vector<T>(m));\n\t\t\ti(v);\n\t\t\treturn v;\n\
    \t\t}\n\t};\n\npublic:\n\tstatic string read_line() {\n\t\tstring v;\n\t\tchar\
    \ c;\n\t\tfor (i(c); c != '\\n' && c != '\\0'; c = gc()) v += c;\n\t\treturn v;\n\
    \t}\n\ttemplate <class T> static T in() {\n\t\tT v;\n\t\ti(v);\n\t\treturn v;\n\
    \t}\n\ttemplate <class T> operator T() const {\n\t\treturn in<T>();\n\t}\n\tint\
    \ operator--(int) const {\n\t\treturn in<int>() - 1;\n\t}\n\tInputV operator[](int\
    \ n) const {\n\t\treturn InputV(n);\n\t}\n\tInputV operator[](const pair<int,\
    \ int>& n) const {\n\t\treturn InputV(n);\n\t}\n\tvoid operator()() const {}\n\
    \ttemplate <class H, class... T> void operator()(H&& h, T&&... t) const {\n\t\t\
    i(h);\n\t\toperator()(forward<T>(t)...);\n\t}\n\nprivate:\n\ttemplate <template\
    \ <class...> class, class...> struct Multiple;\n\ttemplate <template <class...>\
    \ class V, class Head, class... Tail>\n\tstruct Multiple<V, Head, Tail...> {\n\
    \t\ttemplate <class... Args> using vec = V<vector<Head>, Args...>;\n\t\tusing\
    \ type = typename Multiple<vec, Tail...>::type;\n\t};\n\ttemplate <template <class...>\
    \ class V> struct Multiple<V> { using type = V<>; };\n\ttemplate <class... T>\
    \ using multiple_t = typename Multiple<tuple, T...>::type;\n\ttemplate <size_t\
    \ N = 0, class T> void in_multiple(T& t) const {\n\t\tif constexpr (N < tuple_size_v<T>)\
    \ {\n\t\t\tauto& vec = get<N>(t);\n\t\t\tusing V = typename remove_reference_t<decltype(vec)>::value_type;\n\
    \t\t\tvec.push_back(in<V>());\n\t\t\tin_multiple<N + 1>(t);\n\t\t}\n\t}\n\npublic:\n\
    \ttemplate <class... T> auto multiple(int H) const {\n\t\tmultiple_t<T...> res;\n\
    \t\twhile (H--) in_multiple(res);\n\t\treturn res;\n\t}\n} in;\n#define input(T)\
    \ Input::in<T>()\n#define INT input(int)\n#define LL input(long long)\n#define\
    \ STR input(string)\n#define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n\
    #define ini(...) inputs(int, __VA_ARGS__)\n#define inl(...) inputs(long long,\
    \ __VA_ARGS__)\n#define ins(...) inputs(string, __VA_ARGS__)\n#line 6 \"template/Output.cpp\"\
    \n#include <charconv>\n#include <cstring>\n#include <cassert>\nusing namespace\
    \ std;\n\nstruct BoolStr {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const\
    \ char* _f) : t(_t), f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"\
    YES\", \"NO\"), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\t\
    DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"\
    ), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"),\n\
    \    no_endl(\" \", \"\");\nclass Output {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\
    \npublic:\n\tvoid put(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr,\
    \ e] = to_chars(begin(buf), end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char),\
    \ ptr - buf, stdout);\n\t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid\
    \ put(long long v) const {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid put(bool v) const {\n\t\
    \tput(v ? B.t : B.f);\n\t}\n\tvoid put(char v) const {\n\t\tputchar_unlocked(v);\n\
    \t}\n\tvoid put(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v), stdout);\n\
    \t}\n\tvoid put(double v) const {\n\t\tprintf(\"%.20f\", v);\n\t}\n\tvoid put(long\
    \ double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t}\n\ttemplate <class T> void\
    \ put(const T& v) const {\n\t\tcout << v;\n\t}\n\ttemplate <class T, class U>\
    \ void put(const pair<T, U>& v) const {\n\t\tput(v.first);\n\t\tput(D.d);\n\t\t\
    put(v.second);\n\t}\n\ttemplate <class It> void put_range(const It& begin, const\
    \ It& end) const {\n\t\tfor (It i = begin; i != end; ++i) {\n\t\t\tif (i != begin)\
    \ put(D.d);\n\t\t\tput(*i);\n\t\t}\n\t}\n\ttemplate <class T> void put(const vector<T>&\
    \ v) const {\n\t\tput_range(v.begin(), v.end());\n\t}\n\ttemplate <class T, size_t\
    \ N> void put(const array<T, N>& v) const {\n\t\tput_range(v.begin(), v.end());\n\
    \t}\n\ttemplate <class T> void put(const vector<vector<T>>& v) const {\n\t\tfor\
    \ (size_t i = 0; i < v.size(); ++i) {\n\t\t\tif (i) put(D.l);\n\t\t\tput(v[i]);\n\
    \t\t}\n\t}\n\n\tOutput() = default;\n\tOutput(const BoolStr& _boolstr, const DivStr&\
    \ _divstr) : B(_boolstr), D(_divstr) {}\n\tOutput& operator()() {\n\t\tput(D.l);\n\
    \t\treturn *this;\n\t}\n\ttemplate <class H> Output& operator()(H&& h) {\n\t\t\
    put(h);\n\t\tput(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class H, class...\
    \ T> Output& operator()(H&& h, T&&... t) {\n\t\tput(h);\n\t\tput(D.d);\n\t\treturn\
    \ operator()(forward<T>(t)...);\n\t}\n\ttemplate <class It> Output& range(const\
    \ It& begin, const It& end) {\n\t\tput_range(begin, end);\n\t\tput(D.l);\n\t\t\
    return *this;\n\t}\n\ttemplate <class T> Output& range(const T& a) {\n\t\trange(a.begin(),\
    \ a.end());\n\t\treturn *this;\n\t}\n\ttemplate <class... T> void exit(T&&...\
    \ t) {\n\t\toperator()(forward<T>(t)...);\n\t\tstd::exit(EXIT_SUCCESS);\n\t}\n\
    \tOutput& flush() {\n\t\tfflush_unlocked(stdout);\n\t\treturn *this;\n\t}\n\t\
    Output& set(const BoolStr& b) {\n\t\tB = b;\n\t\treturn *this;\n\t}\n\tOutput&\
    \ set(const DivStr& d) {\n\t\tD = d;\n\t\treturn *this;\n\t}\n\tOutput& set(const\
    \ char* t, const char* f) {\n\t\tB = BoolStr(t, f);\n\t\treturn *this;\n\t}\n\
    } out;\n#line 5 \"test/Input_Output.test.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n\tfor (int t = in; t--;) {\n\t\tlong long a = in, b = in;\n\t\tout(a + b);\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"./../template/Input.cpp\"\n#include \"./../template/Output.cpp\"\n#include\
    \ <iostream>\nusing namespace std;\n\nint main() {\n\tfor (int t = in; t--;) {\n\
    \t\tlong long a = in, b = in;\n\t\tout(a + b);\n\t}\n}\n"
  dependsOn:
  - template/Input.cpp
  - template/Output.cpp
  isVerificationFile: true
  path: test/Input_Output.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Input_Output.test.cpp
layout: document
redirect_from:
- /verify/test/Input_Output.test.cpp
- /verify/test/Input_Output.test.cpp.html
title: test/Input_Output.test.cpp
---
