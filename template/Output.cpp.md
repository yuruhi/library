---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  - icon: ':warning:'
    path: template/template_no_Ruby.cpp
    title: template/template_no_Ruby.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Input_Output.test.cpp
    title: test/Input_Output.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/Output.cpp\"\n#include <iostream>\n#include <utility>\n\
    #include <string>\n#include <vector>\n#include <array>\n#include <charconv>\n\
    #include <cstring>\n#include <cassert>\nusing namespace std;\n\nstruct BoolStr\
    \ {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const char* _f) : t(_t),\
    \ f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"YES\", \"NO\"\
    ), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\tDivStr(const char*\
    \ _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"), no_spc(\"\", \"\
    \\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"), no_endl(\" \", \"\"\
    );\nclass Printer {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\npublic:\n\tvoid print(int\
    \ v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(long long v) const\
    \ {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf),\
    \ v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\t\t\
    } else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(bool v) const {\n\t\t\
    print(v ? B.t : B.f);\n\t}\n\tvoid print(vector<bool>::reference v) const {\n\t\
    \tprint(v ? B.t : B.f);\n\t}\n\tvoid print(char v) const {\n\t\tputchar_unlocked(v);\n\
    \t}\n\tvoid print(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v),\
    \ stdout);\n\t}\n\tvoid print(double v) const {\n\t\tprintf(\"%.20f\", v);\n\t\
    }\n\tvoid print(long double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t}\n\ttemplate\
    \ <class T> void print(const T& v) const {\n\t\tcout << v;\n\t}\n\ttemplate <class\
    \ T, class U> void print(const pair<T, U>& v) const {\n\t\tprint(v.first);\n\t\
    \tprint(D.d);\n\t\tprint(v.second);\n\t}\n\ttemplate <class InputIterater>\n\t\
    void print_range(const InputIterater& begin, const InputIterater& end) const {\n\
    \t\tfor (InputIterater i = begin; i != end; ++i) {\n\t\t\tif (i != begin) print(D.d);\n\
    \t\t\tprint(*i);\n\t\t}\n\t}\n\ttemplate <class T> void print(const vector<T>&\
    \ v) const {\n\t\tprint_range(v.begin(), v.end());\n\t}\n\ttemplate <class T,\
    \ size_t N> void print(const array<T, N>& v) const {\n\t\tprint_range(v.begin(),\
    \ v.end());\n\t}\n\ttemplate <class T> void print(const vector<vector<T>>& v)\
    \ const {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tif (i) print(D.l);\n\
    \t\t\tprint(v[i]);\n\t\t}\n\t}\n\n\tPrinter() = default;\n\tPrinter(const BoolStr&\
    \ _boolstr, const DivStr& _divstr) : B(_boolstr), D(_divstr) {}\n\tPrinter& operator()()\
    \ {\n\t\tprint(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class Head> Printer&\
    \ operator()(Head&& h) {\n\t\tprint(h);\n\t\tprint(D.l);\n\t\treturn *this;\n\t\
    }\n\ttemplate <class Head, class... Tail> Printer& operator()(Head&& h, Tail&&...\
    \ t) {\n\t\tprint(h);\n\t\tprint(D.d);\n\t\treturn operator()(forward<Tail>(t)...);\n\
    \t}\n\ttemplate <class... Args> Printer& flag(bool f, Args&&... args) {\n\t\t\
    if (f) {\n\t\t\treturn operator()(forward<Args>(args)...);\n\t\t} else {\n\t\t\
    \treturn *this;\n\t\t}\n\t}\n\ttemplate <class InputIterator>\n\tPrinter& range(const\
    \ InputIterator& begin, const InputIterator& end) {\n\t\tprint_range(begin, end);\n\
    \t\tprint(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class T> Printer& range(const\
    \ T& a) {\n\t\trange(a.begin(), a.end());\n\t\treturn *this;\n\t}\n\ttemplate\
    \ <class... T> void exit(T&&... t) {\n\t\toperator()(forward<T>(t)...);\n\t\t\
    std::exit(EXIT_SUCCESS);\n\t}\n\tPrinter& flush() {\n\t\tfflush_unlocked(stdout);\n\
    \t\treturn *this;\n\t}\n\tPrinter& set(const BoolStr& b) {\n\t\tB = b;\n\t\treturn\
    \ *this;\n\t}\n\tPrinter& set(const DivStr& d) {\n\t\tD = d;\n\t\treturn *this;\n\
    \t}\n\tPrinter& set(const char* t, const char* f) {\n\t\tB = BoolStr(t, f);\n\t\
    \treturn *this;\n\t}\n} out;\n"
  code: "#pragma once\n#include <iostream>\n#include <utility>\n#include <string>\n\
    #include <vector>\n#include <array>\n#include <charconv>\n#include <cstring>\n\
    #include <cassert>\nusing namespace std;\n\nstruct BoolStr {\n\tconst char *t,\
    \ *f;\n\tBoolStr(const char* _t, const char* _f) : t(_t), f(_f) {}\n} Yes(\"Yes\"\
    , \"No\"), yes(\"yes\", \"no\"), YES(\"YES\", \"NO\"), Int(\"1\", \"0\");\nstruct\
    \ DivStr {\n\tconst char *d, *l;\n\tDivStr(const char* _d, const char* _l) : d(_d),\
    \ l(_l) {}\n} spc(\" \", \"\\n\"), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\
    \\n\"), comma(\",\", \"\\n\"), no_endl(\" \", \"\");\nclass Printer {\n\tBoolStr\
    \ B{Yes};\n\tDivStr D{spc};\n\npublic:\n\tvoid print(int v) const {\n\t\tchar\
    \ buf[12]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e ==\
    \ errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\t\t} else {\n\
    \t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(long long v) const {\n\t\tchar\
    \ buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e ==\
    \ errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\t\t} else {\n\
    \t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(bool v) const {\n\t\tprint(v ?\
    \ B.t : B.f);\n\t}\n\tvoid print(vector<bool>::reference v) const {\n\t\tprint(v\
    \ ? B.t : B.f);\n\t}\n\tvoid print(char v) const {\n\t\tputchar_unlocked(v);\n\
    \t}\n\tvoid print(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v),\
    \ stdout);\n\t}\n\tvoid print(double v) const {\n\t\tprintf(\"%.20f\", v);\n\t\
    }\n\tvoid print(long double v) const {\n\t\tprintf(\"%.20Lf\", v);\n\t}\n\ttemplate\
    \ <class T> void print(const T& v) const {\n\t\tcout << v;\n\t}\n\ttemplate <class\
    \ T, class U> void print(const pair<T, U>& v) const {\n\t\tprint(v.first);\n\t\
    \tprint(D.d);\n\t\tprint(v.second);\n\t}\n\ttemplate <class InputIterater>\n\t\
    void print_range(const InputIterater& begin, const InputIterater& end) const {\n\
    \t\tfor (InputIterater i = begin; i != end; ++i) {\n\t\t\tif (i != begin) print(D.d);\n\
    \t\t\tprint(*i);\n\t\t}\n\t}\n\ttemplate <class T> void print(const vector<T>&\
    \ v) const {\n\t\tprint_range(v.begin(), v.end());\n\t}\n\ttemplate <class T,\
    \ size_t N> void print(const array<T, N>& v) const {\n\t\tprint_range(v.begin(),\
    \ v.end());\n\t}\n\ttemplate <class T> void print(const vector<vector<T>>& v)\
    \ const {\n\t\tfor (size_t i = 0; i < v.size(); ++i) {\n\t\t\tif (i) print(D.l);\n\
    \t\t\tprint(v[i]);\n\t\t}\n\t}\n\n\tPrinter() = default;\n\tPrinter(const BoolStr&\
    \ _boolstr, const DivStr& _divstr) : B(_boolstr), D(_divstr) {}\n\tPrinter& operator()()\
    \ {\n\t\tprint(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class Head> Printer&\
    \ operator()(Head&& h) {\n\t\tprint(h);\n\t\tprint(D.l);\n\t\treturn *this;\n\t\
    }\n\ttemplate <class Head, class... Tail> Printer& operator()(Head&& h, Tail&&...\
    \ t) {\n\t\tprint(h);\n\t\tprint(D.d);\n\t\treturn operator()(forward<Tail>(t)...);\n\
    \t}\n\ttemplate <class... Args> Printer& flag(bool f, Args&&... args) {\n\t\t\
    if (f) {\n\t\t\treturn operator()(forward<Args>(args)...);\n\t\t} else {\n\t\t\
    \treturn *this;\n\t\t}\n\t}\n\ttemplate <class InputIterator>\n\tPrinter& range(const\
    \ InputIterator& begin, const InputIterator& end) {\n\t\tprint_range(begin, end);\n\
    \t\tprint(D.l);\n\t\treturn *this;\n\t}\n\ttemplate <class T> Printer& range(const\
    \ T& a) {\n\t\trange(a.begin(), a.end());\n\t\treturn *this;\n\t}\n\ttemplate\
    \ <class... T> void exit(T&&... t) {\n\t\toperator()(forward<T>(t)...);\n\t\t\
    std::exit(EXIT_SUCCESS);\n\t}\n\tPrinter& flush() {\n\t\tfflush_unlocked(stdout);\n\
    \t\treturn *this;\n\t}\n\tPrinter& set(const BoolStr& b) {\n\t\tB = b;\n\t\treturn\
    \ *this;\n\t}\n\tPrinter& set(const DivStr& d) {\n\t\tD = d;\n\t\treturn *this;\n\
    \t}\n\tPrinter& set(const char* t, const char* f) {\n\t\tB = BoolStr(t, f);\n\t\
    \treturn *this;\n\t}\n} out;\n"
  dependsOn: []
  isVerificationFile: false
  path: template/Output.cpp
  requiredBy:
  - template/template_no_Ruby.cpp
  - template/template.cpp
  timestamp: '2021-01-12 17:27:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Input_Output.test.cpp
documentation_of: template/Output.cpp
layout: document
redirect_from:
- /library/template/Output.cpp
- /library/template/Output.cpp.html
title: template/Output.cpp
---
