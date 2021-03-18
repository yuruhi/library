---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/Printer.cpp
    title: Utility/Printer.cpp
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
  bundledCode: "#line 1 \"test/Input_Output.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n#line 2 \"Utility/Scanner.cpp\"\n#include <iostream>\n#include <vector>\n#include\
    \ <string>\n#include <utility>\n#include <tuple>\n#include <type_traits>\n\n#ifdef\
    \ _WIN32\n#define getchar_unlocked _getchar_nolock\n#define putchar_unlocked _putchar_nolock\n\
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
    #define ins(...) inputs(std::string, __VA_ARGS__)\n#line 5 \"Utility/Printer.cpp\"\
    \n#include <array>\n#line 7 \"Utility/Printer.cpp\"\n#include <string_view>\n\
    #include <optional>\n#include <charconv>\n#include <cstring>\n#include <cassert>\n\
    \nclass Printer {\npublic:\n\tstruct BoolString {\n\t\tstd::string_view t, f;\n\
    \t\tBoolString(std::string_view _t, std::string_view _f) : t(_t), f(_f) {}\n\t\
    };\n\tstruct Separator {\n\t\tstd::string_view div, sep, last;\n\t\tSeparator(std::string_view\
    \ _div, std::string_view _sep, std::string_view _last)\n\t\t    : div(_div), sep(_sep),\
    \ last(_last) {}\n\t};\n\n\tinline static const BoolString Yes{\"Yes\", \"No\"\
    }, yes{\"yes\", \"no\"}, YES{\"YES\", \"NO\"},\n\t    Int{\"1\", \"0\"}, Possible{\"\
    Possible\", \"Impossible\"};\n\tinline static const Separator space{\" \", \"\
    \ \", \"\\n\"}, no_space{\"\", \"\", \"\\n\"},\n\t    endl{\"\\n\", \"\\n\", \"\
    \\n\"}, comma{\",\", \",\", \"\\n\"}, no_endl{\" \", \" \", \"\"},\n\t    sep_endl{\"\
    \ \", \"\\n\", \"\\n\"};\n\n\tBoolString bool_str{Yes};\n\tSeparator separator{space};\n\
    \n\tvoid print(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr, e] = std::to_chars(std::begin(buf),\
    \ std::end(buf), v);\n\t\t    e == std::errc{}) {\n\t\t\tprint(std::string_view(buf,\
    \ ptr - buf));\n\t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(long\
    \ long v) const {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = std::to_chars(std::begin(buf),\
    \ std::end(buf), v);\n\t\t    e == std::errc{}) {\n\t\t\tprint(std::string_view(buf,\
    \ ptr - buf));\n\t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(bool\
    \ v) const {\n\t\tprint(v ? bool_str.t : bool_str.f);\n\t}\n\tvoid print(std::vector<bool>::reference\
    \ v) const {\n\t\tprint(v ? bool_str.t : bool_str.f);\n\t}\n\tvoid print(char\
    \ v) const {\n\t\tputchar_unlocked(v);\n\t}\n\tvoid print(std::string_view v)\
    \ const {\n\t\tfwrite_unlocked(v.data(), sizeof(std::string_view::value_type),\
    \ v.size(), stdout);\n\t}\n\tvoid print(double v) const {\n\t\tstd::printf(\"\
    %.20f\", v);\n\t}\n\tvoid print(long double v) const {\n\t\tstd::printf(\"%.20Lf\"\
    , v);\n\t}\n\ttemplate <class T> void print(const T& v) const {\n\t\tstd::cout\
    \ << v;\n\t}\n\ttemplate <class T, class U> void print(const std::pair<T, U>&\
    \ v) const {\n\t\tprint(v.first);\n\t\tprint(separator.div);\n\t\tprint(v.second);\n\
    \t}\n\ttemplate <class T> void print(const std::optional<T>& v) const {\n\t\t\
    print(*v);\n\t}\n\ttemplate <class InputIterater>\n\tvoid print_range(const InputIterater&\
    \ begin, const InputIterater& end) const {\n\t\tfor (InputIterater i = begin;\
    \ i != end; ++i) {\n\t\t\tif (i != begin) print(separator.sep);\n\t\t\tprint(*i);\n\
    \t\t}\n\t}\n\ttemplate <class T> void print(const std::vector<T>& v) const {\n\
    \t\tprint_range(v.begin(), v.end());\n\t}\n\ttemplate <class T, std::size_t N>\
    \ void print(const std::array<T, N>& v) const {\n\t\tprint_range(v.begin(), v.end());\n\
    \t}\n\ttemplate <class T> void print(const std::vector<std::vector<T>>& v) const\
    \ {\n\t\tfor (std::size_t i = 0; i < v.size(); ++i) {\n\t\t\tif (i) print(separator.last);\n\
    \t\t\tprint(v[i]);\n\t\t}\n\t}\n\n\tPrinter() = default;\n\tPrinter(const BoolString&\
    \ _bool_str, const Separator& _separator)\n\t    : bool_str(_bool_str), separator(_separator)\
    \ {}\n\tPrinter& operator()() {\n\t\tprint(separator.last);\n\t\treturn *this;\n\
    \t}\n\ttemplate <class Head> Printer& operator()(Head&& head) {\n\t\tprint(head);\n\
    \t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\ttemplate <class Head, class...\
    \ Tail> Printer& operator()(Head&& head, Tail&&... tail) {\n\t\tprint(head);\n\
    \t\tprint(separator.sep);\n\t\treturn operator()(std::forward<Tail>(tail)...);\n\
    \t}\n\ttemplate <class... Args> Printer& flag(bool f, Args&&... args) {\n\t\t\
    if (f) {\n\t\t\treturn operator()(std::forward<Args>(args)...);\n\t\t} else {\n\
    \t\t\treturn *this;\n\t\t}\n\t}\n\ttemplate <class InputIterator>\n\tPrinter&\
    \ range(const InputIterator& begin, const InputIterator& end) {\n\t\tprint_range(begin,\
    \ end);\n\t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\ttemplate <class\
    \ Container> Printer& range(const Container& a) {\n\t\trange(a.begin(), a.end());\n\
    \t\treturn *this;\n\t}\n\ttemplate <class... T> void exit(T&&... t) {\n\t\toperator()(std::forward<T>(t)...);\n\
    \t\tstd::exit(EXIT_SUCCESS);\n\t}\n\tPrinter& flush() {\n\t\tfflush_unlocked(stdout);\n\
    \t\treturn *this;\n\t}\n\tPrinter& set(const BoolString& _bool_str) {\n\t\tbool_str\
    \ = _bool_str;\n\t\treturn *this;\n\t}\n\tPrinter& set(const Separator& _separator)\
    \ {\n\t\tseparator = _separator;\n\t\treturn *this;\n\t}\n\tPrinter& set(std::string_view\
    \ t, std::string_view f) {\n\t\tbool_str = BoolString(t, f);\n\t\treturn *this;\n\
    \t}\n} out;\n#line 5 \"test/Input_Output.test.cpp\"\nusing namespace std;\n\n\
    int main() {\n\tfor (int t = in; t--;) {\n\t\tlong long a = in, b = in;\n\t\t\
    out(a + b);\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"./../Utility/Scanner.cpp\"\n#include \"./../Utility/Printer.cpp\"\n#include\
    \ <iostream>\nusing namespace std;\n\nint main() {\n\tfor (int t = in; t--;) {\n\
    \t\tlong long a = in, b = in;\n\t\tout(a + b);\n\t}\n}\n"
  dependsOn:
  - Utility/Scanner.cpp
  - Utility/Printer.cpp
  isVerificationFile: true
  path: test/Input_Output.test.cpp
  requiredBy: []
  timestamp: '2021-03-18 17:11:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Input_Output.test.cpp
layout: document
redirect_from:
- /verify/test/Input_Output.test.cpp
- /verify/test/Input_Output.test.cpp.html
title: test/Input_Output.test.cpp
---
