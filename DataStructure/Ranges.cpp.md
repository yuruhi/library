---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/Ranges.cpp\"\n#include <set>\n#include <utility>\n\
    #include <iostream>\nusing namespace std;\n\ntemplate <class T> class Ranges {\n\
    \tset<pair<T, bool>> s;\n\npublic:\n\tbool empty() const {\n\t\treturn s.empty();\n\
    \t}\n\tint size() const {\n\t\treturn s.size() / 2;\n\t}\n\tvoid clear() const\
    \ {\n\t\ts.clear();\n\t}\n\tconst auto& operator*() const {\n\t\treturn s;\n\t\
    }\n\tbool cover(const T& x) const {\n\t\tauto it = s.upper_bound(make_pair(x,\
    \ false));\n\t\treturn it != s.end() && s.upper_bound(make_pair(x, false))->second;\n\
    \t}\n\tbool add(const T& x) {\n\t\tif (cover(x)) return false;\n\t\tauto it =\
    \ s.upper_bound(make_pair(x, false));\n\t\tbool flag1 = it != s.begin() && prev(it)->first\
    \ + 1 == x;\n\t\tbool flag2 = it != s.end() && it->first - 1 == x;\n\t\tif (flag1\
    \ && flag2) {\n\t\t\ts.erase(prev(it), next(it));\n\t\t} else if (flag1) {\n\t\
    \t\ts.erase(prev(it));\n\t\t\ts.emplace(x, true);\n\t\t} else if (flag2) {\n\t\
    \t\ts.erase(it);\n\t\t\ts.emplace(x, false);\n\t\t} else {\n\t\t\ts.emplace(x,\
    \ false);\n\t\t\ts.emplace(x, true);\n\t\t}\n\t\treturn true;\n\t}\n\tbool add(const\
    \ initializer_list<T>& init) {\n\t\tbool res = false;\n\t\tfor (const T& x : init)\
    \ {\n\t\t\tres |= add(x);\n\t\t}\n\t\treturn res;\n\t}\n\tbool erase(const T&\
    \ x) {\n\t\tif (!cover(x)) return false;\n\t\tauto it = s.upper_bound(make_pair(x,\
    \ false));\n\t\tbool flag1 = prev(it)->first == x;\n\t\tbool flag2 = it->first\
    \ == x;\n\t\tif (flag1 && flag2) {\n\t\t\ts.erase(prev(it), next(it));\n\t\t}\
    \ else if (flag1) {\n\t\t\ts.erase(prev(it));\n\t\t\ts.emplace(x + 1, false);\n\
    \t\t} else if (flag2) {\n\t\t\ts.erase(it);\n\t\t\ts.emplace(x - 1, true);\n\t\
    \t} else {\n\t\t\ts.emplace(x - 1, true);\n\t\t\ts.emplace(x + 1, false);\n\t\t\
    }\n\t\treturn true;\n\t}\n\tbool erase(const initializer_list<T>& init) {\n\t\t\
    bool res = false;\n\t\tfor (const T& x : init) {\n\t\t\tres |= erase(x);\n\t\t\
    }\n\t\treturn res;\n\t}\n\tT get_next(const T& x) const {\n\t\tif (!cover(x))\
    \ return x;\n\t\tauto it = s.upper_bound(make_pair(x, false));\n\t\treturn it->first\
    \ + 1;\n\t}\n\tT get_prev(const T& x) const {\n\t\tif (!cover(x)) return x;\n\t\
    \tauto it = s.upper_bound(make_pair(x, false));\n\t\treturn prev(it)->first -\
    \ 1;\n\t}\n};\ntemplate <class T> ostream& operator<<(ostream& os, const Ranges<T>&\
    \ r) {\n\tconst auto& v = *r;\n\tbool first = true;\n\tfor (auto it = v.begin();\
    \ it != v.end(); advance(it, 2)) {\n\t\tos << (exchange(first, false) ? \"\" :\
    \ \", \") << '[' << it->first << \", \" << next(it)->first << ']';\n\t}\n\treturn\
    \ os;\n}\n"
  code: "#pragma once\n#include <set>\n#include <utility>\n#include <iostream>\nusing\
    \ namespace std;\n\ntemplate <class T> class Ranges {\n\tset<pair<T, bool>> s;\n\
    \npublic:\n\tbool empty() const {\n\t\treturn s.empty();\n\t}\n\tint size() const\
    \ {\n\t\treturn s.size() / 2;\n\t}\n\tvoid clear() const {\n\t\ts.clear();\n\t\
    }\n\tconst auto& operator*() const {\n\t\treturn s;\n\t}\n\tbool cover(const T&\
    \ x) const {\n\t\tauto it = s.upper_bound(make_pair(x, false));\n\t\treturn it\
    \ != s.end() && s.upper_bound(make_pair(x, false))->second;\n\t}\n\tbool add(const\
    \ T& x) {\n\t\tif (cover(x)) return false;\n\t\tauto it = s.upper_bound(make_pair(x,\
    \ false));\n\t\tbool flag1 = it != s.begin() && prev(it)->first + 1 == x;\n\t\t\
    bool flag2 = it != s.end() && it->first - 1 == x;\n\t\tif (flag1 && flag2) {\n\
    \t\t\ts.erase(prev(it), next(it));\n\t\t} else if (flag1) {\n\t\t\ts.erase(prev(it));\n\
    \t\t\ts.emplace(x, true);\n\t\t} else if (flag2) {\n\t\t\ts.erase(it);\n\t\t\t\
    s.emplace(x, false);\n\t\t} else {\n\t\t\ts.emplace(x, false);\n\t\t\ts.emplace(x,\
    \ true);\n\t\t}\n\t\treturn true;\n\t}\n\tbool add(const initializer_list<T>&\
    \ init) {\n\t\tbool res = false;\n\t\tfor (const T& x : init) {\n\t\t\tres |=\
    \ add(x);\n\t\t}\n\t\treturn res;\n\t}\n\tbool erase(const T& x) {\n\t\tif (!cover(x))\
    \ return false;\n\t\tauto it = s.upper_bound(make_pair(x, false));\n\t\tbool flag1\
    \ = prev(it)->first == x;\n\t\tbool flag2 = it->first == x;\n\t\tif (flag1 &&\
    \ flag2) {\n\t\t\ts.erase(prev(it), next(it));\n\t\t} else if (flag1) {\n\t\t\t\
    s.erase(prev(it));\n\t\t\ts.emplace(x + 1, false);\n\t\t} else if (flag2) {\n\t\
    \t\ts.erase(it);\n\t\t\ts.emplace(x - 1, true);\n\t\t} else {\n\t\t\ts.emplace(x\
    \ - 1, true);\n\t\t\ts.emplace(x + 1, false);\n\t\t}\n\t\treturn true;\n\t}\n\t\
    bool erase(const initializer_list<T>& init) {\n\t\tbool res = false;\n\t\tfor\
    \ (const T& x : init) {\n\t\t\tres |= erase(x);\n\t\t}\n\t\treturn res;\n\t}\n\
    \tT get_next(const T& x) const {\n\t\tif (!cover(x)) return x;\n\t\tauto it =\
    \ s.upper_bound(make_pair(x, false));\n\t\treturn it->first + 1;\n\t}\n\tT get_prev(const\
    \ T& x) const {\n\t\tif (!cover(x)) return x;\n\t\tauto it = s.upper_bound(make_pair(x,\
    \ false));\n\t\treturn prev(it)->first - 1;\n\t}\n};\ntemplate <class T> ostream&\
    \ operator<<(ostream& os, const Ranges<T>& r) {\n\tconst auto& v = *r;\n\tbool\
    \ first = true;\n\tfor (auto it = v.begin(); it != v.end(); advance(it, 2)) {\n\
    \t\tos << (exchange(first, false) ? \"\" : \", \") << '[' << it->first << \",\
    \ \" << next(it)->first << ']';\n\t}\n\treturn os;\n}"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Ranges.cpp
  requiredBy: []
  timestamp: '2020-10-06 16:32:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Ranges.cpp
layout: document
redirect_from:
- /library/DataStructure/Ranges.cpp
- /library/DataStructure/Ranges.cpp.html
title: DataStructure/Ranges.cpp
---
