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
    path: template/Ruby.cpp
    title: template/Ruby.cpp
  - icon: ':warning:'
    path: template/Step.cpp
    title: template/Step.cpp
  - icon: ':warning:'
    path: template/constants.cpp
    title: template/constants.cpp
  - icon: ':warning:'
    path: template/functions.cpp
    title: template/functions.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 6 \"template/constants.cpp\"\nusing namespace std;\n\n#define rep(i, n) for\
    \ (int i = 0; i < (n); ++i)\n#define FOR(i, m, n) for (int i = (m); i < (n); ++i)\n\
    #define rrep(i, n) for (int i = (n)-1; i >= 0; --i)\n#define rfor(i, m, n) for\
    \ (int i = (m); i >= (n); --i)\n#define unless(c) if (!(c))\n#define all(x) (x).begin(),\
    \ (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define range_it(a, l,\
    \ r) (a).begin() + (l), (a).begin() + (r)\n\nusing namespace std;\nusing ll =\
    \ long long;\nusing LD = long double;\nusing VB = vector<bool>;\nusing VVB = vector<VB>;\n\
    using VI = vector<int>;\nusing VVI = vector<VI>;\nusing VL = vector<ll>;\nusing\
    \ VVL = vector<VL>;\nusing VS = vector<string>;\nusing VD = vector<LD>;\nusing\
    \ PII = pair<int, int>;\nusing VP = vector<PII>;\nusing PLL = pair<ll, ll>;\n\
    using VPL = vector<PLL>;\ntemplate <class T> using PQ = priority_queue<T>;\ntemplate\
    \ <class T> using PQS = priority_queue<T, vector<T>, greater<T>>;\nconstexpr int\
    \ inf = 1e9;\nconstexpr long long inf_ll = 1e18, MOD = 1000000007;\nconstexpr\
    \ long double PI = 3.14159265358979323846, EPS = 1e-12;\n#line 7 \"template/Input.cpp\"\
    \nusing namespace std;\n\n#ifdef _WIN32\n#define getchar_unlocked _getchar_nolock\n\
    #define putchar_unlocked _putchar_nolock\n#define fwrite_unlocked fwrite\n#define\
    \ fflush_unlocked fflush\n#endif\nclass Input {\n\tstatic int gc() {\n\t\treturn\
    \ getchar_unlocked();\n\t}\n\ttemplate <class T> static void i(T& v) {\n\t\tcin\
    \ >> v;\n\t}\n\tstatic void i(char& v) {\n\t\twhile (isspace(v = gc()))\n\t\t\t\
    ;\n\t}\n\tstatic void i(bool& v) {\n\t\tv = in<char>() != '0';\n\t}\n\tstatic\
    \ void i(string& v) {\n\t\tv.clear();\n\t\tchar c;\n\t\tfor (i(c); !isspace(c);\
    \ c = gc())\n\t\t\tv += c;\n\t}\n\tstatic void i(int& v) {\n\t\tbool neg = false;\n\
    \t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\
    \t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c); c = gc())\n\t\t\tv = v * 10 + (c\
    \ - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void i(long long& v) {\n\t\tbool\
    \ neg = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\t\
    neg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c); c = gc())\n\t\t\t\
    v = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void i(double& v)\
    \ {\n\t\tdouble dp = 1;\n\t\tbool neg = false, adp = false;\n\t\tv = 0;\n\t\t\
    char c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\
    \t}\n\t\tfor (; isdigit(c) || c == '.'; c = gc()) {\n\t\t\tif (c == '.')\n\t\t\
    \t\tadp = true;\n\t\t\telse if (adp)\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\
    \t\telse\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t}\n\t\tif (neg) v = -v;\n\t}\n\t\
    static void i(long double& v) {\n\t\tlong double dp = 1;\n\t\tbool neg = false,\
    \ adp = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\t\
    neg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c) || c == '.'; c = gc())\
    \ {\n\t\t\tif (c == '.')\n\t\t\t\tadp = true;\n\t\t\telse if (adp)\n\t\t\t\tv\
    \ += (c - '0') * (dp *= 0.1);\n\t\t\telse\n\t\t\t\tv = v * 10 + (c - '0');\n\t\
    \t}\n\t\tif (neg) v = -v;\n\t}\n\ttemplate <class T, class U> static void i(pair<T,\
    \ U>& v) {\n\t\ti(v.first);\n\t\ti(v.second);\n\t}\n\ttemplate <class T> static\
    \ void i(vector<T>& v) {\n\t\tfor (auto& e : v)\n\t\t\ti(e);\n\t}\n\ttemplate\
    \ <size_t N = 0, class T> static void input_tuple(T& v) {\n\t\tif constexpr (N\
    \ < tuple_size_v<T>) {\n\t\t\ti(get<N>(v));\n\t\t\tinput_tuple<N + 1>(v);\n\t\t\
    }\n\t}\n\ttemplate <class... T> static void i(tuple<T...>& v) {\n\t\tinput_tuple(v);\n\
    \t}\n\tstruct InputV {\n\t\tint n, m;\n\t\tInputV(int _n) : n(_n), m(0) {}\n\t\
    \tInputV(const pair<int, int>& nm) : n(nm.first), m(nm.second) {}\n\t\ttemplate\
    \ <class T> operator vector<T>() {\n\t\t\tvector<T> v(n);\n\t\t\ti(v);\n\t\t\t\
    return v;\n\t\t}\n\t\ttemplate <class T> operator vector<vector<T>>() {\n\t\t\t\
    vector<vector<T>> v(n, vector<T>(m));\n\t\t\ti(v);\n\t\t\treturn v;\n\t\t}\n\t\
    };\n\npublic:\n\tstatic string read_line() {\n\t\tstring v;\n\t\tchar c;\n\t\t\
    for (i(c); c != '\\n' && c != '\\0'; c = gc())\n\t\t\tv += c;\n\t\treturn v;\n\
    \t}\n\ttemplate <class T> static T in() {\n\t\tT v;\n\t\ti(v);\n\t\treturn v;\n\
    \t}\n\ttemplate <class T> operator T() const {\n\t\treturn in<T>();\n\t}\n\tint\
    \ operator--(int) const {\n\t\treturn in<int>() - 1;\n\t}\n\tInputV operator[](int\
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
    #line 6 \"template/Output.cpp\"\n#include <charconv>\n#line 9 \"template/Output.cpp\"\
    \nusing namespace std;\n\nstruct BoolStr {\n\tconst char *t, *f;\n\tBoolStr(const\
    \ char* _t, const char* _f) : t(_t), f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"\
    yes\", \"no\"), YES(\"YES\", \"NO\"), Int(\"1\", \"0\");\nstruct DivStr {\n\t\
    const char *d, *l;\n\tDivStr(const char* _d, const char* _l) : d(_d), l(_l) {}\n\
    } spc(\" \", \"\\n\"), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\\n\"), comma(\"\
    ,\", \"\\n\"), no_endl(\" \", \"\");\nclass Output {\n\tBoolStr B{Yes};\n\tDivStr\
    \ D{spc};\n\npublic:\n\tvoid put(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto\
    \ [ptr, e] = to_chars(begin(buf), end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf,\
    \ sizeof(char), ptr - buf, stdout);\n\t\t} else {\n\t\t\tassert(false);\n\t\t\
    }\n\t}\n\tvoid put(long long v) const {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr,\
    \ e] = to_chars(begin(buf), end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char),\
    \ ptr - buf, stdout);\n\t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid\
    \ put(bool v) const {\n\t\tput(v ? B.t : B.f);\n\t}\n\tvoid put(char v) const\
    \ {\n\t\tputchar_unlocked(v);\n\t}\n\tvoid put(const char* v) const {\n\t\tfwrite_unlocked(v,\
    \ 1, strlen(v), stdout);\n\t}\n\tvoid put(double v) const {\n\t\tprintf(\"%.20f\"\
    , v);\n\t}\n\tvoid put(long double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t\
    }\n\ttemplate <class T> void put(const T& v) const {\n\t\tcout << v;\n\t}\n\t\
    template <class T, class U> void put(const pair<T, U>& v) const {\n\t\tput(v.first);\n\
    \t\tput(D.d);\n\t\tput(v.second);\n\t}\n\ttemplate<class It> void put_range(const\
    \ It& begin ,const It& end) const {\n\t\tfor (It i = begin; i != end; ++i) {\n\
    \t\t\tif (i != begin) put(D.d);\n\t\t\tput(*i);\n\t\t}\n\t}\n\ttemplate <class\
    \ T> void put(const vector<T>& v) const {\n\t\tput_range(v.begin(), v.end());\n\
    \t}\n\ttemplate <class T, size_t N> void put(const array<T, N>& v) const {\n\t\
    \tput_range(v.begin(), v.end());\n\t}\n\ttemplate <class T> void put(const vector<vector<T>>&\
    \ v) const {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tif (i) put(D.l);\n\
    \t\t\tput(v[i]);\n\t\t}\n\t}\n\n\tOutput() = default;\n\tOutput(const BoolStr&\
    \ _boolstr, const DivStr& _divstr) : B(_boolstr), D(_divstr) {}\n\tOutput& operator()()\
    \ {\n\t\tput(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class H> Output& operator()(H&&\
    \ h) {\n\t\tput(h);\n\t\tput(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class\
    \ H, class... T> Output& operator()(H&& h, T&&... t) {\n\t\tput(h);\n\t\tput(D.d);\n\
    \t\treturn operator()(forward<T>(t)...);\n\t}\n\ttemplate <class It> Output& range(const\
    \ It& begin, const It& end) {\n\t\tput_range(begin, end);\n\t\tput(D.l);\n\t\t\
    return *this;\n\t}\n\ttemplate <class T> Output& range(const T& a) {\n\t\trange(a.begin(),\
    \ a.end());\n\t\treturn *this;\n\t}\n\ttemplate <class... T> void exit(T&&...\
    \ t) {\n\t\toperator()(forward<T>(t)...);\n\t\tstd::exit(EXIT_SUCCESS);\n\t}\n\
    \tOutput& flush() {\n\t\tfflush_unlocked(stdout);\n\t\treturn *this;\n\t}\n\t\
    Output& set(const BoolStr& b) {\n\t\tB = b;\n\t\treturn *this;\n\t}\n\tOutput&\
    \ set(const DivStr& d) {\n\t\tD = d;\n\t\treturn *this;\n\t}\n\tOutput& set(const\
    \ char* t, const char* f) {\n\t\tB = BoolStr(t, f);\n\t\treturn *this;\n\t}\n\
    } out;\n#line 3 \"template/Step.cpp\"\nusing namespace std;\n\ntemplate <class\
    \ T> struct Step {\n\tclass It {\n\t\tT a, b, c;\n\n\tpublic:\n\t\tconstexpr It()\
    \ : a(T()), b(T()), c(T()) {}\n\t\tconstexpr It(T _b, T _c, T _s) : a(_b), b(_c),\
    \ c(_s) {}\n\t\tconstexpr It& operator++() {\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\t\
    return *this;\n\t\t}\n\t\tconstexpr It operator++(int) {\n\t\t\tIt tmp = *this;\n\
    \t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn tmp;\n\t\t}\n\t\tconstexpr const T& operator*()\
    \ const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr const T* operator->() const {\n\
    \t\t\treturn &a;\n\t\t}\n\t\tconstexpr bool operator==(const It& i) const {\n\t\
    \t\treturn b == i.b;\n\t\t}\n\t\tconstexpr bool operator!=(const It& i) const\
    \ {\n\t\t\treturn !(b == i.b);\n\t\t}\n\t\tconstexpr T start() const {\n\t\t\t\
    return a;\n\t\t}\n\t\tconstexpr T size() const {\n\t\t\treturn b;\n\t\t}\n\t\t\
    constexpr T step() const {\n\t\t\treturn c;\n\t\t}\n\t};\n\tconstexpr Step(T b,\
    \ T c, T s) : be(b, c, s) {}\n\tconstexpr It begin() const {\n\t\treturn be;\n\
    \t}\n\tconstexpr It end() const {\n\t\treturn en;\n\t}\n\tconstexpr T start()\
    \ const {\n\t\treturn be.start();\n\t}\n\tconstexpr T size() const {\n\t\treturn\
    \ be.size();\n\t}\n\tconstexpr T step() const {\n\t\treturn be.step();\n\t}\n\t\
    constexpr T sum() const {\n\t\treturn start() * size() + step() * (size() * (size()\
    \ - 1) / 2);\n\t}\n\toperator vector<T>() const {\n\t\treturn to_a();\n\t}\n\t\
    auto to_a() const {\n\t\tvector<T> res;\n\t\tres.reserve(size());\n\t\tfor (auto\
    \ i : *this) {\n\t\t\tres.push_back(i);\n\t\t}\n\t\treturn res;\n\t}\n\tusing\
    \ value_type = T;\n\tusing iterator = It;\n\nprivate:\n\tIt be, en;\n};\ntemplate\
    \ <class T> constexpr auto step(T a) {\n\treturn Step<T>(0, a, 1);\n}\ntemplate\
    \ <class T> constexpr auto step(T a, T b) {\n\treturn Step<T>(a, b - a, 1);\n\
    }\ntemplate <class T> constexpr auto step(T a, T b, T c) {\n\treturn Step<T>(a,\
    \ a < b ? (b - a - 1) / c + 1 : 0, c);\n}\n#line 8 \"template/Ruby.cpp\"\nusing\
    \ namespace std;\n\ntemplate <class F> struct Callable {\n\tF func;\n\tCallable(const\
    \ F& f) : func(f) {}\n};\ntemplate <class T, class F> auto operator|(const T&\
    \ v, const Callable<F>& c) {\n\treturn c.func(v);\n}\n\nstruct Sort_impl {\n\t\
    template <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\
    \t\t\tsort(begin(v), end(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class\
    \ T> friend auto operator|(T v, [[maybe_unused]] const Sort_impl& c) {\n\t\tsort(begin(v),\
    \ end(v));\n\t\treturn v;\n\t}\n} Sort;\nstruct SortBy_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tsort(begin(v),\
    \ end(v), [&](const auto& i, const auto& j) {\n\t\t\t\treturn f(i) < f(j);\n\t\
    \t\t});\n\t\t\treturn v;\n\t\t});\n\t}\n} SortBy;\nstruct RSort_impl {\n\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    sort(rbegin(v), rend(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class\
    \ T> friend auto operator|(T v, [[maybe_unused]] const RSort_impl& c) {\n\t\t\
    sort(rbegin(v), rend(v));\n\t\treturn v;\n\t}\n} RSort;\nstruct RSortBy_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tsort(begin(v), end(v), [&](const auto& i, const auto& j) {\n\t\t\t\t\
    return f(i) > f(j);\n\t\t\t});\n\t\t\treturn v;\n\t\t});\n\t}\n} RSortBy;\nstruct\
    \ Reverse_impl {\n\ttemplate <class T> friend auto operator|(T v, const Reverse_impl&\
    \ c) {\n\t\treverse(begin(v), end(v));\n\t\treturn v;\n\t}\n} Reverse;\nstruct\
    \ Unique_impl {\n\ttemplate <class T> friend auto operator|(T v, const Unique_impl&\
    \ c) {\n\t\tv.erase(unique(begin(v), end(v), end(v)));\n\t\treturn v;\n\t}\n}\
    \ Unique;\nstruct Uniq_impl {\n\ttemplate <class T> friend auto operator|(T v,\
    \ const Uniq_impl& c) {\n\t\tsort(begin(v), end(v));\n\t\tv.erase(unique(begin(v),\
    \ end(v)), end(v));\n\t\treturn v;\n\t}\n} Uniq;\nstruct Rotate_impl {\n\tauto\
    \ operator()(int&& left) {\n\t\treturn Callable([&](auto v) {\n\t\t\tint s = static_cast<int>(size(v));\n\
    \t\t\tassert(-s <= left && left <= s);\n\t\t\tif (0 <= left) {\n\t\t\t\trotate(begin(v),\
    \ begin(v) + left, end(v));\n\t\t\t} else {\n\t\t\t\trotate(begin(v), end(v) +\
    \ left, end(v));\n\t\t\t}\n\t\t\treturn v;\n\t\t});\n\t}\n} Rotate;\nstruct Max_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\treturn *max_element(begin(v), end(v), f);\n\t\t});\n\t}\n\ttemplate\
    \ <class T> friend auto operator|(T v, const Max_impl& c) {\n\t\treturn *max_element(begin(v),\
    \ end(v));\n\t}\n} Max;\nstruct Min_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) {\n\t\t\treturn *min_element(begin(v),\
    \ end(v), f);\n\t\t});\n\t}\n\ttemplate <class T> friend auto operator|(T v, const\
    \ Min_impl& c) {\n\t\treturn *min_element(begin(v), end(v));\n\t}\n} Min;\nstruct\
    \ MaxPos_impl {\n\ttemplate <class T> friend auto operator|(T v, const MaxPos_impl&\
    \ c) {\n\t\treturn max_element(begin(v), end(v)) - begin(v);\n\t}\n} MaxPos;\n\
    struct MinPos_impl {\n\ttemplate <class T> friend auto operator|(T v, const MinPos_impl&\
    \ c) {\n\t\treturn min_element(begin(v), end(v)) - begin(v);\n\t}\n} MinPos;\n\
    struct MaxBy_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tauto max_it = begin(v);\n\t\t\tauto max_val =\
    \ f(*max_it);\n\t\t\tfor (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\
    \t\tif (auto val = f(*it); max_val < val) {\n\t\t\t\t\tmax_it = it;\n\t\t\t\t\t\
    max_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn *max_it;\n\t\t});\n\t}\n} MaxBy;\n\
    struct MinBy_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tauto min_it = begin(v);\n\t\t\tauto min_val =\
    \ f(*min_it);\n\t\t\tfor (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\
    \t\tif (auto val = f(*it); min_val > val) {\n\t\t\t\t\tmin_it = it;\n\t\t\t\t\t\
    min_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn *min_it;\n\t\t});\n\t}\n} MinBy;\n\
    struct MaxOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tauto max_val = f(*begin(v));\n\t\t\tfor (auto\
    \ it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); max_val\
    \ < val) {\n\t\t\t\t\tmax_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn max_val;\n\
    \t\t});\n\t}\n} MaxOf;\nstruct MinOf_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto min_val = f(*begin(v));\n\
    \t\t\tfor (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val\
    \ = f(*it); min_val > val) {\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\treturn min_val;\n\t\t});\n\t}\n} MinOf;\nstruct Count_impl {\n\ttemplate <class\
    \ V> auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    return count(begin(v), end(v), val);\n\t\t});\n\t}\n} Count;\nstruct CountIf_impl\
    \ {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\treturn count_if(begin(v), end(v), f);\n\t\t});\n\t}\n} CountIf;\n\
    struct Index_impl {\n\ttemplate <class V> auto operator()(const V& val) {\n\t\t\
    return Callable([&](auto v) -> optional<int> {\n\t\t\tauto res = find(begin(v),\
    \ end(v), val);\n\t\t\treturn res != end(v) ? optional(res - begin(v)) : nullopt;\n\
    \t\t});\n\t}\n} Index;\nstruct IndexIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) -> optional<int> {\n\t\t\tauto res\
    \ = find_if(begin(v), end(v), f);\n\t\t\treturn res != end(v) ? optional(res -\
    \ begin(v)) : nullopt;\n\t\t});\n\t}\n} IndexIf;\nstruct FindIf_impl {\n\ttemplate\
    \ <class F> auto operator()(const F& f) {\n\t\treturn Callable([&](auto v) ->\
    \ optional<typename decltype(v)::value_type> {\n\t\t\tauto res = find_if(begin(v),\
    \ end(v), f);\n\t\t\treturn res != end(v) ? optional(*res) : nullopt;\n\t\t});\n\
    \t}\n} FindIf;\nstruct Sum_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\treturn accumulate(next(begin(v)),\
    \ end(v), f(*begin(v)), [&](const auto& a, const auto& b) {\n\t\t\t\treturn a\
    \ + f(b);\n\t\t\t});\n\t\t});\n\t}\n\ttemplate <class T> friend auto operator|(T\
    \ v, const Sum_impl& c) {\n\t\treturn accumulate(begin(v), end(v), typename T::value_type{});\n\
    \t}\n} Sum;\nstruct Includes {\n\ttemplate <class V> auto operator()(const V&\
    \ val) {\n\t\treturn Callable([&](auto v) {\n\t\t\treturn find(begin(v), end(v),\
    \ val) != end(v);\n\t\t});\n\t}\n} Includes;\nstruct IncludesIf_impl {\n\ttemplate\
    \ <class F> auto operator()(const F& f) {\n\t\treturn Callable([&](auto v) {\n\
    \t\t\treturn find_if(begin(v), end(v), f) != end(v);\n\t\t});\n\t}\n} IncludesIf;\n\
    struct RemoveIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\
    \treturn Callable([&](auto v) {\n\t\t\tv.erase(remove_if(begin(v), end(v), f),\
    \ end(v));\n\t\t\treturn v;\n\t\t});\n\t}\n} RemoveIf;\nstruct Each_impl {\n\t\
    template <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\
    \t\t\tfor (const auto& i : v) {\n\t\t\t\tf(i);\n\t\t\t}\n\t\t});\n\t}\n} Each;\n\
    struct Select_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tusing value_type = typename decltype(v)::value_type;\n\
    \t\t\tvector<value_type> res;\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i))\
    \ res.push_back(i);\n\t\t\t}\n\t\t\treturn res;\n\t\t});\n\t}\n} Select;\nstruct\
    \ Map_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tusing result_type = invoke_result_t<F, typename decltype(v)::value_type>;\n\
    \t\t\tvector<result_type> res;\n\t\t\tres.reserve(size(v));\n\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\tres.push_back(f(i));\n\t\t\t}\n\t\t\treturn res;\n\t\
    \t});\n\t}\n} Map;\nstruct Indexed_impl {\n\ttemplate <class T> friend auto operator|(const\
    \ T& v, Indexed_impl& c) {\n\t\tusing value_type = typename T::value_type;\n\t\
    \tvector<pair<value_type, int>> res;\n\t\tres.reserve(size(v));\n\t\tint index\
    \ = 0;\n\t\tfor (const auto& i : v) {\n\t\t\tres.emplace_back(i, index++);\n\t\
    \t}\n\t\treturn res;\n\t}\n} Indexed;\nstruct AllOf_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\tif (!f(i)) return false;\n\t\t\t}\n\t\t\treturn true;\n\
    \t\t});\n\t}\n} AllOf;\nstruct AnyOf_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\
    \t\t\tif (f(i)) return true;\n\t\t\t}\n\t\t\treturn false;\n\t\t});\n\t}\n} AnyOf;\n\
    struct NoneOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return\
    \ false;\n\t\t\t}\n\t\t\treturn true;\n\t\t});\n\t}\n} NoneOf;\n\nstruct Tally_impl\
    \ {\n\ttemplate <class F> auto operator()(size_t max_val) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tvector<size_t> res(max_val);\n\t\t\tfor (const auto& i : v) {\n\t\
    \t\t\tres[static_cast<size_t>(i)]++;\n\t\t\t}\n\t\t\treturn res;\n\t\t});\n\t\
    }\n\ttemplate <class T, class value_type = typename T::value_type> friend auto\
    \ operator|(const T& v, Tally_impl& c) {\n\t\tmap<value_type, size_t> res;\n\t\
    \tfor (const auto& i : v) {\n\t\t\tres[i]++;\n\t\t}\n\t\treturn res;\n\t}\n} Tally;\n\
    \ntemplate <class T> auto operator*(const vector<T>& a, size_t n) {\n\tT res;\n\
    \tfor (size_t i = 0; i < n; ++i) {\n\t\tres.insert(res.end(), a.begin(), a.end());\n\
    \t}\n\treturn res;\n}\nauto operator*(string a, size_t n) {\n\tstring res;\n\t\
    for (size_t i = 0; i < n; ++i) {\n\t\tres += a;\n\t}\n\treturn res;\n}\ntemplate\
    \ <class T, class U> auto& operator<<(vector<T>& a, const U& b) {\n\ta.insert(a.end(),\
    \ all(b));\n\treturn a;\n}\ntemplate <class T> auto& operator<<(string& a, const\
    \ T& b) {\n\ta.insert(a.end(), all(b));\n\treturn a;\n}\ntemplate <class T, class\
    \ U> auto operator+(vector<T> a, const U& b) {\n\ta << b;\n\treturn a;\n}\ntemplate\
    \ <class T> auto operator+(string a, const T& b) {\n\ta << b;\n\treturn a;\n}\n\
    #line 6 \"template/functions.cpp\"\nusing namespace std;\n\ntemplate <class T>\
    \ int sz(const T& v) {\n\treturn v.size();\n}\ntemplate <class T, class U> int\
    \ Lower(const T& a, const U& v) {\n\treturn lower_bound(all(a), v) - a.begin();\n\
    }\ntemplate <class T, class U> int Upper(const T& a, const U& v) {\n\treturn upper_bound(all(a),\
    \ v) - a.begin();\n}\ntemplate <class T> auto Slice(const T& v, size_t i, size_t\
    \ len) {\n\treturn i < v.size() ? T(v.begin() + i, v.begin() + min(i + len, v.size()))\
    \ : T();\n}\ntemplate <class T> T Ceil(T n, T m) {\n\treturn (n + m - 1) / m;\n\
    }\ntemplate <class T> T Ceil2(T n, T m) {\n\treturn Ceil(n, m) * m;\n}\ntemplate\
    \ <class T> T Tri(T n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n\
    }\ntemplate <class T> T nC2(T n) {\n\treturn (n & 1) ? (n - 1) / 2 * n : n / 2\
    \ * (n - 1);\n}\ntemplate <class T> T Mid(const T& l, const T& r) {\n\treturn\
    \ l + (r - l) / 2;\n}\ntemplate <class T> bool chmax(T& a, const T& b) {\n\tif\
    \ (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class\
    \ T> bool chmin(T& a, const T& b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\
    \t}\n\treturn false;\n}\ntemplate <class T> bool inRange(const T& v, const T&\
    \ min, const T& max) {\n\treturn min <= v && v < max;\n}\ntemplate <class T> bool\
    \ isSquere(T n) {\n\tT s = sqrt(n);\n\treturn s * s == n || (s + 1) * (s + 1)\
    \ == n;\n}\ntemplate <class T = long long> T BIT(int b) {\n\treturn T(1) << b;\n\
    }\ntemplate <class T, class U = typename T::value_type> U Gcdv(const T& v) {\n\
    \treturn accumulate(next(v.begin()), v.end(), U(*v.begin()), gcd<U, U>);\n}\n\
    template <class T, class U = typename T::value_type> U Lcmv(const T& v) {\n\t\
    return accumulate(next(v.begin()), v.end(), U(*v.begin()), lcm<U, U>);\n}\ntemplate\
    \ <class T> T Pow(T a, T n) {\n\tT r = 1;\n\twhile (n > 0) {\n\t\tif (n & 1) r\
    \ *= a;\n\t\ta *= a;\n\t\tn /= 2;\n\t}\n\treturn r;\n}\ntemplate <class T> T Powmod(T\
    \ a, T n, T m = MOD) {\n\tT r = 1;\n\twhile (n > 0) {\n\t\tif (n & 1)\n\t\t\t\
    r = r * a % m, n--;\n\t\telse\n\t\t\ta = a * a % m, n /= 2;\n\t}\n\treturn r;\n\
    }\nnamespace internal {\n\ttemplate <class T, size_t N> auto make_vector(vector<int>&\
    \ sizes, const T& init) {\n\t\tif constexpr (N == 1) {\n\t\t\treturn vector(sizes[0],\
    \ init);\n\t\t} else {\n\t\t\tint size = sizes[N - 1];\n\t\t\tsizes.pop_back();\n\
    \t\t\treturn vector(size, make_vector<T, N - 1>(sizes, init));\n\t\t}\n\t}\n}\
    \  // namespace internal\ntemplate <class T, size_t N> auto make_vector(const\
    \ int (&sizes)[N], const T& init = T()) {\n\tvector s(rbegin(sizes), rend(sizes));\n\
    \treturn internal::make_vector<T, N>(s, init);\n}\n#line 9 \"template/template.cpp\"\
    \n#if __has_include(<library/dump.hpp>)\n#include <library/dump.hpp>\n#define\
    \ LOCAL\n#else\n#define dump(...) ((void)0)\n#endif\n\ntemplate <class T> constexpr\
    \ T oj_local(const T& oj, const T& local) {\n#ifndef LOCAL\n\treturn oj;\n#else\n\
    \treturn local;\n#endif\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"./constants.cpp\"\n#include\
    \ \"./Input.cpp\"\n#include \"./Output.cpp\"\n#include \"./Step.cpp\"\n#include\
    \ \"./Ruby.cpp\"\n#include \"./functions.cpp\"\n#if __has_include(<library/dump.hpp>)\n\
    #include <library/dump.hpp>\n#define LOCAL\n#else\n#define dump(...) ((void)0)\n\
    #endif\n\ntemplate <class T> constexpr T oj_local(const T& oj, const T& local)\
    \ {\n#ifndef LOCAL\n\treturn oj;\n#else\n\treturn local;\n#endif\n}\n"
  dependsOn:
  - template/constants.cpp
  - template/Input.cpp
  - template/Output.cpp
  - template/Step.cpp
  - template/Ruby.cpp
  - template/functions.cpp
  isVerificationFile: false
  path: template/template.cpp
  requiredBy: []
  timestamp: '2020-11-15 09:47:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: template/template.cpp
---
