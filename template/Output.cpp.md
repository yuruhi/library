---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/Output.cpp\"\n#include <iostream>\n#include <utility>\n\
    #include <string>\n#include <vector>\n#include <charconv>\n#include <cassert>\n\
    using namespace std;\n\nstruct BoolStr {\n\tconst char *t, *f;\n\tBoolStr(const\
    \ char* _t, const char* _f) : t(_t), f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"\
    yes\", \"no\"), YES(\"YES\", \"NO\"), Int(\"1\", \"0\");\nstruct DivStr {\n\t\
    const char *d, *l;\n\tDivStr(const char* _d, const char* _l) : d(_d), l(_l) {}\n\
    } spc(\" \", \"\\n\"), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\\n\"), comma(\"\
    ,\", \"\\n\"), no_endl(\" \", \"\");\nclass Output {\n\tBoolStr B{Yes};\n\tDivStr\
    \ D{spc};\n\tvoid p(int v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr, e]\
    \ = to_chars(begin(buf), end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char),\
    \ ptr - buf, stdout);\n\t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid\
    \ p(long long v) const {\n\t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
    \ end(buf), v); e == errc{}) {\n\t\t\tfwrite(buf, sizeof(char), ptr - buf, stdout);\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid p(bool v) const {\n\t\t\
    p(v ? B.t : B.f);\n\t}\n\tvoid p(char v) const {\n\t\tputchar_unlocked(v);\n\t\
    }\n\tvoid p(const char* v) const {\n\t\tfwrite_unlocked(v, 1, strlen(v), stdout);\n\
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
    } out;\n"
  code: "#pragma once\n#include <iostream>\n#include <utility>\n#include <string>\n\
    #include <vector>\n#include <charconv>\n#include <cassert>\nusing namespace std;\n\
    \nstruct BoolStr {\n\tconst char *t, *f;\n\tBoolStr(const char* _t, const char*\
    \ _f) : t(_t), f(_f) {}\n} Yes(\"Yes\", \"No\"), yes(\"yes\", \"no\"), YES(\"\
    YES\", \"NO\"), Int(\"1\", \"0\");\nstruct DivStr {\n\tconst char *d, *l;\n\t\
    DivStr(const char* _d, const char* _l) : d(_d), l(_l) {}\n} spc(\" \", \"\\n\"\
    ), no_spc(\"\", \"\\n\"), end_line(\"\\n\", \"\\n\"), comma(\",\", \"\\n\"), no_endl(\"\
    \ \", \"\");\nclass Output {\n\tBoolStr B{Yes};\n\tDivStr D{spc};\n\tvoid p(int\
    \ v) const {\n\t\tchar buf[12]{};\n\t\tif (auto [ptr, e] = to_chars(begin(buf),\
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
    } out;"
  dependsOn: []
  isVerificationFile: false
  path: template/Output.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/Output.cpp
layout: document
redirect_from:
- /library/template/Output.cpp
- /library/template/Output.cpp.html
title: template/Output.cpp
---
