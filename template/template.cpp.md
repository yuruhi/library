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
    \ 4 \"template/constants.cpp\"\n#include <string_view>\n#line 7 \"template/constants.cpp\"\
    \nusing namespace std;\n\n#define rep(i, n) for (int i = 0; i < (n); ++i)\n#define\
    \ FOR(i, m, n) for (int i = (m); i < (n); ++i)\n#define rrep(i, n) for (int i\
    \ = (n)-1; i >= 0; --i)\n#define rfor(i, m, n) for (int i = (m); i >= (n); --i)\n\
    #define unless(c) if (!(c))\n#define all(x) (x).begin(), (x).end()\n#define rall(x)\
    \ (x).rbegin(), (x).rend()\n#define range_it(a, l, r) (a).begin() + (l), (a).begin()\
    \ + (r)\n\nusing namespace std;\nusing ll = long long;\nusing LD = long double;\n\
    using VB = vector<bool>;\nusing VVB = vector<VB>;\nusing VI = vector<int>;\nusing\
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
    \    no_endl(\" \", \"\");\nclass Output {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\
    \npublic:\n\tvoid put(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr,\
    \ e] = to_chars(begin(buf), end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char),\
    \ ptr - buf, stdout);\n\t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid\
    \ put(long long v) const {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid put(bool v) const {\n\t\
    \tput(v ? B.t : B.f);\n\t}\n\tvoid put(char v) const {\n\t\tputchar_unlocked(v);\n\
    \t}\n\tvoid put(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v), stdout);\n\
    \t}\n\tvoid put(double v) const {\n\t\tprintf(\"%.20f\", v);\n\t}\n\tvoid put(long\
    \ double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t}\n\ttemplate <class T> void\
    \ put(const T& v) const {\n\t\tcout << v;\n\t}\n\ttemplate <class T, class U>\
    \ void put(const pair<T, U>& v) const {\n\t\tput(v.first);\n\t\tput(D.d);\n\t\t\
    put(v.second);\n\t}\n\ttemplate <class InputIterater>\n\tvoid put_range(const\
    \ InputIterater& begin, const InputIterater& end) const {\n\t\tfor (InputIterater\
    \ i = begin; i != end; ++i) {\n\t\t\tif (i != begin) put(D.d);\n\t\t\tput(*i);\n\
    \t\t}\n\t}\n\ttemplate <class T> void put(const vector<T>& v) const {\n\t\tput_range(v.begin(),\
    \ v.end());\n\t}\n\ttemplate <class T, size_t N> void put(const array<T, N>& v)\
    \ const {\n\t\tput_range(v.begin(), v.end());\n\t}\n\ttemplate <class T> void\
    \ put(const vector<vector<T>>& v) const {\n\t\tfor (size_t i = 0; i < v.size();\
    \ ++i) {\n\t\t\tif (i) put(D.l);\n\t\t\tput(v[i]);\n\t\t}\n\t}\n\n\tOutput() =\
    \ default;\n\tOutput(const BoolStr& _boolstr, const DivStr& _divstr) : B(_boolstr),\
    \ D(_divstr) {}\n\tOutput& operator()() {\n\t\tput(D.l);\n\t\treturn *this;\n\t\
    }\n\ttemplate <class H> Output& operator()(H&& h) {\n\t\tput(h);\n\t\tput(D.l);\n\
    \t\treturn *this;\n\t}\n\ttemplate <class H, class... T> Output& operator()(H&&\
    \ h, T&&... t) {\n\t\tput(h);\n\t\tput(D.d);\n\t\treturn operator()(forward<T>(t)...);\n\
    \t}\n\ttemplate <class InputIterator>\n\tOutput& range(const InputIterator& begin,\
    \ const InputIterator& end) {\n\t\tput_range(begin, end);\n\t\tput(D.l);\n\t\t\
    return *this;\n\t}\n\ttemplate <class T> Output& range(const T& a) {\n\t\trange(a.begin(),\
    \ a.end());\n\t\treturn *this;\n\t}\n\ttemplate <class... T> void exit(T&&...\
    \ t) {\n\t\toperator()(forward<T>(t)...);\n\t\tstd::exit(EXIT_SUCCESS);\n\t}\n\
    \tOutput& flush() {\n\t\tfflush_unlocked(stdout);\n\t\treturn *this;\n\t}\n\t\
    Output& set(const BoolStr& b) {\n\t\tB = b;\n\t\treturn *this;\n\t}\n\tOutput&\
    \ set(const DivStr& d) {\n\t\tD = d;\n\t\treturn *this;\n\t}\n\tOutput& set(const\
    \ char* t, const char* f) {\n\t\tB = BoolStr(t, f);\n\t\treturn *this;\n\t}\n\
    } out;\n#line 3 \"template/Step.cpp\"\nusing namespace std;\n\ntemplate <class\
    \ T> struct Step {\n\tusing value_type = T;\n\n\tclass iterator {\n\t\tvalue_type\
    \ a, b, c;\n\n\tpublic:\n\t\tconstexpr iterator() : a(value_type()), b(value_type()),\
    \ c(value_type()) {}\n\t\tconstexpr iterator(value_type _b, value_type _c, value_type\
    \ _s)\n\t\t    : a(_b), b(_c), c(_s) {}\n\t\tconstexpr iterator& operator++()\
    \ {\n\t\t\t--b;\n\t\t\ta += c;\n\t\t\treturn *this;\n\t\t}\n\t\tconstexpr iterator\
    \ operator++(int) {\n\t\t\titerator tmp = *this;\n\t\t\t--b;\n\t\t\ta += c;\n\t\
    \t\treturn tmp;\n\t\t}\n\t\tconstexpr const value_type& operator*() const {\n\t\
    \t\treturn a;\n\t\t}\n\t\tconstexpr const value_type* operator->() const {\n\t\
    \t\treturn &a;\n\t\t}\n\t\tconstexpr bool operator==(const iterator& i) const\
    \ {\n\t\t\treturn b == i.b;\n\t\t}\n\t\tconstexpr bool operator!=(const iterator&\
    \ i) const {\n\t\t\treturn !(b == i.b);\n\t\t}\n\t\tconstexpr value_type start()\
    \ const {\n\t\t\treturn a;\n\t\t}\n\t\tconstexpr value_type size() const {\n\t\
    \t\treturn b;\n\t\t}\n\t\tconstexpr value_type step() const {\n\t\t\treturn c;\n\
    \t\t}\n\t};\n\tconstexpr Step(value_type b, value_type c, value_type s) : be(b,\
    \ c, s) {}\n\tconstexpr iterator begin() const {\n\t\treturn be;\n\t}\n\tconstexpr\
    \ iterator end() const {\n\t\treturn en;\n\t}\n\tconstexpr value_type start()\
    \ const {\n\t\treturn be.start();\n\t}\n\tconstexpr value_type size() const {\n\
    \t\treturn be.size();\n\t}\n\tconstexpr value_type step() const {\n\t\treturn\
    \ be.step();\n\t}\n\tconstexpr value_type sum() const {\n\t\treturn start() *\
    \ size() + step() * (size() * (size() - 1) / 2);\n\t}\n\toperator vector<value_type>()\
    \ const {\n\t\treturn to_a();\n\t}\n\tauto to_a() const {\n\t\tvector<value_type>\
    \ result;\n\t\tresult.reserve(size());\n\t\tfor (auto i : *this) {\n\t\t\tresult.push_back(i);\n\
    \t\t}\n\t\treturn result;\n\t}\n\nprivate:\n\titerator be, en;\n};\ntemplate <class\
    \ T> constexpr auto step(T a) {\n\treturn Step<T>(0, a, 1);\n}\ntemplate <class\
    \ T> constexpr auto step(T a, T b) {\n\treturn Step<T>(a, b - a, 1);\n}\ntemplate\
    \ <class T> constexpr auto step(T a, T b, T c) {\n\treturn Step<T>(a, a < b ?\
    \ (b - a - 1) / c + 1 : 0, c);\n}\n#line 8 \"template/Ruby.cpp\"\nusing namespace\
    \ std;\n\ntemplate <class F> struct Callable {\n\tF func;\n\tCallable(const F&\
    \ f) : func(f) {}\n};\ntemplate <class T, class F> auto operator|(const T& v,\
    \ const Callable<F>& c) {\n\treturn c.func(v);\n}\n\nstruct Sort_impl {\n\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    sort(begin(v), end(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class T>\
    \ friend auto operator|(T v, [[maybe_unused]] const Sort_impl& c) {\n\t\tsort(begin(v),\
    \ end(v));\n\t\treturn v;\n\t}\n} Sort;\nstruct SortBy_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tsort(begin(v),\
    \ end(v),\n\t\t\t     [&](const auto& i, const auto& j) { return f(i) < f(j);\
    \ });\n\t\t\treturn v;\n\t\t});\n\t}\n} SortBy;\nstruct RSort_impl {\n\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    sort(rbegin(v), rend(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class\
    \ T> friend auto operator|(T v, [[maybe_unused]] const RSort_impl& c) {\n\t\t\
    sort(rbegin(v), rend(v));\n\t\treturn v;\n\t}\n} RSort;\nstruct RSortBy_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tsort(begin(v), end(v),\n\t\t\t     [&](const auto& i, const auto& j)\
    \ { return f(i) > f(j); });\n\t\t\treturn v;\n\t\t});\n\t}\n} RSortBy;\nstruct\
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
    \ v) { return *max_element(begin(v), end(v), f); });\n\t}\n\ttemplate <class T>\
    \ friend auto operator|(T v, const Max_impl& c) {\n\t\treturn *max_element(begin(v),\
    \ end(v));\n\t}\n} Max;\nstruct Min_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) { return *min_element(begin(v), end(v),\
    \ f); });\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Min_impl&\
    \ c) {\n\t\treturn *min_element(begin(v), end(v));\n\t}\n} Min;\nstruct MaxPos_impl\
    \ {\n\ttemplate <class T> friend auto operator|(T v, const MaxPos_impl& c) {\n\
    \t\treturn max_element(begin(v), end(v)) - begin(v);\n\t}\n} MaxPos;\nstruct MinPos_impl\
    \ {\n\ttemplate <class T> friend auto operator|(T v, const MinPos_impl& c) {\n\
    \t\treturn min_element(begin(v), end(v)) - begin(v);\n\t}\n} MinPos;\nstruct MaxBy_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tauto max_it = begin(v);\n\t\t\tauto max_val = f(*max_it);\n\t\t\t\
    for (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it);\
    \ max_val < val) {\n\t\t\t\t\tmax_it = it;\n\t\t\t\t\tmax_val = val;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\treturn *max_it;\n\t\t});\n\t}\n} MaxBy;\nstruct MinBy_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tauto min_it = begin(v);\n\t\t\tauto min_val = f(*min_it);\n\t\t\tfor\
    \ (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it);\
    \ min_val > val) {\n\t\t\t\t\tmin_it = it;\n\t\t\t\t\tmin_val = val;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\treturn *min_it;\n\t\t});\n\t}\n} MinBy;\nstruct MaxOf_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tauto max_val = f(*begin(v));\n\t\t\tfor (auto it = next(begin(v));\
    \ it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); max_val < val) {\n\t\t\
    \t\t\tmax_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn max_val;\n\t\t});\n\t}\n\
    } MaxOf;\nstruct MinOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\
    \t\treturn Callable([&](auto v) {\n\t\t\tauto min_val = f(*begin(v));\n\t\t\t\
    for (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it);\
    \ min_val > val) {\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ min_val;\n\t\t});\n\t}\n} MinOf;\nstruct Count_impl {\n\ttemplate <class V>\
    \ auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) { return count(begin(v),\
    \ end(v), val); });\n\t}\n} Count;\nstruct CountIf_impl {\n\ttemplate <class F>\
    \ auto operator()(const F& f) {\n\t\treturn Callable([&](auto v) { return count_if(begin(v),\
    \ end(v), f); });\n\t}\n} CountIf;\nstruct Index_impl {\n\ttemplate <class V>\
    \ auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) -> optional<int>\
    \ {\n\t\t\tauto result = find(begin(v), end(v), val);\n\t\t\treturn result !=\
    \ end(v) ? optional(result - begin(v)) : nullopt;\n\t\t});\n\t}\n} Index;\nstruct\
    \ IndexIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn\
    \ Callable([&](auto v) -> optional<int> {\n\t\t\tauto result = find_if(begin(v),\
    \ end(v), f);\n\t\t\treturn result != end(v) ? optional(result - begin(v)) : nullopt;\n\
    \t\t});\n\t}\n} IndexIf;\nstruct FindIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) -> optional<typename decltype(v)::value_type>\
    \ {\n\t\t\tauto result = find_if(begin(v), end(v), f);\n\t\t\treturn result !=\
    \ end(v) ? optional(*result) : nullopt;\n\t\t});\n\t}\n} FindIf;\nstruct Sum_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\treturn accumulate(next(begin(v)), end(v), f(*begin(v)),\n\t\t\t\
    \                  [&](const auto& a, const auto& b) { return a + f(b); });\n\t\
    \t});\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Sum_impl& c)\
    \ {\n\t\treturn accumulate(begin(v), end(v), typename T::value_type{});\n\t}\n\
    } Sum;\nstruct Includes {\n\ttemplate <class V> auto operator()(const V& val)\
    \ {\n\t\treturn Callable([&](auto v) { return find(begin(v), end(v), val) != end(v);\
    \ });\n\t}\n} Includes;\nstruct IncludesIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) { return find_if(begin(v), end(v),\
    \ f) != end(v); });\n\t}\n} IncludesIf;\nstruct RemoveIf_impl {\n\ttemplate <class\
    \ F> auto operator()(const F& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    v.erase(remove_if(begin(v), end(v), f), end(v));\n\t\t\treturn v;\n\t\t});\n\t\
    }\n} RemoveIf;\nstruct Each_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\
    \tf(i);\n\t\t\t}\n\t\t});\n\t}\n} Each;\nstruct Select_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tusing\
    \ value_type = typename decltype(v)::value_type;\n\t\t\tvector<value_type> result;\n\
    \t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) result.push_back(i);\n\t\t\t\
    }\n\t\t\treturn result;\n\t\t});\n\t}\n} Select;\nstruct Map_impl {\n\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    using result_type = invoke_result_t<F, typename decltype(v)::value_type>;\n\t\t\
    \tvector<result_type> result;\n\t\t\tresult.reserve(size(v));\n\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\tresult.push_back(f(i));\n\t\t\t}\n\t\t\treturn result;\n\
    \t\t});\n\t}\n} Map;\nstruct Indexed_impl {\n\ttemplate <class T> friend auto\
    \ operator|(const T& v, Indexed_impl& c) {\n\t\tusing value_type = typename T::value_type;\n\
    \t\tvector<pair<value_type, int>> result;\n\t\tresult.reserve(size(v));\n\t\t\
    int index = 0;\n\t\tfor (const auto& i : v) {\n\t\t\tresult.emplace_back(i, index++);\n\
    \t\t}\n\t\treturn result;\n\t}\n} Indexed;\nstruct AllOf_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\tif (!f(i)) return false;\n\t\t\t}\n\t\t\treturn true;\n\
    \t\t});\n\t}\n} AllOf;\nstruct AnyOf_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\
    \t\t\tif (f(i)) return true;\n\t\t\t}\n\t\t\treturn false;\n\t\t});\n\t}\n} AnyOf;\n\
    struct NoneOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return\
    \ false;\n\t\t\t}\n\t\t\treturn true;\n\t\t});\n\t}\n} NoneOf;\n\nstruct Tally_impl\
    \ {\n\ttemplate <class F> auto operator()(size_t max_val) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tvector<size_t> result(max_val);\n\t\t\tfor (const auto& i : v) {\n\
    \t\t\t\tresult[static_cast<size_t>(i)]++;\n\t\t\t}\n\t\t\treturn result;\n\t\t\
    });\n\t}\n\ttemplate <class T, class value_type = typename T::value_type>\n\t\
    friend auto operator|(const T& v, Tally_impl& c) {\n\t\tmap<value_type, size_t>\
    \ result;\n\t\tfor (const auto& i : v) {\n\t\t\tresult[i]++;\n\t\t}\n\t\treturn\
    \ result;\n\t}\n} Tally;\n\ntemplate <class T> auto operator*(const vector<T>&\
    \ a, size_t n) {\n\tT result;\n\tfor (size_t i = 0; i < n; ++i) {\n\t\tresult.insert(result.end(),\
    \ a.begin(), a.end());\n\t}\n\treturn result;\n}\nauto operator*(string a, size_t\
    \ n) {\n\tstring result;\n\tfor (size_t i = 0; i < n; ++i) {\n\t\tresult += a;\n\
    \t}\n\treturn result;\n}\ntemplate <class T, class U> auto& operator<<(vector<T>&\
    \ a, const U& b) {\n\ta.insert(a.end(), all(b));\n\treturn a;\n}\ntemplate <class\
    \ T> auto& operator<<(string& a, const T& b) {\n\ta.insert(a.end(), all(b));\n\
    \treturn a;\n}\ntemplate <class T, class U> auto operator+(vector<T> a, const\
    \ U& b) {\n\ta << b;\n\treturn a;\n}\ntemplate <class T> auto operator+(string\
    \ a, const T& b) {\n\ta << b;\n\treturn a;\n}\n#line 6 \"template/functions.cpp\"\
    \nusing namespace std;\n\ntemplate <class T> int sz(const T& v) {\n\treturn v.size();\n\
    }\ntemplate <class T, class U> int lower_index(const T& a, const U& v) {\n\treturn\
    \ lower_bound(all(a), v) - a.begin();\n}\ntemplate <class T, class U> int upper_index(const\
    \ T& a, const U& v) {\n\treturn upper_bound(all(a), v) - a.begin();\n}\ntemplate\
    \ <class T> auto Slice(const T& v, size_t i, size_t len) {\n\treturn i < v.size()\
    \ ? T(v.begin() + i, v.begin() + min(i + len, v.size())) : T();\n}\ntemplate <class\
    \ T> T div_ceil(T n, T m) {\n\treturn (n + m - 1) / m;\n}\ntemplate <class T>\
    \ T div_ceil2(T n, T m) {\n\treturn div_ceil(n, m) * m;\n}\ntemplate <class T>\
    \ T triangle(T n) {\n\treturn (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1);\n}\n\
    template <class T> T nC2(T n) {\n\treturn (n & 1) ? (n - 1) / 2 * n : n / 2 *\
    \ (n - 1);\n}\ntemplate <class T> T middle(const T& l, const T& r) {\n\treturn\
    \ l + (r - l) / 2;\n}\ntemplate <class T> bool chmax(T& a, const T& b) {\n\tif\
    \ (a < b) {\n\t\ta = b;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class\
    \ T> bool chmin(T& a, const T& b) {\n\tif (a > b) {\n\t\ta = b;\n\t\treturn true;\n\
    \t}\n\treturn false;\n}\ntemplate <class T> bool in_range(const T& v, const T&\
    \ min, const T& max) {\n\treturn min <= v && v < max;\n}\ntemplate <class T> bool\
    \ in_square(T n) {\n\tT s = sqrt(n);\n\treturn s * s == n || (s + 1) * (s + 1)\
    \ == n;\n}\ntemplate <class T = long long> T BIT(int b) {\n\treturn T(1) << b;\n\
    }\ntemplate <class T, class U = typename T::value_type> U Gcdv(const T& v) {\n\
    \treturn accumulate(next(v.begin()), v.end(), U(*v.begin()), gcd<U, U>);\n}\n\
    template <class T, class U = typename T::value_type> U Lcmv(const T& v) {\n\t\
    return accumulate(next(v.begin()), v.end(), U(*v.begin()), lcm<U, U>);\n}\ntemplate\
    \ <class T, class U> T Pow(T a, U n) {\n\tT result = 1;\n\twhile (n > 0) {\n\t\
    \tif (n & 1) {\n\t\t\tresult *= a;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta *= a;\n\t\
    \t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\ntemplate <class T, class U> T Powmod(T\
    \ a, U n, T mod) {\n\tT result = 1;\n\twhile (n > 0) {\n\t\tif (n & 1) {\n\t\t\
    \tresult = result * a % mod;\n\t\t\tn--;\n\t\t} else {\n\t\t\ta = a * a % mod;\n\
    \t\t\tn >>= 1;\n\t\t}\n\t}\n\treturn result;\n}\nnamespace internal {\n\ttemplate\
    \ <class T, size_t N> auto make_vector(vector<int>& sizes, const T& init) {\n\t\
    \tif constexpr (N == 1) {\n\t\t\treturn vector(sizes[0], init);\n\t\t} else {\n\
    \t\t\tint size = sizes[N - 1];\n\t\t\tsizes.pop_back();\n\t\t\treturn vector(size,\
    \ make_vector<T, N - 1>(sizes, init));\n\t\t}\n\t}\n}  // namespace internal\n\
    template <class T, size_t N>\nauto make_vector(const int (&sizes)[N], const T&\
    \ init = T()) {\n\tvector s(rbegin(sizes), rend(sizes));\n\treturn internal::make_vector<T,\
    \ N>(s, init);\n}\n#line 9 \"template/template.cpp\"\n#if __has_include(<library/dump.hpp>)\n\
    #include <library/dump.hpp>\n#define LOCAL\n#else\n#define dump(...) ((void)0)\n\
    #endif\n\ntemplate <class T> constexpr T oj_local(const T& oj, const T& local)\
    \ {\n#ifndef LOCAL\n\treturn oj;\n#else\n\treturn local;\n#endif\n}\n"
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
  timestamp: '2020-11-29 15:45:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.cpp
layout: document
redirect_from:
- /library/template/template.cpp
- /library/template/template.cpp.html
title: template/template.cpp
---
