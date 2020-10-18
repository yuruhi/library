---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template14.cpp: line 715: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "// description : C++14\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n#define\
    \ _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n#define rep(i, n) for (int i =\
    \ 0; i < (n); ++i)\n#define FOR(i, m, n) for (int i = (m); i < (n); ++i)\n#define\
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
    \ = 1000000007;\nconstexpr long double PI = M_PI, EPS = 1e-12;\n\n// --- input\
    \ --- //\n#ifdef _WIN32\n#define getchar_unlocked _getchar_nolock\n#define putchar_unlocked\
    \ _putchar_nolock\n#define fwrite_unlocked fwrite\n#define fflush_unlocked fflush\n\
    #endif\nclass Input {\n\tstatic int gc() {\n\t\treturn getchar_unlocked();\n\t\
    }\n\ttemplate <class T> static void i(T& v) {\n\t\tcin >> v;\n\t}\n\tstatic void\
    \ i(char& v) {\n\t\twhile (isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic void i(bool&\
    \ v) {\n\t\tv = in<char>() != '0';\n\t}\n\tstatic void i(string& v) {\n\t\tv.clear();\n\
    \t\tchar c;\n\t\tfor (i(c); !isspace(c); c = gc())\n\t\t\tv += c;\n\t}\n\tstatic\
    \ void i(int& v) {\n\t\tbool neg = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c);\
    \ c = gc())\n\t\t\tv = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic\
    \ void i(long long& v) {\n\t\tbool neg = false;\n\t\tv = 0;\n\t\tchar c;\n\t\t\
    i(c);\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor\
    \ (; isdigit(c); c = gc())\n\t\t\tv = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\
    \t}\n\tstatic void i(double& v) {\n\t\tdouble dp = 1;\n\t\tbool neg = false, adp\
    \ = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\t\tif (c == '-') {\n\t\t\tneg\
    \ = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c) || c == '.'; c = gc())\
    \ {\n\t\t\tif (c == '.')\n\t\t\t\tadp = true;\n\t\t\telse if (adp)\n\t\t\t\tv\
    \ += (c - '0') * (dp *= 0.1);\n\t\t\telse\n\t\t\t\tv = v * 10 + (c - '0');\n\t\
    \t}\n\t\tif (neg) v = -v;\n\t}\n\tstatic void i(long double& v) {\n\t\tlong double\
    \ dp = 1;\n\t\tbool neg = false, adp = false;\n\t\tv = 0;\n\t\tchar c;\n\t\ti(c);\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
    \ || c == '.'; c = gc()) {\n\t\t\tif (c == '.')\n\t\t\t\tadp = true;\n\t\t\telse\
    \ if (adp)\n\t\t\t\tv += (c - '0') * (dp *= 0.1);\n\t\t\telse\n\t\t\t\tv = v *\
    \ 10 + (c - '0');\n\t\t}\n\t\tif (neg) v = -v;\n\t}\n\ttemplate <class T, class\
    \ U> static void i(pair<T, U>& v) {\n\t\ti(v.first);\n\t\ti(v.second);\n\t}\n\t\
    template <class T> static void i(vector<T>& v) {\n\t\tfor (auto& e : v)\n\t\t\t\
    i(e);\n\t}\n\tstruct InputV {\n\t\tint n, m;\n\t\tInputV(int _n) : n(_n), m(0)\
    \ {}\n\t\tInputV(const pair<int, int>& nm) : n(nm.first), m(nm.second) {}\n\t\t\
    template <class T> operator vector<T>() {\n\t\t\tvector<T> v(n);\n\t\t\ti(v);\n\
    \t\t\treturn v;\n\t\t}\n\t\ttemplate <class T> operator vector<vector<T>>() {\n\
    \t\t\tvector<vector<T>> v(n, vector<T>(m));\n\t\t\ti(v);\n\t\t\treturn v;\n\t\t\
    }\n\t};\n\npublic:\n\tstatic string read_line() {\n\t\tstring v;\n\t\tchar c;\n\
    \t\tfor (i(c); c != '\\n' && c != '\\0'; c = gc())\n\t\t\tv += c;\n\t\treturn\
    \ v;\n\t}\n\ttemplate <class T> static T in() {\n\t\tT v;\n\t\ti(v);\n\t\treturn\
    \ v;\n\t}\n\ttemplate <class T> operator T() const {\n\t\treturn in<T>();\n\t\
    }\n\tint operator--(int) const {\n\t\treturn in<int>() - 1;\n\t}\n\tInputV operator[](int\
    \ n) const {\n\t\treturn InputV(n);\n\t}\n\tInputV operator[](const pair<int,\
    \ int>& n) const {\n\t\treturn InputV(n);\n\t}\n\tvoid operator()() const {}\n\
    \ttemplate <class H, class... T> void operator()(H&& h, T&&... t) const {\n\t\t\
    i(h);\n\t\toperator()(forward<T>(t)...);\n\t}\n} in;\n#define input(T) Input::in<T>()\n\
    #define INT input(int)\n#define LL input(long long)\n#define STR input(string)\n\
    #define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n#define\
    \ ini(...) inputs(int, __VA_ARGS__)\n#define inl(...) inputs(long long, __VA_ARGS__)\n\
    #define ins(...) inputs(string, __VA_ARGS__)\n\n// --- output --- //\nstruct BoolStr\
    \ {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const char* _f) : t(_t),\
    \ f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"YES\", \"NO\"\
    ), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\tDivStr(const char*\
    \ _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"), no_spc(\"\", \"\
    \\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"), no_endl(\" \", \"\"\
    );\nclass Output {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\tvoid p(int v) const\
    \ {\n\t\tif (v < 0) putchar_unlocked('-'), v = -v;\n\t\tchar b[10];\n\t\tint i\
    \ = 0;\n\t\twhile (v)\n\t\t\tb[i++] = '0' + v % 10, v /= 10;\n\t\tif (!i) b[i++]\
    \ = '0';\n\t\twhile (i--)\n\t\t\tputchar_unlocked(b[i]);\n\t}\n\tvoid p(long long\
    \ v) const {\n\t\tif (v < 0) putchar_unlocked('-'), v = -v;\n\t\tchar b[20];\n\
    \t\tint i = 0;\n\t\twhile (v)\n\t\t\tb[i++] = '0' + v % 10, v /= 10;\n\t\tif (!i)\
    \ b[i++] = '0';\n\t\twhile (i--)\n\t\t\tputchar_unlocked(b[i]);\n\t}\n\tvoid p(bool\
    \ v) const {\n\t\tp(v ? B.t : B.f);\n\t}\n\tvoid p(char v) const {\n\t\tputchar_unlocked(v);\n\
    \t}\n\tvoid p(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v), stdout);\n\
    \t}\n\tvoid p(double v) const {\n\t\tprintf(\"%.20f\", v);\n\t}\n\tvoid p(long\
    \ double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t}\n\ttemplate <class T> void\
    \ p(const T& v) const {\n\t\tcout << v;\n\t}\n\ttemplate <class T, class U> void\
    \ p(const pair<T, U>& v) const {\n\t\tp(v.first);\n\t\tp(D.d);\n\t\tp(v.second);\n\
    \t}\n\ttemplate <class T> void p(const vector<T>& v) const {\n\t\trep(i, sz(v))\
    \ {\n\t\t\tif (i) p(D.d);\n\t\t\tp(v[i]);\n\t\t}\n\t}\n\ttemplate <class T> void\
    \ p(const vector<vector<T>>& v) const {\n\t\trep(i, sz(v)) {\n\t\t\tif (i) p(D.l);\n\
    \t\t\tp(v[i]);\n\t\t}\n\t}\n\npublic:\n\tOutput& operator()() {\n\t\tp(D.l);\n\
    \t\treturn *this;\n\t}\n\ttemplate <class H> Output& operator()(H&& h) {\n\t\t\
    p(h);\n\t\tp(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class H, class... T> Output&\
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
    \ {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr T count() const {\n\t\t\treturn b;\n\
    \t\t}\n\t\tconstexpr T step() const {\n\t\t\treturn c;\n\t\t}\n\t};\n\tconstexpr\
    \ Step(T b, T c, T s) : be(b, c, s) {}\n\tconstexpr It begin() const {\n\t\treturn\
    \ be;\n\t}\n\tconstexpr It end() const {\n\t\treturn en;\n\t}\n\tconstexpr T start()\
    \ const {\n\t\treturn be.start();\n\t}\n\tconstexpr T count() const {\n\t\treturn\
    \ be.count();\n\t}\n\tconstexpr T step() const {\n\t\treturn be.step();\n\t}\n\
    \tconstexpr T sum() const {\n\t\treturn start() * count() + step() * (count()\
    \ * (count() - 1) / 2);\n\t}\n\toperator vector<T>() const {\n\t\treturn to_a();\n\
    \t}\n\ttemplate <class F> void each(const F& f) const {\n\t\tfor (T i : *this)\n\
    \t\t\tf(i);\n\t}\n\tauto to_a() const {\n\t\tvector<T> res;\n\t\tres.reserve(count());\n\
    \t\teach([&](T i) {\n\t\t\tres.push_back(i);\n\t\t});\n\t\treturn res;\n\t}\n\t\
    template <class F, class U = decay_t<result_of_t<F(T)>>> auto map(const F& f)\
    \ const {\n\t\tvector<U> res;\n\t\tres.reserve(count());\n\t\teach([&](T i) {\n\
    \t\t\tres.push_back(f(i));\n\t\t});\n\t\treturn res;\n\t}\n\ttemplate <class F>\
    \ auto select(const F& f) const {\n\t\tvector<T> res;\n\t\teach([&](T i) {\n\t\
    \t\tif (f(i)) res.push_back(i);\n\t\t});\n\t\treturn res;\n\t}\n\ttemplate <class\
    \ F> int count_if(const F& f) const {\n\t\tint res = 0;\n\t\teach([&](T i) {\n\
    \t\t\tif (f(i)) ++res;\n\t\t});\n\t\treturn res;\n\t}\n\ttemplate <class F> T\
    \ find_if(const F& f) const {\n\t\tfor (T i : *this)\n\t\t\tif (f(i)) return i;\n\
    \t\treturn 0;\n\t}\n\ttemplate <class F> auto max_by(const F& f) const {\n\t\t\
    auto v = map(f);\n\t\treturn *max_element(v.begin(), v.end());\n\t}\n\ttemplate\
    \ <class F> auto min_by(const F& f) const {\n\t\tauto v = map(f);\n\t\treturn\
    \ *min_element(v.begin(), v.end());\n\t}\n\ttemplate <class F> bool all_of(const\
    \ F& f) const {\n\t\tfor (T i : *this)\n\t\t\tif (!f(i)) return false;\n\t\treturn\
    \ true;\n\t}\n\ttemplate <class F> bool any_of(const F& f) const {\n\t\tfor (T\
    \ i : *this)\n\t\t\tif (f(i)) return true;\n\t\treturn false;\n\t}\n\ttemplate\
    \ <class F, class U = decay_t<result_of_t<F(T)>>> auto sum(const F& f) const {\n\
    \t\tU res = 0;\n\t\teach([&](T i) {\n\t\t\tres += static_cast<U>(f(i));\n\t\t\
    });\n\t\treturn res;\n\t}\n\tusing value_type = T;\n\tusing iterator = It;\n\n\
    private:\n\tIt be, en;\n};\ntemplate <class T> inline constexpr auto step(T a)\
    \ {\n\treturn Step<T>(0, a, 1);\n}\ntemplate <class T> inline constexpr auto step(T\
    \ a, T b) {\n\treturn Step<T>(a, b - a, 1);\n}\ntemplate <class T> inline constexpr\
    \ auto step(T a, T b, T c) {\n\treturn Step<T>(a, a < b ? (b - a - 1) / c + 1\
    \ : 0, c);\n}\n\n// --- functions --- //\ninline namespace {\n\ttemplate <class\
    \ T> inline void Sort(T& a) {\n\t\tsort(all(a));\n\t}\n\ttemplate <class T> inline\
    \ void RSort(T& a) {\n\t\tsort(rall(a));\n\t}\n\ttemplate <class T, class F> inline\
    \ void Sort(T& a, const F& f) {\n\t\tsort(all(a), f);\n\t}\n\ttemplate <class\
    \ T, class F> inline void RSort(T& a, const F& f) {\n\t\tsort(rall(a), f);\n\t\
    }\n\ttemplate <class T> inline T Sorted(T a) {\n\t\tSort(a);\n\t\treturn a;\n\t\
    }\n\ttemplate <class T> inline T RSorted(T a) {\n\t\tRSort(a);\n\t\treturn a;\n\
    \t}\n\ttemplate <class T, class F> inline T Sorted(T& a, const F& f) {\n\t\tSort(a,\
    \ f);\n\t\treturn a;\n\t}\n\ttemplate <class T, class F> inline T RSorted(T& a,\
    \ const F& f) {\n\t\tRSort(a, f);\n\t\treturn a;\n\t}\n\ttemplate <class T, class\
    \ F> inline void SortBy(T& a, const F& f) {\n\t\tsort(all(a), [&](const auto&\
    \ x, const auto& y) {\n\t\t\treturn f(x) < f(y);\n\t\t});\n\t}\n\ttemplate <class\
    \ T, class F> inline void RSortBy(T& a, const F& f) {\n\t\tsort(rall(a), [&](const\
    \ auto& x, const auto& y) {\n\t\t\treturn f(x) < f(y);\n\t\t});\n\t}\n\ttemplate\
    \ <class T> inline void Reverse(T& a) {\n\t\treverse(all(a));\n\t}\n\ttemplate\
    \ <class T> inline void Unique(T& a) {\n\t\ta.erase(unique(all(a)), a.end());\n\
    \t}\n\ttemplate <class T> inline void Uniq(T& a) {\n\t\tSort(a);\n\t\tUnique(a);\n\
    \t}\n\ttemplate <class T> inline void Rotate(T& a, int left) {\n\t\trotate(a.begin(),\
    \ a.begin() + left, a.end());\n\t}\n\ttemplate <class T> inline T Reversed(T a)\
    \ {\n\t\tReverse(a);\n\t\treturn a;\n\t}\n\ttemplate <class T> inline T Uniqued(T\
    \ a) {\n\t\tUnique(a);\n\t\treturn a;\n\t}\n\ttemplate <class T> inline T Uniqed(T\
    \ a) {\n\t\tUniq(a);\n\t\treturn a;\n\t}\n\ttemplate <class T> inline T Rotated(T\
    \ a, int left) {\n\t\tRotate(a, left);\n\t\treturn a;\n\t}\n\ttemplate <class\
    \ T> inline auto Max(const T& a) {\n\t\treturn *max_element(all(a));\n\t}\n\t\
    template <class T> inline auto Min(const T& a) {\n\t\treturn *min_element(all(a));\n\
    \t}\n\ttemplate <class T> inline int MaxPos(const T& a) {\n\t\treturn max_element(all(a))\
    \ - a.begin();\n\t}\n\ttemplate <class T> inline int MinPos(const T& a) {\n\t\t\
    return min_element(all(a)) - a.begin();\n\t}\n\ttemplate <class T, class F> inline\
    \ auto MaxBy(const T& a, const F& f) {\n\t\treturn *max_element(all(a), [&](const\
    \ auto& x, const auto& y) {\n\t\t\treturn f(x) < f(y);\n\t\t});\n\t}\n\ttemplate\
    \ <class T, class F> inline auto MinBy(const T& a, const F& f) {\n\t\treturn *min_element(all(a),\
    \ [&](const auto& x, const auto& y) {\n\t\t\treturn f(x) < f(y);\n\t\t});\n\t\
    }\n\ttemplate <class T, class F> inline auto MaxOf(const T& a, const F& f) {\n\
    \t\treturn Max(Map(a, f));\n\t}\n\ttemplate <class T, class F> inline auto MinOf(const\
    \ T& a, const F& f) {\n\t\treturn Min(Map(a, f));\n\t}\n\ttemplate <class T, class\
    \ U> inline int Count(const T& a, const U& v) {\n\t\treturn count(all(a), v);\n\
    \t}\n\ttemplate <class T, class F> inline int CountIf(const T& a, const F& f)\
    \ {\n\t\treturn count_if(all(a), f);\n\t}\n\ttemplate <class T, class U> inline\
    \ int Find(const T& a, const U& v) {\n\t\treturn find(all(a), v) - a.begin();\n\
    \t}\n\ttemplate <class T, class F> inline int FindIf(const T& a, const F& f) {\n\
    \t\treturn find_if(all(a), f) - a.begin();\n\t}\n\ttemplate <class T, class U\
    \ = typename T::value_type> inline U Sum(const T& a) {\n\t\treturn accumulate(all(a),\
    \ U());\n\t}\n\ttemplate <class T, class U> inline bool Includes(const T& a, const\
    \ U& v) {\n\t\treturn find(all(a), v) != a.end();\n\t}\n\ttemplate <class T, class\
    \ F> inline auto Sum(const T& v, const F& f) {\n\t\treturn accumulate(next(v.begin()),\
    \ v.end(), f(*v.begin()), [&](auto a, auto b) {\n\t\t\treturn a + f(b);\n\t\t\
    });\n\t}\n\ttemplate <class T, class U> inline int Lower(const T& a, const U&\
    \ v) {\n\t\treturn lower_bound(all(a), v) - a.begin();\n\t}\n\ttemplate <class\
    \ T, class U> inline int Upper(const T& a, const U& v) {\n\t\treturn upper_bound(all(a),\
    \ v) - a.begin();\n\t}\n\ttemplate <class T, class F> inline void RemoveIf(T&\
    \ a, const F& f) {\n\t\ta.erase(remove_if(all(a), f), a.end());\n\t}\n\ttemplate\
    \ <class F> inline auto Vector(size_t size, const F& f) {\n\t\tvector<decay_t<result_of_t<F(size_t)>>>\
    \ res(size);\n\t\tfor (size_t i = 0; i < size; ++i)\n\t\t\tres[i] = f(i);\n\t\t\
    return res;\n\t}\n\ttemplate <class T> inline auto Grid(size_t h, size_t w, const\
    \ T& v = T()) {\n\t\treturn vector<vector<T>>(h, vector<T>(w, v));\n\t}\n\ttemplate\
    \ <class T> inline auto Slice(const T& v, size_t i, size_t len) {\n\t\treturn\
    \ i < v.size() ? T(v.begin() + i, v.begin() + min(i + len, v.size())) : T();\n\
    \t}\n\ttemplate <class T, class F> inline auto Each(const T& v, F&& f) {\n\t\t\
    for (auto& i : v)\n\t\t\tf(i);\n\t}\n\ttemplate <class T, class F> inline auto\
    \ Select(const T& v, const F& f) {\n\t\tT res;\n\t\tfor (const auto& e : v)\n\t\
    \t\tif (f(e)) res.push_back(e);\n\t\treturn res;\n\t}\n\ttemplate <class T, class\
    \ F> inline auto Map(const T& v, F&& f) {\n\t\tvector<decay_t<result_of_t<F(typename\
    \ T::value_type)>>> res(v.size());\n\t\tsize_t i = 0;\n\t\tfor (const auto& e\
    \ : v)\n\t\t\tres[i++] = f(e);\n\t\treturn res;\n\t}\n\ttemplate <class T, class\
    \ F> inline auto MapIndex(const T& v, const F& f) {\n\t\tvector<decay_t<result_of_t<F(size_t,\
    \ typename T::value_type)>>> res(v.size());\n\t\tsize_t i = 0;\n\t\tfor (auto\
    \ it = v.begin(); it != v.end(); ++it, ++i)\n\t\t\tres[i] = f(i, *it);\n\t\treturn\
    \ res;\n\t}\n\ttemplate <class T, class F> inline auto TrueIndex(const T& v, const\
    \ F& f) {\n\t\tvector<size_t> res;\n\t\tfor (size_t i = 0; i < v.size(); ++i)\n\
    \t\t\tif (f(v[i])) res.push_back(i);\n\t\treturn res;\n\t}\n\ttemplate <class\
    \ T, class U = typename T::value_type> inline auto Indexed(const T& v) {\n\t\t\
    vector<pair<U, int>> res(v.size());\n\t\tfor (int i = 0; i < (int)v.size(); ++i)\n\
    \t\t\tres[i] = make_pair(static_cast<U>(v[i]), i);\n\t\treturn res;\n\t}\n\tinline\
    \ auto operator*(string s, size_t n) {\n\t\tstring res;\n\t\tfor (size_t i = 0;\
    \ i < n; ++i)\n\t\t\tres += s;\n\t\treturn res;\n\t}\n\ttemplate <class T> inline\
    \ auto& operator<<(vector<T>& v, const vector<T>& v2) {\n\t\tv.insert(v.end(),\
    \ all(v2));\n\t\treturn v;\n\t}\n\ttemplate <class T> inline T Ceil(T n, T m)\
    \ {\n\t\treturn (n + m - 1) / m;\n\t}\n\ttemplate <class T> inline T Ceil2(T n,\
    \ T m) {\n\t\treturn Ceil(n, m) * m;\n\t}\n\ttemplate <class T> inline T Tri(T\
    \ n) {\n\t\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n\t}\n\ttemplate\
    \ <class T> inline T nC2(T n) {\n\t\treturn (n & 1) ? (n - 1) / 2 * n : n / 2\
    \ * (n - 1);\n\t}\n\ttemplate <class T> inline T Mid(const T& l, const T& r) {\n\
    \t\treturn l + (r - l) / 2;\n\t}\n\ttemplate <class T> inline bool chmax(T& a,\
    \ const T& b) {\n\t\tif (a < b) {\n\t\t\ta = b;\n\t\t\treturn true;\n\t\t}\n\t\
    \treturn false;\n\t}\n\ttemplate <class T> inline bool chmin(T& a, const T& b)\
    \ {\n\t\tif (a > b) {\n\t\t\ta = b;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\
    \t}\n\ttemplate <class T> inline bool inRange(const T& v, const T& min, const\
    \ T& max) {\n\t\treturn min <= v && v < max;\n\t}\n\ttemplate <class T> inline\
    \ bool isSquere(T n) {\n\t\tT s = sqrt(n);\n\t\treturn s * s == n || (s + 1) *\
    \ (s + 1) == n;\n\t}\n\ttemplate <class T = long long> inline T BIT(int b) {\n\
    \t\treturn T(1) << b;\n\t}\n\ttemplate <class T> inline T Gcd(T n, T m) {\n\t\t\
    return m ? Gcd(m, n % m) : n;\n\t}\n\ttemplate <class T> inline T Lcm(T n, T m)\
    \ {\n\t\treturn n / Gcd(n, m) * m;\n\t}\n\ttemplate <class T, class U = typename\
    \ T::value_type> inline U Gcdv(const T& v) {\n\t\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), Gcd<U>);\n\t}\n\ttemplate <class T, class U = typename\
    \ T::value_type> inline U Lcmv(const T& v) {\n\t\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), Lcm<U>);\n\t}\n\ttemplate <class T> inline T Pow(T a,\
    \ T n) {\n\t\tT r = 1;\n\t\twhile (n > 0) {\n\t\t\tif (n & 1) r *= a;\n\t\t\t\
    a *= a;\n\t\t\tn /= 2;\n\t\t}\n\t\treturn r;\n\t}\n\ttemplate <class T> inline\
    \ T Powmod(T a, T n, T m = MOD) {\n\t\tT r = 1;\n\t\twhile (n > 0) {\n\t\t\tif\
    \ (n & 1)\n\t\t\t\tr = r * a % m, n--;\n\t\t\telse\n\t\t\t\ta = a * a % m, n /=\
    \ 2;\n\t\t}\n\t\treturn r;\n\t}\n}  // namespace\n\n// --- dump --- //\n#if __has_include(\"\
    /home/yuruhiya/contest/library/dump.hpp\")\n#include \"/home/yuruhiya/contest/library/dump.hpp\"\
    \n#else\n#define dump(...) ((void)0)\n#endif\n\n// ----------------------------------------------------------------\
    \ //\n\nint main() {}"
  dependsOn: []
  isVerificationFile: false
  path: template14.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template14.cpp
layout: document
redirect_from:
- /library/template14.cpp
- /library/template14.cpp.html
title: template14.cpp
---
