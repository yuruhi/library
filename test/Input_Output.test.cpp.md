---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/Input.cpp
    title: Utility/Input.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/Output.cpp
    title: Utility/Output.cpp
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
  bundledCode: "#line 1 \"test/Input_Output.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n#line 2 \"Utility/Input.cpp\"\n#include <iostream>\n#include <vector>\n#include\
    \ <string>\n#include <utility>\n#include <tuple>\nusing namespace std;\n\n#ifdef\
    \ _WIN32\n#define getchar_unlocked _getchar_nolock\n#define putchar_unlocked _putchar_nolock\n\
    #define fwrite_unlocked fwrite\n#define fflush_unlocked fflush\n#endif\nclass\
    \ Scanner {\n\tstatic int gc() {\n\t\treturn getchar_unlocked();\n\t}\n\tstatic\
    \ char next_char() {\n\t\tchar c;\n\t\tscan(c);\n\t\treturn c;\n\t}\n\ttemplate\
    \ <class T> static void scan(T& v) {\n\t\tcin >> v;\n\t}\n\tstatic void scan(char&\
    \ v) {\n\t\twhile (isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic void scan(bool&\
    \ v) {\n\t\tv = next_char() != '0';\n\t}\n\tstatic void scan(string& v) {\n\t\t\
    v.clear();\n\t\tfor (char c = next_char(); !isspace(c); c = gc()) v += c;\n\t\
    }\n\tstatic void scan(int& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\t\tchar c\
    \ = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t\
    }\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg) v =\
    \ -v;\n\t}\n\tstatic void scan(long long& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\
    \t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\
    \t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg)\
    \ v = -v;\n\t}\n\tstatic void scan(double& v) {\n\t\tv = 0;\n\t\tdouble dp = 1;\n\
    \t\tbool neg = false, after_dp = false;\n\t\tchar c = next_char();\n\t\tif (c\
    \ == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\
    \t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else\
    \ {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t\
    }\n\tstatic void scan(long double& v) {\n\t\tv = 0;\n\t\tlong double dp = 1;\n\
    \t\tbool neg = false, after_dp = false;\n\t\tchar c = next_char();\n\t\tif (c\
    \ == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\
    \t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else\
    \ {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t\
    }\n\ttemplate <class T, class U> static void scan(pair<T, U>& v) {\n\t\tscan(v.first);\n\
    \t\tscan(v.second);\n\t}\n\ttemplate <class T> static void scan(vector<T>& v)\
    \ {\n\t\tfor (auto& e : v) scan(e);\n\t}\n\ttemplate <size_t N = 0, class T> static\
    \ void scan_tuple_impl(T& v) {\n\t\tif constexpr (N < tuple_size_v<T>) {\n\t\t\
    \tscan(get<N>(v));\n\t\t\tscan_tuple_impl<N + 1>(v);\n\t\t}\n\t}\n\ttemplate <class...\
    \ T> static void scan(tuple<T...>& v) {\n\t\tscan_tuple_impl(v);\n\t}\n\tstruct\
    \ ReadVectorHelper {\n\t\tsize_t n;\n\t\tReadVectorHelper(size_t _n) : n(_n) {}\n\
    \t\ttemplate <class T> operator vector<T>() {\n\t\t\tvector<T> v(n);\n\t\t\tscan(v);\n\
    \t\t\treturn v;\n\t\t}\n\t};\n\tstruct Read2DVectorHelper {\n\t\tsize_t n, m;\n\
    \t\tRead2DVectorHelper(const pair<size_t, size_t>& nm) : n(nm.first), m(nm.second)\
    \ {}\n\t\ttemplate <class T> operator vector<vector<T>>() {\n\t\t\tvector<vector<T>>\
    \ v(n, vector<T>(m));\n\t\t\tscan(v);\n\t\t\treturn v;\n\t\t}\n\t};\n\npublic:\n\
    \tstring read_line() const {\n\t\tstring v;\n\t\tfor (char c = gc(); c != '\\\
    n' && c != '\\0'; c = gc()) v += c;\n\t\treturn v;\n\t}\n\ttemplate <class T>\
    \ T read() const {\n\t\tT result;\n\t\tscan(result);\n\t\treturn result;\n\t}\n\
    \ttemplate <class T> vector<T> read(size_t n) const {\n\t\tvector<T> result(n);\n\
    \t\tscan(result);\n\t\treturn result;\n\t}\n\ttemplate <class T> operator T()\
    \ const {\n\t\treturn read<T>();\n\t}\n\tint operator--(int) const {\n\t\treturn\
    \ read<int>() - 1;\n\t}\n\tReadVectorHelper operator[](size_t n) const {\n\t\t\
    return ReadVectorHelper(n);\n\t}\n\tRead2DVectorHelper operator[](const pair<size_t,\
    \ size_t>& nm) const {\n\t\treturn Read2DVectorHelper(nm);\n\t}\n\tvoid operator()()\
    \ const {}\n\ttemplate <class H, class... T> void operator()(H&& h, T&&... t)\
    \ const {\n\t\tscan(h);\n\t\toperator()(forward<T>(t)...);\n\t}\n\nprivate:\n\t\
    template <template <class...> class, class...> struct Column;\n\ttemplate <template\
    \ <class...> class V, class Head, class... Tail>\n\tstruct Column<V, Head, Tail...>\
    \ {\n\t\ttemplate <class... Args> using vec = V<vector<Head>, Args...>;\n\t\t\
    using type = typename Column<vec, Tail...>::type;\n\t};\n\ttemplate <template\
    \ <class...> class V> struct Column<V> { using type = V<>; };\n\ttemplate <class...\
    \ T> using column_t = typename Column<tuple, T...>::type;\n\ttemplate <size_t\
    \ N = 0, class T> void column_impl(T& t) const {\n\t\tif constexpr (N < tuple_size_v<T>)\
    \ {\n\t\t\tauto& vec = get<N>(t);\n\t\t\tusing V = typename remove_reference_t<decltype(vec)>::value_type;\n\
    \t\t\tvec.push_back(read<V>());\n\t\t\tcolumn_impl<N + 1>(t);\n\t\t}\n\t}\n\n\
    public:\n\ttemplate <class... T> auto column(size_t h) const {\n\t\tcolumn_t<T...>\
    \ result;\n\t\twhile (h--) column_impl(result);\n\t\treturn result;\n\t}\n} in;\n\
    #define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n#define\
    \ ini(...) inputs(int, __VA_ARGS__)\n#define inl(...) inputs(long long, __VA_ARGS__)\n\
    #define ins(...) inputs(string, __VA_ARGS__)\n#line 5 \"Utility/Output.cpp\"\n\
    #include <string_view>\n#line 7 \"Utility/Output.cpp\"\n#include <array>\n#include\
    \ <charconv>\n#include <cstring>\n#include <cassert>\nusing namespace std;\n\n\
    class Printer {\npublic:\n\tstruct BoolString {\n\t\tstring_view t, f;\n\t\tBoolString(string_view\
    \ _t, string_view _f) : t(_t), f(_f) {}\n\t};\n\tstruct Separator {\n\t\tstring_view\
    \ div, sep, last;\n\t\tSeparator(string_view _div, string_view _sep, string_view\
    \ _last)\n\t\t    : div(_div), sep(_sep), last(_last) {}\n\t};\n\n\tinline static\
    \ const BoolString Yes{\"Yes\", \"No\"}, yes{\"yes\", \"no\"}, YES{\"YES\", \"\
    NO\"},\n\t    Int{\"1\", \"0\"};\n\tinline static const Separator space{\" \"\
    , \" \", \"\\n\"}, no_space{\"\", \"\", \"\\n\"},\n\t    end_line{\"\\n\", \"\\\
    n\", \"\\n\"}, comma{\",\", \",\", \"\\n\"}, no_endl{\" \", \" \", \"\"};\n\n\t\
    BoolString bool_str{Yes};\n\tSeparator separator{space};\n\npublic:\n\tvoid print(int\
    \ v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tprint(string_view(buf, ptr - buf));\n\t\t\
    } else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(long long v) const {\n\
    \t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf), v);\
    \ e == errc{}) {\n\t\t\tprint(string_view(buf, ptr - buf));\n\t\t} else {\n\t\t\
    \tassert(false);\n\t\t}\n\t}\n\tvoid print(bool v) const {\n\t\tprint(v ? bool_str.t\
    \ : bool_str.f);\n\t}\n\tvoid print(vector<bool>::reference v) const {\n\t\tprint(v\
    \ ? bool_str.t : bool_str.f);\n\t}\n\tvoid print(char v) const {\n\t\tputchar_unlocked(v);\n\
    \t}\n\tvoid print(string_view v) const {\n\t\tfwrite_unlocked(v.data(), sizeof(string_view::value_type),\
    \ v.size(), stdout);\n\t}\n\tvoid print(double v) const {\n\t\tprintf(\"%.20f\"\
    , v);\n\t}\n\tvoid print(long double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t\
    }\n\ttemplate <class T> void print(const T& v) const {\n\t\tcout << v;\n\t}\n\t\
    template <class T, class U> void print(const pair<T, U>& v) const {\n\t\tprint(v.first);\n\
    \t\tprint(separator.div);\n\t\tprint(v.second);\n\t}\n\ttemplate <class InputIterater>\n\
    \tvoid print_range(const InputIterater& begin, const InputIterater& end) const\
    \ {\n\t\tfor (InputIterater i = begin; i != end; ++i) {\n\t\t\tif (i != begin)\
    \ print(separator.div);\n\t\t\tprint(*i);\n\t\t}\n\t}\n\ttemplate <class T> void\
    \ print(const vector<T>& v) const {\n\t\tprint_range(v.begin(), v.end());\n\t\
    }\n\ttemplate <class T, size_t N> void print(const array<T, N>& v) const {\n\t\
    \tprint_range(v.begin(), v.end());\n\t}\n\ttemplate <class T> void print(const\
    \ vector<vector<T>>& v) const {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\
    \t\t\tif (i) print(separator.last);\n\t\t\tprint(v[i]);\n\t\t}\n\t}\n\n\tPrinter()\
    \ = default;\n\tPrinter(const BoolString& _bool_str, const Separator& _separator)\n\
    \t    : bool_str(_bool_str), separator(_separator) {}\n\tPrinter& operator()()\
    \ {\n\t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\ttemplate <class Head>\
    \ Printer& operator()(Head&& head) {\n\t\tprint(head);\n\t\tprint(separator.last);\n\
    \t\treturn *this;\n\t}\n\ttemplate <class Head, class... Tail> Printer& operator()(Head&&\
    \ head, Tail&&... tail) {\n\t\tprint(head);\n\t\tprint(separator.sep);\n\t\treturn\
    \ operator()(forward<Tail>(tail)...);\n\t}\n\ttemplate <class... Args> Printer&\
    \ flag(bool f, Args&&... args) {\n\t\tif (f) {\n\t\t\treturn operator()(forward<Args>(args)...);\n\
    \t\t} else {\n\t\t\treturn *this;\n\t\t}\n\t}\n\ttemplate <class InputIterator>\n\
    \tPrinter& range(const InputIterator& begin, const InputIterator& end) {\n\t\t\
    print_range(begin, end);\n\t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\
    \ttemplate <class Container> Printer& range(const Container& a) {\n\t\trange(a.begin(),\
    \ a.end());\n\t\treturn *this;\n\t}\n\ttemplate <class... T> void exit(T&&...\
    \ t) {\n\t\toperator()(forward<T>(t)...);\n\t\tstd::exit(EXIT_SUCCESS);\n\t}\n\
    \tPrinter& flush() {\n\t\tfflush_unlocked(stdout);\n\t\treturn *this;\n\t}\n\t\
    Printer& set(const BoolString& _bool_str) {\n\t\tbool_str = _bool_str;\n\t\treturn\
    \ *this;\n\t}\n\tPrinter& set(const Separator& _separator) {\n\t\tseparator =\
    \ _separator;\n\t\treturn *this;\n\t}\n\tPrinter& set(string_view t, string_view\
    \ f) {\n\t\tbool_str = BoolString(t, f);\n\t\treturn *this;\n\t}\n} out;\n#line\
    \ 5 \"test/Input_Output.test.cpp\"\nusing namespace std;\n\nint main() {\n\tfor\
    \ (int t = in; t--;) {\n\t\tlong long a = in, b = in;\n\t\tout(a + b);\n\t}\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"./../Utility/Input.cpp\"\n#include \"./../Utility/Output.cpp\"\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n\tfor (int t = in; t--;) {\n\t\tlong long\
    \ a = in, b = in;\n\t\tout(a + b);\n\t}\n}\n"
  dependsOn:
  - Utility/Input.cpp
  - Utility/Output.cpp
  isVerificationFile: true
  path: test/Input_Output.test.cpp
  requiredBy: []
  timestamp: '2021-03-02 07:38:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Input_Output.test.cpp
layout: document
redirect_from:
- /verify/test/Input_Output.test.cpp
- /verify/test/Input_Output.test.cpp.html
title: test/Input_Output.test.cpp
---
