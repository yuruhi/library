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
    \\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"),\n    no_endl(\" \"\
    , \"\");\nclass Output {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\npublic:\n\tvoid\
    \ put(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid put(long long v) const\
    \ {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf),\
    \ v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\t\t\
    } else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid put(bool v) const {\n\t\tput(v\
    \ ? B.t : B.f);\n\t}\n\tvoid put(vector<bool>::reference v) const {\n\t\tput(v\
    \ ? B.t : B.f);\n\t}\n\tvoid put(char v) const {\n\t\tputchar_unlocked(v);\n\t\
    }\n\tvoid put(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v), stdout);\n\
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
    } out;\n"
  code: "#pragma once\n#include <iostream>\n#include <utility>\n#include <string>\n\
    #include <vector>\n#include <array>\n#include <charconv>\n#include <cstring>\n\
    #include <cassert>\nusing namespace std;\n\nstruct BoolStr {\n\tconst char *t,\
    \ *f;\n\tBoolStr(const char* _t, const char* _f) : t(_t), f(_f) {}\n} Yes(\"Yes\"\
    , \"No\"), yes(\"yes\", \"no\"), YES(\"YES\", \"NO\"), Int(\"1\", \"0\");\nstruct\
    \ DivStr {\n\tconst char *d, *l;\n\tDivStr(const char* _d, const char* _l) : d(_d),\
    \ l(_l) {}\n} spc(\" \", \"\\n\"), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\
    \\n\"), comma(\",\", \"\\n\"),\n    no_endl(\" \", \"\");\nclass Output {\n\t\
    BoolStr B{Yes};\n\tDivStr D{spc};\n\npublic:\n\tvoid put(int v) const {\n\t\t\
    char buf[12]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e\
    \ == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\t\t} else\
    \ {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid put(long long v) const {\n\t\tchar\
    \ buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf), end(buf), v); e ==\
    \ errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\t\t} else {\n\
    \t\t\tassert(false);\n\t\t}\n\t}\n\tvoid put(bool v) const {\n\t\tput(v ? B.t\
    \ : B.f);\n\t}\n\tvoid put(vector<bool>::reference v) const {\n\t\tput(v ? B.t\
    \ : B.f);\n\t}\n\tvoid put(char v) const {\n\t\tputchar_unlocked(v);\n\t}\n\t\
    void put(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v), stdout);\n\
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
    } out;\n"
  dependsOn: []
  isVerificationFile: false
  path: template/Output.cpp
  requiredBy:
  - template/template_no_Ruby.cpp
  - template/template.cpp
  timestamp: '2020-11-29 18:18:00+09:00'
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
