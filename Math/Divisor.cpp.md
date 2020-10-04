---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Divisor.cpp\"\n// description : \u7D04\u6570\u5217\u6319\
    \u3001\u7D04\u6570\u306E\u500B\u6570\u3001\u7D04\u6570\u306E\u7DCF\u548C\ntemplate\
    \ <class T> vector<T> Divisor(T n) {\n\tassert(0 < n);\n\tvector<T> res;\n\tT\
    \ i = 1;\n\tfor (; i * i < n; ++i)\n\t\tif (n % i == 0) res.push_back(i);\n\t\
    bool flag = i * i == n;\n\tif (flag) res.push_back(i);\n\tfor (i = (int)res.size()\
    \ - 1 - flag; i >= 0; --i)\n\t\tres.push_back(n / res[i]);\n\treturn res;\n}\n\
    template <class T> int DivCnt(T n) {\n\tassert(0 < n);\n\tint cnt = 0;\n\tT sq\
    \ = (T)sqrt(n);\n\tfor (T i = 1; i <= sq; ++i)\n\t\tcnt += (n % i == 0);\n\treturn\
    \ cnt * 2 - (sq * sq == n);\n}\ntemplate <class T> T DivSum(T n) {\n\tassert(0\
    \ < n);\n\tT i = 1, res = 0;\n\tfor (; i * i < n; ++i)\n\t\tif (n % i == 0) res\
    \ += i + n / i;\n\treturn res + i * (i * i == n);\n}\n"
  code: "// description : \u7D04\u6570\u5217\u6319\u3001\u7D04\u6570\u306E\u500B\u6570\
    \u3001\u7D04\u6570\u306E\u7DCF\u548C\ntemplate <class T> vector<T> Divisor(T n)\
    \ {\n\tassert(0 < n);\n\tvector<T> res;\n\tT i = 1;\n\tfor (; i * i < n; ++i)\n\
    \t\tif (n % i == 0) res.push_back(i);\n\tbool flag = i * i == n;\n\tif (flag)\
    \ res.push_back(i);\n\tfor (i = (int)res.size() - 1 - flag; i >= 0; --i)\n\t\t\
    res.push_back(n / res[i]);\n\treturn res;\n}\ntemplate <class T> int DivCnt(T\
    \ n) {\n\tassert(0 < n);\n\tint cnt = 0;\n\tT sq = (T)sqrt(n);\n\tfor (T i = 1;\
    \ i <= sq; ++i)\n\t\tcnt += (n % i == 0);\n\treturn cnt * 2 - (sq * sq == n);\n\
    }\ntemplate <class T> T DivSum(T n) {\n\tassert(0 < n);\n\tT i = 1, res = 0;\n\
    \tfor (; i * i < n; ++i)\n\t\tif (n % i == 0) res += i + n / i;\n\treturn res\
    \ + i * (i * i == n);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Divisor.cpp
  requiredBy: []
  timestamp: '2020-09-20 10:56:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Divisor.cpp
layout: document
redirect_from:
- /library/Math/Divisor.cpp
- /library/Math/Divisor.cpp.html
title: Math/Divisor.cpp
---
