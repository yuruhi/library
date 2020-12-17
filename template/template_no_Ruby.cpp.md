---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/Input.cpp
    title: template/Input.cpp
  - icon: ':heavy_check_mark:'
    path: template/Output.cpp
    title: template/Output.cpp
  - icon: ':warning:'
    path: template/constants.cpp
    title: template/constants.cpp
  - icon: ':heavy_check_mark:'
    path: template/functions.cpp
    title: template/functions.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template_no_Ruby.cpp\"\n#include <bits/stdc++.h>\n\
    #line 4 \"template/constants.cpp\"\n#include <string_view>\n#line 7 \"template/constants.cpp\"\
    \n\n#define rep(i, n) for (int i = 0; i < (n); ++i)\n#define FOR(i, m, n) for\
    \ (int i = (m); i < (n); ++i)\n#define rrep(i, n) for (int i = (n)-1; i >= 0;\
    \ --i)\n#define rfor(i, m, n) for (int i = (m); i >= (n); --i)\n#define unless(c)\
    \ if (!(c))\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define range_it(a, l, r) (a).begin() + (l), (a).begin() + (r)\n\
    \nusing namespace std;\nusing ll = long long;\nusing LD = long double;\nusing\
    \ VB = vector<bool>;\nusing VVB = vector<VB>;\nusing VI = vector<int>;\nusing\
    \ VVI = vector<VI>;\nusing VL = vector<ll>;\nusing VVL = vector<VL>;\nusing VS\
    \ = vector<string>;\nusing VD = vector<LD>;\nusing PII = pair<int, int>;\nusing\
    \ VP = vector<PII>;\nusing PLL = pair<ll, ll>;\nusing VPL = vector<PLL>;\ntemplate\
    \ <class T> using PQ = priority_queue<T>;\ntemplate <class T> using PQS = priority_queue<T,\
    \ vector<T>, greater<T>>;\nconstexpr int inf = 1000000000;\nconstexpr long long\
    \ inf_ll = 1000000000000000000ll, MOD = 1000000007;\nconstexpr long double PI\
    \ = 3.14159265358979323846, EPS = 1e-12;\nnamespace CharacterClass {\n\tconstexpr\
    \ string_view\n\t    digit = \"0123456789\",\n\t    xdigit = \"0123456789ABCDEFabcdef\"\
    , lower = \"abcdefghijklmnopqrstuvwxyz\",\n\t    upper = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ,\n\t    alpha = \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\",\n\t\
    \    alnum = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    word = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    punct = R\"(!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~)\",\n\t    graph =\n\t\
    \        R\"(!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~)\"\
    ,\n\t    print =\n\t        R\"( !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\\
    ]^_`abcdefghijklmnopqrstuvwxyz{|}~)\",\n\t    blank = \" \\t\", space = \" \\\
    t\\n\\r\\f\\v\";\n}  // namespace CharacterClass\n#line 7 \"template/Input.cpp\"\
    \nusing namespace std;\n\n#ifdef _WIN32\n#define getchar_unlocked _getchar_nolock\n\
    #define putchar_unlocked _putchar_nolock\n#define fwrite_unlocked fwrite\n#define\
    \ fflush_unlocked fflush\n#endif\nclass Scanner {\n\tstatic int gc() {\n\t\treturn\
    \ getchar_unlocked();\n\t}\n\tstatic char next_char() {\n\t\tchar c;\n\t\tread(c);\n\
    \t\treturn c;\n\t}\n\ttemplate <class T> static void read(T& v) {\n\t\tcin >>\
    \ v;\n\t}\n\tstatic void read(char& v) {\n\t\twhile (isspace(v = gc()))\n\t\t\t\
    ;\n\t}\n\tstatic void read(bool& v) {\n\t\tv = next_char() != '0';\n\t}\n\tstatic\
    \ void read(string& v) {\n\t\tv.clear();\n\t\tfor (char c = next_char(); !isspace(c);\
    \ c = gc()) v += c;\n\t}\n\tstatic void read(int& v) {\n\t\tv = 0;\n\t\tbool neg\
    \ = false;\n\t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\
    \t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\
    \t\tif (neg) v = -v;\n\t}\n\tstatic void read(long long& v) {\n\t\tv = 0;\n\t\t\
    bool neg = false;\n\t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg =\
    \ true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 +\
    \ (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void read(double& v) {\n\t\t\
    v = 0;\n\t\tdouble dp = 1;\n\t\tbool neg = false, after_dp = false;\n\t\tchar\
    \ c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\
    \t}\n\t\tfor (; isdigit(c) || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\t\
    \t\t\tafter_dp = true;\n\t\t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0') *\
    \ (dp *= 0.1);\n\t\t\t} else {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\t\
    }\n\t\tif (neg) v = -v;\n\t}\n\tstatic void read(long double& v) {\n\t\tv = 0;\n\
    \t\tlong double dp = 1;\n\t\tbool neg = false, after_dp = false;\n\t\tchar c =\
    \ next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t\
    }\n\t\tfor (; isdigit(c) || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\t\t\
    \t\tafter_dp = true;\n\t\t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0') * (dp\
    \ *= 0.1);\n\t\t\t} else {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\t}\n\t\
    \tif (neg) v = -v;\n\t}\n\ttemplate <class T, class U> static void read(pair<T,\
    \ U>& v) {\n\t\tread(v.first);\n\t\tread(v.second);\n\t}\n\ttemplate <class T>\
    \ static void read(vector<T>& v) {\n\t\tfor (auto& e : v) read(e);\n\t}\n\ttemplate\
    \ <size_t N = 0, class T> static void read_tuple_impl(T& v) {\n\t\tif constexpr\
    \ (N < tuple_size_v<T>) {\n\t\t\tread(get<N>(v));\n\t\t\tread_tuple_impl<N + 1>(v);\n\
    \t\t}\n\t}\n\ttemplate <class... T> static void read(tuple<T...>& v) {\n\t\tread_tuple_impl(v);\n\
    \t}\n\tstruct ReadVectorHelper {\n\t\tsize_t n;\n\t\tReadVectorHelper(size_t _n)\
    \ : n(_n) {}\n\t\ttemplate <class T> operator vector<T>() {\n\t\t\tvector<T> v(n);\n\
    \t\t\tread(v);\n\t\t\treturn v;\n\t\t}\n\t};\n\tstruct Read2DVectorHelper {\n\t\
    \tsize_t n, m;\n\t\tRead2DVectorHelper(const pair<size_t, size_t>& nm) : n(nm.first),\
    \ m(nm.second) {}\n\t\ttemplate <class T> operator vector<vector<T>>() {\n\t\t\
    \tvector<vector<T>> v(n, vector<T>(m));\n\t\t\tread(v);\n\t\t\treturn v;\n\t\t\
    }\n\t};\n\npublic:\n\tstring read_line() const {\n\t\tstring v;\n\t\tfor (char\
    \ c = gc(); c != '\\n' && c != '\\0'; c = gc()) v += c;\n\t\treturn v;\n\t}\n\t\
    template <class T> T read() const {\n\t\tT v;\n\t\tread(v);\n\t\treturn v;\n\t\
    }\n\ttemplate <class T> vector<T> read_vector(size_t n) const {\n\t\tvector<T>\
    \ a(n);\n\t\tread(a);\n\t\treturn a;\n\t}\n\ttemplate <class T> operator T() const\
    \ {\n\t\treturn read<T>();\n\t}\n\tint operator--(int) const {\n\t\treturn read<int>()\
    \ - 1;\n\t}\n\tReadVectorHelper operator[](size_t n) const {\n\t\treturn ReadVectorHelper(n);\n\
    \t}\n\tRead2DVectorHelper operator[](const pair<size_t, size_t>& nm) const {\n\
    \t\treturn Read2DVectorHelper(nm);\n\t}\n\tvoid operator()() const {}\n\ttemplate\
    \ <class H, class... T> void operator()(H&& h, T&&... t) const {\n\t\tread(h);\n\
    \t\toperator()(forward<T>(t)...);\n\t}\n\nprivate:\n\ttemplate <template <class...>\
    \ class, class...> struct Multiple;\n\ttemplate <template <class...> class V,\
    \ class Head, class... Tail>\n\tstruct Multiple<V, Head, Tail...> {\n\t\ttemplate\
    \ <class... Args> using vec = V<vector<Head>, Args...>;\n\t\tusing type = typename\
    \ Multiple<vec, Tail...>::type;\n\t};\n\ttemplate <template <class...> class V>\
    \ struct Multiple<V> { using type = V<>; };\n\ttemplate <class... T> using multiple_t\
    \ = typename Multiple<tuple, T...>::type;\n\ttemplate <size_t N = 0, class T>\
    \ void multiple_impl(T& t) const {\n\t\tif constexpr (N < tuple_size_v<T>) {\n\
    \t\t\tauto& vec = get<N>(t);\n\t\t\tusing V = typename remove_reference_t<decltype(vec)>::value_type;\n\
    \t\t\tvec.push_back(read<V>());\n\t\t\tmultiple_impl<N + 1>(t);\n\t\t}\n\t}\n\n\
    public:\n\ttemplate <class... T> auto multiple(size_t h) const {\n\t\tmultiple_t<T...>\
    \ result;\n\t\twhile (h--) multiple_impl(result);\n\t\treturn result;\n\t}\n}\
    \ in;\n#define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n\
    #define ini(...) inputs(int, __VA_ARGS__)\n#define inl(...) inputs(long long,\
    \ __VA_ARGS__)\n#define ins(...) inputs(string, __VA_ARGS__)\n#line 7 \"template/Output.cpp\"\
    \n#include <charconv>\n#line 10 \"template/Output.cpp\"\nusing namespace std;\n\
    \nstruct BoolStr {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const char*\
    \ _f) : t(_t), f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"\
    YES\", \"NO\"), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\t\
    DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"\
    ), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"),\n\
    \    no_endl(\" \", \"\");\nclass Printer {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\
    \npublic:\n\tvoid print(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr,\
    \ e] = to_chars(begin(buf), end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char),\
    \ ptr - buf, stdout);\n\t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid\
    \ print(long long v) const {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(bool v) const {\n\
    \t\tprint(v ? B.t : B.f);\n\t}\n\tvoid print(vector<bool>::reference v) const\
    \ {\n\t\tprint(v ? B.t : B.f);\n\t}\n\tvoid print(char v) const {\n\t\tputchar_unlocked(v);\n\
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
    \ {\n\t\tprint(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class H> Printer& operator()(H&&\
    \ h) {\n\t\tprint(h);\n\t\tprint(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class\
    \ H, class... T> Printer& operator()(H&& h, T&&... t) {\n\t\tprint(h);\n\t\tprint(D.d);\n\
    \t\treturn operator()(forward<T>(t)...);\n\t}\n\ttemplate <class InputIterator>\n\
    \tPrinter& range(const InputIterator& begin, const InputIterator& end) {\n\t\t\
    print_range(begin, end);\n\t\tprint(D.l);\n\t\treturn *this;\n\t}\n\ttemplate\
    \ <class T> Printer& range(const T& a) {\n\t\trange(a.begin(), a.end());\n\t\t\
    return *this;\n\t}\n\ttemplate <class... T> void exit(T&&... t) {\n\t\toperator()(forward<T>(t)...);\n\
    \t\tstd::exit(EXIT_SUCCESS);\n\t}\n\tPrinter& flush() {\n\t\tfflush_unlocked(stdout);\n\
    \t\treturn *this;\n\t}\n\tPrinter& set(const BoolStr& b) {\n\t\tB = b;\n\t\treturn\
    \ *this;\n\t}\n\tPrinter& set(const DivStr& d) {\n\t\tD = d;\n\t\treturn *this;\n\
    \t}\n\tPrinter& set(const char* t, const char* f) {\n\t\tB = BoolStr(t, f);\n\t\
    \treturn *this;\n\t}\n} out;\n#line 7 \"template/functions.cpp\"\nusing namespace\
    \ std;\n\ntemplate <class T = long long> constexpr T TEN(size_t n) {\n\tT result\
    \ = 1;\n\tfor (size_t i = 0; i < n; ++i) result *= 10;\n\treturn result;\n}\n\
    template <class T, class U,\n          enable_if_t<is_integral_v<T> && is_integral_v<U>,\
    \ nullptr_t> = nullptr>\nconstexpr auto div_ceil(T n, U m) {\n\treturn (n + m\
    \ - 1) / m;\n}\ntemplate <class T, class U> constexpr auto div_ceil2(T n, U m)\
    \ {\n\treturn div_ceil(n, m) * m;\n}\ntemplate <class T> constexpr T triangle(T\
    \ n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n}\ntemplate <class\
    \ T> constexpr T nC2(T n) {\n\treturn (n & 1) ? (n - 1) / 2 * n : n / 2 * (n -\
    \ 1);\n}\ntemplate <class T, class U> constexpr auto middle(const T& l, const\
    \ U& r) {\n\treturn l + (r - l) / 2;\n}\ntemplate <class T, class U, class V>\n\
    constexpr bool in_range(const T& v, const U& lower, const V& upper) {\n\treturn\
    \ lower <= v && v < upper;\n}\ntemplate <class T, enable_if_t<is_integral_v<T>,\
    \ nullptr_t> = nullptr>\nconstexpr bool is_square(T n) {\n\tT s = sqrt(n);\n\t\
    return s * s == n || (s + 1) * (s + 1) == n;\n}\ntemplate <class T = long long>\
    \ constexpr T BIT(int b) {\n\treturn T(1) << b;\n}\ntemplate <class T> constexpr\
    \ int BIT(T x, int i) {\n\treturn (x & (1 << i)) ? 1 : 0;\n}\ntemplate <class\
    \ T, class U, enable_if_t<is_integral_v<U>, nullptr_t> = nullptr>\nconstexpr T\
    \ Pow(T a, U n) {\n\tassert(n >= 0);\n\tT result = 1;\n\twhile (n > 0) {\n\t\t\
    if (n & 1) {\n\t\t\tresult *= a;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta *= a;\n\t\t\
    \tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class T, class U, enable_if_t<is_integral_v<U>,\
    \ nullptr_t> = nullptr>\nconstexpr T Powmod(T a, U n, T mod) {\n\tassert(n >=\
    \ 0);\n\tif (a > mod) a %= mod;\n\tT result = 1;\n\twhile (n > 0) {\n\t\tif (n\
    \ & 1) {\n\t\t\tresult = result * a % mod;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta\
    \ = a * a % mod;\n\t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class\
    \ T> bool chmax(T& a, const T& b) {\n\tif (a < b) {\n\t\ta = b;\n\t\treturn true;\n\
    \t}\n\treturn false;\n}\ntemplate <class T> bool chmin(T& a, const T& b) {\n\t\
    if (a > b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate\
    \ <class T> int sz(const T& v) {\n\treturn v.size();\n}\ntemplate <class T, class\
    \ U> int lower_index(const T& a, const U& v) {\n\treturn lower_bound(all(a), v)\
    \ - a.begin();\n}\ntemplate <class T, class U> int upper_index(const T& a, const\
    \ U& v) {\n\treturn upper_bound(all(a), v) - a.begin();\n}\ntemplate <class T>\
    \ auto Slice(const T& v, size_t i, size_t len) {\n\treturn i < v.size() ? T(v.begin()\
    \ + i, v.begin() + min(i + len, v.size())) : T();\n}\ntemplate <class T, class\
    \ U = typename T::value_type> U Gcdv(const T& v) {\n\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), gcd<U, U>);\n}\ntemplate <class T, class U = typename\
    \ T::value_type> U Lcmv(const T& v) {\n\treturn accumulate(next(v.begin()), v.end(),\
    \ U(*v.begin()), lcm<U, U>);\n}\nnamespace internal {\n\ttemplate <class T, size_t\
    \ N> auto make_vector(vector<int>& sizes, const T& init) {\n\t\tif constexpr (N\
    \ == 1) {\n\t\t\treturn vector(sizes[0], init);\n\t\t} else {\n\t\t\tint size\
    \ = sizes[N - 1];\n\t\t\tsizes.pop_back();\n\t\t\treturn vector(size, make_vector<T,\
    \ N - 1>(sizes, init));\n\t\t}\n\t}\n}  // namespace internal\ntemplate <class\
    \ T, size_t N>\nauto make_vector(const int (&sizes)[N], const T& init = T()) {\n\
    \tvector s(rbegin(sizes), rend(sizes));\n\treturn internal::make_vector<T, N>(s,\
    \ init);\n}\n#line 7 \"template/template_no_Ruby.cpp\"\n#if __has_include(<library/dump.hpp>)\n\
    #include <library/dump.hpp>\n#define LOCAL\n#else\n#define dump(...) ((void)0)\n\
    #endif\n\ntemplate <class T> constexpr T oj_local(const T& oj, const T& local)\
    \ {\n#ifndef LOCAL\n\treturn oj;\n#else\n\treturn local;\n#endif\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"./constants.cpp\"\n#include\
    \ \"./Input.cpp\"\n#include \"./Output.cpp\"\n#include \"./functions.cpp\"\n#if\
    \ __has_include(<library/dump.hpp>)\n#include <library/dump.hpp>\n#define LOCAL\n\
    #else\n#define dump(...) ((void)0)\n#endif\n\ntemplate <class T> constexpr T oj_local(const\
    \ T& oj, const T& local) {\n#ifndef LOCAL\n\treturn oj;\n#else\n\treturn local;\n\
    #endif\n}\n"
  dependsOn:
  - template/constants.cpp
  - template/Input.cpp
  - template/Output.cpp
  - template/functions.cpp
  isVerificationFile: false
  path: template/template_no_Ruby.cpp
  requiredBy: []
  timestamp: '2020-12-17 18:09:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template_no_Ruby.cpp
layout: document
redirect_from:
- /library/template/template_no_Ruby.cpp
- /library/template/template_no_Ruby.cpp.html
title: template/template_no_Ruby.cpp
---
