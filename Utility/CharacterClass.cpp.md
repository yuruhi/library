---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/CharacterClass.cpp\"\n#include <string_view>\nusing\
    \ namespace std;\n\nnamespace CharacterClass {\n\tconstexpr string_view\n\t  \
    \  digit = \"0123456789\",\n\t    xdigit = \"0123456789ABCDEFabcdef\", lower =\
    \ \"abcdefghijklmnopqrstuvwxyz\",\n\t    upper = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\
    ,\n\t    alpha = \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\",\n\t\
    \    alnum = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    word = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    punct = R\"(!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~)\",\n\t    graph =\n\t\
    \        R\"(!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~)\"\
    ,\n\t    print =\n\t        R\"( !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\\
    ]^_`abcdefghijklmnopqrstuvwxyz{|}~)\",\n\t    blank = \" \\t\", space = \" \\\
    t\\n\\r\\f\\v\";\n}  // namespace CharacterClass\n"
  code: "#pragma once\n#include <string_view>\nusing namespace std;\n\nnamespace CharacterClass\
    \ {\n\tconstexpr string_view\n\t    digit = \"0123456789\",\n\t    xdigit = \"\
    0123456789ABCDEFabcdef\", lower = \"abcdefghijklmnopqrstuvwxyz\",\n\t    upper\
    \ = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\",\n\t    alpha = \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    alnum = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    word = \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz\"\
    ,\n\t    punct = R\"(!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~)\",\n\t    graph =\n\t\
    \        R\"(!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~)\"\
    ,\n\t    print =\n\t        R\"( !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\\
    ]^_`abcdefghijklmnopqrstuvwxyz{|}~)\",\n\t    blank = \" \\t\", space = \" \\\
    t\\n\\r\\f\\v\";\n}  // namespace CharacterClass\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/CharacterClass.cpp
  requiredBy: []
  timestamp: '2020-12-21 12:03:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/CharacterClass.cpp
layout: document
redirect_from:
- /library/Utility/CharacterClass.cpp
- /library/Utility/CharacterClass.cpp.html
title: Utility/CharacterClass.cpp
---
