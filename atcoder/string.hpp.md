---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/string.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <numeric>\n#include <string>\n#include <vector>\n\nnamespace\
    \ atcoder {\n\n\tnamespace internal {\n\n\t\tstd::vector<int> sa_naive(const std::vector<int>&\
    \ s) {\n\t\t\tint n = int(s.size());\n\t\t\tstd::vector<int> sa(n);\n\t\t\tstd::iota(sa.begin(),\
    \ sa.end(), 0);\n\t\t\tstd::sort(sa.begin(), sa.end(), [&](int l, int r) {\n\t\
    \t\t\tif (l == r) return false;\n\t\t\t\twhile (l < n && r < n) {\n\t\t\t\t\t\
    if (s[l] != s[r]) return s[l] < s[r];\n\t\t\t\t\tl++;\n\t\t\t\t\tr++;\n\t\t\t\t\
    }\n\t\t\t\treturn l == n;\n\t\t\t});\n\t\t\treturn sa;\n\t\t}\n\n\t\tstd::vector<int>\
    \ sa_doubling(const std::vector<int>& s) {\n\t\t\tint n = int(s.size());\n\t\t\
    \tstd::vector<int> sa(n), rnk = s, tmp(n);\n\t\t\tstd::iota(sa.begin(), sa.end(),\
    \ 0);\n\t\t\tfor (int k = 1; k < n; k *= 2) {\n\t\t\t\tauto cmp = [&](int x, int\
    \ y) {\n\t\t\t\t\tif (rnk[x] != rnk[y]) return rnk[x] < rnk[y];\n\t\t\t\t\tint\
    \ rx = x + k < n ? rnk[x + k] : -1;\n\t\t\t\t\tint ry = y + k < n ? rnk[y + k]\
    \ : -1;\n\t\t\t\t\treturn rx < ry;\n\t\t\t\t};\n\t\t\t\tstd::sort(sa.begin(),\
    \ sa.end(), cmp);\n\t\t\t\ttmp[sa[0]] = 0;\n\t\t\t\tfor (int i = 1; i < n; i++)\
    \ {\n\t\t\t\t\ttmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n\
    \t\t\t\t}\n\t\t\t\tstd::swap(tmp, rnk);\n\t\t\t}\n\t\t\treturn sa;\n\t\t}\n\n\t\
    \t// SA-IS, linear-time suffix array construction\n\t\t// Reference:\n\t\t// G.\
    \ Nong, S. Zhang, and W. H. Chan,\n\t\t// Two Efficient Algorithms for Linear\
    \ Time Suffix Array Construction\n\t\ttemplate <int THRESHOLD_NAIVE = 10, int\
    \ THRESHOLD_DOUBLING = 40>\n\t\tstd::vector<int> sa_is(const std::vector<int>&\
    \ s, int upper) {\n\t\t\tint n = int(s.size());\n\t\t\tif (n == 0) return {};\n\
    \t\t\tif (n == 1) return {0};\n\t\t\tif (n == 2) {\n\t\t\t\tif (s[0] < s[1]) {\n\
    \t\t\t\t\treturn {0, 1};\n\t\t\t\t} else {\n\t\t\t\t\treturn {1, 0};\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\tif (n < THRESHOLD_NAIVE) {\n\t\t\t\treturn sa_naive(s);\n\t\t\
    \t}\n\t\t\tif (n < THRESHOLD_DOUBLING) {\n\t\t\t\treturn sa_doubling(s);\n\t\t\
    \t}\n\n\t\t\tstd::vector<int> sa(n);\n\t\t\tstd::vector<bool> ls(n);\n\t\t\tfor\
    \ (int i = n - 2; i >= 0; i--) {\n\t\t\t\tls[i] = (s[i] == s[i + 1]) ? ls[i +\
    \ 1] : (s[i] < s[i + 1]);\n\t\t\t}\n\t\t\tstd::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\n\t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\tif (!ls[i]) {\n\t\t\t\t\t\
    sum_s[s[i]]++;\n\t\t\t\t} else {\n\t\t\t\t\tsum_l[s[i] + 1]++;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\tfor (int i = 0; i <= upper; i++) {\n\t\t\t\tsum_s[i] += sum_l[i];\n\
    \t\t\t\tif (i < upper) sum_l[i + 1] += sum_s[i];\n\t\t\t}\n\n\t\t\tauto induce\
    \ = [&](const std::vector<int>& lms) {\n\t\t\t\tstd::fill(sa.begin(), sa.end(),\
    \ -1);\n\t\t\t\tstd::vector<int> buf(upper + 1);\n\t\t\t\tstd::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n\t\t\t\tfor (auto d : lms) {\n\t\t\t\t\tif (d ==\
    \ n) continue;\n\t\t\t\t\tsa[buf[s[d]]++] = d;\n\t\t\t\t}\n\t\t\t\tstd::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n\t\t\t\tsa[buf[s[n - 1]]++] = n - 1;\n\t\t\t\tfor\
    \ (int i = 0; i < n; i++) {\n\t\t\t\t\tint v = sa[i];\n\t\t\t\t\tif (v >= 1 &&\
    \ !ls[v - 1]) {\n\t\t\t\t\t\tsa[buf[s[v - 1]]++] = v - 1;\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\tstd::copy(sum_l.begin(), sum_l.end(), buf.begin());\n\t\t\t\tfor\
    \ (int i = n - 1; i >= 0; i--) {\n\t\t\t\t\tint v = sa[i];\n\t\t\t\t\tif (v >=\
    \ 1 && ls[v - 1]) {\n\t\t\t\t\t\tsa[--buf[s[v - 1] + 1]] = v - 1;\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t};\n\n\t\t\tstd::vector<int> lms_map(n + 1, -1);\n\t\t\tint\
    \ m = 0;\n\t\t\tfor (int i = 1; i < n; i++) {\n\t\t\t\tif (!ls[i - 1] && ls[i])\
    \ {\n\t\t\t\t\tlms_map[i] = m++;\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::vector<int> lms;\n\
    \t\t\tlms.reserve(m);\n\t\t\tfor (int i = 1; i < n; i++) {\n\t\t\t\tif (!ls[i\
    \ - 1] && ls[i]) {\n\t\t\t\t\tlms.push_back(i);\n\t\t\t\t}\n\t\t\t}\n\n\t\t\t\
    induce(lms);\n\n\t\t\tif (m) {\n\t\t\t\tstd::vector<int> sorted_lms;\n\t\t\t\t\
    sorted_lms.reserve(m);\n\t\t\t\tfor (int v : sa) {\n\t\t\t\t\tif (lms_map[v] !=\
    \ -1) sorted_lms.push_back(v);\n\t\t\t\t}\n\t\t\t\tstd::vector<int> rec_s(m);\n\
    \t\t\t\tint rec_upper = 0;\n\t\t\t\trec_s[lms_map[sorted_lms[0]]] = 0;\n\t\t\t\
    \tfor (int i = 1; i < m; i++) {\n\t\t\t\t\tint l = sorted_lms[i - 1], r = sorted_lms[i];\n\
    \t\t\t\t\tint end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n\t\t\t\t\
    \tint end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n\t\t\t\t\tbool\
    \ same = true;\n\t\t\t\t\tif (end_l - l != end_r - r) {\n\t\t\t\t\t\tsame = false;\n\
    \t\t\t\t\t} else {\n\t\t\t\t\t\twhile (l < end_l) {\n\t\t\t\t\t\t\tif (s[l] !=\
    \ s[r]) {\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\tl++;\n\t\t\t\
    \t\t\t\tr++;\n\t\t\t\t\t\t}\n\t\t\t\t\t\tif (l == n || s[l] != s[r]) same = false;\n\
    \t\t\t\t\t}\n\t\t\t\t\tif (!same) rec_upper++;\n\t\t\t\t\trec_s[lms_map[sorted_lms[i]]]\
    \ = rec_upper;\n\t\t\t\t}\n\n\t\t\t\tauto rec_sa = sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\n\n\t\t\t\tfor (int i = 0; i < m; i++) {\n\t\t\t\t\tsorted_lms[i]\
    \ = lms[rec_sa[i]];\n\t\t\t\t}\n\t\t\t\tinduce(sorted_lms);\n\t\t\t}\n\t\t\treturn\
    \ sa;\n\t\t}\n\n\t}  // namespace internal\n\n\tstd::vector<int> suffix_array(const\
    \ std::vector<int>& s, int upper) {\n\t\tassert(0 <= upper);\n\t\tfor (int d :\
    \ s) {\n\t\t\tassert(0 <= d && d <= upper);\n\t\t}\n\t\tauto sa = internal::sa_is(s,\
    \ upper);\n\t\treturn sa;\n\t}\n\n\ttemplate <class T> std::vector<int> suffix_array(const\
    \ std::vector<T>& s) {\n\t\tint n = int(s.size());\n\t\tstd::vector<int> idx(n);\n\
    \t\tiota(idx.begin(), idx.end(), 0);\n\t\tsort(idx.begin(), idx.end(), [&](int\
    \ l, int r) {\n\t\t\treturn s[l] < s[r];\n\t\t});\n\t\tstd::vector<int> s2(n);\n\
    \t\tint now = 0;\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (i && s[idx[i -\
    \ 1]] != s[idx[i]]) now++;\n\t\t\ts2[idx[i]] = now;\n\t\t}\n\t\treturn internal::sa_is(s2,\
    \ now);\n\t}\n\n\tstd::vector<int> suffix_array(const std::string& s) {\n\t\t\
    int n = int(s.size());\n\t\tstd::vector<int> s2(n);\n\t\tfor (int i = 0; i < n;\
    \ i++) {\n\t\t\ts2[i] = s[i];\n\t\t}\n\t\treturn internal::sa_is(s2, 255);\n\t\
    }\n\n\t// Reference:\n\t// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,\n\
    \t// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its\n\t\
    // Applications\n\ttemplate <class T> std::vector<int> lcp_array(const std::vector<T>&\
    \ s, const std::vector<int>& sa) {\n\t\tint n = int(s.size());\n\t\tassert(n >=\
    \ 1);\n\t\tstd::vector<int> rnk(n);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\
    rnk[sa[i]] = i;\n\t\t}\n\t\tstd::vector<int> lcp(n - 1);\n\t\tint h = 0;\n\t\t\
    for (int i = 0; i < n; i++) {\n\t\t\tif (h > 0) h--;\n\t\t\tif (rnk[i] == 0) continue;\n\
    \t\t\tint j = sa[rnk[i] - 1];\n\t\t\tfor (; j + h < n && i + h < n; h++) {\n\t\
    \t\t\tif (s[j + h] != s[i + h]) break;\n\t\t\t}\n\t\t\tlcp[rnk[i] - 1] = h;\n\t\
    \t}\n\t\treturn lcp;\n\t}\n\n\tstd::vector<int> lcp_array(const std::string& s,\
    \ const std::vector<int>& sa) {\n\t\tint n = int(s.size());\n\t\tstd::vector<int>\
    \ s2(n);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\ts2[i] = s[i];\n\t\t}\n\t\t\
    return lcp_array(s2, sa);\n\t}\n\n\t// Reference:\n\t// D. Gusfield,\n\t// Algorithms\
    \ on Strings, Trees, and Sequences: Computer Science and\n\t// Computational Biology\n\
    \ttemplate <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {\n\
    \t\tint n = int(s.size());\n\t\tif (n == 0) return {};\n\t\tstd::vector<int> z(n);\n\
    \t\tz[0] = 0;\n\t\tfor (int i = 1, j = 0; i < n; i++) {\n\t\t\tint& k = z[i];\n\
    \t\t\tk = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n\t\t\twhile\
    \ (i + k < n && s[k] == s[i + k])\n\t\t\t\tk++;\n\t\t\tif (j + z[j] < i + z[i])\
    \ j = i;\n\t\t}\n\t\tz[0] = n;\n\t\treturn z;\n\t}\n\n\tstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n\t\tint n = int(s.size());\n\t\tstd::vector<int> s2(n);\n\
    \t\tfor (int i = 0; i < n; i++) {\n\t\t\ts2[i] = s[i];\n\t\t}\n\t\treturn z_algorithm(s2);\n\
    \t}\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_STRING_HPP\n#define ATCODER_STRING_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <numeric>\n#include <string>\n#include <vector>\n\
    \nnamespace atcoder {\n\n\tnamespace internal {\n\n\t\tstd::vector<int> sa_naive(const\
    \ std::vector<int>& s) {\n\t\t\tint n = int(s.size());\n\t\t\tstd::vector<int>\
    \ sa(n);\n\t\t\tstd::iota(sa.begin(), sa.end(), 0);\n\t\t\tstd::sort(sa.begin(),\
    \ sa.end(), [&](int l, int r) {\n\t\t\t\tif (l == r) return false;\n\t\t\t\twhile\
    \ (l < n && r < n) {\n\t\t\t\t\tif (s[l] != s[r]) return s[l] < s[r];\n\t\t\t\t\
    \tl++;\n\t\t\t\t\tr++;\n\t\t\t\t}\n\t\t\t\treturn l == n;\n\t\t\t});\n\t\t\treturn\
    \ sa;\n\t\t}\n\n\t\tstd::vector<int> sa_doubling(const std::vector<int>& s) {\n\
    \t\t\tint n = int(s.size());\n\t\t\tstd::vector<int> sa(n), rnk = s, tmp(n);\n\
    \t\t\tstd::iota(sa.begin(), sa.end(), 0);\n\t\t\tfor (int k = 1; k < n; k *= 2)\
    \ {\n\t\t\t\tauto cmp = [&](int x, int y) {\n\t\t\t\t\tif (rnk[x] != rnk[y]) return\
    \ rnk[x] < rnk[y];\n\t\t\t\t\tint rx = x + k < n ? rnk[x + k] : -1;\n\t\t\t\t\t\
    int ry = y + k < n ? rnk[y + k] : -1;\n\t\t\t\t\treturn rx < ry;\n\t\t\t\t};\n\
    \t\t\t\tstd::sort(sa.begin(), sa.end(), cmp);\n\t\t\t\ttmp[sa[0]] = 0;\n\t\t\t\
    \tfor (int i = 1; i < n; i++) {\n\t\t\t\t\ttmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i\
    \ - 1], sa[i]) ? 1 : 0);\n\t\t\t\t}\n\t\t\t\tstd::swap(tmp, rnk);\n\t\t\t}\n\t\
    \t\treturn sa;\n\t\t}\n\n\t\t// SA-IS, linear-time suffix array construction\n\
    \t\t// Reference:\n\t\t// G. Nong, S. Zhang, and W. H. Chan,\n\t\t// Two Efficient\
    \ Algorithms for Linear Time Suffix Array Construction\n\t\ttemplate <int THRESHOLD_NAIVE\
    \ = 10, int THRESHOLD_DOUBLING = 40>\n\t\tstd::vector<int> sa_is(const std::vector<int>&\
    \ s, int upper) {\n\t\t\tint n = int(s.size());\n\t\t\tif (n == 0) return {};\n\
    \t\t\tif (n == 1) return {0};\n\t\t\tif (n == 2) {\n\t\t\t\tif (s[0] < s[1]) {\n\
    \t\t\t\t\treturn {0, 1};\n\t\t\t\t} else {\n\t\t\t\t\treturn {1, 0};\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\tif (n < THRESHOLD_NAIVE) {\n\t\t\t\treturn sa_naive(s);\n\t\t\
    \t}\n\t\t\tif (n < THRESHOLD_DOUBLING) {\n\t\t\t\treturn sa_doubling(s);\n\t\t\
    \t}\n\n\t\t\tstd::vector<int> sa(n);\n\t\t\tstd::vector<bool> ls(n);\n\t\t\tfor\
    \ (int i = n - 2; i >= 0; i--) {\n\t\t\t\tls[i] = (s[i] == s[i + 1]) ? ls[i +\
    \ 1] : (s[i] < s[i + 1]);\n\t\t\t}\n\t\t\tstd::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\n\t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\tif (!ls[i]) {\n\t\t\t\t\t\
    sum_s[s[i]]++;\n\t\t\t\t} else {\n\t\t\t\t\tsum_l[s[i] + 1]++;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\tfor (int i = 0; i <= upper; i++) {\n\t\t\t\tsum_s[i] += sum_l[i];\n\
    \t\t\t\tif (i < upper) sum_l[i + 1] += sum_s[i];\n\t\t\t}\n\n\t\t\tauto induce\
    \ = [&](const std::vector<int>& lms) {\n\t\t\t\tstd::fill(sa.begin(), sa.end(),\
    \ -1);\n\t\t\t\tstd::vector<int> buf(upper + 1);\n\t\t\t\tstd::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n\t\t\t\tfor (auto d : lms) {\n\t\t\t\t\tif (d ==\
    \ n) continue;\n\t\t\t\t\tsa[buf[s[d]]++] = d;\n\t\t\t\t}\n\t\t\t\tstd::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n\t\t\t\tsa[buf[s[n - 1]]++] = n - 1;\n\t\t\t\tfor\
    \ (int i = 0; i < n; i++) {\n\t\t\t\t\tint v = sa[i];\n\t\t\t\t\tif (v >= 1 &&\
    \ !ls[v - 1]) {\n\t\t\t\t\t\tsa[buf[s[v - 1]]++] = v - 1;\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\tstd::copy(sum_l.begin(), sum_l.end(), buf.begin());\n\t\t\t\tfor\
    \ (int i = n - 1; i >= 0; i--) {\n\t\t\t\t\tint v = sa[i];\n\t\t\t\t\tif (v >=\
    \ 1 && ls[v - 1]) {\n\t\t\t\t\t\tsa[--buf[s[v - 1] + 1]] = v - 1;\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t};\n\n\t\t\tstd::vector<int> lms_map(n + 1, -1);\n\t\t\tint\
    \ m = 0;\n\t\t\tfor (int i = 1; i < n; i++) {\n\t\t\t\tif (!ls[i - 1] && ls[i])\
    \ {\n\t\t\t\t\tlms_map[i] = m++;\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::vector<int> lms;\n\
    \t\t\tlms.reserve(m);\n\t\t\tfor (int i = 1; i < n; i++) {\n\t\t\t\tif (!ls[i\
    \ - 1] && ls[i]) {\n\t\t\t\t\tlms.push_back(i);\n\t\t\t\t}\n\t\t\t}\n\n\t\t\t\
    induce(lms);\n\n\t\t\tif (m) {\n\t\t\t\tstd::vector<int> sorted_lms;\n\t\t\t\t\
    sorted_lms.reserve(m);\n\t\t\t\tfor (int v : sa) {\n\t\t\t\t\tif (lms_map[v] !=\
    \ -1) sorted_lms.push_back(v);\n\t\t\t\t}\n\t\t\t\tstd::vector<int> rec_s(m);\n\
    \t\t\t\tint rec_upper = 0;\n\t\t\t\trec_s[lms_map[sorted_lms[0]]] = 0;\n\t\t\t\
    \tfor (int i = 1; i < m; i++) {\n\t\t\t\t\tint l = sorted_lms[i - 1], r = sorted_lms[i];\n\
    \t\t\t\t\tint end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n\t\t\t\t\
    \tint end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n\t\t\t\t\tbool\
    \ same = true;\n\t\t\t\t\tif (end_l - l != end_r - r) {\n\t\t\t\t\t\tsame = false;\n\
    \t\t\t\t\t} else {\n\t\t\t\t\t\twhile (l < end_l) {\n\t\t\t\t\t\t\tif (s[l] !=\
    \ s[r]) {\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\tl++;\n\t\t\t\
    \t\t\t\tr++;\n\t\t\t\t\t\t}\n\t\t\t\t\t\tif (l == n || s[l] != s[r]) same = false;\n\
    \t\t\t\t\t}\n\t\t\t\t\tif (!same) rec_upper++;\n\t\t\t\t\trec_s[lms_map[sorted_lms[i]]]\
    \ = rec_upper;\n\t\t\t\t}\n\n\t\t\t\tauto rec_sa = sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\n\n\t\t\t\tfor (int i = 0; i < m; i++) {\n\t\t\t\t\tsorted_lms[i]\
    \ = lms[rec_sa[i]];\n\t\t\t\t}\n\t\t\t\tinduce(sorted_lms);\n\t\t\t}\n\t\t\treturn\
    \ sa;\n\t\t}\n\n\t}  // namespace internal\n\n\tstd::vector<int> suffix_array(const\
    \ std::vector<int>& s, int upper) {\n\t\tassert(0 <= upper);\n\t\tfor (int d :\
    \ s) {\n\t\t\tassert(0 <= d && d <= upper);\n\t\t}\n\t\tauto sa = internal::sa_is(s,\
    \ upper);\n\t\treturn sa;\n\t}\n\n\ttemplate <class T> std::vector<int> suffix_array(const\
    \ std::vector<T>& s) {\n\t\tint n = int(s.size());\n\t\tstd::vector<int> idx(n);\n\
    \t\tiota(idx.begin(), idx.end(), 0);\n\t\tsort(idx.begin(), idx.end(), [&](int\
    \ l, int r) {\n\t\t\treturn s[l] < s[r];\n\t\t});\n\t\tstd::vector<int> s2(n);\n\
    \t\tint now = 0;\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (i && s[idx[i -\
    \ 1]] != s[idx[i]]) now++;\n\t\t\ts2[idx[i]] = now;\n\t\t}\n\t\treturn internal::sa_is(s2,\
    \ now);\n\t}\n\n\tstd::vector<int> suffix_array(const std::string& s) {\n\t\t\
    int n = int(s.size());\n\t\tstd::vector<int> s2(n);\n\t\tfor (int i = 0; i < n;\
    \ i++) {\n\t\t\ts2[i] = s[i];\n\t\t}\n\t\treturn internal::sa_is(s2, 255);\n\t\
    }\n\n\t// Reference:\n\t// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,\n\
    \t// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its\n\t\
    // Applications\n\ttemplate <class T> std::vector<int> lcp_array(const std::vector<T>&\
    \ s, const std::vector<int>& sa) {\n\t\tint n = int(s.size());\n\t\tassert(n >=\
    \ 1);\n\t\tstd::vector<int> rnk(n);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\
    rnk[sa[i]] = i;\n\t\t}\n\t\tstd::vector<int> lcp(n - 1);\n\t\tint h = 0;\n\t\t\
    for (int i = 0; i < n; i++) {\n\t\t\tif (h > 0) h--;\n\t\t\tif (rnk[i] == 0) continue;\n\
    \t\t\tint j = sa[rnk[i] - 1];\n\t\t\tfor (; j + h < n && i + h < n; h++) {\n\t\
    \t\t\tif (s[j + h] != s[i + h]) break;\n\t\t\t}\n\t\t\tlcp[rnk[i] - 1] = h;\n\t\
    \t}\n\t\treturn lcp;\n\t}\n\n\tstd::vector<int> lcp_array(const std::string& s,\
    \ const std::vector<int>& sa) {\n\t\tint n = int(s.size());\n\t\tstd::vector<int>\
    \ s2(n);\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\ts2[i] = s[i];\n\t\t}\n\t\t\
    return lcp_array(s2, sa);\n\t}\n\n\t// Reference:\n\t// D. Gusfield,\n\t// Algorithms\
    \ on Strings, Trees, and Sequences: Computer Science and\n\t// Computational Biology\n\
    \ttemplate <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {\n\
    \t\tint n = int(s.size());\n\t\tif (n == 0) return {};\n\t\tstd::vector<int> z(n);\n\
    \t\tz[0] = 0;\n\t\tfor (int i = 1, j = 0; i < n; i++) {\n\t\t\tint& k = z[i];\n\
    \t\t\tk = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n\t\t\twhile\
    \ (i + k < n && s[k] == s[i + k])\n\t\t\t\tk++;\n\t\t\tif (j + z[j] < i + z[i])\
    \ j = i;\n\t\t}\n\t\tz[0] = n;\n\t\treturn z;\n\t}\n\n\tstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n\t\tint n = int(s.size());\n\t\tstd::vector<int> s2(n);\n\
    \t\tfor (int i = 0; i < n; i++) {\n\t\t\ts2[i] = s[i];\n\t\t}\n\t\treturn z_algorithm(s2);\n\
    \t}\n\n}  // namespace atcoder\n\n#endif  // ATCODER_STRING_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: atcoder/string.hpp
  requiredBy: []
  timestamp: '2020-10-30 19:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/string.hpp
layout: document
redirect_from:
- /library/atcoder/string.hpp
- /library/atcoder/string.hpp.html
title: atcoder/string.hpp
---
