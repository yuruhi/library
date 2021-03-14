---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/StopWatch.cpp\"\n#include <chrono>\n\nclass StopWatch\
    \ {\n\tstd::chrono::system_clock::time_point start_time;\n\n\ttemplate <class\
    \ T> T get_time() const {\n\t\tauto now = std::chrono::system_clock::now();\n\t\
    \treturn std::chrono::duration_cast<T>(now - start_time);\n\t}\n\npublic:\n\t\
    StopWatch(bool start_immediately = false) {\n\t\tif (start_immediately) start();\n\
    \t}\n\tvoid start() {\n\t\tstart_time = std::chrono::system_clock::now();\n\t\
    }\n\tint ms() const {\n\t\treturn static_cast<int>(get_time<std::chrono::milliseconds>().count());\n\
    \t}\n\tlong long ms64() const {\n\t\treturn static_cast<long long>(get_time<std::chrono::milliseconds>().count());\n\
    \t}\n\tint s() const {\n\t\treturn static_cast<int>(get_time<std::chrono::seconds>().count());\n\
    \t}\n\tlong long s64() const {\n\t\treturn static_cast<long long>(get_time<std::chrono::seconds>().count());\n\
    \t}\n};\n"
  code: "#pragma once\n#include <chrono>\n\nclass StopWatch {\n\tstd::chrono::system_clock::time_point\
    \ start_time;\n\n\ttemplate <class T> T get_time() const {\n\t\tauto now = std::chrono::system_clock::now();\n\
    \t\treturn std::chrono::duration_cast<T>(now - start_time);\n\t}\n\npublic:\n\t\
    StopWatch(bool start_immediately = false) {\n\t\tif (start_immediately) start();\n\
    \t}\n\tvoid start() {\n\t\tstart_time = std::chrono::system_clock::now();\n\t\
    }\n\tint ms() const {\n\t\treturn static_cast<int>(get_time<std::chrono::milliseconds>().count());\n\
    \t}\n\tlong long ms64() const {\n\t\treturn static_cast<long long>(get_time<std::chrono::milliseconds>().count());\n\
    \t}\n\tint s() const {\n\t\treturn static_cast<int>(get_time<std::chrono::seconds>().count());\n\
    \t}\n\tlong long s64() const {\n\t\treturn static_cast<long long>(get_time<std::chrono::seconds>().count());\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/StopWatch.cpp
  requiredBy: []
  timestamp: '2021-03-10 22:57:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/StopWatch.cpp
layout: document
redirect_from:
- /library/Utility/StopWatch.cpp
- /library/Utility/StopWatch.cpp.html
title: Utility/StopWatch.cpp
---
