---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/Printer.cpp
    title: Utility/Printer.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/Ruby.cpp
    title: Utility/Ruby.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/Scanner.cpp
    title: Utility/Scanner.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/Step.cpp
    title: Utility/Step.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/constants.cpp
    title: Utility/constants.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/functions.cpp
    title: Utility/functions.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/get_MOD.cpp
    title: Utility/get_MOD.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/oj_local.cpp
    title: Utility/oj_local.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
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
  bundledCode: "#line 1 \"test/template_no_Ruby.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \n#line 2 \"Utility/get_MOD.cpp\"\nconstexpr long long get_MOD() {\n#ifdef SET_MOD\n\
    \treturn SET_MOD;\n#else\n\treturn 1000000007;\n#endif\n}\n#line 3 \"Utility/constants.cpp\"\
    \n#include <vector>\n#include <string>\n#include <utility>\n#include <queue>\n\
    \n#define rep(i, n) for (int i = 0; i < (n); ++i)\n#define FOR(i, m, n) for (int\
    \ i = (m); i < (n); ++i)\n#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)\n\
    #define rfor(i, m, n) for (int i = (m); i >= (n); --i)\n#define INTERNAL_CAT_IMPL(s1,\
    \ s2) s1##s2\n#define INTERNAL_CAT(s1, s2) INTERNAL_CAT_IMPL(s1, s2)\n#ifdef __COUNTER__\n\
    #define loop(n) rep(INTERNAL_CAT(_i, __COUNTER__), n)\n#else\n#define loop(n)\
    \ rep(INTERNAL_CAT(_i, __COUNTER__), n)\n#endif\n#define unless(c) if (!(c))\n\
    #define ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n\
    #define range_it(a, l, r) (a).begin() + (l), (a).begin() + (r)\n\nusing ll = long\
    \ long;\nusing LD = long double;\nusing VB = std::vector<bool>;\nusing VVB = std::vector<VB>;\n\
    using VI = std::vector<int>;\nusing VVI = std::vector<VI>;\nusing VL = std::vector<ll>;\n\
    using VVL = std::vector<VL>;\nusing VS = std::vector<std::string>;\nusing VD =\
    \ std::vector<LD>;\nusing PII = std::pair<int, int>;\nusing VP = std::vector<PII>;\n\
    using PLL = std::pair<ll, ll>;\nusing VPL = std::vector<PLL>;\ntemplate <class\
    \ T> using PQ = std::priority_queue<T>;\ntemplate <class T> using PQS = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\nconstexpr int inf = 1000000000;\nconstexpr\
    \ long long inf_ll = 1000000000000000000ll, MOD = get_MOD();\nconstexpr long double\
    \ PI = 3.14159265358979323846, tau = PI * 2, EPS = 1e-12;\n#line 2 \"Utility/Scanner.cpp\"\
    \n#include <iostream>\n#line 6 \"Utility/Scanner.cpp\"\n#include <tuple>\n#include\
    \ <type_traits>\n\n#ifdef _WIN32\n#define getchar_unlocked _getchar_nolock\n#define\
    \ putchar_unlocked _putchar_nolock\n#define fwrite_unlocked fwrite\n#define fflush_unlocked\
    \ fflush\n#endif\nclass Scanner {\n\ttemplate <class T, class = void> struct has_scan\
    \ : std::false_type {};\n\ttemplate <class T>\n\tstruct has_scan<T, std::void_t<decltype(std::declval<T>().template\
    \ scan<Scanner>())>>\n\t    : std::true_type {};\n\npublic:\n\tstatic int gc()\
    \ {\n\t\treturn getchar_unlocked();\n\t}\n\tstatic char next_char() {\n\t\tchar\
    \ c;\n\t\tscan(c);\n\t\treturn c;\n\t}\n\ttemplate <class T> static void scan(T&\
    \ v) {\n\t\tif (has_scan<T>::value) {\n\t\t\tv.template scan<Scanner>();\n\t\t\
    } else {\n\t\t\tstd::cin >> v;\n\t\t}\n\t}\n\tstatic void scan(char& v) {\n\t\t\
    while (std::isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic void scan(bool& v) {\n\t\
    \tv = next_char() != '0';\n\t}\n\tstatic void scan(std::vector<bool>::reference\
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
    for (auto e : v) scan(e);\n\t}\n\nprivate:\n\ttemplate <std::size_t N = 0, class\
    \ T> static void scan_tuple_impl(T& v) {\n\t\tif constexpr (N < std::tuple_size_v<T>)\
    \ {\n\t\t\tscan(std::get<N>(v));\n\t\t\tscan_tuple_impl<N + 1>(v);\n\t\t}\n\t\
    }\n\npublic:\n\ttemplate <class... T> static void scan(std::tuple<T...>& v) {\n\
    \t\tscan_tuple_impl(v);\n\t}\n\nprivate:\n\tstruct Read2DVectorHelper {\n\t\t\
    std::size_t h, w;\n\t\tRead2DVectorHelper(std::size_t _h, std::size_t _w) : h(_h),\
    \ w(_w) {}\n\t\ttemplate <class T> operator std::vector<std::vector<T>>() {\n\t\
    \t\tstd::vector vector(h, std::vector<T>(w));\n\t\t\tscan(vector);\n\t\t\treturn\
    \ vector;\n\t\t}\n\t};\n\tstruct ReadVectorHelper {\n\t\tstd::size_t n;\n\t\t\
    ReadVectorHelper(std::size_t _n) : n(_n) {}\n\t\ttemplate <class T> operator std::vector<T>()\
    \ {\n\t\t\tstd::vector<T> vector(n);\n\t\t\tscan(vector);\n\t\t\treturn vector;\n\
    \t\t}\n\t\tauto operator[](std::size_t m) {\n\t\t\treturn Read2DVectorHelper(n,\
    \ m);\n\t\t}\n\t};\n\npublic:\n\ttemplate <class T> T read() const {\n\t\tT result;\n\
    \t\tscan(result);\n\t\treturn result;\n\t}\n\ttemplate <class T> auto read(std::size_t\
    \ n) const {\n\t\tstd::vector<T> result(n);\n\t\tscan(result);\n\t\treturn result;\n\
    \t}\n\ttemplate <class T> auto read(std::size_t h, std::size_t w) const {\n\t\t\
    std::vector result(h, std::vector<T>(w));\n\t\tscan(result);\n\t\treturn result;\n\
    \t}\n\tstd::string read_line() const {\n\t\tstd::string v;\n\t\tfor (char c =\
    \ gc(); c != '\\n' && c != '\\0'; c = gc()) v += c;\n\t\treturn v;\n\t}\n\ttemplate\
    \ <class T> operator T() const {\n\t\treturn read<T>();\n\t}\n\tint operator--(int)\
    \ const {\n\t\treturn read<int>() - 1;\n\t}\n\tauto operator[](std::size_t n)\
    \ const {\n\t\treturn ReadVectorHelper(n);\n\t}\n\tauto operator[](const std::pair<std::size_t,\
    \ std::size_t>& nm) const {\n\t\treturn Read2DVectorHelper(nm.first, nm.second);\n\
    \t}\n\tvoid operator()() const {}\n\ttemplate <class H, class... T> void operator()(H&&\
    \ h, T&&... t) const {\n\t\tscan(h);\n\t\toperator()(std::forward<T>(t)...);\n\
    \t}\n\nprivate:\n\ttemplate <template <class...> class, class...> struct Column;\n\
    \ttemplate <template <class...> class V, class Head, class... Tail>\n\tstruct\
    \ Column<V, Head, Tail...> {\n\t\ttemplate <class... Args> using vec = V<std::vector<Head>,\
    \ Args...>;\n\t\tusing type = typename Column<vec, Tail...>::type;\n\t};\n\ttemplate\
    \ <template <class...> class V> struct Column<V> { using type = V<>; };\n\ttemplate\
    \ <class... T> using column_t = typename Column<std::tuple, T...>::type;\n\ttemplate\
    \ <std::size_t N = 0, class T> void column_impl(T& t) const {\n\t\tif constexpr\
    \ (N < std::tuple_size_v<T>) {\n\t\t\tauto& vec = std::get<N>(t);\n\t\t\tusing\
    \ V = typename std::remove_reference_t<decltype(vec)>::value_type;\n\t\t\tvec.push_back(read<V>());\n\
    \t\t\tcolumn_impl<N + 1>(t);\n\t\t}\n\t}\n\npublic:\n\ttemplate <class... T> auto\
    \ column(std::size_t h) const {\n\t\tcolumn_t<T...> result;\n\t\twhile (h--) column_impl(result);\n\
    \t\treturn result;\n\t}\n} in;\n#define inputs(T, ...) \\\n\tT __VA_ARGS__;  \
    \   \\\n\tin(__VA_ARGS__)\n#define ini(...) inputs(int, __VA_ARGS__)\n#define\
    \ inl(...) inputs(long long, __VA_ARGS__)\n#define ins(...) inputs(std::string,\
    \ __VA_ARGS__)\n#line 5 \"Utility/Printer.cpp\"\n#include <array>\n#line 7 \"\
    Utility/Printer.cpp\"\n#include <string_view>\n#include <optional>\n#include <charconv>\n\
    #line 11 \"Utility/Printer.cpp\"\n#include <cstring>\n#include <cassert>\n\nclass\
    \ Printer {\npublic:\n\tstruct BoolString {\n\t\tstd::string_view t, f;\n\t\t\
    BoolString(std::string_view _t, std::string_view _f) : t(_t), f(_f) {}\n\t};\n\
    \tstruct Separator {\n\t\tstd::string_view div, sep, last;\n\t\tSeparator(std::string_view\
    \ _div, std::string_view _sep, std::string_view _last)\n\t\t    : div(_div), sep(_sep),\
    \ last(_last) {}\n\t};\n\n\tinline static const BoolString Yes{\"Yes\", \"No\"\
    }, yes{\"yes\", \"no\"}, YES{\"YES\", \"NO\"},\n\t    Int{\"1\", \"0\"}, Possible{\"\
    Possible\", \"Impossible\"};\n\tinline static const Separator space{\" \", \"\
    \ \", \"\\n\"}, no_space{\"\", \"\", \"\\n\"},\n\t    endl{\"\\n\", \"\\n\", \"\
    \\n\"}, comma{\",\", \",\", \"\\n\"}, no_endl{\" \", \" \", \"\"},\n\t    sep_endl{\"\
    \ \", \"\\n\", \"\\n\"};\n\n\tBoolString bool_str{Yes};\n\tSeparator separator{space};\n\
    \nprivate:\n\ttemplate <class T, class = void> struct has_print : std::false_type\
    \ {};\n\ttemplate <class T>\n\tstruct has_print<T,\n\t                 std::void_t<decltype(std::declval<T>().print(std::declval<Printer>()))>>\n\
    \t    : std::true_type {};\n\npublic:\n\tvoid print(int v) const {\n\t\tchar buf[12]{};\n\
    \t\tif (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf), v);\n\t\t\
    \    e == std::errc{}) {\n\t\t\tprint(std::string_view(buf, ptr - buf));\n\t\t\
    } else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(long long v) const {\n\
    \t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf),\
    \ v);\n\t\t    e == std::errc{}) {\n\t\t\tprint(std::string_view(buf, ptr - buf));\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(bool v) const {\n\
    \t\tprint(v ? bool_str.t : bool_str.f);\n\t}\n\tvoid print(std::vector<bool>::reference\
    \ v) const {\n\t\tprint(v ? bool_str.t : bool_str.f);\n\t}\n\tvoid print(char\
    \ v) const {\n\t\tputchar_unlocked(v);\n\t}\n\tvoid print(std::string_view v)\
    \ const {\n\t\tfwrite_unlocked(v.data(), sizeof(std::string_view::value_type),\
    \ v.size(), stdout);\n\t}\n\tvoid print(double v) const {\n\t\tstd::printf(\"\
    %.20f\", v);\n\t}\n\tvoid print(long double v) const {\n\t\tstd::printf(\"%.20Lf\"\
    , v);\n\t}\n\ttemplate <class T, std::enable_if_t<has_print<T>::value, std::nullptr_t>\
    \ = nullptr>\n\tvoid print(const T& v) const {\n\t\tv.print(*this);\n\t}\n\ttemplate\
    \ <class T, std::enable_if_t<!has_print<T>::value, std::nullptr_t> = nullptr>\n\
    \tvoid print(const T& v) const {\n\t\tstd::cout << v;\n\t}\n\ttemplate <class\
    \ T, class U> void print(const std::pair<T, U>& v) const {\n\t\tprint(v.first);\n\
    \t\tprint(separator.div);\n\t\tprint(v.second);\n\t}\n\ttemplate <class T> void\
    \ print(const std::optional<T>& v) const {\n\t\tprint(*v);\n\t}\n\ttemplate <class\
    \ InputIterater>\n\tvoid print_range(const InputIterater& begin, const InputIterater&\
    \ end) const {\n\t\tfor (InputIterater i = begin; i != end; ++i) {\n\t\t\tif (i\
    \ != begin) print(separator.sep);\n\t\t\tprint(*i);\n\t\t}\n\t}\n\ttemplate <class\
    \ T> void print(const std::vector<T>& v) const {\n\t\tprint_range(v.begin(), v.end());\n\
    \t}\n\ttemplate <class T, std::size_t N> void print(const std::array<T, N>& v)\
    \ const {\n\t\tprint_range(v.begin(), v.end());\n\t}\n\ttemplate <class T> void\
    \ print(const std::vector<std::vector<T>>& v) const {\n\t\tfor (std::size_t i\
    \ = 0; i < v.size(); ++i) {\n\t\t\tif (i) print(separator.last);\n\t\t\tprint(v[i]);\n\
    \t\t}\n\t}\n\n\tPrinter() = default;\n\tPrinter(const BoolString& _bool_str, const\
    \ Separator& _separator)\n\t    : bool_str(_bool_str), separator(_separator) {}\n\
    \tPrinter& operator()() {\n\t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\
    \ttemplate <class Head> Printer& operator()(Head&& head) {\n\t\tprint(head);\n\
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
    \t}\n} out;\n#line 3 \"Utility/Step.cpp\"\n#include <iterator>\n#include <algorithm>\n\
    #line 6 \"Utility/Step.cpp\"\n\ntemplate <class T> class step_iterator {\npublic:\n\
    \tusing value_type = T;\n\tusing difference_type = T;\n\tusing iterator_category\
    \ = std::random_access_iterator_tag;\n\tusing reference = T&;\n\tusing pointer\
    \ = T*;\n\nprivate:\n\tvalue_type start_m, size_m, step_m, index_m;\n\npublic:\n\
    \tconstexpr step_iterator()\n\t    : start_m(value_type()), size_m(value_type()),\
    \ step_m(value_type()), index_m(0) {}\n\tconstexpr step_iterator(value_type _start,\
    \ value_type _size, value_type _step)\n\t    : start_m(_start), size_m(_size),\
    \ step_m(_step), index_m(0) {}\n\tvalue_type operator*() const noexcept {\n\t\t\
    return value();\n\t}\n\tstep_iterator& operator++() noexcept {\n\t\t++index_m;\n\
    \t\treturn *this;\n\t}\n\tstep_iterator& operator++(int) noexcept {\n\t\tauto\
    \ tmp = *this;\n\t\t++*this;\n\t\treturn tmp;\n\t}\n\tstep_iterator& operator--()\
    \ noexcept {\n\t\t--index_m;\n\t\treturn *this;\n\t}\n\tstep_iterator& operator--(int)\
    \ noexcept {\n\t\tauto tmp = *this;\n\t\t--*this;\n\t\treturn tmp;\n\t}\n\tstep_iterator&\
    \ operator+=(difference_type n) {\n\t\tindex_m += n;\n\t\treturn *this;\n\t}\n\
    \tstep_iterator operator+(difference_type n) const {\n\t\treturn step_iterator(*this)\
    \ += n;\n\t}\n\tfriend step_iterator operator+(difference_type n, step_iterator\
    \ i) {\n\t\treturn i + n;\n\t}\n\tstep_iterator& operator-=(difference_type n)\
    \ {\n\t\tindex_m -= n;\n\t\treturn *this;\n\t}\n\tstep_iterator operator-(difference_type\
    \ n) const {\n\t\treturn step_iterator(*this) -= n;\n\t}\n\tfriend step_iterator\
    \ operator-(difference_type n, step_iterator i) {\n\t\treturn i - n;\n\t}\n\t\
    difference_type operator-(const step_iterator& other) const {\n\t\tassert(start_m\
    \ == other.start_m);\n\t\tassert(size_m == other.size_m);\n\t\tassert(step_m ==\
    \ other.step_m);\n\t\treturn index_m - other.index_m;\n\t}\n\tbool operator==(const\
    \ step_iterator& other) const noexcept {\n\t\treturn value() == other.value();\n\
    \t}\n\tbool operator!=(const step_iterator& other) const noexcept {\n\t\treturn\
    \ value() != other.value();\n\t}\n\tbool operator<(const step_iterator& other)\
    \ const noexcept {\n\t\treturn value() < other.value();\n\t}\n\tbool operator<=(const\
    \ step_iterator& other) const noexcept {\n\t\treturn value() <= other.value();\n\
    \t}\n\tbool operator>(const step_iterator& other) const noexcept {\n\t\treturn\
    \ value() > other.value();\n\t}\n\tbool operator>=(const step_iterator& other)\
    \ const noexcept {\n\t\treturn value() >= other.value();\n\t}\n\tconstexpr value_type\
    \ value() const noexcept {\n\t\treturn start_m + step_m * index_m;\n\t}\n};\n\n\
    template <class T> class Step {\npublic:\n\tusing value_type = T;\n\tusing iterator\
    \ = step_iterator<value_type>;\n\nprivate:\n\tvalue_type start_m, size_m, step_m;\n\
    \npublic:\n\tconstexpr Step(value_type _start, value_type _size, value_type _step)\n\
    \t    : start_m(_start), size_m(std::max<value_type>(0, _size)), step_m(_step)\
    \ {}\n\tconstexpr iterator begin() const {\n\t\treturn iterator(start_m, size_m,\
    \ step_m);\n\t}\n\tconstexpr iterator end() const {\n\t\treturn iterator(start_m,\
    \ size_m, step_m) + size_m;\n\t}\n\tconstexpr value_type start() const {\n\t\t\
    return start_m;\n\t}\n\tconstexpr value_type size() const {\n\t\treturn size_m;\n\
    \t}\n\tconstexpr value_type step() const {\n\t\treturn step_m;\n\t}\n\tconstexpr\
    \ value_type sum() const {\n\t\treturn start() * size() + step() * (size() * (size()\
    \ - 1) / 2);\n\t}\n\toperator std::vector<value_type>() const {\n\t\treturn to_a();\n\
    \t}\n\tauto to_a() const {\n\t\tstd::vector<value_type> result;\n\t\tresult.reserve(size());\n\
    \t\tfor (auto i : *this) {\n\t\t\tresult.push_back(i);\n\t\t}\n\t\treturn result;\n\
    \t}\n};\ntemplate <class T> constexpr auto upto(T from, T to, bool exclusive =\
    \ true) {\n\treturn Step<T>(from, to - from + exclusive, 1);\n}\ntemplate <class\
    \ T> constexpr auto downto(T from, T to, bool exclusive = true) {\n\treturn Step<T>(from,\
    \ from - to + exclusive, -1);\n}\ntemplate <class T> constexpr auto times(T n,\
    \ bool exclusive = false) {\n\treturn Step<T>(0, n + static_cast<T>(exclusive),\
    \ 1);\n}\n#line 4 \"Utility/Ruby.cpp\"\n#include <map>\n#line 6 \"Utility/Ruby.cpp\"\
    \n#include <numeric>\n#line 9 \"Utility/Ruby.cpp\"\n\ntemplate <class F> struct\
    \ Callable {\n\tF func;\n\tCallable(const F& f) : func(f) {}\n};\ntemplate <class\
    \ T, class F> auto operator|(const T& v, const Callable<F>& c) {\n\treturn c.func(v);\n\
    }\n\nstruct Sort_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tstd::sort(std::begin(v), std::end(v), f);\n\t\t\
    \treturn v;\n\t\t});\n\t}\n\ttemplate <class T> friend auto operator|(T v, [[maybe_unused]]\
    \ const Sort_impl& c) {\n\t\tstd::sort(std::begin(v), std::end(v));\n\t\treturn\
    \ v;\n\t}\n} Sort;\nstruct SortBy_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::sort(std::begin(v), std::end(v),\n\
    \t\t\t          [&](const auto& i, const auto& j) { return f(i) < f(j); });\n\t\
    \t\treturn v;\n\t\t});\n\t}\n} SortBy;\nstruct RSort_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::sort(rbegin(v),\
    \ rend(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class T> friend auto\
    \ operator|(T v, [[maybe_unused]] const RSort_impl& c) {\n\t\tstd::sort(rbegin(v),\
    \ rend(v));\n\t\treturn v;\n\t}\n} RSort;\nstruct RSortBy_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::sort(std::begin(v),\
    \ std::end(v),\n\t\t\t          [&](const auto& i, const auto& j) { return f(i)\
    \ > f(j); });\n\t\t\treturn v;\n\t\t});\n\t}\n} RSortBy;\nstruct Reverse_impl\
    \ {\n\ttemplate <class T> friend auto operator|(T v, const Reverse_impl& c) {\n\
    \t\tstd::reverse(std::begin(v), std::end(v));\n\t\treturn v;\n\t}\n} Reverse;\n\
    struct Unique_impl {\n\ttemplate <class T> friend auto operator|(T v, const Unique_impl&\
    \ c) {\n\t\tv.erase(std::unique(std::begin(v), std::end(v), std::end(v)));\n\t\
    \treturn v;\n\t}\n\ttemplate <class T, class F> auto operator()(F&& f) {\n\t\t\
    return Callable([&](auto v) {\n\t\t\tv.erase(std::unique(std::begin(v), std::end(v),\
    \ f), std::end(v));\n\t\t\treturn v;\n\t\t});\n\t}\n} Unique;\nstruct Uniq_impl\
    \ {\n\ttemplate <class T> friend auto operator|(T v, const Uniq_impl& c) {\n\t\
    \tstd::sort(std::begin(v), std::end(v));\n\t\tv.erase(std::unique(std::begin(v),\
    \ std::end(v)), std::end(v));\n\t\treturn v;\n\t}\n} Uniq;\nstruct Rotate_impl\
    \ {\n\tauto operator()(int&& left) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    int s = static_cast<int>(std::size(v));\n\t\t\tassert(-s <= left && left <= s);\n\
    \t\t\tif (0 <= left) {\n\t\t\t\tstd::rotate(std::begin(v), std::begin(v) + left,\
    \ std::end(v));\n\t\t\t} else {\n\t\t\t\tstd::rotate(std::begin(v), std::end(v)\
    \ + left, std::end(v));\n\t\t\t}\n\t\t\treturn v;\n\t\t});\n\t}\n} Rotate;\nstruct\
    \ Max_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable(\n\
    \t\t    [&](auto v) { return *std::max_element(std::begin(v), std::end(v), f);\
    \ });\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Max_impl& c)\
    \ {\n\t\treturn *std::max_element(std::begin(v), std::end(v));\n\t}\n} Max;\n\
    struct Min_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable(\n\
    \t\t    [&](auto v) { return *std::min_element(std::begin(v), std::end(v), f);\
    \ });\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Min_impl& c)\
    \ {\n\t\treturn *std::min_element(std::begin(v), std::end(v));\n\t}\n} Min;\n\
    struct MaxPos_impl {\n\ttemplate <class T> friend auto operator|(T v, const MaxPos_impl&\
    \ c) {\n\t\treturn std::max_element(std::begin(v), std::end(v)) - std::begin(v);\n\
    \t}\n} MaxPos;\nstruct MinPos_impl {\n\ttemplate <class T> friend auto operator|(T\
    \ v, const MinPos_impl& c) {\n\t\treturn std::min_element(std::begin(v), std::end(v))\
    \ - std::begin(v);\n\t}\n} MinPos;\nstruct MaxBy_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto max_it\
    \ = std::begin(v);\n\t\t\tauto max_val = f(*max_it);\n\t\t\tfor (auto it = std::next(std::begin(v));\
    \ it != std::end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); max_val < val) {\n\
    \t\t\t\t\tmax_it = it;\n\t\t\t\t\tmax_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ *max_it;\n\t\t});\n\t}\n} MaxBy;\nstruct MinBy_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto min_it\
    \ = std::begin(v);\n\t\t\tauto min_val = f(*min_it);\n\t\t\tfor (auto it = std::next(std::begin(v));\
    \ it != std::end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); min_val > val) {\n\
    \t\t\t\t\tmin_it = it;\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ *min_it;\n\t\t});\n\t}\n} MinBy;\nstruct MaxOf_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto max_val\
    \ = f(*std::begin(v));\n\t\t\tfor (auto it = std::next(std::begin(v)); it != std::end(v);\
    \ ++it) {\n\t\t\t\tif (auto val = f(*it); max_val < val) {\n\t\t\t\t\tmax_val\
    \ = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn max_val;\n\t\t});\n\t}\n} MaxOf;\n\
    struct MinOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tauto min_val = f(*std::begin(v));\n\t\t\tfor (auto\
    \ it = std::next(std::begin(v)); it != std::end(v); ++it) {\n\t\t\t\tif (auto\
    \ val = f(*it); min_val > val) {\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\treturn min_val;\n\t\t});\n\t}\n} MinOf;\nstruct Count_impl {\n\ttemplate\
    \ <class V> auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) {\
    \ return std::count(std::begin(v), std::end(v), val); });\n\t}\n} Count;\nstruct\
    \ CountIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn\
    \ Callable([&](auto v) { return std::count_if(std::begin(v), std::end(v), f);\
    \ });\n\t}\n} CountIf;\nstruct Index_impl {\n\ttemplate <class V> auto operator()(const\
    \ V& val) {\n\t\treturn Callable([&](auto v) -> std::optional<int> {\n\t\t\tauto\
    \ result = std::find(std::begin(v), std::end(v), val);\n\t\t\treturn result !=\
    \ std::end(v) ? std::optional(result - std::begin(v))\n\t\t\t                \
    \             : std::nullopt;\n\t\t});\n\t}\n\ttemplate <class V> auto operator()(const\
    \ V& val, std::size_t i) {\n\t\treturn Callable([&](auto v) -> std::optional<int>\
    \ {\n\t\t\tauto result = std::find(std::next(std::begin(v), i), std::end(v), val);\n\
    \t\t\treturn result != std::end(v) ? std::optional(result - std::begin(v))\n\t\
    \t\t                             : std::nullopt;\n\t\t});\n\t}\n} Index;\nstruct\
    \ IndexIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn\
    \ Callable([&](auto v) -> std::optional<int> {\n\t\t\tauto result = std::find_if(std::begin(v),\
    \ std::end(v), f);\n\t\t\treturn result != std::end(v) ? std::optional(result\
    \ - std::begin(v))\n\t\t\t                             : std::nullopt;\n\t\t});\n\
    \t}\n} IndexIf;\nstruct FindIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) -> std::optional<typename decltype(v)::value_type>\
    \ {\n\t\t\tauto result = std::find_if(std::begin(v), std::end(v), f);\n\t\t\t\
    return result != std::end(v) ? std::optional(*result) : std::nullopt;\n\t\t});\n\
    \t}\n} FindIf;\nstruct Sum_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\treturn std::accumulate(std::next(std::begin(v)),\
    \ std::end(v), f(*std::begin(v)),\n\t\t\t                       [&](const auto&\
    \ a, const auto& b) { return a + f(b); });\n\t\t});\n\t}\n\ttemplate <class T>\
    \ friend auto operator|(T v, [[maybe_unused]] const Sum_impl& c) {\n\t\treturn\
    \ std::accumulate(std::begin(v), std::end(v), typename T::value_type{});\n\t}\n\
    } Sum;\nstruct Includes {\n\ttemplate <class V> auto operator()(const V& val)\
    \ {\n\t\treturn Callable(\n\t\t    [&](auto v) { return std::find(std::begin(v),\
    \ std::end(v), val) != std::end(v); });\n\t}\n} Includes;\nstruct IncludesIf_impl\
    \ {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\treturn std::find_if(std::begin(v), std::end(v), f) != std::end(v);\n\
    \t\t});\n\t}\n} IncludesIf;\nstruct RemoveIf_impl {\n\ttemplate <class F> auto\
    \ operator()(const F& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tv.erase(std::remove_if(std::begin(v),\
    \ std::end(v), f), std::end(v));\n\t\t\treturn v;\n\t\t});\n\t}\n} RemoveIf;\n\
    struct Each_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tf(i);\n\t\t\
    \t}\n\t\t});\n\t}\n} Each;\nstruct EachConsPair_impl {\n\ttemplate <class T, class\
    \ value_type = typename T::value_type>\n\tfriend auto operator|(const T& v, EachConsPair_impl&\
    \ c) {\n\t\tstd::vector<std::pair<value_type, value_type>> result;\n\t\tif (std::size(v)\
    \ >= 2) {\n\t\t\tresult.reserve(std::size(v) - 1);\n\t\t\tfor (std::size_t i =\
    \ 0; i < std::size(v) - 1; ++i) {\n\t\t\t\tresult.emplace_back(v[i], v[i + 1]);\n\
    \t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n} EachConsPair;\nstruct Select_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tusing value_type = typename decltype(v)::value_type;\n\t\t\tstd::vector<value_type>\
    \ result;\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) result.push_back(i);\n\
    \t\t\t}\n\t\t\treturn result;\n\t\t});\n\t}\n} Select;\nstruct Map_impl {\n\t\
    template <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\
    \t\t\tusing result_type = std::invoke_result_t<F, typename decltype(v)::value_type>;\n\
    \t\t\tstd::vector<result_type> result;\n\t\t\tresult.reserve(std::size(v));\n\t\
    \t\tfor (const auto& i : v) {\n\t\t\t\tresult.push_back(f(i));\n\t\t\t}\n\t\t\t\
    return result;\n\t\t});\n\t}\n} Map;\nstruct Indexed_impl {\n\ttemplate <class\
    \ T> friend auto operator|(const T& v, Indexed_impl& c) {\n\t\tusing value_type\
    \ = typename T::value_type;\n\t\tstd::vector<std::pair<value_type, int>> result;\n\
    \t\tresult.reserve(std::size(v));\n\t\tint index = 0;\n\t\tfor (const auto& i\
    \ : v) {\n\t\t\tresult.emplace_back(i, index++);\n\t\t}\n\t\treturn result;\n\t\
    }\n} Indexed;\nstruct AllOf_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\
    \tif (!f(i)) return false;\n\t\t\t}\n\t\t\treturn true;\n\t\t});\n\t}\n} AllOf;\n\
    struct AnyOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return\
    \ true;\n\t\t\t}\n\t\t\treturn false;\n\t\t});\n\t}\n} AnyOf;\nstruct NoneOf_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return false;\n\t\t\
    \t}\n\t\t\treturn true;\n\t\t});\n\t}\n} NoneOf;\n\nstruct Tally_impl {\n\tauto\
    \ operator()(std::size_t max_val) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    std::vector<std::size_t> result(max_val);\n\t\t\tfor (const auto& i : v) {\n\t\
    \t\t\tresult[static_cast<std::size_t>(i)]++;\n\t\t\t}\n\t\t\treturn result;\n\t\
    \t});\n\t}\n\ttemplate <class T, class value_type = typename T::value_type>\n\t\
    friend auto operator|(const T& v, Tally_impl& c) {\n\t\tstd::map<value_type, std::size_t>\
    \ result;\n\t\tfor (const auto& i : v) {\n\t\t\tresult[i]++;\n\t\t}\n\t\treturn\
    \ result;\n\t}\n} Tally;\n\nstruct Reduce_impl {\n\ttemplate <class T, class F>\
    \ auto operator()(T memo, F f) {\n\t\treturn Callable([memo, f](auto v) {\n\t\t\
    \tauto acc = memo;\n\t\t\tfor (auto i : v) {\n\t\t\t\tacc = f(acc, i);\n\t\t\t\
    }\n\t\t\treturn acc;\n\t\t});\n\t}\n} Reduce;\n\nstruct Join_impl {\n\tauto operator()(std::string\
    \ separater) {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::string result;\n\
    \t\t\tbool first = true;\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (!std::exchange(first,\
    \ false)) {\n\t\t\t\t\tresult += separater;\n\t\t\t\t}\n\t\t\t\tresult += std::to_string(i);\n\
    \t\t\t}\n\t\t\treturn result;\n\t\t});\n\t}\n\ttemplate <class T> friend auto\
    \ operator|(const T& v, Join_impl& c) {\n\t\treturn v | c(\"\");\n\t}\n} Join;\n\
    \nstruct At_impl {\n\tauto operator()(std::size_t l, std::size_t r) {\n\t\treturn\
    \ Callable(\n\t\t    [l, r](auto v) { return decltype(v)(std::begin(v) + l, std::begin(v)\
    \ + r); });\n\t}\n} At;\nstruct Slice_impl {\n\tauto operator()(std::size_t i,\
    \ std::size_t cnt) {\n\t\treturn Callable([i, cnt](auto v) {\n\t\t\treturn decltype(v)(std::begin(v)\
    \ + i, std::begin(v) + i + cnt);\n\t\t});\n\t}\n} Slice;\n\nstruct Transpose_impl\
    \ {\n\ttemplate <class T>\n\tfriend auto operator|(const std::vector<std::vector<T>>&\
    \ v, Transpose_impl& c) {\n\t\tstd::size_t h = v.size(), w = v.front().size();\n\
    \t\tstd::vector result(w, std::vector<T>(h));\n\t\tfor (std::size_t i = 0; i <\
    \ h; ++i) {\n\t\t\tassert(v[i].size() == w);\n\t\t\tfor (std::size_t j = 0; j\
    \ < w; ++j) {\n\t\t\t\tresult[j][i] = v[i][j];\n\t\t\t}\n\t\t}\n\t\treturn result;\n\
    \t}\n} Transpose;\n\ntemplate <class T> auto operator*(const std::vector<T>& a,\
    \ std::size_t n) {\n\tT result;\n\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\
    result.insert(result.end(), a.begin(), a.end());\n\t}\n\treturn result;\n}\nauto\
    \ operator*(std::string a, std::size_t n) {\n\tstd::string result;\n\tfor (std::size_t\
    \ i = 0; i < n; ++i) {\n\t\tresult += a;\n\t}\n\treturn result;\n}\n\nnamespace\
    \ internal {\n\ttemplate <class T, class U, class = void> struct has_push_back\
    \ : std::false_type {};\n\ttemplate <class T, class U>\n\tstruct has_push_back<T,\
    \ U,\n\t                     std::void_t<decltype(std::declval<T>().push_back(std::declval<U>()))>>\n\
    \t    : std::true_type {};\n}  // namespace internal\ntemplate <\n    class Container,\
    \ class T,\n    std::enable_if_t<internal::has_push_back<Container, T>::value,\
    \ std::nullptr_t> = nullptr>\nauto& operator<<(Container& continer, const T& val)\
    \ {\n\tcontiner.push_back(val);\n\treturn continer;\n}\ntemplate <\n    class\
    \ Container, class T,\n    std::enable_if_t<internal::has_push_back<Container,\
    \ T>::value, std::nullptr_t> = nullptr>\nauto operator+(Container continer, const\
    \ T& val) {\n\tcontiner << val;\n\treturn continer;\n}\n#line 4 \"Utility/functions.cpp\"\
    \n#include <cmath>\n#line 8 \"Utility/functions.cpp\"\n\ntemplate <class T = long\
    \ long> constexpr T TEN(std::size_t n) {\n\tT result = 1;\n\tfor (std::size_t\
    \ i = 0; i < n; ++i) result *= 10;\n\treturn result;\n}\ntemplate <\n    class\
    \ T, class U,\n    std::enable_if_t<std::is_integral_v<T> && std::is_integral_v<U>,\
    \ std::nullptr_t> = nullptr>\nconstexpr auto div_ceil(T n, U m) {\n\treturn (n\
    \ + m - 1) / m;\n}\ntemplate <class T, class U> constexpr auto div_ceil2(T n,\
    \ U m) {\n\treturn div_ceil(n, m) * m;\n}\ntemplate <class T> constexpr T triangle(T\
    \ n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n}\ntemplate <class\
    \ T> constexpr T nC2(T n) {\n\treturn (n & 1) ? (n - 1) / 2 * n : n / 2 * (n -\
    \ 1);\n}\ntemplate <class T, class U> constexpr auto middle(const T& l, const\
    \ U& r) {\n\treturn l + (r - l) / 2;\n}\ntemplate <class T, class U, class V>\n\
    constexpr bool in_range(const T& v, const U& lower, const V& upper) {\n\treturn\
    \ lower <= v && v < upper;\n}\ntemplate <class T, std::enable_if_t<std::is_integral_v<T>,\
    \ std::nullptr_t> = nullptr>\nconstexpr bool is_square(T n) {\n\tT s = std::sqrt(n);\n\
    \treturn s * s == n || (s + 1) * (s + 1) == n;\n}\ntemplate <class T = long long>\
    \ constexpr T BIT(int b) {\n\treturn T(1) << b;\n}\ntemplate <class T> constexpr\
    \ int BIT(T x, int i) {\n\treturn (x & (T(1) << i)) ? 1 : 0;\n}\ntemplate <class\
    \ T> constexpr int Sgn(T x) {\n\treturn (0 < x) - (0 > x);\n}\ntemplate <class\
    \ T> bool is_leap(T year) {\n\treturn !(year % 4) && (year % 100 || !(year % 400));\n\
    }\ntemplate <class T, class U, std::enable_if_t<std::is_integral_v<U>, std::nullptr_t>\
    \ = nullptr>\nconstexpr T Pow(T a, U n) {\n\tassert(n >= 0);\n\tT result = 1;\n\
    \twhile (n > 0) {\n\t\tif (n & 1) {\n\t\t\tresult *= a;\n\t\t\tn--;\n\t\t} else\
    \ {\n\t\t\ta *= a;\n\t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate\
    \ <class T, class U, std::enable_if_t<std::is_integral_v<U>, std::nullptr_t> =\
    \ nullptr>\nconstexpr T Powmod(T a, U n, T mod) {\n\tassert(n >= 0);\n\tif (a\
    \ > mod) a %= mod;\n\tT result = 1;\n\twhile (n > 0) {\n\t\tif (n & 1) {\n\t\t\
    \tresult = result * a % mod;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta = a * a % mod;\n\
    \t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class T> bool chmax(T&\
    \ a, const T& b) {\n\treturn a < b ? a = b, true : false;\n}\ntemplate <class\
    \ T> bool chmin(T& a, const T& b) {\n\treturn a > b ? a = b, true : false;\n}\n\
    template <class T> int sz(const T& v) {\n\treturn v.size();\n}\ntemplate <class\
    \ T, class U> int lower_index(const T& a, const U& v) {\n\treturn std::lower_bound(a.begin(),\
    \ a.end(), v) - a.begin();\n}\ntemplate <class T, class U, class F> int lower_index(const\
    \ T& a, const U& v, const F& f) {\n\treturn std::lower_bound(a.begin(), a.end(),\
    \ v, f) - a.begin();\n}\ntemplate <class T, class U> int upper_index(const T&\
    \ a, const U& v) {\n\treturn std::upper_bound(a.begin(), a.end(), v) - a.begin();\n\
    }\ntemplate <class T, class U, class F> int upper_index(const T& a, const U& v,\
    \ const F& f) {\n\treturn std::upper_bound(a.begin(), a.end(), v, f) - a.begin();\n\
    }\ntemplate <class T, class U = typename T::value_type> U Gcdv(const T& v) {\n\
    \treturn std::accumulate(std::next(v.begin()), v.end(), U(*v.begin()), std::gcd<U,\
    \ U>);\n}\ntemplate <class T, class U = typename T::value_type> U Lcmv(const T&\
    \ v) {\n\treturn std::accumulate(std::next(v.begin()), v.end(), U(*v.begin()),\
    \ std::lcm<U, U>);\n}\ntemplate <class T> T& Concat(T& v, const T& vec) {\n\t\
    v.insert(v.end(), vec.begin(), vec.end());\n\treturn v;\n}\nnamespace internal\
    \ {\n\ttemplate <class T, std::size_t N>\n\tauto make_vector(std::vector<int>&\
    \ sizes, const T& init) {\n\t\tif constexpr (N == 1) {\n\t\t\treturn std::vector(sizes[0],\
    \ init);\n\t\t} else {\n\t\t\tint size = sizes[N - 1];\n\t\t\tsizes.pop_back();\n\
    \t\t\treturn std::vector(size, make_vector<T, N - 1>(sizes, init));\n\t\t}\n\t\
    }\n}  // namespace internal\ntemplate <class T, std::size_t N>\nauto make_vector(const\
    \ int (&sizes)[N], const T& init = T()) {\n\tstd::vector s(std::rbegin(sizes),\
    \ std::rend(sizes));\n\treturn internal::make_vector<T, N>(s, init);\n}\ntemplate\
    \ <class F> struct rec_lambda {\n\tF f;\n\trec_lambda(F&& f_) : f(std::forward<F>(f_))\
    \ {}\n\ttemplate <class... Args> auto operator()(Args&&... args) const {\n\t\t\
    return f(*this, std::forward<Args>(args)...);\n\t}\n};\n\nnamespace lambda {\n\
    \tauto char_to_int = [](char c) {\n\t\treturn c - '0';\n\t};\n\tauto lower_to_int\
    \ = [](char c) {\n\t\treturn c - 'a';\n\t};\n\tauto upper_to_int = [](char c)\
    \ {\n\t\treturn c - 'A';\n\t};\n\tauto int_to_char = [](int i) -> char {\n\t\t\
    return '0' + i;\n\t};\n\tauto int_to_lower = [](int i) -> char {\n\t\treturn 'a'\
    \ + i;\n\t};\n\tauto int_to_upper = [](int i) -> char {\n\t\treturn 'A' + i;\n\
    \t};\n\tauto is_odd = [](auto n) {\n\t\treturn n % 2 == 1;\n\t};\n\tauto is_even\
    \ = [](auto n) {\n\t\treturn n % 2 == 0;\n\t};\n\tauto is_positive = [](auto n)\
    \ {\n\t\treturn n > 0;\n\t};\n\tauto is_negative = [](auto n) {\n\t\treturn n\
    \ < 0;\n\t};\n\tauto increment = [](auto n) {\n\t\treturn ++n;\n\t};\n\tauto decrement\
    \ = [](auto n) {\n\t\treturn --n;\n\t};\n\tauto self = [](const auto& n) {\n\t\
    \treturn n;\n\t};\n\tauto first = [](const auto& n) {\n\t\treturn n.first;\n\t\
    };\n\tauto second = [](const auto& n) {\n\t\treturn n.second;\n\t};\n\ttemplate\
    \ <class T> auto cast() {\n\t\treturn [](const auto& n) {\n\t\t\treturn static_cast<T>(n);\n\
    \t\t};\n\t};\n\ttemplate <class T> auto equal_to(const T& x) {\n\t\treturn [x](auto\
    \ y) {\n\t\t\treturn x == y;\n\t\t};\n\t}\n\ttemplate <std::size_t I> auto get()\
    \ {\n\t\treturn [](const auto& n) {\n\t\t\treturn std::get<I>(n);\n\t\t};\n\t\
    }\n\ttemplate <class F> auto cmp(F&& f) {\n\t\treturn [f](const auto& a, const\
    \ auto& b) {\n\t\t\treturn f(a) < f(b);\n\t\t};\n\t}\n}  // namespace lambda\n\
    #line 8 \"template.cpp\"\n#if __has_include(<library/dump.hpp>)\n#include <library/dump.hpp>\n\
    #define LOCAL\n#else\n#define dump(...) ((void)0)\n#define dump2(...) ((void)0)\n\
    #endif\n#line 2 \"Utility/oj_local.cpp\"\ntemplate <class T> constexpr T oj_local(const\
    \ T& oj, const T& local) {\n#ifndef LOCAL\n\treturn oj;\n#else\n\treturn local;\n\
    #endif\n}\n#line 16 \"template.cpp\"\n#include <bits/stdc++.h>\n#line 4 \"test/template_no_Ruby.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tfor (int t = in; t--;) {\n\t\tll a =\
    \ in, b = in;\n\t\tout(a + b);\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n#include\
    \ \"./../template.cpp\"\n#include <iostream>\nusing namespace std;\n\nint main()\
    \ {\n\tfor (int t = in; t--;) {\n\t\tll a = in, b = in;\n\t\tout(a + b);\n\t}\n\
    }\n"
  dependsOn:
  - template.cpp
  - Utility/constants.cpp
  - Utility/get_MOD.cpp
  - Utility/Scanner.cpp
  - Utility/Printer.cpp
  - Utility/Step.cpp
  - Utility/Ruby.cpp
  - Utility/functions.cpp
  - Utility/oj_local.cpp
  isVerificationFile: true
  path: test/template_no_Ruby.test.cpp
  requiredBy: []
  timestamp: '2021-04-18 18:33:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/template_no_Ruby.test.cpp
layout: document
redirect_from:
- /verify/test/template_no_Ruby.test.cpp
- /verify/test/template_no_Ruby.test.cpp.html
title: test/template_no_Ruby.test.cpp
---
