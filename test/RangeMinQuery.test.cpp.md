---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.cpp
    title: DataStructure/SegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
  bundledCode: "#line 1 \"test/RangeMinQuery.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A\"\
    \n#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n#line 1 \"atcoder/internal_bit.hpp\"\
    \n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\n\
    \tnamespace internal {\n\n\t\t// @param n `0 <= n`\n\t\t// @return minimum non-negative\
    \ `x` s.t. `n <= 2**x`\n\t\tint ceil_pow2(int n) {\n\t\t\tint x = 0;\n\t\t\twhile\
    \ ((1U << x) < (unsigned int)(n))\n\t\t\t\tx++;\n\t\t\treturn x;\n\t\t}\n\n\t\t\
    // @param n `1 <= n`\n\t\t// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\n\t\tint bsf(unsigned int n) {\n#ifdef _MSC_VER\n\t\t\tunsigned long\
    \ index;\n\t\t\t_BitScanForward(&index, n);\n\t\t\treturn index;\n#else\n\t\t\t\
    return __builtin_ctz(n);\n#endif\n\t\t}\n\n\t}  // namespace internal\n\n}  //\
    \ namespace atcoder\n\n\n#line 6 \"atcoder/segtree.hpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace atcoder {\n\n\ttemplate <class S, S (*op)(S, S),\
    \ S (*e)()> struct segtree {\n\tpublic:\n\t\tsegtree() : segtree(0) {}\n\t\tsegtree(int\
    \ n) : segtree(std::vector<S>(n, e())) {}\n\t\tsegtree(const std::vector<S>& v)\
    \ : _n(int(v.size())) {\n\t\t\tlog = internal::ceil_pow2(_n);\n\t\t\tsize = 1\
    \ << log;\n\t\t\td = std::vector<S>(2 * size, e());\n\t\t\tfor (int i = 0; i <\
    \ _n; i++) d[size + i] = v[i];\n\t\t\tfor (int i = size - 1; i >= 1; i--) {\n\t\
    \t\t\tupdate(i);\n\t\t\t}\n\t\t}\n\n\t\tvoid set(int p, S x) {\n\t\t\tassert(0\
    \ <= p && p < _n);\n\t\t\tp += size;\n\t\t\td[p] = x;\n\t\t\tfor (int i = 1; i\
    \ <= log; i++) update(p >> i);\n\t\t}\n\n\t\tS get(int p) {\n\t\t\tassert(0 <=\
    \ p && p < _n);\n\t\t\treturn d[p + size];\n\t\t}\n\n\t\tS operator[](int p) {\n\
    \t\t\treturn get(p);\n\t\t}\n\n\t\tS prod(int l, int r) {\n\t\t\tassert(0 <= l\
    \ && l <= r && r <= _n);\n\t\t\tS sml = e(), smr = e();\n\t\t\tl += size;\n\t\t\
    \tr += size;\n\n\t\t\twhile (l < r) {\n\t\t\t\tif (l & 1) sml = op(sml, d[l++]);\n\
    \t\t\t\tif (r & 1) smr = op(d[--r], smr);\n\t\t\t\tl >>= 1;\n\t\t\t\tr >>= 1;\n\
    \t\t\t}\n\t\t\treturn op(sml, smr);\n\t\t}\n\n\t\tS operator()(int l, int r) {\n\
    \t\t\treturn prod(l, r);\n\t\t}\n\n\t\tS all_prod() {\n\t\t\treturn d[1];\n\t\t\
    }\n\n\t\ttemplate <bool (*f)(S)> int max_right(int l) {\n\t\t\treturn max_right(l,\
    \ [](S x) { return f(x); });\n\t\t}\n\t\ttemplate <class F> int max_right(int\
    \ l, F f) {\n\t\t\tassert(0 <= l && l <= _n);\n\t\t\tassert(f(e()));\n\t\t\tif\
    \ (l == _n) return _n;\n\t\t\tl += size;\n\t\t\tS sm = e();\n\t\t\tdo {\n\t\t\t\
    \twhile (l % 2 == 0) l >>= 1;\n\t\t\t\tif (!f(op(sm, d[l]))) {\n\t\t\t\t\twhile\
    \ (l < size) {\n\t\t\t\t\t\tl = (2 * l);\n\t\t\t\t\t\tif (f(op(sm, d[l]))) {\n\
    \t\t\t\t\t\t\tsm = op(sm, d[l]);\n\t\t\t\t\t\t\tl++;\n\t\t\t\t\t\t}\n\t\t\t\t\t\
    }\n\t\t\t\t\treturn l - size;\n\t\t\t\t}\n\t\t\t\tsm = op(sm, d[l]);\n\t\t\t\t\
    l++;\n\t\t\t} while ((l & -l) != l);\n\t\t\treturn _n;\n\t\t}\n\n\t\ttemplate\
    \ <bool (*f)(S)> int min_left(int r) {\n\t\t\treturn min_left(r, [](S x) { return\
    \ f(x); });\n\t\t}\n\t\ttemplate <class F> int min_left(int r, F f) {\n\t\t\t\
    assert(0 <= r && r <= _n);\n\t\t\tassert(f(e()));\n\t\t\tif (r == 0) return 0;\n\
    \t\t\tr += size;\n\t\t\tS sm = e();\n\t\t\tdo {\n\t\t\t\tr--;\n\t\t\t\twhile (r\
    \ > 1 && (r % 2)) r >>= 1;\n\t\t\t\tif (!f(op(d[r], sm))) {\n\t\t\t\t\twhile (r\
    \ < size) {\n\t\t\t\t\t\tr = (2 * r + 1);\n\t\t\t\t\t\tif (f(op(d[r], sm))) {\n\
    \t\t\t\t\t\t\tsm = op(d[r], sm);\n\t\t\t\t\t\t\tr--;\n\t\t\t\t\t\t}\n\t\t\t\t\t\
    }\n\t\t\t\t\treturn r + 1 - size;\n\t\t\t\t}\n\t\t\t\tsm = op(d[r], sm);\n\t\t\
    \t} while ((r & -r) != r);\n\t\t\treturn 0;\n\t\t}\n\n\t\tstd::vector<S> to_a()\
    \ {\n\t\t\tstd::vector<S> result(_n);\n\t\t\tfor (int i = 0; i < _n; ++i) {\n\t\
    \t\t\tresult[i] = get(i);\n\t\t\t}\n\t\t\treturn result;\n\t\t}\n\n\tprivate:\n\
    \t\tint _n, size, log;\n\t\tstd::vector<S> d;\n\n\t\tvoid update(int k) {\n\t\t\
    \td[k] = op(d[2 * k], d[2 * k + 1]);\n\t\t}\n\t};\n\n}  // namespace atcoder\n\
    \n\n#line 4 \"DataStructure/SegmentTree.cpp\"\n#include <limits>\n\nnamespace\
    \ internal {\n\ttemplate <class S> constexpr S op_max(S x, S y) {\n\t\treturn\
    \ std::max(x, y);\n\t}\n\ttemplate <class S> constexpr S op_min(S x, S y) {\n\t\
    \treturn std::min(x, y);\n\t}\n\ttemplate <class S> constexpr S op_sum(S x, S\
    \ y) {\n\t\treturn x + y;\n\t}\n\ttemplate <class S> constexpr S e_min() {\n\t\
    \treturn std::numeric_limits<S>::min();\n\t}\n\ttemplate <class S> constexpr S\
    \ e_max() {\n\t\treturn std::numeric_limits<S>::max();\n\t}\n\ttemplate <class\
    \ S> constexpr S e_zero() {\n\t\treturn static_cast<S>(0);\n\t}\n}  // namespace\
    \ internal\n\ntemplate <class S>\nusing RangeMaxQuery = atcoder::segtree<S, internal::op_max<S>,\
    \ internal::e_min<S>>;\ntemplate <class S>\nusing RangeMinQuery = atcoder::segtree<S,\
    \ internal::op_min<S>, internal::e_max<S>>;\ntemplate <class S>\nusing RangeSumQuery\
    \ = atcoder::segtree<S, internal::op_sum<S>, internal::e_zero<S>>;\n#line 3 \"\
    test/RangeMinQuery.test.cpp\"\n#include <iostream>\n#line 5 \"test/RangeMinQuery.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint n, q;\n\tcin >> n >> q;\n\tRangeMinQuery<int> seg(vector(n, 0x7FFFFFFF));\n\
    \twhile (q--) {\n\t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\tif (com ==\
    \ 0) {\n\t\t\tseg.set(x, y);\n\t\t} else if (com == 1) {\n\t\t\tcout << seg(x,\
    \ y + 1) << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A\"\
    \n#include \"./../DataStructure/SegmentTree.cpp\"\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\n\nint main() {\n\tcin.tie(nullptr);\n\tios_base::sync_with_stdio(false);\n\
    \n\tint n, q;\n\tcin >> n >> q;\n\tRangeMinQuery<int> seg(vector(n, 0x7FFFFFFF));\n\
    \twhile (q--) {\n\t\tint com, x, y;\n\t\tcin >> com >> x >> y;\n\t\tif (com ==\
    \ 0) {\n\t\t\tseg.set(x, y);\n\t\t} else if (com == 1) {\n\t\t\tcout << seg(x,\
    \ y + 1) << '\\n';\n\t\t}\n\t}\n}"
  dependsOn:
  - DataStructure/SegmentTree.cpp
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  isVerificationFile: true
  path: test/RangeMinQuery.test.cpp
  requiredBy: []
  timestamp: '2021-01-01 18:54:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/RangeMinQuery.test.cpp
layout: document
redirect_from:
- /verify/test/RangeMinQuery.test.cpp
- /verify/test/RangeMinQuery.test.cpp.html
title: test/RangeMinQuery.test.cpp
---
