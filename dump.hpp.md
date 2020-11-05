---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template17.cpp
    title: template17.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dump.hpp\"\n#include <iostream>\n#include <iomanip>\n#include\
    \ <string>\n#include <utility>\n#include <vector>\n#include <array>\n#include\
    \ <map>\n#include <set>\n#include <list>\n#include <stack>\n#include <queue>\n\
    #include <cassert>\n#include <climits>\n#ifdef __cpp_lib_optional\n#include <optional>\n\
    #endif\nusing namespace std;\n\nnamespace Debug {\n\tstruct AtFirst {\n\t\tAtFirst()\
    \ {\n\t\t\tcerr << fixed << setprecision(6);\n\t\t}\n\t};\n\tAtFirst at_first;\n\
    \n\tstring BeginLine = \"..|\", EndLine = \"\\n\" + BeginLine;\n\tstring Begin\
    \ = \"{ \", End = \" }\";\n\tstring Empty = \"{ empty }\", Separate = \", \",\
    \ Indent = \"  \";\n\tstring True = \"O\", False = \"X\";\n\tvoid FirstLine(int\
    \ line, string func) {\n\t\tcerr << BeginLine + string(15, '-') << line << \"\
    \ : \" << func << string(15, '-') << EndLine;\n\t}\n\n\ttemplate <class T> void\
    \ DebugPrint(const T& v);\n\tvoid DebugPrint(const int v);\n\tvoid DebugPrint(const\
    \ long long v);\n\tvoid DebugPrint(const bool v);\n\tvoid DebugPrint(const char\
    \ v);\n\tvoid DebugPrint(const char* v);\n\tvoid DebugPrint(const string& v);\n\
    \ttemplate <class T, class U> void DebugPrint(const pair<T, U>& v);\n#ifdef __cpp_lib_optional\n\
    \ttemplate <class T> void DebugPrint(const optional<T>& v);\n#endif\n#ifdef __cpp_if_constexpr\n\
    \ttemplate <size_t N = 0, class T> void print_tuple_impl(const T& v);\n\ttemplate\
    \ <class... T> void DebugPrint(const tuple<T...>& v);\n#endif\n\ttemplate <class\
    \ T> void DebugPrint(const vector<T>& v);\n\ttemplate <class T, size_t N> void\
    \ DebugPrint(const array<T, N>& v);\n\ttemplate <class T> void DebugPrint(const\
    \ vector<vector<T>>& v);\n\ttemplate <class T, class U> void DebugPrint(const\
    \ map<T, U>& v);\n\ttemplate <class T> void DebugPrint(const set<T>& v);\n\ttemplate\
    \ <class T> void DebugPrint(const multiset<T>& v);\n\ttemplate <class T> void\
    \ DebugPrint(const list<T>& v);\n\ttemplate <class T> void DebugPrint(stack<T>\
    \ v);\n\ttemplate <class T> void DebugPrint(queue<T> v);\n\ttemplate <class T,\
    \ class U, class V> void DebugPrint(priority_queue<T, U, V> v);\n\ttemplate <class\
    \ T> void DebugPrint(deque<T> v);\n\n\ttemplate <class T> void DebugPrint(const\
    \ T& v) {\n\t\tcerr << v;\n\t}\n\tvoid DebugPrint(const int v) {\n\t\tif (v ==\
    \ INT_MAX) {\n\t\t\tcerr << \"MAX\";\n\t\t} else if (v == INT_MIN) {\n\t\t\tcerr\
    \ << \"MIN\";\n\t\t} else {\n\t\t\tcerr << v;\n\t\t}\n\t}\n\tvoid DebugPrint(const\
    \ long long v) {\n\t\tif (v == LLONG_MAX) {\n\t\t\tcerr << \"MAX\";\n\t\t} else\
    \ if (v == LLONG_MIN) {\n\t\t\tcerr << \"MIN\";\n\t\t} else {\n\t\t\tcerr << v;\n\
    \t\t}\n\t}\n\tvoid DebugPrint(const bool v) {\n\t\tcerr << (v ? True : False);\n\
    \t}\n\tvoid DebugPrint(const char v) {\n\t\tcerr << '\\'' << v << '\\'';\n\t}\n\
    \tvoid DebugPrint(const char* v) {\n\t\tcerr << '\\\"' << v << '\\\"';\n\t}\n\t\
    void DebugPrint(const string& v) {\n\t\tcerr << '\\\"' << v << '\\\"';\n\t}\n\t\
    template <class T, class U> void DebugPrint(const pair<T, U>& v) {\n\t\tcerr <<\
    \ \"(\";\n\t\tDebugPrint(v.first);\n\t\tcerr << \", \";\n\t\tDebugPrint(v.second);\n\
    \t\tcerr << \")\";\n\t}\n#ifdef __cpp_lib_optional\n\ttemplate <class T> void\
    \ DebugPrint(const optional<T>& v) {\n\t\tif (v) {\n\t\t\tDebugPrint(*v);\n\t\t\
    } else {\n\t\t\tcerr << '-';\n\t\t}\n\t}\n#endif\n#ifdef __cpp_if_constexpr\n\t\
    template <size_t N = 0, class T> void print_tuple_impl(const T& v) {\n\t\tif constexpr\
    \ (N < tuple_size_v<T>) {\n\t\t\tDebugPrint(get<N>(v));\n\t\t\tif constexpr (N\
    \ < tuple_size_v<T> - 1) {\n\t\t\t\tcerr << Separate;\n\t\t\t}\n\t\t\tprint_tuple_impl<N\
    \ + 1>(v);\n\t\t}\n\t}\n\ttemplate <class... T> void DebugPrint(const tuple<T...>&\
    \ v) {\n\t\tcerr << Begin;\n\t\tprint_tuple_impl(v);\n\t\tcerr << End;\n\t}\n\
    #endif\n\ttemplate <class T> void DebugPrint(const vector<T>& v) {\n\t\tif (v.empty())\
    \ {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\t\t\tfor (int\
    \ i = 0; i < (int)v.size(); ++i) {\n\t\t\t\tif (i) cerr << Separate;\n\t\t\t\t\
    DebugPrint(v[i]);\n\t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class\
    \ T, size_t N> void DebugPrint(const array<T, N>& v) {\n\t\tif (v.empty()) {\n\
    \t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\t\t\tfor (int i = 0;\
    \ i < N; ++i) {\n\t\t\t\tif (i) cerr << Separate;\n\t\t\t\tDebugPrint(v[i]);\n\
    \t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ vector<vector<T>>& v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else\
    \ {\n\t\t\tcerr << Begin << EndLine;\n\t\t\tfor (int i = 0; i < (int)v.size();\
    \ i++) {\n\t\t\t\tcerr << Indent << \"[\" << i << \"] \";\n\t\t\t\tDebugPrint(v[i]);\n\
    \t\t\t\tcerr << EndLine;\n\t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate\
    \ <class T, class U> void DebugPrint(const map<T, U>& v) {\n\t\tif (v.empty())\
    \ {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin << EndLine;\n\t\t\
    \tfor (const auto& i : v) {\n\t\t\t\tcerr << Indent;\n\t\t\t\tDebugPrint(i.first);\n\
    \t\t\t\tcerr << \" : \";\n\t\t\t\tDebugPrint(i.second);\n\t\t\t\tcerr << EndLine;\n\
    \t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ set<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\
    \tcerr << Begin;\n\t\t\tfor (auto it = v.begin(); it != v.end(); ++it) {\n\t\t\
    \t\tif (it != v.begin()) cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\t\t\t}\n\
    \t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const multiset<T>&\
    \ v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr <<\
    \ Begin;\n\t\t\tfor (auto it = v.begin(); it != v.end(); ++it) {\n\t\t\t\tif (it\
    \ != v.begin()) cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\t\t\t}\n\t\t\tcerr\
    \ << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const list<T>& v)\
    \ {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\
    \t\t\tfor (auto it = v.begin(); it != v.end(); ++it) {\n\t\t\t\tif (it != v.begin())\
    \ cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\t\t\t}\n\t\t\tcerr << End;\n\t\
    \t}\n\t}\n\ttemplate <class T> void DebugPrint(stack<T> v) {\n\t\tif (v.empty())\
    \ {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\t\t\twhile (!v.empty())\
    \ {\n\t\t\t\tDebugPrint(v.top());\n\t\t\t\tv.pop();\n\t\t\t\tif (!v.empty()) cerr\
    \ << Separate;\n\t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class T>\
    \ void DebugPrint(queue<T> v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\
    \t} else {\n\t\t\tcerr << Begin;\n\t\t\twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.front());\n\
    \t\t\t\tv.pop();\n\t\t\t\tif (!v.empty()) cerr << Separate;\n\t\t\t}\n\t\t\tcerr\
    \ << End;\n\t\t}\n\t}\n\ttemplate <class T, class U, class V> void DebugPrint(priority_queue<T,\
    \ U, V> v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\t\
    cerr << Begin;\n\t\t\twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.top());\n\t\t\
    \t\tv.pop();\n\t\t\t\tif (!v.empty()) cerr << Separate;\n\t\t\t}\n\t\t\tcerr <<\
    \ End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(deque<T> v) {\n\t\tif\
    \ (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\t\t\
    \twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.front());\n\t\t\t\tv.pop_front();\n\
    \t\t\t\tif (!v.empty()) cerr << Separate;\n\t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\
    \t}\n\n\tqueue<string> Name;\n\tvoid SetName(const string& s) {\n\t\tint size\
    \ = s.size(), par = 0;\n\t\tstring name;\n\t\tfor (int i = 0; i < size; i++) {\n\
    \t\t\tif (s[i] == '(' || s[i] == '{' || (s[i] == '<' && s[i + 1] != '=' && s[i\
    \ - 1] != ' ' && s[i + 1] != ' ')) {\n\t\t\t\tpar++;\n\t\t\t} else if (s[i] ==\
    \ ')' || s[i] == '}' ||\n\t\t\t           (s[i] == '>' && s[i + 1] != '=' && s[i\
    \ - 1] != ' ' && s[i + 1] != ' ')) {\n\t\t\t\tpar--;\n\t\t\t}\n\t\t\tif (!par\
    \ && s[i] == ',') {\n\t\t\t\tName.push(name.front() == ' ' ? name.substr(1) :\
    \ name);\n\t\t\t\tname.clear();\n\t\t\t} else {\n\t\t\t\tname += s[i];\n\t\t\t\
    }\n\t\t}\n\t\tName.push(name.front() == ' ' ? name.substr(1) : name);\n\t}\n\t\
    template <class H> void Dump(H&& h) {\n\t\tassert(!Name.empty());\n\t\tcerr <<\
    \ Name.front() << \" = \";\n\t\tDebugPrint(h);\n\t\tcerr << \"\\n\";\n\t\tName.pop();\n\
    \t}\n\ttemplate <class H, class... T> void Dump(H&& h, T&&... t) {\n\t\tassert(!Name.empty());\n\
    \t\tcerr << Name.front() << \" = \";\n\t\tDebugPrint(h);\n\t\tcerr << EndLine;\n\
    \t\tName.pop();\n\t\tDump(forward<T>(t)...);\n\t}\n};  // namespace Debug\n\n\
    #define dump(...)                                 \\\n\tdo {                 \
    \                         \\\n\t\tDebug::FirstLine(__LINE__, __FUNCTION__); \\\
    \n\t\tDebug::SetName(#__VA_ARGS__);             \\\n\t\tDebug::Dump(__VA_ARGS__);\
    \                 \\\n\t} while (false)\n"
  code: "#pragma once\n#include <iostream>\n#include <iomanip>\n#include <string>\n\
    #include <utility>\n#include <vector>\n#include <array>\n#include <map>\n#include\
    \ <set>\n#include <list>\n#include <stack>\n#include <queue>\n#include <cassert>\n\
    #include <climits>\n#ifdef __cpp_lib_optional\n#include <optional>\n#endif\nusing\
    \ namespace std;\n\nnamespace Debug {\n\tstruct AtFirst {\n\t\tAtFirst() {\n\t\
    \t\tcerr << fixed << setprecision(6);\n\t\t}\n\t};\n\tAtFirst at_first;\n\n\t\
    string BeginLine = \"..|\", EndLine = \"\\n\" + BeginLine;\n\tstring Begin = \"\
    { \", End = \" }\";\n\tstring Empty = \"{ empty }\", Separate = \", \", Indent\
    \ = \"  \";\n\tstring True = \"O\", False = \"X\";\n\tvoid FirstLine(int line,\
    \ string func) {\n\t\tcerr << BeginLine + string(15, '-') << line << \" : \" <<\
    \ func << string(15, '-') << EndLine;\n\t}\n\n\ttemplate <class T> void DebugPrint(const\
    \ T& v);\n\tvoid DebugPrint(const int v);\n\tvoid DebugPrint(const long long v);\n\
    \tvoid DebugPrint(const bool v);\n\tvoid DebugPrint(const char v);\n\tvoid DebugPrint(const\
    \ char* v);\n\tvoid DebugPrint(const string& v);\n\ttemplate <class T, class U>\
    \ void DebugPrint(const pair<T, U>& v);\n#ifdef __cpp_lib_optional\n\ttemplate\
    \ <class T> void DebugPrint(const optional<T>& v);\n#endif\n#ifdef __cpp_if_constexpr\n\
    \ttemplate <size_t N = 0, class T> void print_tuple_impl(const T& v);\n\ttemplate\
    \ <class... T> void DebugPrint(const tuple<T...>& v);\n#endif\n\ttemplate <class\
    \ T> void DebugPrint(const vector<T>& v);\n\ttemplate <class T, size_t N> void\
    \ DebugPrint(const array<T, N>& v);\n\ttemplate <class T> void DebugPrint(const\
    \ vector<vector<T>>& v);\n\ttemplate <class T, class U> void DebugPrint(const\
    \ map<T, U>& v);\n\ttemplate <class T> void DebugPrint(const set<T>& v);\n\ttemplate\
    \ <class T> void DebugPrint(const multiset<T>& v);\n\ttemplate <class T> void\
    \ DebugPrint(const list<T>& v);\n\ttemplate <class T> void DebugPrint(stack<T>\
    \ v);\n\ttemplate <class T> void DebugPrint(queue<T> v);\n\ttemplate <class T,\
    \ class U, class V> void DebugPrint(priority_queue<T, U, V> v);\n\ttemplate <class\
    \ T> void DebugPrint(deque<T> v);\n\n\ttemplate <class T> void DebugPrint(const\
    \ T& v) {\n\t\tcerr << v;\n\t}\n\tvoid DebugPrint(const int v) {\n\t\tif (v ==\
    \ INT_MAX) {\n\t\t\tcerr << \"MAX\";\n\t\t} else if (v == INT_MIN) {\n\t\t\tcerr\
    \ << \"MIN\";\n\t\t} else {\n\t\t\tcerr << v;\n\t\t}\n\t}\n\tvoid DebugPrint(const\
    \ long long v) {\n\t\tif (v == LLONG_MAX) {\n\t\t\tcerr << \"MAX\";\n\t\t} else\
    \ if (v == LLONG_MIN) {\n\t\t\tcerr << \"MIN\";\n\t\t} else {\n\t\t\tcerr << v;\n\
    \t\t}\n\t}\n\tvoid DebugPrint(const bool v) {\n\t\tcerr << (v ? True : False);\n\
    \t}\n\tvoid DebugPrint(const char v) {\n\t\tcerr << '\\'' << v << '\\'';\n\t}\n\
    \tvoid DebugPrint(const char* v) {\n\t\tcerr << '\\\"' << v << '\\\"';\n\t}\n\t\
    void DebugPrint(const string& v) {\n\t\tcerr << '\\\"' << v << '\\\"';\n\t}\n\t\
    template <class T, class U> void DebugPrint(const pair<T, U>& v) {\n\t\tcerr <<\
    \ \"(\";\n\t\tDebugPrint(v.first);\n\t\tcerr << \", \";\n\t\tDebugPrint(v.second);\n\
    \t\tcerr << \")\";\n\t}\n#ifdef __cpp_lib_optional\n\ttemplate <class T> void\
    \ DebugPrint(const optional<T>& v) {\n\t\tif (v) {\n\t\t\tDebugPrint(*v);\n\t\t\
    } else {\n\t\t\tcerr << '-';\n\t\t}\n\t}\n#endif\n#ifdef __cpp_if_constexpr\n\t\
    template <size_t N = 0, class T> void print_tuple_impl(const T& v) {\n\t\tif constexpr\
    \ (N < tuple_size_v<T>) {\n\t\t\tDebugPrint(get<N>(v));\n\t\t\tif constexpr (N\
    \ < tuple_size_v<T> - 1) {\n\t\t\t\tcerr << Separate;\n\t\t\t}\n\t\t\tprint_tuple_impl<N\
    \ + 1>(v);\n\t\t}\n\t}\n\ttemplate <class... T> void DebugPrint(const tuple<T...>&\
    \ v) {\n\t\tcerr << Begin;\n\t\tprint_tuple_impl(v);\n\t\tcerr << End;\n\t}\n\
    #endif\n\ttemplate <class T> void DebugPrint(const vector<T>& v) {\n\t\tif (v.empty())\
    \ {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\t\t\tfor (int\
    \ i = 0; i < (int)v.size(); ++i) {\n\t\t\t\tif (i) cerr << Separate;\n\t\t\t\t\
    DebugPrint(v[i]);\n\t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class\
    \ T, size_t N> void DebugPrint(const array<T, N>& v) {\n\t\tif (v.empty()) {\n\
    \t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\t\t\tfor (int i = 0;\
    \ i < N; ++i) {\n\t\t\t\tif (i) cerr << Separate;\n\t\t\t\tDebugPrint(v[i]);\n\
    \t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ vector<vector<T>>& v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else\
    \ {\n\t\t\tcerr << Begin << EndLine;\n\t\t\tfor (int i = 0; i < (int)v.size();\
    \ i++) {\n\t\t\t\tcerr << Indent << \"[\" << i << \"] \";\n\t\t\t\tDebugPrint(v[i]);\n\
    \t\t\t\tcerr << EndLine;\n\t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate\
    \ <class T, class U> void DebugPrint(const map<T, U>& v) {\n\t\tif (v.empty())\
    \ {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin << EndLine;\n\t\t\
    \tfor (const auto& i : v) {\n\t\t\t\tcerr << Indent;\n\t\t\t\tDebugPrint(i.first);\n\
    \t\t\t\tcerr << \" : \";\n\t\t\t\tDebugPrint(i.second);\n\t\t\t\tcerr << EndLine;\n\
    \t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const\
    \ set<T>& v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\
    \tcerr << Begin;\n\t\t\tfor (auto it = v.begin(); it != v.end(); ++it) {\n\t\t\
    \t\tif (it != v.begin()) cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\t\t\t}\n\
    \t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const multiset<T>&\
    \ v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr <<\
    \ Begin;\n\t\t\tfor (auto it = v.begin(); it != v.end(); ++it) {\n\t\t\t\tif (it\
    \ != v.begin()) cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\t\t\t}\n\t\t\tcerr\
    \ << End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(const list<T>& v)\
    \ {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\
    \t\t\tfor (auto it = v.begin(); it != v.end(); ++it) {\n\t\t\t\tif (it != v.begin())\
    \ cerr << Separate;\n\t\t\t\tDebugPrint(*it);\n\t\t\t}\n\t\t\tcerr << End;\n\t\
    \t}\n\t}\n\ttemplate <class T> void DebugPrint(stack<T> v) {\n\t\tif (v.empty())\
    \ {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\t\t\twhile (!v.empty())\
    \ {\n\t\t\t\tDebugPrint(v.top());\n\t\t\t\tv.pop();\n\t\t\t\tif (!v.empty()) cerr\
    \ << Separate;\n\t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\t}\n\ttemplate <class T>\
    \ void DebugPrint(queue<T> v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\
    \t} else {\n\t\t\tcerr << Begin;\n\t\t\twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.front());\n\
    \t\t\t\tv.pop();\n\t\t\t\tif (!v.empty()) cerr << Separate;\n\t\t\t}\n\t\t\tcerr\
    \ << End;\n\t\t}\n\t}\n\ttemplate <class T, class U, class V> void DebugPrint(priority_queue<T,\
    \ U, V> v) {\n\t\tif (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\t\
    cerr << Begin;\n\t\t\twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.top());\n\t\t\
    \t\tv.pop();\n\t\t\t\tif (!v.empty()) cerr << Separate;\n\t\t\t}\n\t\t\tcerr <<\
    \ End;\n\t\t}\n\t}\n\ttemplate <class T> void DebugPrint(deque<T> v) {\n\t\tif\
    \ (v.empty()) {\n\t\t\tcerr << Empty;\n\t\t} else {\n\t\t\tcerr << Begin;\n\t\t\
    \twhile (!v.empty()) {\n\t\t\t\tDebugPrint(v.front());\n\t\t\t\tv.pop_front();\n\
    \t\t\t\tif (!v.empty()) cerr << Separate;\n\t\t\t}\n\t\t\tcerr << End;\n\t\t}\n\
    \t}\n\n\tqueue<string> Name;\n\tvoid SetName(const string& s) {\n\t\tint size\
    \ = s.size(), par = 0;\n\t\tstring name;\n\t\tfor (int i = 0; i < size; i++) {\n\
    \t\t\tif (s[i] == '(' || s[i] == '{' || (s[i] == '<' && s[i + 1] != '=' && s[i\
    \ - 1] != ' ' && s[i + 1] != ' ')) {\n\t\t\t\tpar++;\n\t\t\t} else if (s[i] ==\
    \ ')' || s[i] == '}' ||\n\t\t\t           (s[i] == '>' && s[i + 1] != '=' && s[i\
    \ - 1] != ' ' && s[i + 1] != ' ')) {\n\t\t\t\tpar--;\n\t\t\t}\n\t\t\tif (!par\
    \ && s[i] == ',') {\n\t\t\t\tName.push(name.front() == ' ' ? name.substr(1) :\
    \ name);\n\t\t\t\tname.clear();\n\t\t\t} else {\n\t\t\t\tname += s[i];\n\t\t\t\
    }\n\t\t}\n\t\tName.push(name.front() == ' ' ? name.substr(1) : name);\n\t}\n\t\
    template <class H> void Dump(H&& h) {\n\t\tassert(!Name.empty());\n\t\tcerr <<\
    \ Name.front() << \" = \";\n\t\tDebugPrint(h);\n\t\tcerr << \"\\n\";\n\t\tName.pop();\n\
    \t}\n\ttemplate <class H, class... T> void Dump(H&& h, T&&... t) {\n\t\tassert(!Name.empty());\n\
    \t\tcerr << Name.front() << \" = \";\n\t\tDebugPrint(h);\n\t\tcerr << EndLine;\n\
    \t\tName.pop();\n\t\tDump(forward<T>(t)...);\n\t}\n};  // namespace Debug\n\n\
    #define dump(...)                                 \\\n\tdo {                 \
    \                         \\\n\t\tDebug::FirstLine(__LINE__, __FUNCTION__); \\\
    \n\t\tDebug::SetName(#__VA_ARGS__);             \\\n\t\tDebug::Dump(__VA_ARGS__);\
    \                 \\\n\t} while (false)\n"
  dependsOn: []
  isVerificationFile: false
  path: dump.hpp
  requiredBy:
  - template17.cpp
  timestamp: '2020-11-05 16:42:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dump.hpp
layout: document
redirect_from:
- /library/dump.hpp
- /library/dump.hpp.html
title: dump.hpp
---
