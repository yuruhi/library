---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/Ruby.cpp\"\n#include <vector>\n#include <string>\n\
    #include <map>\n#include <algorithm>\n#include <numeric>\n#include <cassert>\n\
    using namespace std;\n\ntemplate <class F> struct Callable {\n\tF func;\n\tCallable(const\
    \ F& f) : func(f) {}\n};\ntemplate <class T, class F> auto operator|(const T&\
    \ v, const Callable<F>& c) {\n\treturn c.func(v);\n}\n\nstruct Sort_impl {\n\t\
    template <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\
    \t\t\tsort(begin(v), end(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class\
    \ T> friend auto operator|(T v, [[maybe_unused]] const Sort_impl& c) {\n\t\tsort(begin(v),\
    \ end(v));\n\t\treturn v;\n\t}\n} Sort;\nstruct SortBy_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tsort(begin(v),\
    \ end(v),\n\t\t\t     [&](const auto& i, const auto& j) { return f(i) < f(j);\
    \ });\n\t\t\treturn v;\n\t\t});\n\t}\n} SortBy;\nstruct RSort_impl {\n\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    sort(rbegin(v), rend(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class\
    \ T> friend auto operator|(T v, [[maybe_unused]] const RSort_impl& c) {\n\t\t\
    sort(rbegin(v), rend(v));\n\t\treturn v;\n\t}\n} RSort;\nstruct RSortBy_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tsort(begin(v), end(v),\n\t\t\t     [&](const auto& i, const auto& j)\
    \ { return f(i) > f(j); });\n\t\t\treturn v;\n\t\t});\n\t}\n} RSortBy;\nstruct\
    \ Reverse_impl {\n\ttemplate <class T> friend auto operator|(T v, const Reverse_impl&\
    \ c) {\n\t\treverse(begin(v), end(v));\n\t\treturn v;\n\t}\n} Reverse;\nstruct\
    \ Unique_impl {\n\ttemplate <class T> friend auto operator|(T v, const Unique_impl&\
    \ c) {\n\t\tv.erase(unique(begin(v), end(v), end(v)));\n\t\treturn v;\n\t}\n}\
    \ Unique;\nstruct Uniq_impl {\n\ttemplate <class T> friend auto operator|(T v,\
    \ const Uniq_impl& c) {\n\t\tsort(begin(v), end(v));\n\t\tv.erase(unique(begin(v),\
    \ end(v)), end(v));\n\t\treturn v;\n\t}\n} Uniq;\nstruct Rotate_impl {\n\tauto\
    \ operator()(int&& left) {\n\t\treturn Callable([&](auto v) {\n\t\t\tint s = static_cast<int>(size(v));\n\
    \t\t\tassert(-s <= left && left <= s);\n\t\t\tif (0 <= left) {\n\t\t\t\trotate(begin(v),\
    \ begin(v) + left, end(v));\n\t\t\t} else {\n\t\t\t\trotate(begin(v), end(v) +\
    \ left, end(v));\n\t\t\t}\n\t\t\treturn v;\n\t\t});\n\t}\n} Rotate;\nstruct Max_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) { return *max_element(begin(v), end(v), f); });\n\t}\n\ttemplate <class T>\
    \ friend auto operator|(T v, const Max_impl& c) {\n\t\treturn *max_element(begin(v),\
    \ end(v));\n\t}\n} Max;\nstruct Min_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) { return *min_element(begin(v), end(v),\
    \ f); });\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Min_impl&\
    \ c) {\n\t\treturn *min_element(begin(v), end(v));\n\t}\n} Min;\nstruct MaxPos_impl\
    \ {\n\ttemplate <class T> friend auto operator|(T v, const MaxPos_impl& c) {\n\
    \t\treturn max_element(begin(v), end(v)) - begin(v);\n\t}\n} MaxPos;\nstruct MinPos_impl\
    \ {\n\ttemplate <class T> friend auto operator|(T v, const MinPos_impl& c) {\n\
    \t\treturn min_element(begin(v), end(v)) - begin(v);\n\t}\n} MinPos;\nstruct MaxBy_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tauto max_it = begin(v);\n\t\t\tauto max_val = f(*max_it);\n\t\t\t\
    for (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it);\
    \ max_val < val) {\n\t\t\t\t\tmax_it = it;\n\t\t\t\t\tmax_val = val;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\treturn *max_it;\n\t\t});\n\t}\n} MaxBy;\nstruct MinBy_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tauto min_it = begin(v);\n\t\t\tauto min_val = f(*min_it);\n\t\t\tfor\
    \ (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it);\
    \ min_val > val) {\n\t\t\t\t\tmin_it = it;\n\t\t\t\t\tmin_val = val;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\treturn *min_it;\n\t\t});\n\t}\n} MinBy;\nstruct MaxOf_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tauto max_val = f(*begin(v));\n\t\t\tfor (auto it = next(begin(v));\
    \ it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); max_val < val) {\n\t\t\
    \t\t\tmax_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn max_val;\n\t\t});\n\t}\n\
    } MaxOf;\nstruct MinOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\
    \t\treturn Callable([&](auto v) {\n\t\t\tauto min_val = f(*begin(v));\n\t\t\t\
    for (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it);\
    \ min_val > val) {\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ min_val;\n\t\t});\n\t}\n} MinOf;\nstruct Count_impl {\n\ttemplate <class V>\
    \ auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) { return count(begin(v),\
    \ end(v), val); });\n\t}\n} Count;\nstruct CountIf_impl {\n\ttemplate <class F>\
    \ auto operator()(const F& f) {\n\t\treturn Callable([&](auto v) { return count_if(begin(v),\
    \ end(v), f); });\n\t}\n} CountIf;\nstruct Index_impl {\n\ttemplate <class V>\
    \ auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) -> optional<int>\
    \ {\n\t\t\tauto result = find(begin(v), end(v), val);\n\t\t\treturn result !=\
    \ end(v) ? optional(result - begin(v)) : nullopt;\n\t\t});\n\t}\n} Index;\nstruct\
    \ IndexIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn\
    \ Callable([&](auto v) -> optional<int> {\n\t\t\tauto result = find_if(begin(v),\
    \ end(v), f);\n\t\t\treturn result != end(v) ? optional(result - begin(v)) : nullopt;\n\
    \t\t});\n\t}\n} IndexIf;\nstruct FindIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) -> optional<typename decltype(v)::value_type>\
    \ {\n\t\t\tauto result = find_if(begin(v), end(v), f);\n\t\t\treturn result !=\
    \ end(v) ? optional(*result) : nullopt;\n\t\t});\n\t}\n} FindIf;\nstruct Sum_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\treturn accumulate(next(begin(v)), end(v), f(*begin(v)),\n\t\t\t\
    \                  [&](const auto& a, const auto& b) { return a + f(b); });\n\t\
    \t});\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Sum_impl& c)\
    \ {\n\t\treturn accumulate(begin(v), end(v), typename T::value_type{});\n\t}\n\
    } Sum;\nstruct Includes {\n\ttemplate <class V> auto operator()(const V& val)\
    \ {\n\t\treturn Callable([&](auto v) { return find(begin(v), end(v), val) != end(v);\
    \ });\n\t}\n} Includes;\nstruct IncludesIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) { return find_if(begin(v), end(v),\
    \ f) != end(v); });\n\t}\n} IncludesIf;\nstruct RemoveIf_impl {\n\ttemplate <class\
    \ F> auto operator()(const F& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    v.erase(remove_if(begin(v), end(v), f), end(v));\n\t\t\treturn v;\n\t\t});\n\t\
    }\n} RemoveIf;\nstruct Each_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\
    \tf(i);\n\t\t\t}\n\t\t});\n\t}\n} Each;\nstruct Select_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tusing\
    \ value_type = typename decltype(v)::value_type;\n\t\t\tvector<value_type> result;\n\
    \t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) result.push_back(i);\n\t\t\t\
    }\n\t\t\treturn result;\n\t\t});\n\t}\n} Select;\nstruct Map_impl {\n\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    using result_type = invoke_result_t<F, typename decltype(v)::value_type>;\n\t\t\
    \tvector<result_type> result;\n\t\t\tresult.reserve(size(v));\n\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\tresult.push_back(f(i));\n\t\t\t}\n\t\t\treturn result;\n\
    \t\t});\n\t}\n} Map;\nstruct Indexed_impl {\n\ttemplate <class T> friend auto\
    \ operator|(const T& v, Indexed_impl& c) {\n\t\tusing value_type = typename T::value_type;\n\
    \t\tvector<pair<value_type, int>> result;\n\t\tresult.reserve(size(v));\n\t\t\
    int index = 0;\n\t\tfor (const auto& i : v) {\n\t\t\tresult.emplace_back(i, index++);\n\
    \t\t}\n\t\treturn result;\n\t}\n} Indexed;\nstruct AllOf_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\tif (!f(i)) return false;\n\t\t\t}\n\t\t\treturn true;\n\
    \t\t});\n\t}\n} AllOf;\nstruct AnyOf_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\
    \t\t\tif (f(i)) return true;\n\t\t\t}\n\t\t\treturn false;\n\t\t});\n\t}\n} AnyOf;\n\
    struct NoneOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return\
    \ false;\n\t\t\t}\n\t\t\treturn true;\n\t\t});\n\t}\n} NoneOf;\n\nstruct Tally_impl\
    \ {\n\ttemplate <class F> auto operator()(size_t max_val) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tvector<size_t> result(max_val);\n\t\t\tfor (const auto& i : v) {\n\
    \t\t\t\tresult[static_cast<size_t>(i)]++;\n\t\t\t}\n\t\t\treturn result;\n\t\t\
    });\n\t}\n\ttemplate <class T, class value_type = typename T::value_type>\n\t\
    friend auto operator|(const T& v, Tally_impl& c) {\n\t\tmap<value_type, size_t>\
    \ result;\n\t\tfor (const auto& i : v) {\n\t\t\tresult[i]++;\n\t\t}\n\t\treturn\
    \ result;\n\t}\n} Tally;\n\ntemplate <class T> auto operator*(const vector<T>&\
    \ a, size_t n) {\n\tT result;\n\tfor (size_t i = 0; i < n; ++i) {\n\t\tresult.insert(result.end(),\
    \ a.begin(), a.end());\n\t}\n\treturn result;\n}\nauto operator*(string a, size_t\
    \ n) {\n\tstring result;\n\tfor (size_t i = 0; i < n; ++i) {\n\t\tresult += a;\n\
    \t}\n\treturn result;\n}\ntemplate <class T, class U> auto& operator<<(vector<T>&\
    \ a, const U& b) {\n\ta.insert(a.end(), all(b));\n\treturn a;\n}\ntemplate <class\
    \ T> auto& operator<<(string& a, const T& b) {\n\ta.insert(a.end(), all(b));\n\
    \treturn a;\n}\ntemplate <class T, class U> auto operator+(vector<T> a, const\
    \ U& b) {\n\ta << b;\n\treturn a;\n}\ntemplate <class T> auto operator+(string\
    \ a, const T& b) {\n\ta << b;\n\treturn a;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <string>\n#include <map>\n#include\
    \ <algorithm>\n#include <numeric>\n#include <cassert>\nusing namespace std;\n\n\
    template <class F> struct Callable {\n\tF func;\n\tCallable(const F& f) : func(f)\
    \ {}\n};\ntemplate <class T, class F> auto operator|(const T& v, const Callable<F>&\
    \ c) {\n\treturn c.func(v);\n}\n\nstruct Sort_impl {\n\ttemplate <class F> auto\
    \ operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tsort(begin(v),\
    \ end(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class T> friend auto\
    \ operator|(T v, [[maybe_unused]] const Sort_impl& c) {\n\t\tsort(begin(v), end(v));\n\
    \t\treturn v;\n\t}\n} Sort;\nstruct SortBy_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tsort(begin(v), end(v),\n\t\t\t\
    \     [&](const auto& i, const auto& j) { return f(i) < f(j); });\n\t\t\treturn\
    \ v;\n\t\t});\n\t}\n} SortBy;\nstruct RSort_impl {\n\ttemplate <class F> auto\
    \ operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tsort(rbegin(v),\
    \ rend(v), f);\n\t\t\treturn v;\n\t\t});\n\t}\n\ttemplate <class T> friend auto\
    \ operator|(T v, [[maybe_unused]] const RSort_impl& c) {\n\t\tsort(rbegin(v),\
    \ rend(v));\n\t\treturn v;\n\t}\n} RSort;\nstruct RSortBy_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tsort(begin(v),\
    \ end(v),\n\t\t\t     [&](const auto& i, const auto& j) { return f(i) > f(j);\
    \ });\n\t\t\treturn v;\n\t\t});\n\t}\n} RSortBy;\nstruct Reverse_impl {\n\ttemplate\
    \ <class T> friend auto operator|(T v, const Reverse_impl& c) {\n\t\treverse(begin(v),\
    \ end(v));\n\t\treturn v;\n\t}\n} Reverse;\nstruct Unique_impl {\n\ttemplate <class\
    \ T> friend auto operator|(T v, const Unique_impl& c) {\n\t\tv.erase(unique(begin(v),\
    \ end(v), end(v)));\n\t\treturn v;\n\t}\n} Unique;\nstruct Uniq_impl {\n\ttemplate\
    \ <class T> friend auto operator|(T v, const Uniq_impl& c) {\n\t\tsort(begin(v),\
    \ end(v));\n\t\tv.erase(unique(begin(v), end(v)), end(v));\n\t\treturn v;\n\t\
    }\n} Uniq;\nstruct Rotate_impl {\n\tauto operator()(int&& left) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tint s = static_cast<int>(size(v));\n\t\t\tassert(-s\
    \ <= left && left <= s);\n\t\t\tif (0 <= left) {\n\t\t\t\trotate(begin(v), begin(v)\
    \ + left, end(v));\n\t\t\t} else {\n\t\t\t\trotate(begin(v), end(v) + left, end(v));\n\
    \t\t\t}\n\t\t\treturn v;\n\t\t});\n\t}\n} Rotate;\nstruct Max_impl {\n\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) { return\
    \ *max_element(begin(v), end(v), f); });\n\t}\n\ttemplate <class T> friend auto\
    \ operator|(T v, const Max_impl& c) {\n\t\treturn *max_element(begin(v), end(v));\n\
    \t}\n} Max;\nstruct Min_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\
    \t\treturn Callable([&](auto v) { return *min_element(begin(v), end(v), f); });\n\
    \t}\n\ttemplate <class T> friend auto operator|(T v, const Min_impl& c) {\n\t\t\
    return *min_element(begin(v), end(v));\n\t}\n} Min;\nstruct MaxPos_impl {\n\t\
    template <class T> friend auto operator|(T v, const MaxPos_impl& c) {\n\t\treturn\
    \ max_element(begin(v), end(v)) - begin(v);\n\t}\n} MaxPos;\nstruct MinPos_impl\
    \ {\n\ttemplate <class T> friend auto operator|(T v, const MinPos_impl& c) {\n\
    \t\treturn min_element(begin(v), end(v)) - begin(v);\n\t}\n} MinPos;\nstruct MaxBy_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tauto max_it = begin(v);\n\t\t\tauto max_val = f(*max_it);\n\t\t\t\
    for (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it);\
    \ max_val < val) {\n\t\t\t\t\tmax_it = it;\n\t\t\t\t\tmax_val = val;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\treturn *max_it;\n\t\t});\n\t}\n} MaxBy;\nstruct MinBy_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tauto min_it = begin(v);\n\t\t\tauto min_val = f(*min_it);\n\t\t\tfor\
    \ (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it);\
    \ min_val > val) {\n\t\t\t\t\tmin_it = it;\n\t\t\t\t\tmin_val = val;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\treturn *min_it;\n\t\t});\n\t}\n} MinBy;\nstruct MaxOf_impl {\n\
    \ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v)\
    \ {\n\t\t\tauto max_val = f(*begin(v));\n\t\t\tfor (auto it = next(begin(v));\
    \ it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it); max_val < val) {\n\t\t\
    \t\t\tmax_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn max_val;\n\t\t});\n\t}\n\
    } MaxOf;\nstruct MinOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\
    \t\treturn Callable([&](auto v) {\n\t\t\tauto min_val = f(*begin(v));\n\t\t\t\
    for (auto it = next(begin(v)); it != end(v); ++it) {\n\t\t\t\tif (auto val = f(*it);\
    \ min_val > val) {\n\t\t\t\t\tmin_val = val;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ min_val;\n\t\t});\n\t}\n} MinOf;\nstruct Count_impl {\n\ttemplate <class V>\
    \ auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) { return count(begin(v),\
    \ end(v), val); });\n\t}\n} Count;\nstruct CountIf_impl {\n\ttemplate <class F>\
    \ auto operator()(const F& f) {\n\t\treturn Callable([&](auto v) { return count_if(begin(v),\
    \ end(v), f); });\n\t}\n} CountIf;\nstruct Index_impl {\n\ttemplate <class V>\
    \ auto operator()(const V& val) {\n\t\treturn Callable([&](auto v) -> optional<int>\
    \ {\n\t\t\tauto result = find(begin(v), end(v), val);\n\t\t\treturn result !=\
    \ end(v) ? optional(result - begin(v)) : nullopt;\n\t\t});\n\t}\n} Index;\nstruct\
    \ IndexIf_impl {\n\ttemplate <class F> auto operator()(const F& f) {\n\t\treturn\
    \ Callable([&](auto v) -> optional<int> {\n\t\t\tauto result = find_if(begin(v),\
    \ end(v), f);\n\t\t\treturn result != end(v) ? optional(result - begin(v)) : nullopt;\n\
    \t\t});\n\t}\n} IndexIf;\nstruct FindIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) -> optional<typename decltype(v)::value_type>\
    \ {\n\t\t\tauto result = find_if(begin(v), end(v), f);\n\t\t\treturn result !=\
    \ end(v) ? optional(*result) : nullopt;\n\t\t});\n\t}\n} FindIf;\nstruct Sum_impl\
    \ {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\treturn accumulate(next(begin(v)), end(v), f(*begin(v)),\n\t\t\t\
    \                  [&](const auto& a, const auto& b) { return a + f(b); });\n\t\
    \t});\n\t}\n\ttemplate <class T> friend auto operator|(T v, const Sum_impl& c)\
    \ {\n\t\treturn accumulate(begin(v), end(v), typename T::value_type{});\n\t}\n\
    } Sum;\nstruct Includes {\n\ttemplate <class V> auto operator()(const V& val)\
    \ {\n\t\treturn Callable([&](auto v) { return find(begin(v), end(v), val) != end(v);\
    \ });\n\t}\n} Includes;\nstruct IncludesIf_impl {\n\ttemplate <class F> auto operator()(const\
    \ F& f) {\n\t\treturn Callable([&](auto v) { return find_if(begin(v), end(v),\
    \ f) != end(v); });\n\t}\n} IncludesIf;\nstruct RemoveIf_impl {\n\ttemplate <class\
    \ F> auto operator()(const F& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    v.erase(remove_if(begin(v), end(v), f), end(v));\n\t\t\treturn v;\n\t\t});\n\t\
    }\n} RemoveIf;\nstruct Each_impl {\n\ttemplate <class F> auto operator()(F&& f)\
    \ {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\
    \tf(i);\n\t\t\t}\n\t\t});\n\t}\n} Each;\nstruct Select_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tusing\
    \ value_type = typename decltype(v)::value_type;\n\t\t\tvector<value_type> result;\n\
    \t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) result.push_back(i);\n\t\t\t\
    }\n\t\t\treturn result;\n\t\t});\n\t}\n} Select;\nstruct Map_impl {\n\ttemplate\
    \ <class F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\t\
    using result_type = invoke_result_t<F, typename decltype(v)::value_type>;\n\t\t\
    \tvector<result_type> result;\n\t\t\tresult.reserve(size(v));\n\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\tresult.push_back(f(i));\n\t\t\t}\n\t\t\treturn result;\n\
    \t\t});\n\t}\n} Map;\nstruct Indexed_impl {\n\ttemplate <class T> friend auto\
    \ operator|(const T& v, Indexed_impl& c) {\n\t\tusing value_type = typename T::value_type;\n\
    \t\tvector<pair<value_type, int>> result;\n\t\tresult.reserve(size(v));\n\t\t\
    int index = 0;\n\t\tfor (const auto& i : v) {\n\t\t\tresult.emplace_back(i, index++);\n\
    \t\t}\n\t\treturn result;\n\t}\n} Indexed;\nstruct AllOf_impl {\n\ttemplate <class\
    \ F> auto operator()(F&& f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const\
    \ auto& i : v) {\n\t\t\t\tif (!f(i)) return false;\n\t\t\t}\n\t\t\treturn true;\n\
    \t\t});\n\t}\n} AllOf;\nstruct AnyOf_impl {\n\ttemplate <class F> auto operator()(F&&\
    \ f) {\n\t\treturn Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\
    \t\t\tif (f(i)) return true;\n\t\t\t}\n\t\t\treturn false;\n\t\t});\n\t}\n} AnyOf;\n\
    struct NoneOf_impl {\n\ttemplate <class F> auto operator()(F&& f) {\n\t\treturn\
    \ Callable([&](auto v) {\n\t\t\tfor (const auto& i : v) {\n\t\t\t\tif (f(i)) return\
    \ false;\n\t\t\t}\n\t\t\treturn true;\n\t\t});\n\t}\n} NoneOf;\n\nstruct Tally_impl\
    \ {\n\ttemplate <class F> auto operator()(size_t max_val) {\n\t\treturn Callable([&](auto\
    \ v) {\n\t\t\tvector<size_t> result(max_val);\n\t\t\tfor (const auto& i : v) {\n\
    \t\t\t\tresult[static_cast<size_t>(i)]++;\n\t\t\t}\n\t\t\treturn result;\n\t\t\
    });\n\t}\n\ttemplate <class T, class value_type = typename T::value_type>\n\t\
    friend auto operator|(const T& v, Tally_impl& c) {\n\t\tmap<value_type, size_t>\
    \ result;\n\t\tfor (const auto& i : v) {\n\t\t\tresult[i]++;\n\t\t}\n\t\treturn\
    \ result;\n\t}\n} Tally;\n\ntemplate <class T> auto operator*(const vector<T>&\
    \ a, size_t n) {\n\tT result;\n\tfor (size_t i = 0; i < n; ++i) {\n\t\tresult.insert(result.end(),\
    \ a.begin(), a.end());\n\t}\n\treturn result;\n}\nauto operator*(string a, size_t\
    \ n) {\n\tstring result;\n\tfor (size_t i = 0; i < n; ++i) {\n\t\tresult += a;\n\
    \t}\n\treturn result;\n}\ntemplate <class T, class U> auto& operator<<(vector<T>&\
    \ a, const U& b) {\n\ta.insert(a.end(), all(b));\n\treturn a;\n}\ntemplate <class\
    \ T> auto& operator<<(string& a, const T& b) {\n\ta.insert(a.end(), all(b));\n\
    \treturn a;\n}\ntemplate <class T, class U> auto operator+(vector<T> a, const\
    \ U& b) {\n\ta << b;\n\treturn a;\n}\ntemplate <class T> auto operator+(string\
    \ a, const T& b) {\n\ta << b;\n\treturn a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/Ruby.cpp
  requiredBy:
  - template/template.cpp
  timestamp: '2020-11-23 14:52:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/Ruby.cpp
layout: document
redirect_from:
- /library/template/Ruby.cpp
- /library/template/Ruby.cpp.html
title: template/Ruby.cpp
---