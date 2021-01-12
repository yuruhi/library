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
    \ Scanner {\n\tstatic int gc() {\n\t\treturn getchar_unlocked();\n\t}\n\tstatic\
    \ char next_char() {\n\t\tchar c;\n\t\tread(c);\n\t\treturn c;\n\t}\n\ttemplate\
    \ <class T> static void read(T& v) {\n\t\tcin >> v;\n\t}\n\tstatic void read(char&\
    \ v) {\n\t\twhile (isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic void read(bool&\
    \ v) {\n\t\tv = next_char() != '0';\n\t}\n\tstatic void read(string& v) {\n\t\t\
    v.clear();\n\t\tfor (char c = next_char(); !isspace(c); c = gc()) v += c;\n\t\
    }\n\tstatic void read(int& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\t\tchar c\
    \ = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t\
    }\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg) v =\
    \ -v;\n\t}\n\tstatic void read(long long& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\
    \t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\
    \t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg)\
    \ v = -v;\n\t}\n\tstatic void read(double& v) {\n\t\tv = 0;\n\t\tdouble dp = 1;\n\
    \t\tbool neg = false, after_dp = false;\n\t\tchar c = next_char();\n\t\tif (c\
    \ == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\
    \t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else\
    \ {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t\
    }\n\tstatic void read(long double& v) {\n\t\tv = 0;\n\t\tlong double dp = 1;\n\
    \t\tbool neg = false, after_dp = false;\n\t\tchar c = next_char();\n\t\tif (c\
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
    \ ReadVectorHelper {\n\t\tsize_t n;\n\t\tReadVectorHelper(size_t _n) : n(_n) {}\n\
    \t\ttemplate <class T> operator vector<T>() {\n\t\t\tvector<T> v(n);\n\t\t\tread(v);\n\
    \t\t\treturn v;\n\t\t}\n\t};\n\tstruct Read2DVectorHelper {\n\t\tsize_t n, m;\n\
    \t\tRead2DVectorHelper(const pair<size_t, size_t>& nm) : n(nm.first), m(nm.second)\
    \ {}\n\t\ttemplate <class T> operator vector<vector<T>>() {\n\t\t\tvector<vector<T>>\
    \ v(n, vector<T>(m));\n\t\t\tread(v);\n\t\t\treturn v;\n\t\t}\n\t};\n\npublic:\n\
    \tstring read_line() const {\n\t\tstring v;\n\t\tfor (char c = gc(); c != '\\\
    n' && c != '\\0'; c = gc()) v += c;\n\t\treturn v;\n\t}\n\ttemplate <class T>\
    \ T read() const {\n\t\tT v;\n\t\tread(v);\n\t\treturn v;\n\t}\n\ttemplate <class\
    \ T> vector<T> read_vector(size_t n) const {\n\t\tvector<T> a(n);\n\t\tread(a);\n\
    \t\treturn a;\n\t}\n\ttemplate <class T> operator T() const {\n\t\treturn read<T>();\n\
    \t}\n\tint operator--(int) const {\n\t\treturn read<int>() - 1;\n\t}\n\tReadVectorHelper\
    \ operator[](size_t n) const {\n\t\treturn ReadVectorHelper(n);\n\t}\n\tRead2DVectorHelper\
    \ operator[](const pair<size_t, size_t>& nm) const {\n\t\treturn Read2DVectorHelper(nm);\n\
    \t}\n\tvoid operator()() const {}\n\ttemplate <class H, class... T> void operator()(H&&\
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
    \ auto multiple(size_t h) const {\n\t\tmultiple_t<T...> result;\n\t\twhile (h--)\
    \ multiple_impl(result);\n\t\treturn result;\n\t}\n} in;\n#define inputs(T, ...)\
    \ \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n#define ini(...) inputs(int,\
    \ __VA_ARGS__)\n#define inl(...) inputs(long long, __VA_ARGS__)\n#define ins(...)\
    \ inputs(string, __VA_ARGS__)\n#line 6 \"template/Output.cpp\"\n#include <array>\n\
    #include <charconv>\n#include <cstring>\n#include <cassert>\nusing namespace std;\n\
    \nstruct BoolStr {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const char*\
    \ _f) : t(_t), f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"\
    YES\", \"NO\"), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\t\
    DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"\
    ), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"), no_endl(\"\
    \ \", \"\");\nclass Printer {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\npublic:\n\
    \tvoid print(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(long long v) const\
    \ {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf),\
    \ v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\t\t\
    } else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(bool v) const {\n\t\t\
    print(v ? B.t : B.f);\n\t}\n\tvoid print(vector<bool>::reference v) const {\n\t\
    \tprint(v ? B.t : B.f);\n\t}\n\tvoid print(char v) const {\n\t\tputchar_unlocked(v);\n\
    \t}\n\tvoid print(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v),\
    \ stdout);\n\t}\n\tvoid print(double v) const {\n\t\tprintf(\"%.20f\", v);\n\t\
    }\n\tvoid print(long double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t}\n\ttemplate\
    \ <class T> void print(const T& v) const {\n\t\tcout << v;\n\t}\n\ttemplate <class\
    \ T, class U> void print(const pair<T, U>& v) const {\n\t\tprint(v.first);\n\t\
    \tprint(D.d);\n\t\tprint(v.second);\n\t}\n\ttemplate <class InputIterater>\n\t\
    void print_range(const InputIterater& begin, const InputIterater& end) const {\n\
    \t\tfor (InputIterater i = begin; i != end; ++i) {\n\t\t\tif (i != begin) print(D.d);\n\
    \t\t\tprint(*i);\n\t\t}\n\t}\n\ttemplate <class T> void print(const vector<T>&\
    \ v) const {\n\t\tprint_range(v.begin(), v.end());\n\t}\n\ttemplate <class T,\
    \ size_t N> void print(const array<T, N>& v) const {\n\t\tprint_range(v.begin(),\
    \ v.end());\n\t}\n\ttemplate <class T> void print(const vector<vector<T>>& v)\
    \ const {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tif (i) print(D.l);\n\
    \t\t\tprint(v[i]);\n\t\t}\n\t}\n\n\tPrinter() = default;\n\tPrinter(const BoolStr&\
    \ _boolstr, const DivStr& _divstr) : B(_boolstr), D(_divstr) {}\n\tPrinter& operator()()\
    \ {\n\t\tprint(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class Head> Printer&\
    \ operator()(Head&& h) {\n\t\tprint(h);\n\t\tprint(D.l);\n\t\treturn *this;\n\t\
    }\n\ttemplate <class Head, class... Tail> Printer& operator()(Head&& h, Tail&&...\
    \ t) {\n\t\tprint(h);\n\t\tprint(D.d);\n\t\treturn operator()(forward<Tail>(t)...);\n\
    \t}\n\ttemplate <class... Args> Printer& flag(bool f, Args&&... args) {\n\t\t\
    if (f) {\n\t\t\treturn operator()(forward<Args>(args)...);\n\t\t} else {\n\t\t\
    \treturn *this;\n\t\t}\n\t}\n\ttemplate <class InputIterator>\n\tPrinter& range(const\
    \ InputIterator& begin, const InputIterator& end) {\n\t\tprint_range(begin, end);\n\
    \t\tprint(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class T> Printer& range(const\
    \ T& a) {\n\t\trange(a.begin(), a.end());\n\t\treturn *this;\n\t}\n\ttemplate\
    \ <class... T> void exit(T&&... t) {\n\t\toperator()(forward<T>(t)...);\n\t\t\
    std::exit(EXIT_SUCCESS);\n\t}\n\tPrinter& flush() {\n\t\tfflush_unlocked(stdout);\n\
    \t\treturn *this;\n\t}\n\tPrinter& set(const BoolStr& b) {\n\t\tB = b;\n\t\treturn\
    \ *this;\n\t}\n\tPrinter& set(const DivStr& d) {\n\t\tD = d;\n\t\treturn *this;\n\
    \t}\n\tPrinter& set(const char* t, const char* f) {\n\t\tB = BoolStr(t, f);\n\t\
    \treturn *this;\n\t}\n} out;\n#line 5 \"test/Input_Output.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n\tfor (int t = in; t--;) {\n\t\tlong long a = in, b =\
    \ in;\n\t\tout(a + b);\n\t}\n}\n"
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
  timestamp: '2021-01-12 17:27:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Input_Output.test.cpp
layout: document
redirect_from:
- /verify/test/Input_Output.test.cpp
- /verify/test/Input_Output.test.cpp.html
title: test/Input_Output.test.cpp
---
