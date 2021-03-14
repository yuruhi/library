---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template17.cpp
    title: template17.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dump.hpp\"\n#include <iostream>\n#include <iomanip>\n#include\
    \ <string>\n#include <vector>\n#include <array>\n#include <map>\n#include <set>\n\
    #include <unordered_set>\n#include <list>\n#include <stack>\n#include <queue>\n\
    #include <utility>\n#include <tuple>\n#include <cassert>\n#include <climits>\n\
    #ifdef __cpp_lib_optional\n#include <optional>\n#endif\n\nnamespace Debug {\n\t\
    struct AtFirst {\n\t\tAtFirst() {\n\t\t\tstd::cerr << std::fixed << std::setprecision(6);\n\
    \t\t}\n\t};\n\t// AtFirst at_first;\n\n\tconst std::string BeginLine = \"..|\"\
    , EndLine = \"\\n\" + BeginLine;\n\tconst std::string Begin = \"{ \", End = \"\
    \ }\";\n\tconst std::string Empty = \"{ empty }\", Separate = \", \", Indent =\
    \ \"  \";\n\tconst std::string True = \"O\", False = \"X\";\n\tvoid FirstLine(int\
    \ line, std::string func) {\n\t\tstd::cerr << BeginLine + std::string(15, '-')\
    \ << line << \" : \" << func\n\t\t          << std::string(15, '-') << EndLine;\n\
    \t}\n\n\ttemplate <class T> void DebugPrint(const T& v);\n\tvoid DebugPrint(const\
    \ int v);\n\tvoid DebugPrint(const long long v);\n\tvoid DebugPrint(const bool\
    \ v);\n\tvoid DebugPrint(const char v);\n\tvoid DebugPrint(const char* v);\n\t\
    void DebugPrint(const std::string& v);\n\ttemplate <class T, class U> void DebugPrint(const\
    \ std::pair<T, U>& v);\n#ifdef __cpp_lib_optional\n\ttemplate <class T> void DebugPrint(const\
    \ std::optional<T>& v);\n#endif\n#ifdef __cpp_if_constexpr\n\ttemplate <std::size_t\
    \ N = 0, class T> void print_tuple_impl(const T& v);\n\ttemplate <class... T>\
    \ void DebugPrint(const std::tuple<T...>& v);\n#endif\n\ttemplate <class T> void\
    \ DebugPrint(const std::vector<T>& v);\n\ttemplate <class T, std::size_t N> void\
    \ DebugPrint(const std::array<T, N>& v);\n\ttemplate <class T> void DebugPrint(const\
    \ std::vector<std::vector<T>>& v);\n\ttemplate <class T, class U> void DebugPrint(const\
    \ std::map<T, U>& v);\n\ttemplate <class T> void DebugPrint(const std::set<T>&\
    \ v);\n\ttemplate <class T> void DebugPrint(const std::multiset<T>& v);\n\ttemplate\
    \ <class T> void DebugPrint(const std::unordered_set<T>& v);\n\ttemplate <class\
    \ T> void DebugPrint(const std::list<T>& v);\n\ttemplate <class T> void DebugPrint(std::stack<T>\
    \ v);\n\ttemplate <class T> void DebugPrint(std::queue<T> v);\n\ttemplate <class\
    \ T, class U, class V> void DebugPrint(std::priority_queue<T, U, V> v);\n\ttemplate\
    \ <class T> void DebugPrint(std::deque<T> v);\n\n\ttemplate <class T> void DebugPrint(const\
    \ T& v) {\n\t\tstd::cerr << v;\n\t}\n\tvoid DebugPrint(const int v) {\n\t\tif\
    \ (v == INT_MAX) {\n\t\t\tstd::cerr << \"MAX\";\n\t\t} else if (v == INT_MIN)\
    \ {\n\t\t\tstd::cerr << \"MIN\";\n\t\t} else {\n\t\t\tstd::cerr << v;\n\t\t}\n\
    \t}\n\tvoid DebugPrint(const long long v) {\n\t\tif (v == LLONG_MAX) {\n\t\t\t\
    std::cerr << \"MAX\";\n\t\t} else if (v == LLONG_MIN) {\n\t\t\tstd::cerr << \"\
    MIN\";\n\t\t} else {\n\t\t\tstd::cerr << v;\n\t\t}\n\t}\n\tvoid DebugPrint(const\
    \ bool v) {\n\t\tstd::cerr << (v ? True : False);\n\t}\n\tvoid DebugPrint(const\
    \ char v) {\n\t\tstd::cerr << '\\'' << v << '\\'';\n\t}\n\tvoid DebugPrint(const\
    \ char* v) {\n\t\tstd::cerr << '\\\"' << v << '\\\"';\n\t}\n\tvoid DebugPrint(const\
    \ std::string& v) {\n\t\tstd::cerr << '\\\"' << v << '\\\"';\n\t}\n\ttemplate\
    \ <class T, class U> void DebugPrint(const std::pair<T, U>& v) {\n\t\tstd::cerr\
    \ << \"(\";\n\t\tDebugPrint(v.first);\n\t\tstd::cerr << \", \";\n\t\tDebugPrint(v.second);\n\
    \t\tstd::cerr << \")\";\n\t}\n#ifdef __cpp_lib_optional\n\ttemplate <class T>\
    \ void DebugPrint(const std::optional<T>& v) {\n\t\tif (v) {\n\t\t\tDebugPrint(*v);\n\
    \t\t} else {\n\t\t\tstd::cerr << '-';\n\t\t}\n\t}\n#endif\n#ifdef __cpp_if_constexpr\n\
    \ttemplate <std::size_t N = 0, class T> void print_tuple_impl(const T& v) {\n\t\
    \tif constexpr (N < std::tuple_size_v<T>) {\n\t\t\tDebugPrint(std::get<N>(v));\n\
    \t\t\tif constexpr (N < std::tuple_size_v<T> - 1) {\n\t\t\t\tstd::cerr << Separate;\n\
    \t\t\t}\n\t\t\tprint_tuple_impl<N + 1>(v);\n\t\t}\n\t}\n\ttemplate <class... T>\
    \ void DebugPrint(const std::tuple<T...>& v) {\n\t\tstd::cerr << Begin;\n\t\t\
    print_tuple_impl(v);\n\t\tstd::cerr << End;\n\t}\n#endif\n\ttemplate <class T>\
    \ void DebugPrint(const std::vector<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr\
    \ << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (std::size_t i\
    \ = 0; i < v.size(); ++i) {\n\t\t\t\tif (i) std::cerr << Separate;\n\t\t\t\tDebugPrint(v[i]);\n\
    \t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T, std::size_t\
    \ N> void DebugPrint(const std::array<T, N>& v) {\n\t\tif (v.empty()) {\n\t\t\t\
    std::cerr << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (std::size_t\
    \ i = 0; i < N; ++i) {\n\t\t\t\tif (i) std::cerr << Separate;\n\t\t\t\tDebugPrint(v[i]);\n\
    \t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ std::vector<std::vector<T>>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr <<\
    \ Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin << EndLine;\n\t\t\tfor (std::size_t\
    \ i = 0; i < v.size(); i++) {\n\t\t\t\tstd::cerr << Indent << \"[\" << i << \"\
    ] \";\n\t\t\t\tDebugPrint(v[i]);\n\t\t\t\tstd::cerr << EndLine;\n\t\t\t}\n\t\t\
    \tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T, class U> void DebugPrint(const\
    \ std::map<T, U>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t\
    } else {\n\t\t\tstd::cerr << Begin << EndLine;\n\t\t\tfor (const auto& i : v)\
    \ {\n\t\t\t\tstd::cerr << Indent;\n\t\t\t\tDebugPrint(i.first);\n\t\t\t\tstd::cerr\
    \ << \" : \";\n\t\t\t\tDebugPrint(i.second);\n\t\t\t\tstd::cerr << EndLine;\n\t\
    \t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ std::set<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t} else\
    \ {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (auto it = v.begin(); it != v.end();\
    \ ++it) {\n\t\t\t\tif (it != v.begin()) std::cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\
    \t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ std::multiset<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t\
    } else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (auto it = v.begin(); it != v.end();\
    \ ++it) {\n\t\t\t\tif (it != v.begin()) std::cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\
    \t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ std::unordered_set<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\
    \t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (auto it = v.begin(); it !=\
    \ v.end(); ++it) {\n\t\t\t\tif (it != v.begin()) std::cerr << Separate;\n\t\t\t\
    \tDebugPrint(*it);\n\t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class\
    \ T> void DebugPrint(const std::list<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr\
    \ << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (auto it = v.begin();\
    \ it != v.end(); ++it) {\n\t\t\t\tif (it != v.begin()) std::cerr << Separate;\n\
    \t\t\t\tDebugPrint(*it);\n\t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate\
    \ <class T> void DebugPrint(std::stack<T> v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr\
    \ << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\twhile (!v.empty())\
    \ {\n\t\t\t\tDebugPrint(v.top());\n\t\t\t\tv.pop();\n\t\t\t\tif (!v.empty()) std::cerr\
    \ << Separate;\n\t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class\
    \ T> void DebugPrint(std::queue<T> v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr\
    \ << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\twhile (!v.empty())\
    \ {\n\t\t\t\tDebugPrint(v.front());\n\t\t\t\tv.pop();\n\t\t\t\tif (!v.empty())\
    \ std::cerr << Separate;\n\t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate\
    \ <class T, class U, class V> void DebugPrint(std::priority_queue<T, U, V> v)\
    \ {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t} else {\n\t\t\tstd::cerr\
    \ << Begin;\n\t\t\twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.top());\n\t\t\t\t\
    v.pop();\n\t\t\t\tif (!v.empty()) std::cerr << Separate;\n\t\t\t}\n\t\t\tstd::cerr\
    \ << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(std::deque<T> v) {\n\
    \t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t} else {\n\t\t\tstd::cerr\
    \ << Begin;\n\t\t\twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.front());\n\t\t\t\
    \tv.pop_front();\n\t\t\t\tif (!v.empty()) std::cerr << Separate;\n\t\t\t}\n\t\t\
    \tstd::cerr << End;\n\t\t}\n\t}\n\n\tstd::queue<std::string> Name;\n\tvoid SetName(const\
    \ std::string& s) {\n\t\tint par = 0;\n\t\tstd::string name;\n\t\tfor (size_t\
    \ i = 0; i < s.size(); i++) {\n\t\t\tif (s[i] == '(' || s[i] == '{' ||\n\t\t\t\
    \    (s[i] == '<' && s[i + 1] != '=' && s[i - 1] != ' ' && s[i + 1] != ' ')) {\n\
    \t\t\t\tpar++;\n\t\t\t} else if (s[i] == ')' || s[i] == '}' ||\n\t\t\t       \
    \    (s[i] == '>' && s[i + 1] != '=' && s[i - 1] != ' ' &&\n\t\t\t           \
    \ s[i + 1] != ' ')) {\n\t\t\t\tpar--;\n\t\t\t}\n\t\t\tif (!par && s[i] == ',')\
    \ {\n\t\t\t\tName.push(name.front() == ' ' ? name.substr(1) : name);\n\t\t\t\t\
    name.clear();\n\t\t\t} else {\n\t\t\t\tname += s[i];\n\t\t\t}\n\t\t}\n\t\tName.push(name.front()\
    \ == ' ' ? name.substr(1) : name);\n\t}\n\n\ttemplate <class Head> void Dump(Head&&\
    \ h) {\n\t\tassert(!Name.empty());\n\t\tstd::cerr << Name.front() << \" = \";\n\
    \t\tDebugPrint(h);\n\t\tstd::cerr << \"\\n\";\n\t\tName.pop();\n\t}\n\ttemplate\
    \ <class Head, class... Tail> void Dump(Head&& h, Tail&&... t) {\n\t\tassert(!Name.empty());\n\
    \t\tstd::cerr << Name.front() << \" = \";\n\t\tDebugPrint(h);\n\t\tstd::cerr <<\
    \ EndLine;\n\t\tName.pop();\n\t\tDump(std::forward<Tail>(t)...);\n\t}\n};  //\
    \ namespace Debug\n\n#define dump(...)                                 \\\n\t\
    do {                                          \\\n\t\tDebug::FirstLine(__LINE__,\
    \ __FUNCTION__); \\\n\t\tDebug::SetName(#__VA_ARGS__);             \\\n\t\tDebug::Dump(__VA_ARGS__);\
    \                 \\\n\t} while (false)\n\n#define dump2(...)                \
    \    \\\n\tdo {                              \\\n\t\tDebug::SetName(#__VA_ARGS__);\
    \ \\\n\t\tDebug::Dump(__VA_ARGS__);     \\\n\t} while (false)\n"
  code: "#pragma once\n#include <iostream>\n#include <iomanip>\n#include <string>\n\
    #include <vector>\n#include <array>\n#include <map>\n#include <set>\n#include\
    \ <unordered_set>\n#include <list>\n#include <stack>\n#include <queue>\n#include\
    \ <utility>\n#include <tuple>\n#include <cassert>\n#include <climits>\n#ifdef\
    \ __cpp_lib_optional\n#include <optional>\n#endif\n\nnamespace Debug {\n\tstruct\
    \ AtFirst {\n\t\tAtFirst() {\n\t\t\tstd::cerr << std::fixed << std::setprecision(6);\n\
    \t\t}\n\t};\n\t// AtFirst at_first;\n\n\tconst std::string BeginLine = \"..|\"\
    , EndLine = \"\\n\" + BeginLine;\n\tconst std::string Begin = \"{ \", End = \"\
    \ }\";\n\tconst std::string Empty = \"{ empty }\", Separate = \", \", Indent =\
    \ \"  \";\n\tconst std::string True = \"O\", False = \"X\";\n\tvoid FirstLine(int\
    \ line, std::string func) {\n\t\tstd::cerr << BeginLine + std::string(15, '-')\
    \ << line << \" : \" << func\n\t\t          << std::string(15, '-') << EndLine;\n\
    \t}\n\n\ttemplate <class T> void DebugPrint(const T& v);\n\tvoid DebugPrint(const\
    \ int v);\n\tvoid DebugPrint(const long long v);\n\tvoid DebugPrint(const bool\
    \ v);\n\tvoid DebugPrint(const char v);\n\tvoid DebugPrint(const char* v);\n\t\
    void DebugPrint(const std::string& v);\n\ttemplate <class T, class U> void DebugPrint(const\
    \ std::pair<T, U>& v);\n#ifdef __cpp_lib_optional\n\ttemplate <class T> void DebugPrint(const\
    \ std::optional<T>& v);\n#endif\n#ifdef __cpp_if_constexpr\n\ttemplate <std::size_t\
    \ N = 0, class T> void print_tuple_impl(const T& v);\n\ttemplate <class... T>\
    \ void DebugPrint(const std::tuple<T...>& v);\n#endif\n\ttemplate <class T> void\
    \ DebugPrint(const std::vector<T>& v);\n\ttemplate <class T, std::size_t N> void\
    \ DebugPrint(const std::array<T, N>& v);\n\ttemplate <class T> void DebugPrint(const\
    \ std::vector<std::vector<T>>& v);\n\ttemplate <class T, class U> void DebugPrint(const\
    \ std::map<T, U>& v);\n\ttemplate <class T> void DebugPrint(const std::set<T>&\
    \ v);\n\ttemplate <class T> void DebugPrint(const std::multiset<T>& v);\n\ttemplate\
    \ <class T> void DebugPrint(const std::unordered_set<T>& v);\n\ttemplate <class\
    \ T> void DebugPrint(const std::list<T>& v);\n\ttemplate <class T> void DebugPrint(std::stack<T>\
    \ v);\n\ttemplate <class T> void DebugPrint(std::queue<T> v);\n\ttemplate <class\
    \ T, class U, class V> void DebugPrint(std::priority_queue<T, U, V> v);\n\ttemplate\
    \ <class T> void DebugPrint(std::deque<T> v);\n\n\ttemplate <class T> void DebugPrint(const\
    \ T& v) {\n\t\tstd::cerr << v;\n\t}\n\tvoid DebugPrint(const int v) {\n\t\tif\
    \ (v == INT_MAX) {\n\t\t\tstd::cerr << \"MAX\";\n\t\t} else if (v == INT_MIN)\
    \ {\n\t\t\tstd::cerr << \"MIN\";\n\t\t} else {\n\t\t\tstd::cerr << v;\n\t\t}\n\
    \t}\n\tvoid DebugPrint(const long long v) {\n\t\tif (v == LLONG_MAX) {\n\t\t\t\
    std::cerr << \"MAX\";\n\t\t} else if (v == LLONG_MIN) {\n\t\t\tstd::cerr << \"\
    MIN\";\n\t\t} else {\n\t\t\tstd::cerr << v;\n\t\t}\n\t}\n\tvoid DebugPrint(const\
    \ bool v) {\n\t\tstd::cerr << (v ? True : False);\n\t}\n\tvoid DebugPrint(const\
    \ char v) {\n\t\tstd::cerr << '\\'' << v << '\\'';\n\t}\n\tvoid DebugPrint(const\
    \ char* v) {\n\t\tstd::cerr << '\\\"' << v << '\\\"';\n\t}\n\tvoid DebugPrint(const\
    \ std::string& v) {\n\t\tstd::cerr << '\\\"' << v << '\\\"';\n\t}\n\ttemplate\
    \ <class T, class U> void DebugPrint(const std::pair<T, U>& v) {\n\t\tstd::cerr\
    \ << \"(\";\n\t\tDebugPrint(v.first);\n\t\tstd::cerr << \", \";\n\t\tDebugPrint(v.second);\n\
    \t\tstd::cerr << \")\";\n\t}\n#ifdef __cpp_lib_optional\n\ttemplate <class T>\
    \ void DebugPrint(const std::optional<T>& v) {\n\t\tif (v) {\n\t\t\tDebugPrint(*v);\n\
    \t\t} else {\n\t\t\tstd::cerr << '-';\n\t\t}\n\t}\n#endif\n#ifdef __cpp_if_constexpr\n\
    \ttemplate <std::size_t N = 0, class T> void print_tuple_impl(const T& v) {\n\t\
    \tif constexpr (N < std::tuple_size_v<T>) {\n\t\t\tDebugPrint(std::get<N>(v));\n\
    \t\t\tif constexpr (N < std::tuple_size_v<T> - 1) {\n\t\t\t\tstd::cerr << Separate;\n\
    \t\t\t}\n\t\t\tprint_tuple_impl<N + 1>(v);\n\t\t}\n\t}\n\ttemplate <class... T>\
    \ void DebugPrint(const std::tuple<T...>& v) {\n\t\tstd::cerr << Begin;\n\t\t\
    print_tuple_impl(v);\n\t\tstd::cerr << End;\n\t}\n#endif\n\ttemplate <class T>\
    \ void DebugPrint(const std::vector<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr\
    \ << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (std::size_t i\
    \ = 0; i < v.size(); ++i) {\n\t\t\t\tif (i) std::cerr << Separate;\n\t\t\t\tDebugPrint(v[i]);\n\
    \t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T, std::size_t\
    \ N> void DebugPrint(const std::array<T, N>& v) {\n\t\tif (v.empty()) {\n\t\t\t\
    std::cerr << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (std::size_t\
    \ i = 0; i < N; ++i) {\n\t\t\t\tif (i) std::cerr << Separate;\n\t\t\t\tDebugPrint(v[i]);\n\
    \t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ std::vector<std::vector<T>>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr <<\
    \ Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin << EndLine;\n\t\t\tfor (std::size_t\
    \ i = 0; i < v.size(); i++) {\n\t\t\t\tstd::cerr << Indent << \"[\" << i << \"\
    ] \";\n\t\t\t\tDebugPrint(v[i]);\n\t\t\t\tstd::cerr << EndLine;\n\t\t\t}\n\t\t\
    \tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T, class U> void DebugPrint(const\
    \ std::map<T, U>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t\
    } else {\n\t\t\tstd::cerr << Begin << EndLine;\n\t\t\tfor (const auto& i : v)\
    \ {\n\t\t\t\tstd::cerr << Indent;\n\t\t\t\tDebugPrint(i.first);\n\t\t\t\tstd::cerr\
    \ << \" : \";\n\t\t\t\tDebugPrint(i.second);\n\t\t\t\tstd::cerr << EndLine;\n\t\
    \t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ std::set<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t} else\
    \ {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (auto it = v.begin(); it != v.end();\
    \ ++it) {\n\t\t\t\tif (it != v.begin()) std::cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\
    \t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ std::multiset<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t\
    } else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (auto it = v.begin(); it != v.end();\
    \ ++it) {\n\t\t\t\tif (it != v.begin()) std::cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\
    \t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ std::unordered_set<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\
    \t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (auto it = v.begin(); it !=\
    \ v.end(); ++it) {\n\t\t\t\tif (it != v.begin()) std::cerr << Separate;\n\t\t\t\
    \tDebugPrint(*it);\n\t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class\
    \ T> void DebugPrint(const std::list<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr\
    \ << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\tfor (auto it = v.begin();\
    \ it != v.end(); ++it) {\n\t\t\t\tif (it != v.begin()) std::cerr << Separate;\n\
    \t\t\t\tDebugPrint(*it);\n\t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate\
    \ <class T> void DebugPrint(std::stack<T> v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr\
    \ << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\twhile (!v.empty())\
    \ {\n\t\t\t\tDebugPrint(v.top());\n\t\t\t\tv.pop();\n\t\t\t\tif (!v.empty()) std::cerr\
    \ << Separate;\n\t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate <class\
    \ T> void DebugPrint(std::queue<T> v) {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr\
    \ << Empty;\n\t\t} else {\n\t\t\tstd::cerr << Begin;\n\t\t\twhile (!v.empty())\
    \ {\n\t\t\t\tDebugPrint(v.front());\n\t\t\t\tv.pop();\n\t\t\t\tif (!v.empty())\
    \ std::cerr << Separate;\n\t\t\t}\n\t\t\tstd::cerr << End;\n\t\t}\n\t}\n\ttemplate\
    \ <class T, class U, class V> void DebugPrint(std::priority_queue<T, U, V> v)\
    \ {\n\t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t} else {\n\t\t\tstd::cerr\
    \ << Begin;\n\t\t\twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.top());\n\t\t\t\t\
    v.pop();\n\t\t\t\tif (!v.empty()) std::cerr << Separate;\n\t\t\t}\n\t\t\tstd::cerr\
    \ << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(std::deque<T> v) {\n\
    \t\tif (v.empty()) {\n\t\t\tstd::cerr << Empty;\n\t\t} else {\n\t\t\tstd::cerr\
    \ << Begin;\n\t\t\twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.front());\n\t\t\t\
    \tv.pop_front();\n\t\t\t\tif (!v.empty()) std::cerr << Separate;\n\t\t\t}\n\t\t\
    \tstd::cerr << End;\n\t\t}\n\t}\n\n\tstd::queue<std::string> Name;\n\tvoid SetName(const\
    \ std::string& s) {\n\t\tint par = 0;\n\t\tstd::string name;\n\t\tfor (size_t\
    \ i = 0; i < s.size(); i++) {\n\t\t\tif (s[i] == '(' || s[i] == '{' ||\n\t\t\t\
    \    (s[i] == '<' && s[i + 1] != '=' && s[i - 1] != ' ' && s[i + 1] != ' ')) {\n\
    \t\t\t\tpar++;\n\t\t\t} else if (s[i] == ')' || s[i] == '}' ||\n\t\t\t       \
    \    (s[i] == '>' && s[i + 1] != '=' && s[i - 1] != ' ' &&\n\t\t\t           \
    \ s[i + 1] != ' ')) {\n\t\t\t\tpar--;\n\t\t\t}\n\t\t\tif (!par && s[i] == ',')\
    \ {\n\t\t\t\tName.push(name.front() == ' ' ? name.substr(1) : name);\n\t\t\t\t\
    name.clear();\n\t\t\t} else {\n\t\t\t\tname += s[i];\n\t\t\t}\n\t\t}\n\t\tName.push(name.front()\
    \ == ' ' ? name.substr(1) : name);\n\t}\n\n\ttemplate <class Head> void Dump(Head&&\
    \ h) {\n\t\tassert(!Name.empty());\n\t\tstd::cerr << Name.front() << \" = \";\n\
    \t\tDebugPrint(h);\n\t\tstd::cerr << \"\\n\";\n\t\tName.pop();\n\t}\n\ttemplate\
    \ <class Head, class... Tail> void Dump(Head&& h, Tail&&... t) {\n\t\tassert(!Name.empty());\n\
    \t\tstd::cerr << Name.front() << \" = \";\n\t\tDebugPrint(h);\n\t\tstd::cerr <<\
    \ EndLine;\n\t\tName.pop();\n\t\tDump(std::forward<Tail>(t)...);\n\t}\n};  //\
    \ namespace Debug\n\n#define dump(...)                                 \\\n\t\
    do {                                          \\\n\t\tDebug::FirstLine(__LINE__,\
    \ __FUNCTION__); \\\n\t\tDebug::SetName(#__VA_ARGS__);             \\\n\t\tDebug::Dump(__VA_ARGS__);\
    \                 \\\n\t} while (false)\n\n#define dump2(...)                \
    \    \\\n\tdo {                              \\\n\t\tDebug::SetName(#__VA_ARGS__);\
    \ \\\n\t\tDebug::Dump(__VA_ARGS__);     \\\n\t} while (false)\n"
  dependsOn: []
  isVerificationFile: false
  path: dump.hpp
  requiredBy:
  - template17.cpp
  timestamp: '2021-03-12 09:09:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dump.hpp
layout: document
redirect_from:
- /library/dump.hpp
- /library/dump.hpp.html
title: dump.hpp
---
