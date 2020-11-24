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
    \ <class T> static void read(T& v) {\n\t\tcin >> v;\n\t}\n\tstatic void read(char&\
    \ v) {\n\t\twhile (isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic void read(bool&\
    \ v) {\n\t\tv = read<char>() != '0';\n\t}\n\tstatic void read(string& v) {\n\t\
    \tv.clear();\n\t\tfor (char c = read<char>(); !isspace(c); c = gc()) v += c;\n\
    \t}\n\tstatic void read(int& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\t\tchar\
    \ c = read<char>();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\
    \t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg)\
    \ v = -v;\n\t}\n\tstatic void read(long long& v) {\n\t\tv = 0;\n\t\tbool neg =\
    \ false;\n\t\tchar c = read<char>();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\
    \t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\
    \t\tif (neg) v = -v;\n\t}\n\tstatic void read(double& v) {\n\t\tv = 0;\n\t\tdouble\
    \ dp = 1;\n\t\tbool neg = false, after_dp = false;\n\t\tchar c = read<char>();\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\
    \t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else\
    \ {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t\
    }\n\tstatic void read(long double& v) {\n\t\tv = 0;\n\t\tlong double dp = 1;\n\
    \t\tbool neg = false, after_dp = false;\n\t\tchar c = read<char>();\n\t\tif (c\
    \ == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\
    \t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else\
    \ {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t\
    }\n\ttemplate <class T, class U> static void read(pair<T, U>& v) {\n\t\tread(v.first);\n\
    \t\tread(v.second);\n\t}\n\ttemplate <class T> static void read(vector<T>& v)\
    \ {\n\t\tfor (auto& e : v) read(e);\n\t}\n\ttemplate <size_t N = 0, class T> static\
    \ void read_tuple_impl(T& v) {\n\t\tif constexpr (N < tuple_size_v<T>) {\n\t\t\
    \tread(get<N>(v));\n\t\t\tread_tuple_impl<N + 1>(v);\n\t\t}\n\t}\n\ttemplate <class...\
    \ T> static void read(tuple<T...>& v) {\n\t\tread_tuple_impl(v);\n\t}\n\tstruct\
    \ ReadVectorHelper {\n\t\tint n;\n\t\tReadVectorHelper(int _n) : n(_n) {}\n\t\t\
    template <class T> operator vector<T>() {\n\t\t\tvector<T> v(n);\n\t\t\tread(v);\n\
    \t\t\treturn v;\n\t\t}\n\t};\n\tstruct Read2DVectorHelper {\n\t\tint n, m;\n\t\
    \tRead2DVectorHelper(const pair<int, int>& nm) : n(nm.first), m(nm.second) {}\n\
    \t\ttemplate <class T> operator vector<vector<T>>() {\n\t\t\tvector<vector<T>>\
    \ v(n, vector<T>(m));\n\t\t\tread(v);\n\t\t\treturn v;\n\t\t}\n\t};\n\npublic:\n\
    \tstatic string read_line() {\n\t\tstring v;\n\t\tfor (char c = read<char>();\
    \ c != '\\n' && c != '\\0'; c = gc()) v += c;\n\t\treturn v;\n\t}\n\ttemplate\
    \ <class T> static T read() {\n\t\tT v;\n\t\tread(v);\n\t\treturn v;\n\t}\n\t\
    template <class T> operator T() const {\n\t\treturn read<T>();\n\t}\n\tint operator--(int)\
    \ const {\n\t\treturn read<int>() - 1;\n\t}\n\tReadVectorHelper operator[](int\
    \ n) const {\n\t\treturn ReadVectorHelper(n);\n\t}\n\tRead2DVectorHelper operator[](const\
    \ pair<int, int>& nm) const {\n\t\treturn Read2DVectorHelper(nm);\n\t}\n\tvoid\
    \ operator()() const {}\n\ttemplate <class H, class... T> void operator()(H&&\
    \ h, T&&... t) const {\n\t\tread(h);\n\t\toperator()(forward<T>(t)...);\n\t}\n\
    \nprivate:\n\ttemplate <template <class...> class, class...> struct Multiple;\n\
    \ttemplate <template <class...> class V, class Head, class... Tail>\n\tstruct\
    \ Multiple<V, Head, Tail...> {\n\t\ttemplate <class... Args> using vec = V<vector<Head>,\
    \ Args...>;\n\t\tusing type = typename Multiple<vec, Tail...>::type;\n\t};\n\t\
    template <template <class...> class V> struct Multiple<V> { using type = V<>;\
    \ };\n\ttemplate <class... T> using multiple_t = typename Multiple<tuple, T...>::type;\n\
    \ttemplate <size_t N = 0, class T> void multiple_impl(T& t) const {\n\t\tif constexpr\
    \ (N < tuple_size_v<T>) {\n\t\t\tauto& vec = get<N>(t);\n\t\t\tusing V = typename\
    \ remove_reference_t<decltype(vec)>::value_type;\n\t\t\tvec.push_back(read<V>());\n\
    \t\t\tmultiple_impl<N + 1>(t);\n\t\t}\n\t}\n\npublic:\n\ttemplate <class... T>\
    \ auto multiple(int h) const {\n\t\tmultiple_t<T...> result;\n\t\twhile (h--)\
    \ multiple_impl(result);\n\t\treturn result;\n\t}\n} in;\n#define inputs(T, ...)\
    \ \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n#define ini(...) inputs(int,\
    \ __VA_ARGS__)\n#define inl(...) inputs(long long, __VA_ARGS__)\n#define ins(...)\
    \ inputs(string, __VA_ARGS__)\n#line 6 \"template/Output.cpp\"\n#include <charconv>\n\
    #include <cstring>\n#include <cassert>\nusing namespace std;\n\nstruct BoolStr\
    \ {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const char* _f) : t(_t),\
    \ f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"YES\", \"NO\"\
    ), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\tDivStr(const char*\
    \ _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"), no_spc(\"\", \"\
    \\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"),\n    no_endl(\" \"\
    , \"\");\nclass Output {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\npublic:\n\tvoid\
    \ put(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid put(long long v) const\
    \ {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf),\
    \ v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\t\t\
    } else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid put(bool v) const {\n\t\tput(v\
    \ ? B.t : B.f);\n\t}\n\tvoid put(char v) const {\n\t\tputchar_unlocked(v);\n\t\
    }\n\tvoid put(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v), stdout);\n\
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
  timestamp: '2020-11-24 20:32:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Input_Output.test.cpp
layout: document
redirect_from:
- /verify/test/Input_Output.test.cpp
- /verify/test/Input_Output.test.cpp.html
title: test/Input_Output.test.cpp
---
