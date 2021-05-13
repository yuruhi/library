---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/IO_2Dvector_and_Ruby_push_back_Transpose_Map_Sum.test.cpp
    title: test/IO_2Dvector_and_Ruby_push_back_Transpose_Map_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/IO_vector_and_Ruby_Reverse.test.cpp
    title: test/IO_vector_and_Ruby_Reverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Ruby_Min_Max_Sum.test.cpp
    title: test/Ruby_Min_Max_Sum.test.cpp
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
  bundledCode: "#line 2 \"Utility/Ruby.cpp\"\n#include <vector>\n#include <string>\n\
    #include <map>\n#include <algorithm>\n#include <numeric>\n#include <cassert>\n\
    #include <iostream>\n\ntemplate <class F> struct Callable {\n\tF func;\n\tCallable(const\
    \ F& f) : func(f) {}\n};\ntemplate <class T, class F> auto operator|(const T&\
    \ v, const Callable<F>& c) {\n\treturn c.func(v);\n}\n\nstruct Sort_impl {\n\t\
    template <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\
    \t\t\tstd::sort(std::begin(v), std::end(v), f);\n\t\t\treturn v;\n\t\t});\n\t\
    }\n\ttemplate <class T> friend auto operator|(T v, [[maybe_unused]] const Sort_impl&\
    \ c) {\n\t\tstd::sort(std::begin(v), std::end(v));\n\t\treturn v;\n\t}\n} Sort;\n\
    struct SortBy_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tstd::sort(std::begin(v), std::end(v),\n\t\t\t\
    \          [&](const auto& i, const auto& j) { return f(i) < f(j); });\n\t\t\t\
    return v;\n\t\t});\n\t}\n} SortBy;\nstruct RSort_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::sort(rbegin(v),\
    \ rend(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class T> friend auto\
    \ operator|(T v, [[maybe_unused]] const RSort_impl& c) {\n\t\tstd::sort(rbegin(v),\
    \ rend(v));\n\t\treturn v;\n\t}\n} RSort;\nstruct RSortBy_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::sort(std::begin(v),\
    \ std::end(v),\n\t\t\t          [&](const auto& i, const auto& j) { return f(i)\
    \ > f(j); });\n\t\t\treturn v;\n\t\t});\n\t}\n} RSortBy;\nstruct Reverse_impl\
    \ {\n\ttemplate <class T> friend auto operator|(T v, const Reverse_impl& c) {\n\
    \t\tstd::reverse(std::begin(v), std::end(v));\n\t\treturn v;\n\t}\n} Reverse;\n\
    struct Unique_impl {\n\ttemplate <class T> friend auto operator|(T v, const Unique_impl&\
    \ c) {\n\t\tv.erase(std::unique(std::begin(v), std::end(v), std::end(v)));\n\t\
    \treturn v;\n\t}\n\ttemplate <class T, class F> auto operator()(F&& f) {\n\t\t\
    return Callable([&](auto v) {\n\t\t\tv.erase(std::unique(std::begin(v), std::end(v),\
    \ f), std::end(v));\n\t\t\treturn v;\n\t\t});\n\t}\n} Unique;\nstruct Uniq_impl\
    \ {\n\ttemplate <class T> friend auto operator|(T v, const Uniq_impl& c) {\n\t\
    \tstd::sort(std::begin(v), std::end(v));\n\t\tv.erase(std::unique(std::begin(v),\
    \ std::end(v)), std::end(v));\n\t\treturn v;\n\t}\n} Uniq;\nstruct Rotate_impl\
    \ {\n\tauto operator()(int&& left) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    int s = static_cast<int>(std::size(v));\n\t\t\tassert(-s <= left && left <= s);\n\
    \t\t\tif (0 <= left) {\n\t\t\t\tstd::rotate(std::begin(v), std::begin(v) + left,\
    \ std::end(v));\n\t\t\t} else {\n\t\t\t\tstd::rotate(std::begin(v), std::end(v)\
    \ + left, std::end(v));\n\t\t\t}\n\t\t\treturn v;\n\t\t});\n\t}\n} Rotate;\nstruct\
    \ Max_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable(\n\
    \t\t    [&](auto v) { return *std::max_element(std::begin(v), std::end(v), f);\
    \ });\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Max_impl& c)\
    \ {\n\t\treturn *std::max_element(std::begin(v), std::end(v));\n\t}\n} Max;\n\
    struct Min_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable(\n\
    \t\t    [&](auto v) { return *std::min_element(std::begin(v), std::end(v), f);\
    \ });\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Min_impl& c)\
    \ {\n\t\treturn *std::min_element(std::begin(v), std::end(v));\n\t}\n} Min;\n\
    struct MaxPos_impl {\n\ttemplate <class T> friend auto operator|(T v, const MaxPos_impl&\
    \ c) {\n\t\treturn std::max_element(std::begin(v), std::end(v)) - std::begin(v);\n\
    \t}\n} MaxPos;\nstruct MinPos_impl {\n\ttemplate <class T> friend auto operator|(T\
    \ v, const MinPos_impl& c) {\n\t\treturn std::min_element(std::begin(v), std::end(v))\
    \ - std::begin(v);\n\t}\n} MinPos;\nstruct MaxBy_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto max_it\
    \ = std::begin(v);\n\t\t\tauto max_val = f(*max_it);\n\t\t\tfor (auto it = std::next(std::begin(v));\
    \ it != std::end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); max_val < val) {\n\
    \t\t\t\t\tmax_it = it;\n\t\t\t\t\tmax_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ *max_it;\n\t\t});\n\t}\n} MaxBy;\nstruct MinBy_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto min_it\
    \ = std::begin(v);\n\t\t\tauto min_val = f(*min_it);\n\t\t\tfor (auto it = std::next(std::begin(v));\
    \ it != std::end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); min_val > val) {\n\
    \t\t\t\t\tmin_it = it;\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ *min_it;\n\t\t});\n\t}\n} MinBy;\nstruct MaxOf_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto max_val\
    \ = f(*std::begin(v));\n\t\t\tfor (auto it = std::next(std::begin(v)); it != std::end(v);\
    \ ++it) {\n\t\t\t\tif (auto val = f(*it); max_val < val) {\n\t\t\t\t\tmax_val\
    \ = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn max_val;\n\t\t});\n\t}\n} MaxOf;\n\
    struct MinOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tauto min_val = f(*std::begin(v));\n\t\t\tfor (auto\
    \ it = std::next(std::begin(v)); it != std::end(v); ++it) {\n\t\t\t\tif (auto\
    \ val = f(*it); min_val > val) {\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\treturn min_val;\n\t\t});\n\t}\n} MinOf;\nstruct Count_impl {\n\ttemplate\
    \ <class V> auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) {\
    \ return std::count(std::begin(v), std::end(v), val); });\n\t}\n} Count;\nstruct\
    \ CountIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn\
    \ Callable([&](auto v) { return std::count_if(std::begin(v), std::end(v), f);\
    \ });\n\t}\n} CountIf;\nstruct Index_impl {\n\ttemplate <class V> auto operator()(const\
    \ V& val) {\n\t\treturn Callable([&](auto v) -> std::optional<int> {\n\t\t\tauto\
    \ result = std::find(std::begin(v), std::end(v), val);\n\t\t\treturn result !=\
    \ std::end(v) ? std::optional(result - std::begin(v))\n\t\t\t                \
    \             : std::nullopt;\n\t\t});\n\t}\n\ttemplate <class V> auto operator()(const\
    \ V& val, std::size_t i) {\n\t\treturn Callable([&](auto v) -> std::optional<int>\
    \ {\n\t\t\tauto result = std::find(std::next(std::begin(v), i), std::end(v), val);\n\
    \t\t\treturn result != std::end(v) ? std::optional(result - std::begin(v))\n\t\
    \t\t                             : std::nullopt;\n\t\t});\n\t}\n} Index;\nstruct\
    \ IndexIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn\
    \ Callable([&](auto v) -> std::optional<int> {\n\t\t\tauto result = std::find_if(std::begin(v),\
    \ std::end(v), f);\n\t\t\treturn result != std::end(v) ? std::optional(result\
    \ - std::begin(v))\n\t\t\t                             : std::nullopt;\n\t\t});\n\
    \t}\n} IndexIf;\nstruct FindIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) -> std::optional<typename decltype(v)::value_type>\
    \ {\n\t\t\tauto result = std::find_if(std::begin(v), std::end(v), f);\n\t\t\t\
    return result != std::end(v) ? std::optional(*result) : std::nullopt;\n\t\t});\n\
    \t}\n} FindIf;\nstruct Sum_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\treturn std::accumulate(std::next(std::begin(v)),\
    \ std::end(v), f(*std::begin(v)),\n\t\t\t                       [&](const auto&\
    \ a, const auto& b) { return a + f(b); });\n\t\t});\n\t}\n\ttemplate <class T>\
    \ friend auto operator|(T v, [[maybe_unused]] const Sum_impl& c) {\n\t\treturn\
    \ std::accumulate(std::begin(v), std::end(v), typename T::value_type{});\n\t}\n\
    } Sum;\nstruct Includes {\n\ttemplate <class V> auto operator()(const V& val)\
    \ {\n\t\treturn Callable(\n\t\t    [&](auto v) { return std::find(std::begin(v),\
    \ std::end(v), val) != std::end(v); });\n\t}\n} Includes;\nstruct IncludesIf_impl\
    \ {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\treturn std::find_if(std::begin(v), std::end(v), f) != std::end(v);\n\
    \t\t});\n\t}\n} IncludesIf;\nstruct RemoveIf_impl {\n\ttemplate <class F> auto\
    \ operator()(const F& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tv.erase(std::remove_if(std::begin(v),\
    \ std::end(v), f), std::end(v));\n\t\t\treturn v;\n\t\t});\n\t}\n} RemoveIf;\n\
    struct Each_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tf(i);\n\t\t\
    \t}\n\t\t});\n\t}\n} Each;\nstruct EachConsPair_impl {\n\ttemplate <class T, class\
    \ value_type = typename T::value_type>\n\tfriend auto operator|(const T& v, EachConsPair_impl&\
    \ c) {\n\t\tstd::vector<std::pair<value_type, value_type>> result;\n\t\tif (std::size(v)\
    \ >= 2) {\n\t\t\tresult.reserve(std::size(v) - 1);\n\t\t\tfor (std::size_t i =\
    \ 0; i < std::size(v) - 1; ++i) {\n\t\t\t\tresult.emplace_back(v[i], v[i + 1]);\n\
    \t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n} EachConsPair;\nstruct Select_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tusing value_type = typename decltype(v)::value_type;\n\t\t\tstd::vector<value_type>\
    \ result;\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) result.push_back(i);\n\
    \t\t\t}\n\t\t\treturn result;\n\t\t});\n\t}\n} Select;\nstruct Map_impl {\n\t\
    template <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\
    \t\t\tusing result_type = std::invoke_result_t<F, typename decltype(v)::value_type>;\n\
    \t\t\tstd::vector<result_type> result;\n\t\t\tresult.reserve(std::size(v));\n\t\
    \t\tfor (const auto& i : v) {\n\t\t\t\tresult.push_back(f(i));\n\t\t\t}\n\t\t\t\
    return result;\n\t\t});\n\t}\n} Map;\nstruct Indexed_impl {\n\ttemplate <class\
    \ T> friend auto operator|(const T& v, Indexed_impl& c) {\n\t\tusing value_type\
    \ = typename T::value_type;\n\t\tstd::vector<std::pair<value_type, int>> result;\n\
    \t\tresult.reserve(std::size(v));\n\t\tint index = 0;\n\t\tfor (const auto& i\
    \ : v) {\n\t\t\tresult.emplace_back(i, index++);\n\t\t}\n\t\treturn result;\n\t\
    }\n} Indexed;\nstruct AllOf_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\
    \tif (!f(i)) return false;\n\t\t\t}\n\t\t\treturn true;\n\t\t});\n\t}\n} AllOf;\n\
    struct AnyOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return\
    \ true;\n\t\t\t}\n\t\t\treturn false;\n\t\t});\n\t}\n} AnyOf;\nstruct NoneOf_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return false;\n\t\t\
    \t}\n\t\t\treturn true;\n\t\t});\n\t}\n} NoneOf;\n\nstruct Tally_impl {\n\tauto\
    \ operator()(std::size_t max_val) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    std::vector<std::size_t> result(max_val);\n\t\t\tfor (const auto& i : v) {\n\t\
    \t\t\tresult[static_cast<std::size_t>(i)]++;\n\t\t\t}\n\t\t\treturn result;\n\t\
    \t});\n\t}\n\ttemplate <class T, class value_type = typename T::value_type>\n\t\
    friend auto operator|(const T& v, Tally_impl& c) {\n\t\tstd::map<value_type, std::size_t>\
    \ result;\n\t\tfor (const auto& i : v) {\n\t\t\tresult[i]++;\n\t\t}\n\t\treturn\
    \ result;\n\t}\n} Tally;\n\nstruct Reduce_impl {\n\ttemplate <class T, class F>\
    \ auto operator()(T memo, F f) {\n\t\treturn Callable([memo, f](auto v) {\n\t\t\
    \tauto acc = memo;\n\t\t\tfor (auto i : v) {\n\t\t\t\tacc = f(acc, i);\n\t\t\t\
    }\n\t\t\treturn acc;\n\t\t});\n\t}\n} Reduce;\n\nstruct Join_impl {\n\tauto operator()(std::string\
    \ separater) {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::string result;\n\
    \t\t\tbool first = true;\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (!std::exchange(first,\
    \ false)) {\n\t\t\t\t\tresult += separater;\n\t\t\t\t}\n\t\t\t\tresult += std::to_string(i);\n\
    \t\t\t}\n\t\t\treturn result;\n\t\t});\n\t}\n\ttemplate <class T> friend auto\
    \ operator|(const T& v, Join_impl& c) {\n\t\treturn v | c(\"\");\n\t}\n} Join;\n\
    \nstruct At_impl {\n\tauto operator()(std::size_t l, std::size_t r) {\n\t\treturn\
    \ Callable(\n\t\t    [l, r](auto v) { return decltype(v)(std::begin(v) + l, std::begin(v)\
    \ + r); });\n\t}\n} At;\nstruct Slice_impl {\n\tauto operator()(std::size_t i,\
    \ std::size_t cnt) {\n\t\treturn Callable([i, cnt](auto v) {\n\t\t\treturn decltype(v)(std::begin(v)\
    \ + i, std::begin(v) + i + cnt);\n\t\t});\n\t}\n} Slice;\n\nstruct Transpose_impl\
    \ {\n\ttemplate <class T>\n\tfriend auto operator|(const std::vector<std::vector<T>>&\
    \ v, Transpose_impl& c) {\n\t\tstd::size_t h = v.size(), w = v.front().size();\n\
    \t\tstd::vector result(w, std::vector<T>(h));\n\t\tfor (std::size_t i = 0; i <\
    \ h; ++i) {\n\t\t\tassert(v[i].size() == w);\n\t\t\tfor (std::size_t j = 0; j\
    \ < w; ++j) {\n\t\t\t\tresult[j][i] = v[i][j];\n\t\t\t}\n\t\t}\n\t\treturn result;\n\
    \t}\n} Transpose;\n\ntemplate <class T> auto operator*(const std::vector<T>& a,\
    \ std::size_t n) {\n\tT result;\n\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\
    result.insert(result.end(), a.begin(), a.end());\n\t}\n\treturn result;\n}\nauto\
    \ operator*(std::string a, std::size_t n) {\n\tstd::string result;\n\tfor (std::size_t\
    \ i = 0; i < n; ++i) {\n\t\tresult += a;\n\t}\n\treturn result;\n}\n\nnamespace\
    \ internal {\n\ttemplate <class T, class U, class = void> struct has_push_back\
    \ : std::false_type {};\n\ttemplate <class T, class U>\n\tstruct has_push_back<T,\
    \ U,\n\t                     std::void_t<decltype(std::declval<T>().push_back(std::declval<U>()))>>\n\
    \t    : std::true_type {};\n}  // namespace internal\ntemplate <\n    class Container,\
    \ class T,\n    std::enable_if_t<internal::has_push_back<Container, T>::value,\
    \ std::nullptr_t> = nullptr>\nauto& operator<<(Container& continer, const T& val)\
    \ {\n\tcontiner.push_back(val);\n\treturn continer;\n}\ntemplate <\n    class\
    \ Container, class T,\n    std::enable_if_t<internal::has_push_back<Container,\
    \ T>::value, std::nullptr_t> = nullptr>\nauto operator+(Container continer, const\
    \ T& val) {\n\tcontiner << val;\n\treturn continer;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <map>\n#include\
    \ <algorithm>\n#include <numeric>\n#include <cassert>\n#include <iostream>\n\n\
    template <class F> struct Callable {\n\tF func;\n\tCallable(const F& f) : func(f)\
    \ {}\n};\ntemplate <class T, class F> auto operator|(const T& v, const Callable<F>&\
    \ c) {\n\treturn c.func(v);\n}\n\nstruct Sort_impl {\n\ttemplate <class F> auto\
    \ operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::sort(std::begin(v),\
    \ std::end(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class T> friend\
    \ auto operator|(T v, [[maybe_unused]] const Sort_impl& c) {\n\t\tstd::sort(std::begin(v),\
    \ std::end(v));\n\t\treturn v;\n\t}\n} Sort;\nstruct SortBy_impl {\n\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    std::sort(std::begin(v), std::end(v),\n\t\t\t          [&](const auto& i, const\
    \ auto& j) { return f(i) < f(j); });\n\t\t\treturn v;\n\t\t});\n\t}\n} SortBy;\n\
    struct RSort_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tstd::sort(rbegin(v), rend(v), f);\n\t\t\treturn\
    \ v;\n\t\t});\n\t}\n\ttemplate <class T> friend auto operator|(T v, [[maybe_unused]]\
    \ const RSort_impl& c) {\n\t\tstd::sort(rbegin(v), rend(v));\n\t\treturn v;\n\t\
    }\n} RSort;\nstruct RSortBy_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::sort(std::begin(v), std::end(v),\n\
    \t\t\t          [&](const auto& i, const auto& j) { return f(i) > f(j); });\n\t\
    \t\treturn v;\n\t\t});\n\t}\n} RSortBy;\nstruct Reverse_impl {\n\ttemplate <class\
    \ T> friend auto operator|(T v, const Reverse_impl& c) {\n\t\tstd::reverse(std::begin(v),\
    \ std::end(v));\n\t\treturn v;\n\t}\n} Reverse;\nstruct Unique_impl {\n\ttemplate\
    \ <class T> friend auto operator|(T v, const Unique_impl& c) {\n\t\tv.erase(std::unique(std::begin(v),\
    \ std::end(v), std::end(v)));\n\t\treturn v;\n\t}\n\ttemplate <class T, class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tv.erase(std::unique(std::begin(v),\
    \ std::end(v), f), std::end(v));\n\t\t\treturn v;\n\t\t});\n\t}\n} Unique;\nstruct\
    \ Uniq_impl {\n\ttemplate <class T> friend auto operator|(T v, const Uniq_impl&\
    \ c) {\n\t\tstd::sort(std::begin(v), std::end(v));\n\t\tv.erase(std::unique(std::begin(v),\
    \ std::end(v)), std::end(v));\n\t\treturn v;\n\t}\n} Uniq;\nstruct Rotate_impl\
    \ {\n\tauto operator()(int&& left) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    int s = static_cast<int>(std::size(v));\n\t\t\tassert(-s <= left && left <= s);\n\
    \t\t\tif (0 <= left) {\n\t\t\t\tstd::rotate(std::begin(v), std::begin(v) + left,\
    \ std::end(v));\n\t\t\t} else {\n\t\t\t\tstd::rotate(std::begin(v), std::end(v)\
    \ + left, std::end(v));\n\t\t\t}\n\t\t\treturn v;\n\t\t});\n\t}\n} Rotate;\nstruct\
    \ Max_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable(\n\
    \t\t    [&](auto v) { return *std::max_element(std::begin(v), std::end(v), f);\
    \ });\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Max_impl& c)\
    \ {\n\t\treturn *std::max_element(std::begin(v), std::end(v));\n\t}\n} Max;\n\
    struct Min_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable(\n\
    \t\t    [&](auto v) { return *std::min_element(std::begin(v), std::end(v), f);\
    \ });\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Min_impl& c)\
    \ {\n\t\treturn *std::min_element(std::begin(v), std::end(v));\n\t}\n} Min;\n\
    struct MaxPos_impl {\n\ttemplate <class T> friend auto operator|(T v, const MaxPos_impl&\
    \ c) {\n\t\treturn std::max_element(std::begin(v), std::end(v)) - std::begin(v);\n\
    \t}\n} MaxPos;\nstruct MinPos_impl {\n\ttemplate <class T> friend auto operator|(T\
    \ v, const MinPos_impl& c) {\n\t\treturn std::min_element(std::begin(v), std::end(v))\
    \ - std::begin(v);\n\t}\n} MinPos;\nstruct MaxBy_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto max_it\
    \ = std::begin(v);\n\t\t\tauto max_val = f(*max_it);\n\t\t\tfor (auto it = std::next(std::begin(v));\
    \ it != std::end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); max_val < val) {\n\
    \t\t\t\t\tmax_it = it;\n\t\t\t\t\tmax_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ *max_it;\n\t\t});\n\t}\n} MaxBy;\nstruct MinBy_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto min_it\
    \ = std::begin(v);\n\t\t\tauto min_val = f(*min_it);\n\t\t\tfor (auto it = std::next(std::begin(v));\
    \ it != std::end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); min_val > val) {\n\
    \t\t\t\t\tmin_it = it;\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ *min_it;\n\t\t});\n\t}\n} MinBy;\nstruct MaxOf_impl {\n\ttemplate <class F>\
    \ auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tauto max_val\
    \ = f(*std::begin(v));\n\t\t\tfor (auto it = std::next(std::begin(v)); it != std::end(v);\
    \ ++it) {\n\t\t\t\tif (auto val = f(*it); max_val < val) {\n\t\t\t\t\tmax_val\
    \ = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn max_val;\n\t\t});\n\t}\n} MaxOf;\n\
    struct MinOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tauto min_val = f(*std::begin(v));\n\t\t\tfor (auto\
    \ it = std::next(std::begin(v)); it != std::end(v); ++it) {\n\t\t\t\tif (auto\
    \ val = f(*it); min_val > val) {\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\treturn min_val;\n\t\t});\n\t}\n} MinOf;\nstruct Count_impl {\n\ttemplate\
    \ <class V> auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) {\
    \ return std::count(std::begin(v), std::end(v), val); });\n\t}\n} Count;\nstruct\
    \ CountIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn\
    \ Callable([&](auto v) { return std::count_if(std::begin(v), std::end(v), f);\
    \ });\n\t}\n} CountIf;\nstruct Index_impl {\n\ttemplate <class V> auto operator()(const\
    \ V& val) {\n\t\treturn Callable([&](auto v) -> std::optional<int> {\n\t\t\tauto\
    \ result = std::find(std::begin(v), std::end(v), val);\n\t\t\treturn result !=\
    \ std::end(v) ? std::optional(result - std::begin(v))\n\t\t\t                \
    \             : std::nullopt;\n\t\t});\n\t}\n\ttemplate <class V> auto operator()(const\
    \ V& val, std::size_t i) {\n\t\treturn Callable([&](auto v) -> std::optional<int>\
    \ {\n\t\t\tauto result = std::find(std::next(std::begin(v), i), std::end(v), val);\n\
    \t\t\treturn result != std::end(v) ? std::optional(result - std::begin(v))\n\t\
    \t\t                             : std::nullopt;\n\t\t});\n\t}\n} Index;\nstruct\
    \ IndexIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn\
    \ Callable([&](auto v) -> std::optional<int> {\n\t\t\tauto result = std::find_if(std::begin(v),\
    \ std::end(v), f);\n\t\t\treturn result != std::end(v) ? std::optional(result\
    \ - std::begin(v))\n\t\t\t                             : std::nullopt;\n\t\t});\n\
    \t}\n} IndexIf;\nstruct FindIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) -> std::optional<typename decltype(v)::value_type>\
    \ {\n\t\t\tauto result = std::find_if(std::begin(v), std::end(v), f);\n\t\t\t\
    return result != std::end(v) ? std::optional(*result) : std::nullopt;\n\t\t});\n\
    \t}\n} FindIf;\nstruct Sum_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\treturn std::accumulate(std::next(std::begin(v)),\
    \ std::end(v), f(*std::begin(v)),\n\t\t\t                       [&](const auto&\
    \ a, const auto& b) { return a + f(b); });\n\t\t});\n\t}\n\ttemplate <class T>\
    \ friend auto operator|(T v, [[maybe_unused]] const Sum_impl& c) {\n\t\treturn\
    \ std::accumulate(std::begin(v), std::end(v), typename T::value_type{});\n\t}\n\
    } Sum;\nstruct Includes {\n\ttemplate <class V> auto operator()(const V& val)\
    \ {\n\t\treturn Callable(\n\t\t    [&](auto v) { return std::find(std::begin(v),\
    \ std::end(v), val) != std::end(v); });\n\t}\n} Includes;\nstruct IncludesIf_impl\
    \ {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\treturn std::find_if(std::begin(v), std::end(v), f) != std::end(v);\n\
    \t\t});\n\t}\n} IncludesIf;\nstruct RemoveIf_impl {\n\ttemplate <class F> auto\
    \ operator()(const F& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tv.erase(std::remove_if(std::begin(v),\
    \ std::end(v), f), std::end(v));\n\t\t\treturn v;\n\t\t});\n\t}\n} RemoveIf;\n\
    struct Each_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tf(i);\n\t\t\
    \t}\n\t\t});\n\t}\n} Each;\nstruct EachConsPair_impl {\n\ttemplate <class T, class\
    \ value_type = typename T::value_type>\n\tfriend auto operator|(const T& v, EachConsPair_impl&\
    \ c) {\n\t\tstd::vector<std::pair<value_type, value_type>> result;\n\t\tif (std::size(v)\
    \ >= 2) {\n\t\t\tresult.reserve(std::size(v) - 1);\n\t\t\tfor (std::size_t i =\
    \ 0; i < std::size(v) - 1; ++i) {\n\t\t\t\tresult.emplace_back(v[i], v[i + 1]);\n\
    \t\t\t}\n\t\t}\n\t\treturn result;\n\t}\n} EachConsPair;\nstruct Select_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tusing value_type = typename decltype(v)::value_type;\n\t\t\tstd::vector<value_type>\
    \ result;\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) result.push_back(i);\n\
    \t\t\t}\n\t\t\treturn result;\n\t\t});\n\t}\n} Select;\nstruct Map_impl {\n\t\
    template <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\
    \t\t\tusing result_type = std::invoke_result_t<F, typename decltype(v)::value_type>;\n\
    \t\t\tstd::vector<result_type> result;\n\t\t\tresult.reserve(std::size(v));\n\t\
    \t\tfor (const auto& i : v) {\n\t\t\t\tresult.push_back(f(i));\n\t\t\t}\n\t\t\t\
    return result;\n\t\t});\n\t}\n} Map;\nstruct Indexed_impl {\n\ttemplate <class\
    \ T> friend auto operator|(const T& v, Indexed_impl& c) {\n\t\tusing value_type\
    \ = typename T::value_type;\n\t\tstd::vector<std::pair<value_type, int>> result;\n\
    \t\tresult.reserve(std::size(v));\n\t\tint index = 0;\n\t\tfor (const auto& i\
    \ : v) {\n\t\t\tresult.emplace_back(i, index++);\n\t\t}\n\t\treturn result;\n\t\
    }\n} Indexed;\nstruct AllOf_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\
    \tif (!f(i)) return false;\n\t\t\t}\n\t\t\treturn true;\n\t\t});\n\t}\n} AllOf;\n\
    struct AnyOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return\
    \ true;\n\t\t\t}\n\t\t\treturn false;\n\t\t});\n\t}\n} AnyOf;\nstruct NoneOf_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return false;\n\t\t\
    \t}\n\t\t\treturn true;\n\t\t});\n\t}\n} NoneOf;\n\nstruct Tally_impl {\n\tauto\
    \ operator()(std::size_t max_val) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    std::vector<std::size_t> result(max_val);\n\t\t\tfor (const auto& i : v) {\n\t\
    \t\t\tresult[static_cast<std::size_t>(i)]++;\n\t\t\t}\n\t\t\treturn result;\n\t\
    \t});\n\t}\n\ttemplate <class T, class value_type = typename T::value_type>\n\t\
    friend auto operator|(const T& v, Tally_impl& c) {\n\t\tstd::map<value_type, std::size_t>\
    \ result;\n\t\tfor (const auto& i : v) {\n\t\t\tresult[i]++;\n\t\t}\n\t\treturn\
    \ result;\n\t}\n} Tally;\n\nstruct Reduce_impl {\n\ttemplate <class T, class F>\
    \ auto operator()(T memo, F f) {\n\t\treturn Callable([memo, f](auto v) {\n\t\t\
    \tauto acc = memo;\n\t\t\tfor (auto i : v) {\n\t\t\t\tacc = f(acc, i);\n\t\t\t\
    }\n\t\t\treturn acc;\n\t\t});\n\t}\n} Reduce;\n\nstruct Join_impl {\n\tauto operator()(std::string\
    \ separater) {\n\t\treturn Callable([&](auto v) {\n\t\t\tstd::string result;\n\
    \t\t\tbool first = true;\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (!std::exchange(first,\
    \ false)) {\n\t\t\t\t\tresult += separater;\n\t\t\t\t}\n\t\t\t\tresult += std::to_string(i);\n\
    \t\t\t}\n\t\t\treturn result;\n\t\t});\n\t}\n\ttemplate <class T> friend auto\
    \ operator|(const T& v, Join_impl& c) {\n\t\treturn v | c(\"\");\n\t}\n} Join;\n\
    \nstruct At_impl {\n\tauto operator()(std::size_t l, std::size_t r) {\n\t\treturn\
    \ Callable(\n\t\t    [l, r](auto v) { return decltype(v)(std::begin(v) + l, std::begin(v)\
    \ + r); });\n\t}\n} At;\nstruct Slice_impl {\n\tauto operator()(std::size_t i,\
    \ std::size_t cnt) {\n\t\treturn Callable([i, cnt](auto v) {\n\t\t\treturn decltype(v)(std::begin(v)\
    \ + i, std::begin(v) + i + cnt);\n\t\t});\n\t}\n} Slice;\n\nstruct Transpose_impl\
    \ {\n\ttemplate <class T>\n\tfriend auto operator|(const std::vector<std::vector<T>>&\
    \ v, Transpose_impl& c) {\n\t\tstd::size_t h = v.size(), w = v.front().size();\n\
    \t\tstd::vector result(w, std::vector<T>(h));\n\t\tfor (std::size_t i = 0; i <\
    \ h; ++i) {\n\t\t\tassert(v[i].size() == w);\n\t\t\tfor (std::size_t j = 0; j\
    \ < w; ++j) {\n\t\t\t\tresult[j][i] = v[i][j];\n\t\t\t}\n\t\t}\n\t\treturn result;\n\
    \t}\n} Transpose;\n\ntemplate <class T> auto operator*(const std::vector<T>& a,\
    \ std::size_t n) {\n\tT result;\n\tfor (std::size_t i = 0; i < n; ++i) {\n\t\t\
    result.insert(result.end(), a.begin(), a.end());\n\t}\n\treturn result;\n}\nauto\
    \ operator*(std::string a, std::size_t n) {\n\tstd::string result;\n\tfor (std::size_t\
    \ i = 0; i < n; ++i) {\n\t\tresult += a;\n\t}\n\treturn result;\n}\n\nnamespace\
    \ internal {\n\ttemplate <class T, class U, class = void> struct has_push_back\
    \ : std::false_type {};\n\ttemplate <class T, class U>\n\tstruct has_push_back<T,\
    \ U,\n\t                     std::void_t<decltype(std::declval<T>().push_back(std::declval<U>()))>>\n\
    \t    : std::true_type {};\n}  // namespace internal\ntemplate <\n    class Container,\
    \ class T,\n    std::enable_if_t<internal::has_push_back<Container, T>::value,\
    \ std::nullptr_t> = nullptr>\nauto& operator<<(Container& continer, const T& val)\
    \ {\n\tcontiner.push_back(val);\n\treturn continer;\n}\ntemplate <\n    class\
    \ Container, class T,\n    std::enable_if_t<internal::has_push_back<Container,\
    \ T>::value, std::nullptr_t> = nullptr>\nauto operator+(Container continer, const\
    \ T& val) {\n\tcontiner << val;\n\treturn continer;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Ruby.cpp
  requiredBy:
  - template.cpp
  timestamp: '2021-03-26 12:00:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Ruby_Min_Max_Sum.test.cpp
  - test/template_no_Ruby.test.cpp
  - test/template.test.cpp
  - test/IO_vector_and_Ruby_Reverse.test.cpp
  - test/IO_2Dvector_and_Ruby_push_back_Transpose_Map_Sum.test.cpp
documentation_of: Utility/Ruby.cpp
layout: document
redirect_from:
- /library/Utility/Ruby.cpp
- /library/Utility/Ruby.cpp.html
title: Utility/Ruby.cpp
---
