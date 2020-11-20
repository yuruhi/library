---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryIndexedTree.cpp
    title: DataStructure/BinaryIndexedTree.cpp
  - icon: ':heavy_check_mark:'
    path: Math/Inversion.cpp
    title: Math/Inversion.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_5_D
  bundledCode: "#line 1 \"test/Inversion.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_5_D\"\
    \n#line 2 \"DataStructure/BinaryIndexedTree.cpp\"\n#include <vector>\n#include\
    \ <cassert>\nusing namespace std;\n\ntemplate <class T> class BinaryIndexedTree\
    \ {\n\tint n, n2;\n\tvector<T> a;\n\npublic:\n\tBinaryIndexedTree(int n_) : n(n_),\
    \ n2(1), a(n_ + 1) {\n\t\twhile (n2 < n) n2 *= 2;\n\t\tn2 /= 2;\n\t}\n\tT operator()(int\
    \ i) const {  // [0, i]\n\t\tassert(0 < ++i);\n\t\tT res = 0;\n\t\tfor (; i >\
    \ 0; i -= i & -i) {\n\t\t\tres += a[i];\n\t\t}\n\t\treturn res;\n\t}\n\tT operator()(int\
    \ i, int j) const {  // [i, j]\n\t\treturn operator()(j) - (i ? operator()(i -\
    \ 1) : 0);\n\t}\n\tT operator[](int i) const {\n\t\treturn operator()(i, i);\n\
    \t}\n\tvoid add(int i, T x) {\n\t\tassert(0 < ++i);\n\t\tfor (; i <= n; i += i\
    \ & -i) {\n\t\t\ta[i] += x;\n\t\t}\n\t}\n\tint lower_bound(T k) const {\n\t\t\
    if (k <= 0) return 0;\n\t\tint res = 0;\n\t\tfor (int i = n2; i > 0; i /= 2) {\n\
    \t\t\tif (res + i <= n && a[res + i] < k) {\n\t\t\t\tk -= a[res + i];\n\t\t\t\t\
    res += i;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tvector<int> to_a() const {\n\
    \t\tvector<int> res(n);\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tres[i] = operator()(i,\
    \ i);\n\t\t}\n\t\treturn res;\n\t}\n};\n#line 4 \"Math/Inversion.cpp\"\nusing\
    \ namespace std;\n\nlong long Inversion(const vector<int>& a, int max_val) {\n\
    \tlong long ans = 0;\n\tBinaryIndexedTree<int> bit(max_val + 1);\n\tfor (size_t\
    \ i = 0; i < a.size(); ++i) {\n\t\tans += i - bit(a[i]);\n\t\tbit.add(a[i], 1);\n\
    \t}\n\treturn ans;\n}\n#line 3 \"test/Inversion.test.cpp\"\n#include <iostream>\n\
    #include <algorithm>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\
    \tios_base::sync_with_stdio(false);\n\tint n;\n\tcin >> n;\n\tvector<int> a(n);\n\
    \tfor (int& i : a) {\n\t\tcin >> i;\n\t}\n\n\tauto b = a;\n\tsort(b.begin(), b.end());\n\
    \tfor (int& i : a) {\n\t\ti = lower_bound(b.begin(), b.end(), i) - b.begin() +\
    \ 1;\n\t}\n\tcout << Inversion(a, n) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_5_D\"\
    \n#include \"./../Math/Inversion.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    using namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \tint n;\n\tcin >> n;\n\tvector<int> a(n);\n\tfor (int& i : a) {\n\t\tcin >> i;\n\
    \t}\n\n\tauto b = a;\n\tsort(b.begin(), b.end());\n\tfor (int& i : a) {\n\t\t\
    i = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;\n\t}\n\tcout << Inversion(a,\
    \ n) << '\\n';\n}"
  dependsOn:
  - Math/Inversion.cpp
  - DataStructure/BinaryIndexedTree.cpp
  isVerificationFile: true
  path: test/Inversion.test.cpp
  requiredBy: []
  timestamp: '2020-11-20 21:19:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Inversion.test.cpp
layout: document
redirect_from:
- /verify/test/Inversion.test.cpp
- /verify/test/Inversion.test.cpp.html
title: test/Inversion.test.cpp
---
