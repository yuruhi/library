---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template14.cpp\"\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    #define rep(i, n) for (int i = 0; i < (n); ++i)\n#define FOR(i, m, n) for (int\
    \ i = (m); i < (n); ++i)\n#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)\n\
    #define rfor(i, m, n) for (int i = (m); i >= (n); --i)\n#define unless(c) if (!(c))\n\
    #define sz(x) ((int)(x).size())\n#define all(x) (x).begin(), (x).end()\n#define\
    \ rall(x) (x).rbegin(), (x).rend()\n#define range_it(a, l, r) (a).begin() + (l),\
    \ (a).begin() + (r)\n\nusing namespace std;\nusing ll = long long;\nusing LD =\
    \ long double;\nusing VB = vector<bool>;\nusing VVB = vector<VB>;\nusing VI =\
    \ vector<int>;\nusing VVI = vector<VI>;\nusing VL = vector<ll>;\nusing VVL = vector<VL>;\n\
    using VS = vector<string>;\nusing VD = vector<LD>;\nusing PII = pair<int, int>;\n\
    using VP = vector<PII>;\nusing PLL = pair<ll, ll>;\nusing VPL = vector<PLL>;\n\
    template <class T> using PQ = priority_queue<T>;\ntemplate <class T> using PQS\
    \ = priority_queue<T, vector<T>, greater<T>>;\nconstexpr int inf = 1e9;\nconstexpr\
    \ long long inf_ll = 1e18, MOD = 1000000007;\nconstexpr long double PI = M_PI,\
    \ EPS = 1e-12;\n\n// --- input --- //\n#ifdef _WIN32\n#define getchar_unlocked\
    \ _getchar_nolock\n#define putchar_unlocked _putchar_nolock\n#define fwrite_unlocked\
    \ fwrite\n#define fflush_unlocked fflush\n#endif\nclass Scanner {\n\tstatic int\
    \ gc() {\n\t\treturn getchar_unlocked();\n\t}\n\tstatic char next_char() {\n\t\
    \tchar c;\n\t\tread(c);\n\t\treturn c;\n\t}\n\ttemplate <class T> static void\
    \ read(T& v) {\n\t\tcin >> v;\n\t}\n\tstatic void read(char& v) {\n\t\twhile (isspace(v\
    \ = gc()))\n\t\t\t;\n\t}\n\tstatic void read(bool& v) {\n\t\tv = next_char() !=\
    \ '0';\n\t}\n\tstatic void read(string& v) {\n\t\tv.clear();\n\t\tfor (char c\
    \ = next_char(); !isspace(c); c = gc()) v += c;\n\t}\n\tstatic void read(int&\
    \ v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\t\tchar c = next_char();\n\t\tif (c\
    \ == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c);\
    \ c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void\
    \ read(long long& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\t\tchar c = next_char();\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c);\
    \ c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg) v = -v;\n\t}\n\tstatic void\
    \ read(double& v) {\n\t\tv = 0;\n\t\tdouble dp = 1;\n\t\tbool neg = false, after_dp\
    \ = false;\n\t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\
    \t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c) || c == '.'; c = gc()) {\n\t\t\t\
    if (c == '.') {\n\t\t\t\tafter_dp = true;\n\t\t\t} else if (after_dp) {\n\t\t\t\
    \tv += (c - '0') * (dp *= 0.1);\n\t\t\t} else {\n\t\t\t\tv = v * 10 + (c - '0');\n\
    \t\t\t}\n\t\t}\n\t\tif (neg) v = -v;\n\t}\n\tstatic void read(long double& v)\
    \ {\n\t\tv = 0;\n\t\tlong double dp = 1;\n\t\tbool neg = false, after_dp = false;\n\
    \t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\
    \t\t}\n\t\tfor (; isdigit(c) || c == '.'; c = gc()) {\n\t\t\tif (c == '.') {\n\
    \t\t\t\tafter_dp = true;\n\t\t\t} else if (after_dp) {\n\t\t\t\tv += (c - '0')\
    \ * (dp *= 0.1);\n\t\t\t} else {\n\t\t\t\tv = v * 10 + (c - '0');\n\t\t\t}\n\t\
    \t}\n\t\tif (neg) v = -v;\n\t}\n\ttemplate <class T, class U> static void read(pair<T,\
    \ U>& v) {\n\t\tread(v.first);\n\t\tread(v.second);\n\t}\n\ttemplate <class T>\
    \ static void read(vector<T>& v) {\n\t\tfor (auto& e : v) read(e);\n\t}\n\tstruct\
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
    } in;\n#define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n\
    #define ini(...) inputs(int, __VA_ARGS__)\n#define inl(...) inputs(long long,\
    \ __VA_ARGS__)\n#define ins(...) inputs(string, __VA_ARGS__)\n\n// --- output\
    \ --- //\nstruct BoolStr {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const\
    \ char* _f) : t(_t), f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"\
    YES\", \"NO\"), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\t\
    DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"\
    ), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"),\n\
    \    no_endl(\" \", \"\");\nclass Printer {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\
    \npublic:\n\tvoid print(int v) const {\n\t\tif (v < 0) putchar_unlocked('-'),\
    \ v = -v;\n\t\tchar b[10];\n\t\tint i = 0;\n\t\twhile (v) b[i++] = '0' + v % 10,\
    \ v /= 10;\n\t\tif (!i) b[i++] = '0';\n\t\twhile (i--) putchar_unlocked(b[i]);\n\
    \t}\n\tvoid print(long long v) const {\n\t\tif (v < 0) putchar_unlocked('-'),\
    \ v = -v;\n\t\tchar b[20];\n\t\tint i = 0;\n\t\twhile (v) b[i++] = '0' + v % 10,\
    \ v /= 10;\n\t\tif (!i) b[i++] = '0';\n\t\twhile (i--) putchar_unlocked(b[i]);\n\
    \t}\n\tvoid print(bool v) const {\n\t\tprint(v ? B.t : B.f);\n\t}\n\tvoid print(vector<bool>::reference\
    \ v) const {\n\t\tprint(v ? B.t : B.f);\n\t}\n\tvoid print(char v) const {\n\t\
    \tputchar_unlocked(v);\n\t}\n\tvoid print(const char* v) const {\n\t\tfwrite_unlocked(v,\
    \ 1, strlen(v), stdout);\n\t}\n\tvoid print(double v) const {\n\t\tprintf(\"%.20f\"\
    , v);\n\t}\n\tvoid print(long double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t\
    }\n\ttemplate <class T> void print(const T& v) const {\n\t\tcout << v;\n\t}\n\t\
    template <class T, class U> void print(const pair<T, U>& v) const {\n\t\tprint(v.first);\n\
    \t\tprint(D.d);\n\t\tprint(v.second);\n\t}\n\ttemplate <class InputIterater>\n\
    \tvoid print_range(const InputIterater& begin, const InputIterater& end) const\
    \ {\n\t\tfor (InputIterater i = begin; i != end; ++i) {\n\t\t\tif (i != begin)\
    \ print(D.d);\n\t\t\tprint(*i);\n\t\t}\n\t}\n\ttemplate <class T> void print(const\
    \ vector<T>& v) const {\n\t\tprint_range(v.begin(), v.end());\n\t}\n\ttemplate\
    \ <class T, size_t N> void print(const array<T, N>& v) const {\n\t\tprint_range(v.begin(),\
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
    \treturn *this;\n\t}\n} out;\n\n// --- step --- //\ntemplate <class T> struct\
    \ Step {\n\tclass It {\n\t\tT a, b, c;\n\n\tpublic:\n\t\tconstexpr It() : a(T()),\
    \ b(T()), c(T()) {}\n\t\tconstexpr It(T _b, T _c, T _s) : a(_b), b(_c), c(_s)\
    \ {}\n\t\tconstexpr It& operator++() {\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tconstexpr It operator++(int) {\n\t\t\tIt tmp = *this;\n\t\
    \t\t--b;\n\t\t\ta += c;\n\t\t\treturn tmp;\n\t\t}\n\t\tconstexpr const T& operator*()\
    \ const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr const T* operator->() const {\n\
    \t\t\treturn &a;\n\t\t}\n\t\tconstexpr bool operator==(const It& i) const {\n\t\
    \t\treturn b == i.b;\n\t\t}\n\t\tconstexpr bool operator!=(const It& i) const\
    \ {\n\t\t\treturn !(b == i.b);\n\t\t}\n\t\tconstexpr T start() const {\n\t\t\t\
    return a;\n\t\t}\n\t\tconstexpr T count() const {\n\t\t\treturn b;\n\t\t}\n\t\t\
    constexpr T step() const {\n\t\t\treturn c;\n\t\t}\n\t};\n\tconstexpr Step(T b,\
    \ T c, T s) : be(b, c, s) {}\n\tconstexpr It begin() const {\n\t\treturn be;\n\
    \t}\n\tconstexpr It end() const {\n\t\treturn en;\n\t}\n\tconstexpr T start()\
    \ const {\n\t\treturn be.start();\n\t}\n\tconstexpr T count() const {\n\t\treturn\
    \ be.count();\n\t}\n\tconstexpr T step() const {\n\t\treturn be.step();\n\t}\n\
    \tconstexpr T sum() const {\n\t\treturn start() * count() + step() * (count()\
    \ * (count() - 1) / 2);\n\t}\n\toperator vector<T>() const {\n\t\treturn to_a();\n\
    \t}\n\ttemplate <class F> void each(const F& f) const {\n\t\tfor (T i : *this)\
    \ f(i);\n\t}\n\tauto to_a() const {\n\t\tvector<T> res;\n\t\tres.reserve(count());\n\
    \t\teach([&](T i) { res.push_back(i); });\n\t\treturn res;\n\t}\n\ttemplate <class\
    \ F, class U = decay_t<result_of_t<F(T)>>> auto map(const F& f) const {\n\t\t\
    vector<U> res;\n\t\tres.reserve(count());\n\t\teach([&](T i) { res.push_back(f(i));\
    \ });\n\t\treturn res;\n\t}\n\ttemplate <class F> auto select(const F& f) const\
    \ {\n\t\tvector<T> res;\n\t\teach([&](T i) {\n\t\t\tif (f(i)) res.push_back(i);\n\
    \t\t});\n\t\treturn res;\n\t}\n\ttemplate <class F> int count_if(const F& f) const\
    \ {\n\t\tint res = 0;\n\t\teach([&](T i) {\n\t\t\tif (f(i)) ++res;\n\t\t});\n\t\
    \treturn res;\n\t}\n\ttemplate <class F> T find_if(const F& f) const {\n\t\tfor\
    \ (T i : *this)\n\t\t\tif (f(i)) return i;\n\t\treturn 0;\n\t}\n\ttemplate <class\
    \ F> auto max_by(const F& f) const {\n\t\tauto v = map(f);\n\t\treturn *max_element(v.begin(),\
    \ v.end());\n\t}\n\ttemplate <class F> auto min_by(const F& f) const {\n\t\tauto\
    \ v = map(f);\n\t\treturn *min_element(v.begin(), v.end());\n\t}\n\ttemplate <class\
    \ F> bool all_of(const F& f) const {\n\t\tfor (T i : *this)\n\t\t\tif (!f(i))\
    \ return false;\n\t\treturn true;\n\t}\n\ttemplate <class F> bool any_of(const\
    \ F& f) const {\n\t\tfor (T i : *this)\n\t\t\tif (f(i)) return true;\n\t\treturn\
    \ false;\n\t}\n\ttemplate <class F, class U = decay_t<result_of_t<F(T)>>> auto\
    \ sum(const F& f) const {\n\t\tU res = 0;\n\t\teach([&](T i) { res += static_cast<U>(f(i));\
    \ });\n\t\treturn res;\n\t}\n\tusing value_type = T;\n\tusing iterator = It;\n\
    \nprivate:\n\tIt be, en;\n};\ntemplate <class T> constexpr auto step(T a) {\n\t\
    return Step<T>(0, a, 1);\n}\ntemplate <class T> constexpr auto step(T a, T b)\
    \ {\n\treturn Step<T>(a, b - a, 1);\n}\ntemplate <class T> constexpr auto step(T\
    \ a, T b, T c) {\n\treturn Step<T>(a, a < b ? (b - a - 1) / c + 1 : 0, c);\n}\n\
    \n// --- functions --- //\ninline namespace {\n\ttemplate <class T> void Sort(T&\
    \ a) {\n\t\tsort(all(a));\n\t}\n\ttemplate <class T> void RSort(T& a) {\n\t\t\
    sort(rall(a));\n\t}\n\ttemplate <class T, class F> void Sort(T& a, const F& f)\
    \ {\n\t\tsort(all(a), f);\n\t}\n\ttemplate <class T, class F> void RSort(T& a,\
    \ const F& f) {\n\t\tsort(rall(a), f);\n\t}\n\ttemplate <class T> T Sorted(T a)\
    \ {\n\t\tSort(a);\n\t\treturn a;\n\t}\n\ttemplate <class T> T RSorted(T a) {\n\
    \t\tRSort(a);\n\t\treturn a;\n\t}\n\ttemplate <class T, class F> T Sorted(T& a,\
    \ const F& f) {\n\t\tSort(a, f);\n\t\treturn a;\n\t}\n\ttemplate <class T, class\
    \ F> T RSorted(T& a, const F& f) {\n\t\tRSort(a, f);\n\t\treturn a;\n\t}\n\ttemplate\
    \ <class T, class F> void SortBy(T& a, const F& f) {\n\t\tsort(all(a), [&](const\
    \ auto& x, const auto& y) { return f(x) < f(y); });\n\t}\n\ttemplate <class T,\
    \ class F> void RSortBy(T& a, const F& f) {\n\t\tsort(rall(a), [&](const auto&\
    \ x, const auto& y) { return f(x) < f(y); });\n\t}\n\ttemplate <class T> void\
    \ Reverse(T& a) {\n\t\treverse(all(a));\n\t}\n\ttemplate <class T> void Unique(T&\
    \ a) {\n\t\ta.erase(unique(all(a)), a.end());\n\t}\n\ttemplate <class T> void\
    \ Uniq(T& a) {\n\t\tSort(a);\n\t\tUnique(a);\n\t}\n\ttemplate <class T> void Rotate(T&\
    \ a, int left) {\n\t\trotate(a.begin(), a.begin() + left, a.end());\n\t}\n\ttemplate\
    \ <class T> T Reversed(T a) {\n\t\tReverse(a);\n\t\treturn a;\n\t}\n\ttemplate\
    \ <class T> T Uniqued(T a) {\n\t\tUnique(a);\n\t\treturn a;\n\t}\n\ttemplate <class\
    \ T> T Uniqed(T a) {\n\t\tUniq(a);\n\t\treturn a;\n\t}\n\ttemplate <class T> T\
    \ Rotated(T a, int left) {\n\t\tRotate(a, left);\n\t\treturn a;\n\t}\n\ttemplate\
    \ <class T> auto Max(const T& a) {\n\t\treturn *max_element(all(a));\n\t}\n\t\
    template <class T> auto Min(const T& a) {\n\t\treturn *min_element(all(a));\n\t\
    }\n\ttemplate <class T> int MaxPos(const T& a) {\n\t\treturn max_element(all(a))\
    \ - a.begin();\n\t}\n\ttemplate <class T> int MinPos(const T& a) {\n\t\treturn\
    \ min_element(all(a)) - a.begin();\n\t}\n\ttemplate <class T, class F> auto MaxBy(const\
    \ T& a, const F& f) {\n\t\treturn *max_element(all(a),\n\t\t                 \
    \   [&](const auto& x, const auto& y) { return f(x) < f(y); });\n\t}\n\ttemplate\
    \ <class T, class F> auto MinBy(const T& a, const F& f) {\n\t\treturn *min_element(all(a),\n\
    \t\t                    [&](const auto& x, const auto& y) { return f(x) < f(y);\
    \ });\n\t}\n\ttemplate <class T, class F> auto MaxOf(const T& a, const F& f) {\n\
    \t\treturn Max(Map(a, f));\n\t}\n\ttemplate <class T, class F> auto MinOf(const\
    \ T& a, const F& f) {\n\t\treturn Min(Map(a, f));\n\t}\n\ttemplate <class T, class\
    \ U> int Count(const T& a, const U& v) {\n\t\treturn count(all(a), v);\n\t}\n\t\
    template <class T, class F> int CountIf(const T& a, const F& f) {\n\t\treturn\
    \ count_if(all(a), f);\n\t}\n\ttemplate <class T, class U> int Find(const T& a,\
    \ const U& v) {\n\t\treturn find(all(a), v) - a.begin();\n\t}\n\ttemplate <class\
    \ T, class F> int FindIf(const T& a, const F& f) {\n\t\treturn find_if(all(a),\
    \ f) - a.begin();\n\t}\n\ttemplate <class T, class U = typename T::value_type>\
    \ U Sum(const T& a) {\n\t\treturn accumulate(all(a), U());\n\t}\n\ttemplate <class\
    \ T, class U> bool Includes(const T& a, const U& v) {\n\t\treturn find(all(a),\
    \ v) != a.end();\n\t}\n\ttemplate <class T, class F> auto Sum(const T& v, const\
    \ F& f) {\n\t\treturn accumulate(next(v.begin()), v.end(), f(*v.begin()),\n\t\t\
    \                  [&](auto a, auto b) { return a + f(b); });\n\t}\n\ttemplate\
    \ <class T, class U> int Lower(const T& a, const U& v) {\n\t\treturn lower_bound(all(a),\
    \ v) - a.begin();\n\t}\n\ttemplate <class T, class U> int Upper(const T& a, const\
    \ U& v) {\n\t\treturn upper_bound(all(a), v) - a.begin();\n\t}\n\ttemplate <class\
    \ T, class F> void RemoveIf(T& a, const F& f) {\n\t\ta.erase(remove_if(all(a),\
    \ f), a.end());\n\t}\n\ttemplate <class F> auto Vector(size_t size, const F& f)\
    \ {\n\t\tvector<decay_t<result_of_t<F(size_t)>>> res(size);\n\t\tfor (size_t i\
    \ = 0; i < size; ++i) res[i] = f(i);\n\t\treturn res;\n\t}\n\ttemplate <class\
    \ T> auto Grid(size_t h, size_t w, const T& v = T()) {\n\t\treturn vector<vector<T>>(h,\
    \ vector<T>(w, v));\n\t}\n\ttemplate <class T> auto Slice(const T& v, size_t i,\
    \ size_t len) {\n\t\treturn i < v.size() ? T(v.begin() + i, v.begin() + min(i\
    \ + len, v.size())) : T();\n\t}\n\ttemplate <class T, class F> auto Each(const\
    \ T& v, F&& f) {\n\t\tfor (auto& i : v) f(i);\n\t}\n\ttemplate <class T, class\
    \ F> auto Select(const T& v, const F& f) {\n\t\tT res;\n\t\tfor (const auto& e\
    \ : v)\n\t\t\tif (f(e)) res.push_back(e);\n\t\treturn res;\n\t}\n\ttemplate <class\
    \ T, class F> auto Map(const T& v, F&& f) {\n\t\tvector<decay_t<result_of_t<F(typename\
    \ T::value_type)>>> res(v.size());\n\t\tsize_t i = 0;\n\t\tfor (const auto& e\
    \ : v) res[i++] = f(e);\n\t\treturn res;\n\t}\n\ttemplate <class T, class F> auto\
    \ MapIndex(const T& v, const F& f) {\n\t\tvector<decay_t<result_of_t<F(size_t,\
    \ typename T::value_type)>>> res(v.size());\n\t\tsize_t i = 0;\n\t\tfor (auto\
    \ it = v.begin(); it != v.end(); ++it, ++i) res[i] = f(i, *it);\n\t\treturn res;\n\
    \t}\n\ttemplate <class T, class F> auto TrueIndex(const T& v, const F& f) {\n\t\
    \tvector<size_t> res;\n\t\tfor (size_t i = 0; i < v.size(); ++i)\n\t\t\tif (f(v[i]))\
    \ res.push_back(i);\n\t\treturn res;\n\t}\n\ttemplate <class T, class U = typename\
    \ T::value_type> auto Indexed(const T& v) {\n\t\tvector<pair<U, int>> res(v.size());\n\
    \t\tfor (int i = 0; i < (int)v.size(); ++i)\n\t\t\tres[i] = make_pair(static_cast<U>(v[i]),\
    \ i);\n\t\treturn res;\n\t}\n\tauto operator*(string s, size_t n) {\n\t\tstring\
    \ res;\n\t\tfor (size_t i = 0; i < n; ++i) res += s;\n\t\treturn res;\n\t}\n\t\
    template <class T> auto& operator<<(vector<T>& v, const vector<T>& v2) {\n\t\t\
    v.insert(v.end(), all(v2));\n\t\treturn v;\n\t}\n\ttemplate <class T> T Ceil(T\
    \ n, T m) {\n\t\treturn (n + m - 1) / m;\n\t}\n\ttemplate <class T> T Ceil2(T\
    \ n, T m) {\n\t\treturn Ceil(n, m) * m;\n\t}\n\ttemplate <class T> T Tri(T n)\
    \ {\n\t\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n\t}\n\ttemplate\
    \ <class T> T nC2(T n) {\n\t\treturn (n & 1) ? (n - 1) / 2 * n : n / 2 * (n -\
    \ 1);\n\t}\n\ttemplate <class T> T Mid(const T& l, const T& r) {\n\t\treturn l\
    \ + (r - l) / 2;\n\t}\n\ttemplate <class T> bool chmax(T& a, const T& b) {\n\t\
    \tif (a < b) {\n\t\t\ta = b;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t\
    }\n\ttemplate <class T> bool chmin(T& a, const T& b) {\n\t\tif (a > b) {\n\t\t\
    \ta = b;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t}\n\ttemplate <class\
    \ T> bool inRange(const T& v, const T& min, const T& max) {\n\t\treturn min <=\
    \ v && v < max;\n\t}\n\ttemplate <class T> bool isSquere(T n) {\n\t\tT s = sqrt(n);\n\
    \t\treturn s * s == n || (s + 1) * (s + 1) == n;\n\t}\n\ttemplate <class T = long\
    \ long> T BIT(int b) {\n\t\treturn T(1) << b;\n\t}\n\ttemplate <class T> T Gcd(T\
    \ n, T m) {\n\t\treturn m ? Gcd(m, n % m) : n;\n\t}\n\ttemplate <class T> T Lcm(T\
    \ n, T m) {\n\t\treturn n / Gcd(n, m) * m;\n\t}\n\ttemplate <class T, class U\
    \ = typename T::value_type> U Gcdv(const T& v) {\n\t\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), Gcd<U>);\n\t}\n\ttemplate <class T, class U = typename\
    \ T::value_type> U Lcmv(const T& v) {\n\t\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), Lcm<U>);\n\t}\n\ttemplate <class T> T Pow(T a, T n)\
    \ {\n\t\tT r = 1;\n\t\twhile (n > 0) {\n\t\t\tif (n & 1) r *= a;\n\t\t\ta *= a;\n\
    \t\t\tn /= 2;\n\t\t}\n\t\treturn r;\n\t}\n\ttemplate <class T> T Powmod(T a, T\
    \ n, T m = MOD) {\n\t\tT r = 1;\n\t\twhile (n > 0) {\n\t\t\tif (n & 1)\n\t\t\t\
    \tr = r * a % m, n--;\n\t\t\telse\n\t\t\t\ta = a * a % m, n /= 2;\n\t\t}\n\t\t\
    return r;\n\t}\n}  // namespace\n\n// --- dump --- //\n#if __has_include(<library/dump.hpp>)\n\
    #include <library/dump.hpp>\n#else\n#define dump(...) ((void)0)\n#endif\n\n//\
    \ ---------------------------------------------------------------- //\n"
  code: "#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n#define rep(i, n) for\
    \ (int i = 0; i < (n); ++i)\n#define FOR(i, m, n) for (int i = (m); i < (n); ++i)\n\
    #define rrep(i, n) for (int i = (n)-1; i >= 0; --i)\n#define rfor(i, m, n) for\
    \ (int i = (m); i >= (n); --i)\n#define unless(c) if (!(c))\n#define sz(x) ((int)(x).size())\n\
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
    #endif\nclass Scanner {\n\tstatic int gc() {\n\t\treturn getchar_unlocked();\n\
    \t}\n\tstatic char next_char() {\n\t\tchar c;\n\t\tread(c);\n\t\treturn c;\n\t\
    }\n\ttemplate <class T> static void read(T& v) {\n\t\tcin >> v;\n\t}\n\tstatic\
    \ void read(char& v) {\n\t\twhile (isspace(v = gc()))\n\t\t\t;\n\t}\n\tstatic\
    \ void read(bool& v) {\n\t\tv = next_char() != '0';\n\t}\n\tstatic void read(string&\
    \ v) {\n\t\tv.clear();\n\t\tfor (char c = next_char(); !isspace(c); c = gc())\
    \ v += c;\n\t}\n\tstatic void read(int& v) {\n\t\tv = 0;\n\t\tbool neg = false;\n\
    \t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\
    \t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\t\tif (neg)\
    \ v = -v;\n\t}\n\tstatic void read(long long& v) {\n\t\tv = 0;\n\t\tbool neg =\
    \ false;\n\t\tchar c = next_char();\n\t\tif (c == '-') {\n\t\t\tneg = true;\n\t\
    \t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c); c = gc()) v = v * 10 + (c - '0');\n\
    \t\tif (neg) v = -v;\n\t}\n\tstatic void read(double& v) {\n\t\tv = 0;\n\t\tdouble\
    \ dp = 1;\n\t\tbool neg = false, after_dp = false;\n\t\tchar c = next_char();\n\
    \t\tif (c == '-') {\n\t\t\tneg = true;\n\t\t\tc = gc();\n\t\t}\n\t\tfor (; isdigit(c)\
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
    \ {\n\t\tfor (auto& e : v) read(e);\n\t}\n\tstruct ReadVectorHelper {\n\t\tsize_t\
    \ n;\n\t\tReadVectorHelper(size_t _n) : n(_n) {}\n\t\ttemplate <class T> operator\
    \ vector<T>() {\n\t\t\tvector<T> v(n);\n\t\t\tread(v);\n\t\t\treturn v;\n\t\t\
    }\n\t};\n\tstruct Read2DVectorHelper {\n\t\tsize_t n, m;\n\t\tRead2DVectorHelper(const\
    \ pair<size_t, size_t>& nm) : n(nm.first), m(nm.second) {}\n\t\ttemplate <class\
    \ T> operator vector<vector<T>>() {\n\t\t\tvector<vector<T>> v(n, vector<T>(m));\n\
    \t\t\tread(v);\n\t\t\treturn v;\n\t\t}\n\t};\n\npublic:\n\tstring read_line()\
    \ const {\n\t\tstring v;\n\t\tfor (char c = gc(); c != '\\n' && c != '\\0'; c\
    \ = gc()) v += c;\n\t\treturn v;\n\t}\n\ttemplate <class T> T read() const {\n\
    \t\tT v;\n\t\tread(v);\n\t\treturn v;\n\t}\n\ttemplate <class T> vector<T> read_vector(size_t\
    \ n) const {\n\t\tvector<T> a(n);\n\t\tread(a);\n\t\treturn a;\n\t}\n\ttemplate\
    \ <class T> operator T() const {\n\t\treturn read<T>();\n\t}\n\tint operator--(int)\
    \ const {\n\t\treturn read<int>() - 1;\n\t}\n\tReadVectorHelper operator[](size_t\
    \ n) const {\n\t\treturn ReadVectorHelper(n);\n\t}\n\tRead2DVectorHelper operator[](const\
    \ pair<size_t, size_t>& nm) const {\n\t\treturn Read2DVectorHelper(nm);\n\t}\n\
    \tvoid operator()() const {}\n\ttemplate <class H, class... T> void operator()(H&&\
    \ h, T&&... t) const {\n\t\tread(h);\n\t\toperator()(forward<T>(t)...);\n\t}\n\
    } in;\n#define inputs(T, ...) \\\n\tT __VA_ARGS__;     \\\n\tin(__VA_ARGS__)\n\
    #define ini(...) inputs(int, __VA_ARGS__)\n#define inl(...) inputs(long long,\
    \ __VA_ARGS__)\n#define ins(...) inputs(string, __VA_ARGS__)\n\n// --- output\
    \ --- //\nstruct BoolStr {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const\
    \ char* _f) : t(_t), f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"\
    YES\", \"NO\"), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\t\
    DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"\
    ), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"),\n\
    \    no_endl(\" \", \"\");\nclass Printer {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\
    \npublic:\n\tvoid print(int v) const {\n\t\tif (v < 0) putchar_unlocked('-'),\
    \ v = -v;\n\t\tchar b[10];\n\t\tint i = 0;\n\t\twhile (v) b[i++] = '0' + v % 10,\
    \ v /= 10;\n\t\tif (!i) b[i++] = '0';\n\t\twhile (i--) putchar_unlocked(b[i]);\n\
    \t}\n\tvoid print(long long v) const {\n\t\tif (v < 0) putchar_unlocked('-'),\
    \ v = -v;\n\t\tchar b[20];\n\t\tint i = 0;\n\t\twhile (v) b[i++] = '0' + v % 10,\
    \ v /= 10;\n\t\tif (!i) b[i++] = '0';\n\t\twhile (i--) putchar_unlocked(b[i]);\n\
    \t}\n\tvoid print(bool v) const {\n\t\tprint(v ? B.t : B.f);\n\t}\n\tvoid print(vector<bool>::reference\
    \ v) const {\n\t\tprint(v ? B.t : B.f);\n\t}\n\tvoid print(char v) const {\n\t\
    \tputchar_unlocked(v);\n\t}\n\tvoid print(const char* v) const {\n\t\tfwrite_unlocked(v,\
    \ 1, strlen(v), stdout);\n\t}\n\tvoid print(double v) const {\n\t\tprintf(\"%.20f\"\
    , v);\n\t}\n\tvoid print(long double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t\
    }\n\ttemplate <class T> void print(const T& v) const {\n\t\tcout << v;\n\t}\n\t\
    template <class T, class U> void print(const pair<T, U>& v) const {\n\t\tprint(v.first);\n\
    \t\tprint(D.d);\n\t\tprint(v.second);\n\t}\n\ttemplate <class InputIterater>\n\
    \tvoid print_range(const InputIterater& begin, const InputIterater& end) const\
    \ {\n\t\tfor (InputIterater i = begin; i != end; ++i) {\n\t\t\tif (i != begin)\
    \ print(D.d);\n\t\t\tprint(*i);\n\t\t}\n\t}\n\ttemplate <class T> void print(const\
    \ vector<T>& v) const {\n\t\tprint_range(v.begin(), v.end());\n\t}\n\ttemplate\
    \ <class T, size_t N> void print(const array<T, N>& v) const {\n\t\tprint_range(v.begin(),\
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
    \treturn *this;\n\t}\n} out;\n\n// --- step --- //\ntemplate <class T> struct\
    \ Step {\n\tclass It {\n\t\tT a, b, c;\n\n\tpublic:\n\t\tconstexpr It() : a(T()),\
    \ b(T()), c(T()) {}\n\t\tconstexpr It(T _b, T _c, T _s) : a(_b), b(_c), c(_s)\
    \ {}\n\t\tconstexpr It& operator++() {\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tconstexpr It operator++(int) {\n\t\t\tIt tmp = *this;\n\t\
    \t\t--b;\n\t\t\ta += c;\n\t\t\treturn tmp;\n\t\t}\n\t\tconstexpr const T& operator*()\
    \ const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr const T* operator->() const {\n\
    \t\t\treturn &a;\n\t\t}\n\t\tconstexpr bool operator==(const It& i) const {\n\t\
    \t\treturn b == i.b;\n\t\t}\n\t\tconstexpr bool operator!=(const It& i) const\
    \ {\n\t\t\treturn !(b == i.b);\n\t\t}\n\t\tconstexpr T start() const {\n\t\t\t\
    return a;\n\t\t}\n\t\tconstexpr T count() const {\n\t\t\treturn b;\n\t\t}\n\t\t\
    constexpr T step() const {\n\t\t\treturn c;\n\t\t}\n\t};\n\tconstexpr Step(T b,\
    \ T c, T s) : be(b, c, s) {}\n\tconstexpr It begin() const {\n\t\treturn be;\n\
    \t}\n\tconstexpr It end() const {\n\t\treturn en;\n\t}\n\tconstexpr T start()\
    \ const {\n\t\treturn be.start();\n\t}\n\tconstexpr T count() const {\n\t\treturn\
    \ be.count();\n\t}\n\tconstexpr T step() const {\n\t\treturn be.step();\n\t}\n\
    \tconstexpr T sum() const {\n\t\treturn start() * count() + step() * (count()\
    \ * (count() - 1) / 2);\n\t}\n\toperator vector<T>() const {\n\t\treturn to_a();\n\
    \t}\n\ttemplate <class F> void each(const F& f) const {\n\t\tfor (T i : *this)\
    \ f(i);\n\t}\n\tauto to_a() const {\n\t\tvector<T> res;\n\t\tres.reserve(count());\n\
    \t\teach([&](T i) { res.push_back(i); });\n\t\treturn res;\n\t}\n\ttemplate <class\
    \ F, class U = decay_t<result_of_t<F(T)>>> auto map(const F& f) const {\n\t\t\
    vector<U> res;\n\t\tres.reserve(count());\n\t\teach([&](T i) { res.push_back(f(i));\
    \ });\n\t\treturn res;\n\t}\n\ttemplate <class F> auto select(const F& f) const\
    \ {\n\t\tvector<T> res;\n\t\teach([&](T i) {\n\t\t\tif (f(i)) res.push_back(i);\n\
    \t\t});\n\t\treturn res;\n\t}\n\ttemplate <class F> int count_if(const F& f) const\
    \ {\n\t\tint res = 0;\n\t\teach([&](T i) {\n\t\t\tif (f(i)) ++res;\n\t\t});\n\t\
    \treturn res;\n\t}\n\ttemplate <class F> T find_if(const F& f) const {\n\t\tfor\
    \ (T i : *this)\n\t\t\tif (f(i)) return i;\n\t\treturn 0;\n\t}\n\ttemplate <class\
    \ F> auto max_by(const F& f) const {\n\t\tauto v = map(f);\n\t\treturn *max_element(v.begin(),\
    \ v.end());\n\t}\n\ttemplate <class F> auto min_by(const F& f) const {\n\t\tauto\
    \ v = map(f);\n\t\treturn *min_element(v.begin(), v.end());\n\t}\n\ttemplate <class\
    \ F> bool all_of(const F& f) const {\n\t\tfor (T i : *this)\n\t\t\tif (!f(i))\
    \ return false;\n\t\treturn true;\n\t}\n\ttemplate <class F> bool any_of(const\
    \ F& f) const {\n\t\tfor (T i : *this)\n\t\t\tif (f(i)) return true;\n\t\treturn\
    \ false;\n\t}\n\ttemplate <class F, class U = decay_t<result_of_t<F(T)>>> auto\
    \ sum(const F& f) const {\n\t\tU res = 0;\n\t\teach([&](T i) { res += static_cast<U>(f(i));\
    \ });\n\t\treturn res;\n\t}\n\tusing value_type = T;\n\tusing iterator = It;\n\
    \nprivate:\n\tIt be, en;\n};\ntemplate <class T> constexpr auto step(T a) {\n\t\
    return Step<T>(0, a, 1);\n}\ntemplate <class T> constexpr auto step(T a, T b)\
    \ {\n\treturn Step<T>(a, b - a, 1);\n}\ntemplate <class T> constexpr auto step(T\
    \ a, T b, T c) {\n\treturn Step<T>(a, a < b ? (b - a - 1) / c + 1 : 0, c);\n}\n\
    \n// --- functions --- //\ninline namespace {\n\ttemplate <class T> void Sort(T&\
    \ a) {\n\t\tsort(all(a));\n\t}\n\ttemplate <class T> void RSort(T& a) {\n\t\t\
    sort(rall(a));\n\t}\n\ttemplate <class T, class F> void Sort(T& a, const F& f)\
    \ {\n\t\tsort(all(a), f);\n\t}\n\ttemplate <class T, class F> void RSort(T& a,\
    \ const F& f) {\n\t\tsort(rall(a), f);\n\t}\n\ttemplate <class T> T Sorted(T a)\
    \ {\n\t\tSort(a);\n\t\treturn a;\n\t}\n\ttemplate <class T> T RSorted(T a) {\n\
    \t\tRSort(a);\n\t\treturn a;\n\t}\n\ttemplate <class T, class F> T Sorted(T& a,\
    \ const F& f) {\n\t\tSort(a, f);\n\t\treturn a;\n\t}\n\ttemplate <class T, class\
    \ F> T RSorted(T& a, const F& f) {\n\t\tRSort(a, f);\n\t\treturn a;\n\t}\n\ttemplate\
    \ <class T, class F> void SortBy(T& a, const F& f) {\n\t\tsort(all(a), [&](const\
    \ auto& x, const auto& y) { return f(x) < f(y); });\n\t}\n\ttemplate <class T,\
    \ class F> void RSortBy(T& a, const F& f) {\n\t\tsort(rall(a), [&](const auto&\
    \ x, const auto& y) { return f(x) < f(y); });\n\t}\n\ttemplate <class T> void\
    \ Reverse(T& a) {\n\t\treverse(all(a));\n\t}\n\ttemplate <class T> void Unique(T&\
    \ a) {\n\t\ta.erase(unique(all(a)), a.end());\n\t}\n\ttemplate <class T> void\
    \ Uniq(T& a) {\n\t\tSort(a);\n\t\tUnique(a);\n\t}\n\ttemplate <class T> void Rotate(T&\
    \ a, int left) {\n\t\trotate(a.begin(), a.begin() + left, a.end());\n\t}\n\ttemplate\
    \ <class T> T Reversed(T a) {\n\t\tReverse(a);\n\t\treturn a;\n\t}\n\ttemplate\
    \ <class T> T Uniqued(T a) {\n\t\tUnique(a);\n\t\treturn a;\n\t}\n\ttemplate <class\
    \ T> T Uniqed(T a) {\n\t\tUniq(a);\n\t\treturn a;\n\t}\n\ttemplate <class T> T\
    \ Rotated(T a, int left) {\n\t\tRotate(a, left);\n\t\treturn a;\n\t}\n\ttemplate\
    \ <class T> auto Max(const T& a) {\n\t\treturn *max_element(all(a));\n\t}\n\t\
    template <class T> auto Min(const T& a) {\n\t\treturn *min_element(all(a));\n\t\
    }\n\ttemplate <class T> int MaxPos(const T& a) {\n\t\treturn max_element(all(a))\
    \ - a.begin();\n\t}\n\ttemplate <class T> int MinPos(const T& a) {\n\t\treturn\
    \ min_element(all(a)) - a.begin();\n\t}\n\ttemplate <class T, class F> auto MaxBy(const\
    \ T& a, const F& f) {\n\t\treturn *max_element(all(a),\n\t\t                 \
    \   [&](const auto& x, const auto& y) { return f(x) < f(y); });\n\t}\n\ttemplate\
    \ <class T, class F> auto MinBy(const T& a, const F& f) {\n\t\treturn *min_element(all(a),\n\
    \t\t                    [&](const auto& x, const auto& y) { return f(x) < f(y);\
    \ });\n\t}\n\ttemplate <class T, class F> auto MaxOf(const T& a, const F& f) {\n\
    \t\treturn Max(Map(a, f));\n\t}\n\ttemplate <class T, class F> auto MinOf(const\
    \ T& a, const F& f) {\n\t\treturn Min(Map(a, f));\n\t}\n\ttemplate <class T, class\
    \ U> int Count(const T& a, const U& v) {\n\t\treturn count(all(a), v);\n\t}\n\t\
    template <class T, class F> int CountIf(const T& a, const F& f) {\n\t\treturn\
    \ count_if(all(a), f);\n\t}\n\ttemplate <class T, class U> int Find(const T& a,\
    \ const U& v) {\n\t\treturn find(all(a), v) - a.begin();\n\t}\n\ttemplate <class\
    \ T, class F> int FindIf(const T& a, const F& f) {\n\t\treturn find_if(all(a),\
    \ f) - a.begin();\n\t}\n\ttemplate <class T, class U = typename T::value_type>\
    \ U Sum(const T& a) {\n\t\treturn accumulate(all(a), U());\n\t}\n\ttemplate <class\
    \ T, class U> bool Includes(const T& a, const U& v) {\n\t\treturn find(all(a),\
    \ v) != a.end();\n\t}\n\ttemplate <class T, class F> auto Sum(const T& v, const\
    \ F& f) {\n\t\treturn accumulate(next(v.begin()), v.end(), f(*v.begin()),\n\t\t\
    \                  [&](auto a, auto b) { return a + f(b); });\n\t}\n\ttemplate\
    \ <class T, class U> int Lower(const T& a, const U& v) {\n\t\treturn lower_bound(all(a),\
    \ v) - a.begin();\n\t}\n\ttemplate <class T, class U> int Upper(const T& a, const\
    \ U& v) {\n\t\treturn upper_bound(all(a), v) - a.begin();\n\t}\n\ttemplate <class\
    \ T, class F> void RemoveIf(T& a, const F& f) {\n\t\ta.erase(remove_if(all(a),\
    \ f), a.end());\n\t}\n\ttemplate <class F> auto Vector(size_t size, const F& f)\
    \ {\n\t\tvector<decay_t<result_of_t<F(size_t)>>> res(size);\n\t\tfor (size_t i\
    \ = 0; i < size; ++i) res[i] = f(i);\n\t\treturn res;\n\t}\n\ttemplate <class\
    \ T> auto Grid(size_t h, size_t w, const T& v = T()) {\n\t\treturn vector<vector<T>>(h,\
    \ vector<T>(w, v));\n\t}\n\ttemplate <class T> auto Slice(const T& v, size_t i,\
    \ size_t len) {\n\t\treturn i < v.size() ? T(v.begin() + i, v.begin() + min(i\
    \ + len, v.size())) : T();\n\t}\n\ttemplate <class T, class F> auto Each(const\
    \ T& v, F&& f) {\n\t\tfor (auto& i : v) f(i);\n\t}\n\ttemplate <class T, class\
    \ F> auto Select(const T& v, const F& f) {\n\t\tT res;\n\t\tfor (const auto& e\
    \ : v)\n\t\t\tif (f(e)) res.push_back(e);\n\t\treturn res;\n\t}\n\ttemplate <class\
    \ T, class F> auto Map(const T& v, F&& f) {\n\t\tvector<decay_t<result_of_t<F(typename\
    \ T::value_type)>>> res(v.size());\n\t\tsize_t i = 0;\n\t\tfor (const auto& e\
    \ : v) res[i++] = f(e);\n\t\treturn res;\n\t}\n\ttemplate <class T, class F> auto\
    \ MapIndex(const T& v, const F& f) {\n\t\tvector<decay_t<result_of_t<F(size_t,\
    \ typename T::value_type)>>> res(v.size());\n\t\tsize_t i = 0;\n\t\tfor (auto\
    \ it = v.begin(); it != v.end(); ++it, ++i) res[i] = f(i, *it);\n\t\treturn res;\n\
    \t}\n\ttemplate <class T, class F> auto TrueIndex(const T& v, const F& f) {\n\t\
    \tvector<size_t> res;\n\t\tfor (size_t i = 0; i < v.size(); ++i)\n\t\t\tif (f(v[i]))\
    \ res.push_back(i);\n\t\treturn res;\n\t}\n\ttemplate <class T, class U = typename\
    \ T::value_type> auto Indexed(const T& v) {\n\t\tvector<pair<U, int>> res(v.size());\n\
    \t\tfor (int i = 0; i < (int)v.size(); ++i)\n\t\t\tres[i] = make_pair(static_cast<U>(v[i]),\
    \ i);\n\t\treturn res;\n\t}\n\tauto operator*(string s, size_t n) {\n\t\tstring\
    \ res;\n\t\tfor (size_t i = 0; i < n; ++i) res += s;\n\t\treturn res;\n\t}\n\t\
    template <class T> auto& operator<<(vector<T>& v, const vector<T>& v2) {\n\t\t\
    v.insert(v.end(), all(v2));\n\t\treturn v;\n\t}\n\ttemplate <class T> T Ceil(T\
    \ n, T m) {\n\t\treturn (n + m - 1) / m;\n\t}\n\ttemplate <class T> T Ceil2(T\
    \ n, T m) {\n\t\treturn Ceil(n, m) * m;\n\t}\n\ttemplate <class T> T Tri(T n)\
    \ {\n\t\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n\t}\n\ttemplate\
    \ <class T> T nC2(T n) {\n\t\treturn (n & 1) ? (n - 1) / 2 * n : n / 2 * (n -\
    \ 1);\n\t}\n\ttemplate <class T> T Mid(const T& l, const T& r) {\n\t\treturn l\
    \ + (r - l) / 2;\n\t}\n\ttemplate <class T> bool chmax(T& a, const T& b) {\n\t\
    \tif (a < b) {\n\t\t\ta = b;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t\
    }\n\ttemplate <class T> bool chmin(T& a, const T& b) {\n\t\tif (a > b) {\n\t\t\
    \ta = b;\n\t\t\treturn true;\n\t\t}\n\t\treturn false;\n\t}\n\ttemplate <class\
    \ T> bool inRange(const T& v, const T& min, const T& max) {\n\t\treturn min <=\
    \ v && v < max;\n\t}\n\ttemplate <class T> bool isSquere(T n) {\n\t\tT s = sqrt(n);\n\
    \t\treturn s * s == n || (s + 1) * (s + 1) == n;\n\t}\n\ttemplate <class T = long\
    \ long> T BIT(int b) {\n\t\treturn T(1) << b;\n\t}\n\ttemplate <class T> T Gcd(T\
    \ n, T m) {\n\t\treturn m ? Gcd(m, n % m) : n;\n\t}\n\ttemplate <class T> T Lcm(T\
    \ n, T m) {\n\t\treturn n / Gcd(n, m) * m;\n\t}\n\ttemplate <class T, class U\
    \ = typename T::value_type> U Gcdv(const T& v) {\n\t\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), Gcd<U>);\n\t}\n\ttemplate <class T, class U = typename\
    \ T::value_type> U Lcmv(const T& v) {\n\t\treturn accumulate(next(v.begin()),\
    \ v.end(), U(*v.begin()), Lcm<U>);\n\t}\n\ttemplate <class T> T Pow(T a, T n)\
    \ {\n\t\tT r = 1;\n\t\twhile (n > 0) {\n\t\t\tif (n & 1) r *= a;\n\t\t\ta *= a;\n\
    \t\t\tn /= 2;\n\t\t}\n\t\treturn r;\n\t}\n\ttemplate <class T> T Powmod(T a, T\
    \ n, T m = MOD) {\n\t\tT r = 1;\n\t\twhile (n > 0) {\n\t\t\tif (n & 1)\n\t\t\t\
    \tr = r * a % m, n--;\n\t\t\telse\n\t\t\t\ta = a * a % m, n /= 2;\n\t\t}\n\t\t\
    return r;\n\t}\n}  // namespace\n\n// --- dump --- //\n#if __has_include(<library/dump.hpp>)\n\
    #include <library/dump.hpp>\n#else\n#define dump(...) ((void)0)\n#endif\n\n//\
    \ ---------------------------------------------------------------- //\n"
  dependsOn: []
  isVerificationFile: false
  path: template14.cpp
  requiredBy: []
  timestamp: '2020-12-20 11:57:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template14.cpp
layout: document
redirect_from:
- /library/template14.cpp
- /library/template14.cpp.html
title: template14.cpp
---
