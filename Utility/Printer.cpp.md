---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  - icon: ':warning:'
    path: template_no_Ruby.cpp
    title: template_no_Ruby.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/IO_2Dvector_and_Ruby_push_back_Transpose_Map_Sum.test.cpp
    title: test/IO_2Dvector_and_Ruby_push_back_Transpose_Map_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/IO_vector_and_Ruby_Reverse.test.cpp
    title: test/IO_vector_and_Ruby_Reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Input_Output.test.cpp
    title: test/Input_Output.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template.test.cpp
    title: test/template.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/template_no_Ruby.test.cpp
    title: test/template_no_Ruby.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Printer.cpp\"\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n#include <array>\n#include <string>\n#include <string_view>\n\
    #include <optional>\n#include <charconv>\n#include <type_traits>\n#include <cstring>\n\
    #include <cassert>\n\nclass Printer {\npublic:\n\tstruct BoolString {\n\t\tstd::string_view\
    \ t, f;\n\t\tBoolString(std::string_view _t, std::string_view _f) : t(_t), f(_f)\
    \ {}\n\t};\n\tstruct Separator {\n\t\tstd::string_view div, sep, last;\n\t\tSeparator(std::string_view\
    \ _div, std::string_view _sep, std::string_view _last)\n\t\t    : div(_div), sep(_sep),\
    \ last(_last) {}\n\t};\n\n\tinline static const BoolString Yes{\"Yes\", \"No\"\
    }, yes{\"yes\", \"no\"}, YES{\"YES\", \"NO\"},\n\t    Int{\"1\", \"0\"}, Possible{\"\
    Possible\", \"Impossible\"};\n\tinline static const Separator space{\" \", \"\
    \ \", \"\\n\"}, no_space{\"\", \"\", \"\\n\"},\n\t    endl{\"\\n\", \"\\n\", \"\
    \\n\"}, comma{\",\", \",\", \"\\n\"}, no_endl{\" \", \" \", \"\"},\n\t    sep_endl{\"\
    \ \", \"\\n\", \"\\n\"};\n\n\tBoolString bool_str{Yes};\n\tSeparator separator{space};\n\
    \nprivate:\n\ttemplate <class T, class = void> struct has_print : std::false_type\
    \ {};\n\ttemplate <class T>\n\tstruct has_print<T,\n\t                 std::void_t<decltype(std::declval<T>().print(std::declval<Printer>()))>>\n\
    \t    : std::true_type {};\n\npublic:\n\tvoid print(int v) const {\n\t\tchar buf[12]{};\n\
    \t\tif (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf), v);\n\t\t\
    \    e == std::errc{}) {\n\t\t\tprint(std::string_view(buf, ptr - buf));\n\t\t\
    } else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(long long v) const {\n\
    \t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf),\
    \ v);\n\t\t    e == std::errc{}) {\n\t\t\tprint(std::string_view(buf, ptr - buf));\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(bool v) const {\n\
    \t\tprint(v ? bool_str.t : bool_str.f);\n\t}\n\tvoid print(std::vector<bool>::reference\
    \ v) const {\n\t\tprint(v ? bool_str.t : bool_str.f);\n\t}\n\tvoid print(char\
    \ v) const {\n\t\tputchar_unlocked(v);\n\t}\n\tvoid print(std::string_view v)\
    \ const {\n\t\tfwrite_unlocked(v.data(), sizeof(std::string_view::value_type),\
    \ v.size(), stdout);\n\t}\n\tvoid print(double v) const {\n\t\tstd::printf(\"\
    %.20f\", v);\n\t}\n\tvoid print(long double v) const {\n\t\tstd::printf(\"%.20Lf\"\
    , v);\n\t}\n\ttemplate <class T, std::enable_if_t<has_print<T>::value, std::nullptr_t>\
    \ = nullptr>\n\tvoid print(const T& v) const {\n\t\tv.print(*this);\n\t}\n\ttemplate\
    \ <class T, std::enable_if_t<!has_print<T>::value, std::nullptr_t> = nullptr>\n\
    \tvoid print(const T& v) const {\n\t\tstd::cout << v;\n\t}\n\ttemplate <class\
    \ T, class U> void print(const std::pair<T, U>& v) const {\n\t\tprint(v.first);\n\
    \t\tprint(separator.div);\n\t\tprint(v.second);\n\t}\n\ttemplate <class T> void\
    \ print(const std::optional<T>& v) const {\n\t\tprint(*v);\n\t}\n\ttemplate <class\
    \ InputIterater>\n\tvoid print_range(const InputIterater& begin, const InputIterater&\
    \ end) const {\n\t\tfor (InputIterater i = begin; i != end; ++i) {\n\t\t\tif (i\
    \ != begin) print(separator.sep);\n\t\t\tprint(*i);\n\t\t}\n\t}\n\ttemplate <class\
    \ T> void print(const std::vector<T>& v) const {\n\t\tprint_range(v.begin(), v.end());\n\
    \t}\n\ttemplate <class T, std::size_t N> void print(const std::array<T, N>& v)\
    \ const {\n\t\tprint_range(v.begin(), v.end());\n\t}\n\ttemplate <class T> void\
    \ print(const std::vector<std::vector<T>>& v) const {\n\t\tfor (std::size_t i\
    \ = 0; i < v.size(); ++i) {\n\t\t\tif (i) print(separator.last);\n\t\t\tprint(v[i]);\n\
    \t\t}\n\t}\n\n\tPrinter() = default;\n\tPrinter(const BoolString& _bool_str, const\
    \ Separator& _separator)\n\t    : bool_str(_bool_str), separator(_separator) {}\n\
    \tPrinter& operator()() {\n\t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\
    \ttemplate <class Head> Printer& operator()(Head&& head) {\n\t\tprint(head);\n\
    \t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\ttemplate <class Head, class...\
    \ Tail> Printer& operator()(Head&& head, Tail&&... tail) {\n\t\tprint(head);\n\
    \t\tprint(separator.sep);\n\t\treturn operator()(std::forward<Tail>(tail)...);\n\
    \t}\n\ttemplate <class... Args> Printer& flag(bool f, Args&&... args) {\n\t\t\
    if (f) {\n\t\t\treturn operator()(std::forward<Args>(args)...);\n\t\t} else {\n\
    \t\t\treturn *this;\n\t\t}\n\t}\n\ttemplate <class InputIterator>\n\tPrinter&\
    \ range(const InputIterator& begin, const InputIterator& end) {\n\t\tprint_range(begin,\
    \ end);\n\t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\ttemplate <class\
    \ Container> Printer& range(const Container& a) {\n\t\trange(a.begin(), a.end());\n\
    \t\treturn *this;\n\t}\n\ttemplate <class... T> void exit(T&&... t) {\n\t\toperator()(std::forward<T>(t)...);\n\
    \t\tstd::exit(EXIT_SUCCESS);\n\t}\n\tPrinter& flush() {\n\t\tfflush_unlocked(stdout);\n\
    \t\treturn *this;\n\t}\n\tPrinter& set(const BoolString& _bool_str) {\n\t\tbool_str\
    \ = _bool_str;\n\t\treturn *this;\n\t}\n\tPrinter& set(const Separator& _separator)\
    \ {\n\t\tseparator = _separator;\n\t\treturn *this;\n\t}\n\tPrinter& set(std::string_view\
    \ t, std::string_view f) {\n\t\tbool_str = BoolString(t, f);\n\t\treturn *this;\n\
    \t}\n} out;\n"
  code: "#pragma once\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    #include <array>\n#include <string>\n#include <string_view>\n#include <optional>\n\
    #include <charconv>\n#include <type_traits>\n#include <cstring>\n#include <cassert>\n\
    \nclass Printer {\npublic:\n\tstruct BoolString {\n\t\tstd::string_view t, f;\n\
    \t\tBoolString(std::string_view _t, std::string_view _f) : t(_t), f(_f) {}\n\t\
    };\n\tstruct Separator {\n\t\tstd::string_view div, sep, last;\n\t\tSeparator(std::string_view\
    \ _div, std::string_view _sep, std::string_view _last)\n\t\t    : div(_div), sep(_sep),\
    \ last(_last) {}\n\t};\n\n\tinline static const BoolString Yes{\"Yes\", \"No\"\
    }, yes{\"yes\", \"no\"}, YES{\"YES\", \"NO\"},\n\t    Int{\"1\", \"0\"}, Possible{\"\
    Possible\", \"Impossible\"};\n\tinline static const Separator space{\" \", \"\
    \ \", \"\\n\"}, no_space{\"\", \"\", \"\\n\"},\n\t    endl{\"\\n\", \"\\n\", \"\
    \\n\"}, comma{\",\", \",\", \"\\n\"}, no_endl{\" \", \" \", \"\"},\n\t    sep_endl{\"\
    \ \", \"\\n\", \"\\n\"};\n\n\tBoolString bool_str{Yes};\n\tSeparator separator{space};\n\
    \nprivate:\n\ttemplate <class T, class = void> struct has_print : std::false_type\
    \ {};\n\ttemplate <class T>\n\tstruct has_print<T,\n\t                 std::void_t<decltype(std::declval<T>().print(std::declval<Printer>()))>>\n\
    \t    : std::true_type {};\n\npublic:\n\tvoid print(int v) const {\n\t\tchar buf[12]{};\n\
    \t\tif (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf), v);\n\t\t\
    \    e == std::errc{}) {\n\t\t\tprint(std::string_view(buf, ptr - buf));\n\t\t\
    } else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(long long v) const {\n\
    \t\tchar buf[21]{};\n\t\tif (auto [ptr, e] = std::to_chars(std::begin(buf), std::end(buf),\
    \ v);\n\t\t    e == std::errc{}) {\n\t\t\tprint(std::string_view(buf, ptr - buf));\n\
    \t\t} else {\n\t\t\tassert(false);\n\t\t}\n\t}\n\tvoid print(bool v) const {\n\
    \t\tprint(v ? bool_str.t : bool_str.f);\n\t}\n\tvoid print(std::vector<bool>::reference\
    \ v) const {\n\t\tprint(v ? bool_str.t : bool_str.f);\n\t}\n\tvoid print(char\
    \ v) const {\n\t\tputchar_unlocked(v);\n\t}\n\tvoid print(std::string_view v)\
    \ const {\n\t\tfwrite_unlocked(v.data(), sizeof(std::string_view::value_type),\
    \ v.size(), stdout);\n\t}\n\tvoid print(double v) const {\n\t\tstd::printf(\"\
    %.20f\", v);\n\t}\n\tvoid print(long double v) const {\n\t\tstd::printf(\"%.20Lf\"\
    , v);\n\t}\n\ttemplate <class T, std::enable_if_t<has_print<T>::value, std::nullptr_t>\
    \ = nullptr>\n\tvoid print(const T& v) const {\n\t\tv.print(*this);\n\t}\n\ttemplate\
    \ <class T, std::enable_if_t<!has_print<T>::value, std::nullptr_t> = nullptr>\n\
    \tvoid print(const T& v) const {\n\t\tstd::cout << v;\n\t}\n\ttemplate <class\
    \ T, class U> void print(const std::pair<T, U>& v) const {\n\t\tprint(v.first);\n\
    \t\tprint(separator.div);\n\t\tprint(v.second);\n\t}\n\ttemplate <class T> void\
    \ print(const std::optional<T>& v) const {\n\t\tprint(*v);\n\t}\n\ttemplate <class\
    \ InputIterater>\n\tvoid print_range(const InputIterater& begin, const InputIterater&\
    \ end) const {\n\t\tfor (InputIterater i = begin; i != end; ++i) {\n\t\t\tif (i\
    \ != begin) print(separator.sep);\n\t\t\tprint(*i);\n\t\t}\n\t}\n\ttemplate <class\
    \ T> void print(const std::vector<T>& v) const {\n\t\tprint_range(v.begin(), v.end());\n\
    \t}\n\ttemplate <class T, std::size_t N> void print(const std::array<T, N>& v)\
    \ const {\n\t\tprint_range(v.begin(), v.end());\n\t}\n\ttemplate <class T> void\
    \ print(const std::vector<std::vector<T>>& v) const {\n\t\tfor (std::size_t i\
    \ = 0; i < v.size(); ++i) {\n\t\t\tif (i) print(separator.last);\n\t\t\tprint(v[i]);\n\
    \t\t}\n\t}\n\n\tPrinter() = default;\n\tPrinter(const BoolString& _bool_str, const\
    \ Separator& _separator)\n\t    : bool_str(_bool_str), separator(_separator) {}\n\
    \tPrinter& operator()() {\n\t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\
    \ttemplate <class Head> Printer& operator()(Head&& head) {\n\t\tprint(head);\n\
    \t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\ttemplate <class Head, class...\
    \ Tail> Printer& operator()(Head&& head, Tail&&... tail) {\n\t\tprint(head);\n\
    \t\tprint(separator.sep);\n\t\treturn operator()(std::forward<Tail>(tail)...);\n\
    \t}\n\ttemplate <class... Args> Printer& flag(bool f, Args&&... args) {\n\t\t\
    if (f) {\n\t\t\treturn operator()(std::forward<Args>(args)...);\n\t\t} else {\n\
    \t\t\treturn *this;\n\t\t}\n\t}\n\ttemplate <class InputIterator>\n\tPrinter&\
    \ range(const InputIterator& begin, const InputIterator& end) {\n\t\tprint_range(begin,\
    \ end);\n\t\tprint(separator.last);\n\t\treturn *this;\n\t}\n\ttemplate <class\
    \ Container> Printer& range(const Container& a) {\n\t\trange(a.begin(), a.end());\n\
    \t\treturn *this;\n\t}\n\ttemplate <class... T> void exit(T&&... t) {\n\t\toperator()(std::forward<T>(t)...);\n\
    \t\tstd::exit(EXIT_SUCCESS);\n\t}\n\tPrinter& flush() {\n\t\tfflush_unlocked(stdout);\n\
    \t\treturn *this;\n\t}\n\tPrinter& set(const BoolString& _bool_str) {\n\t\tbool_str\
    \ = _bool_str;\n\t\treturn *this;\n\t}\n\tPrinter& set(const Separator& _separator)\
    \ {\n\t\tseparator = _separator;\n\t\treturn *this;\n\t}\n\tPrinter& set(std::string_view\
    \ t, std::string_view f) {\n\t\tbool_str = BoolString(t, f);\n\t\treturn *this;\n\
    \t}\n} out;\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Printer.cpp
  requiredBy:
  - template.cpp
  - template_no_Ruby.cpp
  timestamp: '2021-04-15 19:19:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/template.test.cpp
  - test/IO_2Dvector_and_Ruby_push_back_Transpose_Map_Sum.test.cpp
  - test/Input_Output.test.cpp
  - test/template_no_Ruby.test.cpp
  - test/IO_vector_and_Ruby_Reverse.test.cpp
documentation_of: Utility/Printer.cpp
layout: document
redirect_from:
- /library/Utility/Printer.cpp
- /library/Utility/Printer.cpp.html
title: Utility/Printer.cpp
---
