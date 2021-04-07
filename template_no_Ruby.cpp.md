---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/Printer.cpp
    title: Utility/Printer.cpp
  - icon: ':heavy_check_mark:'
    path: Utility/Scanner.cpp
    title: Utility/Scanner.cpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/get_MOD.cpp\"\nconstexpr long long get_MOD() {\n\
    #ifdef SET_MOD\n\treturn SET_MOD;\n#else\n\treturn 1000000007;\n#endif\n}\n#line\
    \ 3 \"Utility/constants.cpp\"\n#include <vector>\n#include <string>\n#include\
    \ <utility>\n#include <queue>\n\n#define rep(i, n) for (int i = 0; i < (n); ++i)\n\
    #define FOR(i, m, n) for (int i = (m); i < (n); ++i)\n#define rrep(i, n) for (int\
    \ i = (n)-1; i >= 0; --i)\n#define rfor(i, m, n) for (int i = (m); i >= (n); --i)\n\
    #define loop(n) rep(i##__COUNTER__, n)\n#define unless(c) if (!(c))\n#define ALL(x)\
    \ (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define range_it(a,\
    \ l, r) (a).begin() + (l), (a).begin() + (r)\n\nusing ll = long long;\nusing LD\
    \ = long double;\nusing VB = std::vector<bool>;\nusing VVB = std::vector<VB>;\n\
    using VI = std::vector<int>;\nusing VVI = std::vector<VI>;\nusing VL = std::vector<ll>;\n\
    using VVL = std::vector<VL>;\nusing VS = std::vector<std::string>;\nusing VD =\
    \ std::vector<LD>;\nusing PII = std::pair<int, int>;\nusing VP = std::vector<PII>;\n\
    using PLL = std::pair<ll, ll>;\nusing VPL = std::vector<PLL>;\ntemplate <class\
    \ T> using PQ = std::priority_queue<T>;\ntemplate <class T> using PQS = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\nconstexpr int inf = 1000000000;\nconstexpr\
    \ long long inf_ll = 1000000000000000000ll, MOD = get_MOD();\nconstexpr long double\
    \ PI = 3.14159265358979323846, EPS = 1e-12;\n#line 2 \"Utility/Scanner.cpp\"\n\
    #include <iostream>\n#line 6 \"Utility/Scanner.cpp\"\n#include <tuple>\n#include\
    \ <type_traits>\n\n#ifdef _WIN32\n#define getchar_unlocked _getchar_nolock\n#define\
    \ putchar_unlocked _putchar_nolock\n#define fwrite_unlocked fwrite\n#define fflush_unlocked\
    \ fflush\n#endif\nclass Scanner {\n\tstatic int gc() {\n\t\treturn getchar_unlocked();\n\
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
    \t}\n} out;\n#line 2 \"Utility/functions.cpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <cmath>\n#line 8 \"Utility/functions.cpp\"\n\ntemplate <class\
    \ T = long long> constexpr T TEN(std::size_t n) {\n\tT result = 1;\n\tfor (std::size_t\
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
    \ a.end(), v) - a.begin();\n}\ntemplate <class T, class U> int upper_index(const\
    \ T& a, const U& v) {\n\treturn std::upper_bound(a.begin(), a.end(), v) - a.begin();\n\
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
    \ std::rend(sizes));\n\treturn internal::make_vector<T, N>(s, init);\n}\n\nnamespace\
    \ lambda {\n\tauto char_to_int = [](char c) {\n\t\treturn c - '0';\n\t};\n\tauto\
    \ lower_to_int = [](char c) {\n\t\treturn c - 'a';\n\t};\n\tauto upper_to_int\
    \ = [](char c) {\n\t\treturn c - 'A';\n\t};\n\tauto int_to_char = [](int i) ->\
    \ char {\n\t\treturn '0' + i;\n\t};\n\tauto int_to_lower = [](int i) -> char {\n\
    \t\treturn 'a' + i;\n\t};\n\tauto int_to_upper = [](int i) -> char {\n\t\treturn\
    \ 'A' + i;\n\t};\n\tauto is_odd = [](auto n) {\n\t\treturn n % 2 == 1;\n\t};\n\
    \tauto is_even = [](auto n) {\n\t\treturn n % 2 == 0;\n\t};\n\tauto is_positive\
    \ = [](auto n) {\n\t\treturn n > 0;\n\t};\n\tauto is_negative = [](auto n) {\n\
    \t\treturn n < 0;\n\t};\n\tauto increment = [](auto n) {\n\t\treturn ++n;\n\t\
    };\n\tauto decrement = [](auto n) {\n\t\treturn --n;\n\t};\n\tauto self = [](const\
    \ auto& n) {\n\t\treturn n;\n\t};\n\tauto first = [](const auto& n) {\n\t\treturn\
    \ n.first;\n\t};\n\tauto second = [](const auto& n) {\n\t\treturn n.second;\n\t\
    };\n\ttemplate <class T> auto cast() {\n\t\treturn [](const auto& n) {\n\t\t\t\
    return static_cast<T>(n);\n\t\t};\n\t};\n\ttemplate <class T> auto equal_to(const\
    \ T& x) {\n\t\treturn [x](auto y) {\n\t\t\treturn x == y;\n\t\t};\n\t}\n\ttemplate\
    \ <std::size_t I> auto get() {\n\t\treturn [](const auto& n) {\n\t\t\treturn std::get<I>(n);\n\
    \t\t};\n\t}\n\ttemplate <class F> auto cmp(F&& f) {\n\t\treturn [f](const auto&\
    \ a, const auto& b) {\n\t\t\treturn f(a) < f(b);\n\t\t};\n\t}\n}  // namespace\
    \ lambda\n#line 6 \"template_no_Ruby.cpp\"\n#if __has_include(<library/dump.hpp>)\n\
    #include <library/dump.hpp>\n#define LOCAL\n#else\n#define dump(...) ((void)0)\n\
    #define dump2(...) ((void)0)\n#endif\n#line 2 \"Utility/oj_local.cpp\"\ntemplate\
    \ <class T> constexpr T oj_local(const T& oj, const T& local) {\n#ifndef LOCAL\n\
    \treturn oj;\n#else\n\treturn local;\n#endif\n}\n#line 14 \"template_no_Ruby.cpp\"\
    \n#include <bits/stdc++.h>\n"
  code: '#pragma once

    #include "./Utility/constants.cpp"

    #include "./Utility/Scanner.cpp"

    #include "./Utility/Printer.cpp"

    #include "./Utility/functions.cpp"

    #if __has_include(<library/dump.hpp>)

    #include <library/dump.hpp>

    #define LOCAL

    #else

    #define dump(...) ((void)0)

    #define dump2(...) ((void)0)

    #endif

    #include "./Utility/oj_local.cpp"

    #include <bits/stdc++.h>

    '
  dependsOn:
  - Utility/constants.cpp
  - Utility/get_MOD.cpp
  - Utility/Scanner.cpp
  - Utility/Printer.cpp
  - Utility/functions.cpp
  - Utility/oj_local.cpp
  isVerificationFile: false
  path: template_no_Ruby.cpp
  requiredBy: []
  timestamp: '2021-04-02 18:59:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template_no_Ruby.cpp
layout: document
redirect_from:
- /library/template_no_Ruby.cpp
- /library/template_no_Ruby.cpp.html
title: template_no_Ruby.cpp
---
