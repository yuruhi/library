---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: dump.hpp
    title: dump.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template17.cpp: line 845: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// description : C++17\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n#include\
    \ <bits/stdc++.h>\n#pragma region template\n#define rep(i, n) for (int i = 0;\
    \ i < (n); ++i)\n#define FOR(i, m, n) for (int i = (m); i < (n); ++i)\n#define\
    \ rrep(i, n) for (int i = (n)-1; i >= 0; --i)\n#define rfor(i, m, n) for (int\
    \ i = (m); i >= (n); --i)\n#define unless(c) if (!(c))\n#define sz(x) ((int)(x).size())\n\
    #define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n\
    #define range_it(a, l, r) (a).begin() + (l), (a).begin() + (r)\n\nusing namespace\
    \ std;\nusing ll = long long;\nusing LD = long double;\nusing VB = vector<bool>;\n\
    using VVB = vector<VB>;\nusing VI = vector<int>;\nusing VVI = vector<VI>;\nusing\
    \ VL = vector<ll>;\nusing VVL = vector<VL>;\nusing VS = vector<string>;\nusing\
    \ VD = vector<LD>;\nusing PII = pair<int, int>;\nusing VP = vector<PII>;\nusing\
    \ PLL = pair<ll, ll>;\nusing VPL = vector<PLL>;\ntemplate <class T> using PQ =\
    \ priority_queue<T>;\ntemplate <class T> using PQS = priority_queue<T, vector<T>,\
    \ greater<T>>;\nconstexpr int inf = 1e9;\nconstexpr long long inf_ll = 1e18, MOD\
    \ = 1000000007;\nconstexpr long double PI = 3.14159265358979323846, EPS = 1e-12;\n\
    \n// --- input --- //\n#ifdef _WIN32\n#define getchar_unlocked _getchar_nolock\n\
    #define putchar_unlocked _putchar_nolock\n#define fwrite_unlocked fwrite\n#define\
    \ fflush_unlocked fflush\n#endif\nclass Input {\n\tstatic int gc() {\n\t\treturn\
    \ getchar_unlocked();\n\t}\n\ttemplate <class T> static void i(T& v) {\n\t\tcin\
    \ >> v;\n\t}\n\tstatic void i(char& v) {\n\t\twhile (isspace(v = gc()))\n\t\t\t\
    ;\n\t}\n\tstatic void i(bool& v) {\n\t\tv = in<char>() != '0';\n\t}\n\tstatic\
    \ void i(string& v) {\n\t\tv.clear();\n\t\tchar c;\n\t\tfor (i(c); !isspace(c);\
    \ c = gc()) v += c;\n\t}\n\tstatic void i(int& v) {\n\t\tbool neg = false;\n\t\
    \tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\
    \tc = gc();\n\t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\
    \t\tif (neg) v = -v;\n\t}\n\tstatic void i(long long& v) {\n\t\tbool neg = false;\n\
    \t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\
    \t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\
    \t\tif (neg) v = -v;\n\t}\n\tstatic void i(double& v) {\n\t\tdouble dp = 1;\n\t\
    \tbool neg = false, adp = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c\
    \ == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.')\n\t\t\t\tadp = true;\n\t\t\telse\
    \ if (adp)\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\telse\n\t\t\t\tv = v *\
    \ 10 + (c - '0');\n\t\t}\n\t\tif (neg) v = -v;\n\t}\n\tstatic void i(long double&\
    \ v) {\n\t\tlong double dp = 1;\n\t\tbool neg = false, adp = false;\n\t\tv = 0;\n\
    \t\tchar c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\
    \t\t}\n\t\tfor (; isdigit(c) || c == '.'; c = gc()) {\n\t\t\tif (c == '.')\n\t\
    \t\t\tadp = true;\n\t\t\telse if (adp)\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\
    \t\t\telse\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t}\n\t\tif (neg) v = -v;\n\t}\n\
    \ttemplate <class T, class U> static void i(pair<T, U>& v) {\n\t\ti(v.first);\n\
    \t\ti(v.second);\n\t}\n\ttemplate <class T> static void i(vector<T>& v) {\n\t\t\
    for (auto& e : v) i(e);\n\t}\n\ttemplate <size_t N = 0, class T> static void input_tuple(T&\
    \ v) {\n\t\tif constexpr (N < tuple_size_v<T>) {\n\t\t\ti(get<N>(v));\n\t\t\t\
    input_tuple<N + 1>(v);\n\t\t}\n\t}\n\ttemplate <class... T> static void i(tuple<T...>&\
    \ v) {\n\t\tinput_tuple(v);\n\t}\n\tstruct InputV {\n\t\tint n, m;\n\t\tInputV(int\
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
    \ __VA_ARGS__)\n#define ins(...) inputs(string, __VA_ARGS__)\n\n// --- output\
    \ --- //\nstruct BoolStr {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const\
    \ char* _f) : t(_t), f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"\
    YES\", \"NO\"), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\t\
    DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"\
    ), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"),\n\
    \    no_endl(\" \", \"\");\nclass Output {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\
    \tvoid p(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid p(long long v) const {\n\
    \t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf), v);\
    \ e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\t\t} else\
    \ {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid p(bool v) const {\n\t\tp(v ? B.t\
    \ : B.f);\n\t}\n\tvoid p(char v) const {\n\t\tputchar_unlocked(v);\n\t}\n\tvoid\
    \ p(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v), stdout);\n\t\
    }\n\tvoid p(double v) const {\n\t\tprintf(\"%.20f\", v);\n\t}\n\tvoid p(long double\
    \ v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t}\n\ttemplate <class T> void p(const\
    \ T& v) const {\n\t\tcout << v;\n\t}\n\ttemplate <class T, class U> void p(const\
    \ pair<T, U>& v) const {\n\t\tp(v.first);\n\t\tp(D.d);\n\t\tp(v.second);\n\t}\n\
    \ttemplate <class T> void p(const vector<T>& v) const {\n\t\trep(i, sz(v)) {\n\
    \t\t\tif (i) p(D.d);\n\t\t\tp(v[i]);\n\t\t}\n\t}\n\ttemplate <class T> void p(const\
    \ vector<vector<T>>& v) const {\n\t\trep(i, sz(v)) {\n\t\t\tif (i) p(D.l);\n\t\
    \t\tp(v[i]);\n\t\t}\n\t}\n\npublic:\n\tOutput& operator()() {\n\t\tp(D.l);\n\t\
    \treturn *this;\n\t}\n\ttemplate <class H> Output& operator()(H&& h) {\n\t\tp(h);\n\
    \t\tp(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class H, class... T> Output&\
    \ operator()(H&& h, T&&... t) {\n\t\tp(h);\n\t\tp(D.d);\n\t\treturn operator()(forward<T>(t)...);\n\
    \t}\n\ttemplate <class It> Output& range(const It& l, const It& r) {\n\t\tfor\
    \ (It i = l; i != r; i++) {\n\t\t\tif (i != l) p(D.d);\n\t\t\tp(*i);\n\t\t}\n\t\
    \tp(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class T> Output& range(const T&\
    \ a) {\n\t\trange(a.begin(), a.end());\n\t\treturn *this;\n\t}\n\ttemplate <class...\
    \ T> void exit(T&&... t) {\n\t\toperator()(forward<T>(t)...);\n\t\tstd::exit(EXIT_SUCCESS);\n\
    \t}\n\tOutput& flush() {\n\t\tfflush_unlocked(stdout);\n\t\treturn *this;\n\t\
    }\n\tOutput& set(const BoolStr& b) {\n\t\tB = b;\n\t\treturn *this;\n\t}\n\tOutput&\
    \ set(const DivStr& d) {\n\t\tD = d;\n\t\treturn *this;\n\t}\n\tOutput& set(const\
    \ char* t, const char* f) {\n\t\tB = BoolStr(t, f);\n\t\treturn *this;\n\t}\n\
    } out;\n\n// --- step --- //\ntemplate <class T> struct Step {\n\tclass It {\n\
    \t\tT a, b, c;\n\n\tpublic:\n\t\tconstexpr It() : a(T()), b(T()), c(T()) {}\n\t\
    \tconstexpr It(T _b, T _c, T _s) : a(_b), b(_c), c(_s) {}\n\t\tconstexpr It& operator++()\
    \ {\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr It operator++(int)\
    \ {\n\t\t\tIt tmp = *this;\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn tmp;\n\t\t\
    }\n\t\tconstexpr const T& operator*() const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr\
    \ const T* operator->() const {\n\t\t\treturn &a;\n\t\t}\n\t\tconstexpr bool operator==(const\
    \ It& i) const {\n\t\t\treturn b == i.b;\n\t\t}\n\t\tconstexpr bool operator!=(const\
    \ It& i) const {\n\t\t\treturn !(b == i.b);\n\t\t}\n\t\tconstexpr T start() const\
    \ {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr T size() const {\n\t\t\treturn b;\n\
    \t\t}\n\t\tconstexpr T step() const {\n\t\t\treturn c;\n\t\t}\n\t};\n\tconstexpr\
    \ Step(T b, T c, T s) : be(b, c, s) {}\n\tconstexpr It begin() const {\n\t\treturn\
    \ be;\n\t}\n\tconstexpr It end() const {\n\t\treturn en;\n\t}\n\tconstexpr T start()\
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
    \ a < b ? (b - a - 1) / c + 1 : 0, c);\n}\n\n// --- Ruby --- //\nnamespace Ruby\
    \ {\n\ttemplate <class F> struct Callable {\n\t\tF func;\n\t\tCallable(const F&\
    \ f) : func(f) {}\n\t};\n\ttemplate <class T, class F> auto operator|(const T&\
    \ v, const Callable<F>& c) {\n\t\treturn c.func(v);\n\t}\n\n\tstruct Sort_impl\
    \ {\n\t\ttemplate <class F> auto operator()(F&& f) {\n\t\t\treturn Callable([&](auto\
    \ v) {\n\t\t\t\tsort(begin(v), end(v), f);\n\t\t\t\treturn v;\n\t\t\t});\n\t\t\
    }\n\t\ttemplate <class T>\n\t\tfriend auto operator|(T v, [[maybe_unused]] const\
    \ Sort_impl& c) {\n\t\t\tsort(begin(v), end(v));\n\t\t\treturn v;\n\t\t}\n\t}\
    \ Sort;\n\tstruct SortBy_impl {\n\t\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\t\treturn Callable([&](auto v) {\n\t\t\t\tsort(begin(v), end(v),\n\t\t\
    \t\t     [&](const auto& i, const auto& j) { return f(i) < f(j); });\n\t\t\t\t\
    return v;\n\t\t\t});\n\t\t}\n\t} SortBy;\n\tstruct RSort_impl {\n\t\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\t\treturn Callable([&](auto v) {\n\t\t\
    \t\tsort(rbegin(v), rend(v), f);\n\t\t\t\treturn v;\n\t\t\t});\n\t\t}\n\t\ttemplate\
    \ <class T>\n\t\tfriend auto operator|(T v, [[maybe_unused]] const RSort_impl&\
    \ c) {\n\t\t\tsort(rbegin(v), rend(v));\n\t\t\treturn v;\n\t\t}\n\t} RSort;\n\t\
    struct RSortBy_impl {\n\t\ttemplate <class F> auto operator()(F&& f) {\n\t\t\t\
    return Callable([&](auto v) {\n\t\t\t\tsort(begin(v), end(v),\n\t\t\t\t     [&](const\
    \ auto& i, const auto& j) { return f(i) > f(j); });\n\t\t\t\treturn v;\n\t\t\t\
    });\n\t\t}\n\t} RSortBy;\n\tstruct Reverse_impl {\n\t\ttemplate <class T> friend\
    \ auto operator|(T v, const Reverse_impl& c) {\n\t\t\treverse(begin(v), end(v));\n\
    \t\t\treturn v;\n\t\t}\n\t} Reverse;\n\tstruct Unique_impl {\n\t\ttemplate <class\
    \ T> friend auto operator|(T v, const Unique_impl& c) {\n\t\t\tv.erase(unique(begin(v),\
    \ end(v), end(v)));\n\t\t\treturn v;\n\t\t}\n\t} Unique;\n\tstruct Uniq_impl {\n\
    \t\ttemplate <class T> friend auto operator|(T v, const Uniq_impl& c) {\n\t\t\t\
    sort(begin(v), end(v));\n\t\t\tv.erase(unique(begin(v), end(v)), end(v));\n\t\t\
    \treturn v;\n\t\t}\n\t} Uniq;\n\tstruct Rotate_impl {\n\t\tauto operator()(int&&\
    \ left) {\n\t\t\treturn Callable([&](auto v) {\n\t\t\t\tint s = static_cast<int>(size(v));\n\
    \t\t\t\tassert(-s <= left && left <= s);\n\t\t\t\tif (0 <= left) {\n\t\t\t\t\t\
    rotate(begin(v), begin(v) + left, end(v));\n\t\t\t\t} else {\n\t\t\t\t\trotate(begin(v),\
    \ end(v) + left, end(v));\n\t\t\t\t}\n\t\t\t\treturn v;\n\t\t\t});\n\t\t}\n\t\
    } Rotate;\n\tstruct Max_impl {\n\t\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\t\treturn Callable([&](auto v) { return *max_element(begin(v), end(v),\
    \ f); });\n\t\t}\n\t\ttemplate <class T> friend auto operator|(T v, const Max_impl&\
    \ c) {\n\t\t\treturn *max_element(begin(v), end(v));\n\t\t}\n\t} Max;\n\tstruct\
    \ Min_impl {\n\t\ttemplate <class F> auto operator()(F&& f) {\n\t\t\treturn Callable([&](auto\
    \ v) { return *min_element(begin(v), end(v), f); });\n\t\t}\n\t\ttemplate <class\
    \ T> friend auto operator|(T v, const Min_impl& c) {\n\t\t\treturn *min_element(begin(v),\
    \ end(v));\n\t\t}\n\t} Min;\n\tstruct MaxPos_impl {\n\t\ttemplate <class T> friend\
    \ auto operator|(T v, const MaxPos_impl& c) {\n\t\t\treturn max_element(begin(v),\
    \ end(v)) - begin(v);\n\t\t}\n\t} MaxPos;\n\tstruct MinPos_impl {\n\t\ttemplate\
    \ <class T> friend auto operator|(T v, const MinPos_impl& c) {\n\t\t\treturn min_element(begin(v),\
    \ end(v)) - begin(v);\n\t\t}\n\t} MinPos;\n\tstruct MaxBy_impl {\n\t\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\t\treturn Callable([&](auto v) {\n\t\t\
    \t\tauto max_it = begin(v);\n\t\t\t\tauto max_val = f(*max_it);\n\t\t\t\tfor (auto\
    \ it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\t\tif (auto val = f(*it);\
    \ max_val < val) {\n\t\t\t\t\t\tmax_it = it;\n\t\t\t\t\t\tmax_val = val;\n\t\t\
    \t\t\t}\n\t\t\t\t}\n\t\t\t\treturn *max_it;\n\t\t\t});\n\t\t}\n\t} MaxBy;\n\t\
    struct MinBy_impl {\n\t\ttemplate <class F> auto operator()(F&& f) {\n\t\t\treturn\
    \ Callable([&](auto v) {\n\t\t\t\tauto min_it = begin(v);\n\t\t\t\tauto min_val\
    \ = f(*min_it);\n\t\t\t\tfor (auto it = next(begin(v)); it != end(v); ++it) {\n\
    \t\t\t\t\tif (auto val = f(*it); min_val > val) {\n\t\t\t\t\t\tmin_it = it;\n\t\
    \t\t\t\t\tmin_val = val;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn *min_it;\n\t\t\
    \t});\n\t\t}\n\t} MinBy;\n\tstruct MaxOf_impl {\n\t\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\t\treturn Callable([&](auto v) {\n\t\t\t\tauto max_val = f(*begin(v));\n\
    \t\t\t\tfor (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\t\tif (auto\
    \ val = f(*it); max_val < val) {\n\t\t\t\t\t\tmax_val = val;\n\t\t\t\t\t}\n\t\t\
    \t\t}\n\t\t\t\treturn max_val;\n\t\t\t});\n\t\t}\n\t} MaxOf;\n\tstruct MinOf_impl\
    \ {\n\t\ttemplate <class F> auto operator()(F&& f) {\n\t\t\treturn Callable([&](auto\
    \ v) {\n\t\t\t\tauto min_val = f(*begin(v));\n\t\t\t\tfor (auto it = next(begin(v));\
    \ it != end(v); ++it) {\n\t\t\t\t\tif (auto val = f(*it); min_val > val) {\n\t\
    \t\t\t\t\tmin_val = val;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn min_val;\n\t\t\
    \t});\n\t\t}\n\t} MinOf;\n\tstruct Count_impl {\n\t\ttemplate <class V> auto operator()(const\
    \ V& val) {\n\t\t\treturn Callable([&](auto v) { return count(begin(v), end(v),\
    \ val); });\n\t\t}\n\t} Count;\n\tstruct CountIf_impl {\n\t\ttemplate <class F>\
    \ auto operator()(const F& f) {\n\t\t\treturn Callable([&](auto v) { return count_if(begin(v),\
    \ end(v), f); });\n\t\t}\n\t} CountIf;\n\tstruct Index_impl {\n\t\ttemplate <class\
    \ V> auto operator()(const V& val) {\n\t\t\treturn Callable([&](auto v) -> optional<int>\
    \ {\n\t\t\t\tauto res = find(begin(v), end(v), val);\n\t\t\t\treturn res != end(v)\
    \ ? optional(res - begin(v)) : nullopt;\n\t\t\t});\n\t\t}\n\t} Index;\n\tstruct\
    \ IndexIf_impl {\n\t\ttemplate <class F> auto operator()(const F& f) {\n\t\t\t\
    return Callable([&](auto v) -> optional<int> {\n\t\t\t\tauto res = find_if(begin(v),\
    \ end(v), f);\n\t\t\t\treturn res != end(v) ? optional(res - begin(v)) : nullopt;\n\
    \t\t\t});\n\t\t}\n\t} IndexIf;\n\tstruct FindIf_impl {\n\t\ttemplate <class F>\
    \ auto operator()(const F& f) {\n\t\t\treturn Callable([&](auto v) -> optional<typename\
    \ decltype(v)::value_type> {\n\t\t\t\tauto res = find_if(begin(v), end(v), f);\n\
    \t\t\t\treturn res != end(v) ? optional(*res) : nullopt;\n\t\t\t});\n\t\t}\n\t\
    } FindIf;\n\tstruct Sum_impl {\n\t\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\t\treturn Callable([&](auto v) {\n\t\t\t\treturn accumulate(next(begin(v)),\
    \ end(v), f(*begin(v)),\n\t\t\t\t                  [&](const auto& a, const auto&\
    \ b) { return a + f(b); });\n\t\t\t});\n\t\t}\n\t\ttemplate <class T> friend auto\
    \ operator|(T v, const Sum_impl& c) {\n\t\t\treturn accumulate(begin(v), end(v),\
    \ typename T::value_type());\n\t\t}\n\t} Sum;\n\tstruct Includes {\n\t\ttemplate\
    \ <class V> auto operator()(const V& val) {\n\t\t\treturn Callable(\n\t\t\t  \
    \  [&](auto v) { return find(begin(v), end(v), val) != end(v); });\n\t\t}\n\t\
    } Includes;\n\tstruct IncludesIf_impl {\n\t\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\t\treturn Callable(\n\t\t\t    [&](auto v) { return find_if(begin(v),\
    \ end(v), f) != end(v); });\n\t\t}\n\t} IncludesIf;\n\tstruct RemoveIf_impl {\n\
    \t\ttemplate <class F> auto operator()(const F& f) {\n\t\t\treturn Callable([&](auto\
    \ v) {\n\t\t\t\tv.erase(remove_if(begin(v), end(v), f), end(v));\n\t\t\t\treturn\
    \ v;\n\t\t\t});\n\t\t}\n\t} RemoveIf;\n\tstruct Each_impl {\n\t\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\t\treturn Callable([&](auto v) {\n\t\t\t\tfor\
    \ (const auto& i : v) {\n\t\t\t\t\tf(i);\n\t\t\t\t}\n\t\t\t});\n\t\t}\n\t} Each;\n\
    \tstruct Select_impl {\n\t\ttemplate <class F> auto operator()(F&& f) {\n\t\t\t\
    return Callable([&](auto v) {\n\t\t\t\tusing value_type = typename decltype(v)::value_type;\n\
    \t\t\t\tvector<value_type> res;\n\t\t\t\tfor (const auto& i : v) {\n\t\t\t\t\t\
    if (f(i)) res.push_back(i);\n\t\t\t\t}\n\t\t\t\treturn res;\n\t\t\t});\n\t\t}\n\
    \t} Select;\n\tstruct Map_impl {\n\t\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\t\treturn Callable([&](auto v) {\n\t\t\t\tusing result_type = invoke_result_t<F,\
    \ typename decltype(v)::value_type>;\n\t\t\t\tvector<result_type> res;\n\t\t\t\
    \tres.reserve(size(v));\n\t\t\t\tfor (const auto& i : v) {\n\t\t\t\t\tres.push_back(f(i));\n\
    \t\t\t\t}\n\t\t\t\treturn res;\n\t\t\t});\n\t\t}\n\t} Map;\n\tstruct Indexed_impl\
    \ {\n\t\ttemplate <class T> friend auto operator|(const T& v, Indexed_impl& c)\
    \ {\n\t\t\tusing value_type = typename T::value_type;\n\t\t\tvector<pair<value_type,\
    \ int>> res;\n\t\t\tres.reserve(size(v));\n\t\t\tint index = 0;\n\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\tres.emplace_back(i, index++);\n\t\t\t}\n\t\t\treturn\
    \ res;\n\t\t}\n\t} Indexed;\n\tstruct AllOf_impl {\n\t\ttemplate <class F> auto\
    \ operator()(F&& f) {\n\t\t\treturn Callable([&](auto v) {\n\t\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\t\tif (!f(i)) return false;\n\t\t\t\t}\n\t\t\t\treturn\
    \ true;\n\t\t\t});\n\t\t}\n\t} AllOf;\n\tstruct AnyOf_impl {\n\t\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\t\treturn Callable([&](auto v) {\n\t\t\t\tfor\
    \ (const auto& i : v) {\n\t\t\t\t\tif (f(i)) return true;\n\t\t\t\t}\n\t\t\t\t\
    return false;\n\t\t\t});\n\t\t}\n\t} AnyOf;\n\tstruct NoneOf_impl {\n\t\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\t\treturn Callable([&](auto v) {\n\t\t\
    \t\tfor (const auto& i : v) {\n\t\t\t\t\tif (f(i)) return false;\n\t\t\t\t}\n\t\
    \t\t\treturn true;\n\t\t\t});\n\t\t}\n\t} NoneOf;\n\n\ttemplate <class T> auto\
    \ operator*(const vector<T>& a, size_t n) {\n\t\tT res;\n\t\tfor (size_t i = 0;\
    \ i < n; ++i) {\n\t\t\tres.insert(res.end(), a.begin(), a.end());\n\t\t}\n\t\t\
    return res;\n\t}\n\tauto operator*(string a, size_t n) {\n\t\tstring res;\n\t\t\
    for (size_t i = 0; i < n; ++i) {\n\t\t\tres += a;\n\t\t}\n\t\treturn res;\n\t\
    }\n\ttemplate <class T, class U> auto& operator<<(vector<T>& a, const U& b) {\n\
    \t\ta.insert(a.end(), all(b));\n\t\treturn a;\n\t}\n\ttemplate <class T> auto&\
    \ operator<<(string& a, const T& b) {\n\t\ta.insert(a.end(), all(b));\n\t\treturn\
    \ a;\n\t}\n\ttemplate <class T, class U> auto operator+(vector<T> a, const U&\
    \ b) {\n\t\ta << b;\n\t\treturn a;\n\t}\n\ttemplate <class T> auto operator+(string\
    \ a, const T& b) {\n\t\ta << b;\n\t\treturn a;\n\t}\n}  // namespace Ruby\nusing\
    \ namespace Ruby;\n\n// --- functions --- //\ntemplate <class T, class U> int\
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
    }\n\n// --- dump --- //\n#if __has_include(\"dump.hpp\")\n#include \"dump.hpp\"\
    \n#else\n#define dump(...) ((void)0)\n#endif\n#pragma endregion\n\n// ----------------------------------------------------------------\
    \ //\n\nint main() {}"
  dependsOn:
  - dump.hpp
  isVerificationFile: false
  path: template17.cpp
  requiredBy: []
  timestamp: '2021-01-03 14:44:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template17.cpp
layout: document
redirect_from:
- /library/template17.cpp
- /library/template17.cpp.html
title: template17.cpp
---
