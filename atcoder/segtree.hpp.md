---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n#line\
    \ 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nnamespace atcoder {\n\n\tnamespace internal {\n\n\t\t// @param n `0\
    \ <= n`\n\t\t// @return minimum non-negative `x` s.t. `n <= 2**x`\n\t\tint ceil_pow2(int\
    \ n) {\n\t\t\tint x = 0;\n\t\t\twhile ((1U << x) < (unsigned int)(n))\n\t\t\t\t\
    x++;\n\t\t\treturn x;\n\t\t}\n\n\t\t// @param n `1 <= n`\n\t\t// @return minimum\
    \ non-negative `x` s.t. `(n & (1 << x)) != 0`\n\t\tint bsf(unsigned int n) {\n\
    #ifdef _MSC_VER\n\t\t\tunsigned long index;\n\t\t\t_BitScanForward(&index, n);\n\
    \t\t\treturn index;\n#else\n\t\t\treturn __builtin_ctz(n);\n#endif\n\t\t}\n\n\t\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 6 \"atcoder/segtree.hpp\"\
    \n#include <cassert>\n#include <vector>\n\nnamespace atcoder {\n\n\ttemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct segtree {\n\tpublic:\n\t\tsegtree() : segtree(0)\
    \ {}\n\t\tsegtree(int n) : segtree(std::vector<S>(n, e())) {}\n\t\tsegtree(const\
    \ std::vector<S>& v) : _n(int(v.size())) {\n\t\t\tlog = internal::ceil_pow2(_n);\n\
    \t\t\tsize = 1 << log;\n\t\t\td = std::vector<S>(2 * size, e());\n\t\t\tfor (int\
    \ i = 0; i < _n; i++)\n\t\t\t\td[size + i] = v[i];\n\t\t\tfor (int i = size -\
    \ 1; i >= 1; i--) {\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t}\n\n\t\tvoid set(int p,\
    \ S x) {\n\t\t\tassert(0 <= p && p < _n);\n\t\t\tp += size;\n\t\t\td[p] = x;\n\
    \t\t\tfor (int i = 1; i <= log; i++)\n\t\t\t\tupdate(p >> i);\n\t\t}\n\n\t\tS\
    \ get(int p) {\n\t\t\tassert(0 <= p && p < _n);\n\t\t\treturn d[p + size];\n\t\
    \t}\n\n\t\tS prod(int l, int r) {\n\t\t\tassert(0 <= l && l <= r && r <= _n);\n\
    \t\t\tS sml = e(), smr = e();\n\t\t\tl += size;\n\t\t\tr += size;\n\n\t\t\twhile\
    \ (l < r) {\n\t\t\t\tif (l & 1) sml = op(sml, d[l++]);\n\t\t\t\tif (r & 1) smr\
    \ = op(d[--r], smr);\n\t\t\t\tl >>= 1;\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\treturn\
    \ op(sml, smr);\n\t\t}\n\n\t\tS all_prod() {\n\t\t\treturn d[1];\n\t\t}\n\n\t\t\
    template <bool (*f)(S)> int max_right(int l) {\n\t\t\treturn max_right(l, [](S\
    \ x) {\n\t\t\t\treturn f(x);\n\t\t\t});\n\t\t}\n\t\ttemplate <class F> int max_right(int\
    \ l, F f) {\n\t\t\tassert(0 <= l && l <= _n);\n\t\t\tassert(f(e()));\n\t\t\tif\
    \ (l == _n) return _n;\n\t\t\tl += size;\n\t\t\tS sm = e();\n\t\t\tdo {\n\t\t\t\
    \twhile (l % 2 == 0)\n\t\t\t\t\tl >>= 1;\n\t\t\t\tif (!f(op(sm, d[l]))) {\n\t\t\
    \t\t\twhile (l < size) {\n\t\t\t\t\t\tl = (2 * l);\n\t\t\t\t\t\tif (f(op(sm, d[l])))\
    \ {\n\t\t\t\t\t\t\tsm = op(sm, d[l]);\n\t\t\t\t\t\t\tl++;\n\t\t\t\t\t\t}\n\t\t\
    \t\t\t}\n\t\t\t\t\treturn l - size;\n\t\t\t\t}\n\t\t\t\tsm = op(sm, d[l]);\n\t\
    \t\t\tl++;\n\t\t\t} while ((l & -l) != l);\n\t\t\treturn _n;\n\t\t}\n\n\t\ttemplate\
    \ <bool (*f)(S)> int min_left(int r) {\n\t\t\treturn min_left(r, [](S x) {\n\t\
    \t\t\treturn f(x);\n\t\t\t});\n\t\t}\n\t\ttemplate <class F> int min_left(int\
    \ r, F f) {\n\t\t\tassert(0 <= r && r <= _n);\n\t\t\tassert(f(e()));\n\t\t\tif\
    \ (r == 0) return 0;\n\t\t\tr += size;\n\t\t\tS sm = e();\n\t\t\tdo {\n\t\t\t\t\
    r--;\n\t\t\t\twhile (r > 1 && (r % 2))\n\t\t\t\t\tr >>= 1;\n\t\t\t\tif (!f(op(d[r],\
    \ sm))) {\n\t\t\t\t\twhile (r < size) {\n\t\t\t\t\t\tr = (2 * r + 1);\n\t\t\t\t\
    \t\tif (f(op(d[r], sm))) {\n\t\t\t\t\t\t\tsm = op(d[r], sm);\n\t\t\t\t\t\t\tr--;\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\treturn r + 1 - size;\n\t\t\t\t}\n\t\t\t\t\
    sm = op(d[r], sm);\n\t\t\t} while ((r & -r) != r);\n\t\t\treturn 0;\n\t\t}\n\n\
    \tprivate:\n\t\tint _n, size, log;\n\t\tstd::vector<S> d;\n\n\t\tvoid update(int\
    \ k) {\n\t\t\td[k] = op(d[2 * k], d[2 * k + 1]);\n\t\t}\n\t};\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_SEGTREE_HPP\n#define ATCODER_SEGTREE_HPP 1\n\n#include <algorithm>\n\
    #include \"./internal_bit.hpp\"\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\n\ttemplate <class S, S (*op)(S, S), S (*e)()> struct segtree {\n\
    \tpublic:\n\t\tsegtree() : segtree(0) {}\n\t\tsegtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n\t\tsegtree(const std::vector<S>& v) : _n(int(v.size())) {\n\t\t\t\
    log = internal::ceil_pow2(_n);\n\t\t\tsize = 1 << log;\n\t\t\td = std::vector<S>(2\
    \ * size, e());\n\t\t\tfor (int i = 0; i < _n; i++)\n\t\t\t\td[size + i] = v[i];\n\
    \t\t\tfor (int i = size - 1; i >= 1; i--) {\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t\
    }\n\n\t\tvoid set(int p, S x) {\n\t\t\tassert(0 <= p && p < _n);\n\t\t\tp += size;\n\
    \t\t\td[p] = x;\n\t\t\tfor (int i = 1; i <= log; i++)\n\t\t\t\tupdate(p >> i);\n\
    \t\t}\n\n\t\tS get(int p) {\n\t\t\tassert(0 <= p && p < _n);\n\t\t\treturn d[p\
    \ + size];\n\t\t}\n\n\t\tS prod(int l, int r) {\n\t\t\tassert(0 <= l && l <= r\
    \ && r <= _n);\n\t\t\tS sml = e(), smr = e();\n\t\t\tl += size;\n\t\t\tr += size;\n\
    \n\t\t\twhile (l < r) {\n\t\t\t\tif (l & 1) sml = op(sml, d[l++]);\n\t\t\t\tif\
    \ (r & 1) smr = op(d[--r], smr);\n\t\t\t\tl >>= 1;\n\t\t\t\tr >>= 1;\n\t\t\t}\n\
    \t\t\treturn op(sml, smr);\n\t\t}\n\n\t\tS all_prod() {\n\t\t\treturn d[1];\n\t\
    \t}\n\n\t\ttemplate <bool (*f)(S)> int max_right(int l) {\n\t\t\treturn max_right(l,\
    \ [](S x) {\n\t\t\t\treturn f(x);\n\t\t\t});\n\t\t}\n\t\ttemplate <class F> int\
    \ max_right(int l, F f) {\n\t\t\tassert(0 <= l && l <= _n);\n\t\t\tassert(f(e()));\n\
    \t\t\tif (l == _n) return _n;\n\t\t\tl += size;\n\t\t\tS sm = e();\n\t\t\tdo {\n\
    \t\t\t\twhile (l % 2 == 0)\n\t\t\t\t\tl >>= 1;\n\t\t\t\tif (!f(op(sm, d[l])))\
    \ {\n\t\t\t\t\twhile (l < size) {\n\t\t\t\t\t\tl = (2 * l);\n\t\t\t\t\t\tif (f(op(sm,\
    \ d[l]))) {\n\t\t\t\t\t\t\tsm = op(sm, d[l]);\n\t\t\t\t\t\t\tl++;\n\t\t\t\t\t\t\
    }\n\t\t\t\t\t}\n\t\t\t\t\treturn l - size;\n\t\t\t\t}\n\t\t\t\tsm = op(sm, d[l]);\n\
    \t\t\t\tl++;\n\t\t\t} while ((l & -l) != l);\n\t\t\treturn _n;\n\t\t}\n\n\t\t\
    template <bool (*f)(S)> int min_left(int r) {\n\t\t\treturn min_left(r, [](S x)\
    \ {\n\t\t\t\treturn f(x);\n\t\t\t});\n\t\t}\n\t\ttemplate <class F> int min_left(int\
    \ r, F f) {\n\t\t\tassert(0 <= r && r <= _n);\n\t\t\tassert(f(e()));\n\t\t\tif\
    \ (r == 0) return 0;\n\t\t\tr += size;\n\t\t\tS sm = e();\n\t\t\tdo {\n\t\t\t\t\
    r--;\n\t\t\t\twhile (r > 1 && (r % 2))\n\t\t\t\t\tr >>= 1;\n\t\t\t\tif (!f(op(d[r],\
    \ sm))) {\n\t\t\t\t\twhile (r < size) {\n\t\t\t\t\t\tr = (2 * r + 1);\n\t\t\t\t\
    \t\tif (f(op(d[r], sm))) {\n\t\t\t\t\t\t\tsm = op(d[r], sm);\n\t\t\t\t\t\t\tr--;\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\treturn r + 1 - size;\n\t\t\t\t}\n\t\t\t\t\
    sm = op(d[r], sm);\n\t\t\t} while ((r & -r) != r);\n\t\t\treturn 0;\n\t\t}\n\n\
    \tprivate:\n\t\tint _n, size, log;\n\t\tstd::vector<S> d;\n\n\t\tvoid update(int\
    \ k) {\n\t\t\td[k] = op(d[2 * k], d[2 * k + 1]);\n\t\t}\n\t};\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_SEGTREE_HPP\n"
  dependsOn:
  - atcoder/internal_bit.hpp
  isVerificationFile: false
  path: atcoder/segtree.hpp
  requiredBy: []
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/segtree.hpp
layout: document
redirect_from:
- /library/atcoder/segtree.hpp
- /library/atcoder/segtree.hpp.html
title: atcoder/segtree.hpp
---