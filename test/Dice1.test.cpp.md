---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/Dice.cpp
    title: Utility/Dice.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_A
  bundledCode: "#line 1 \"test/Dice1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_A\"\
    \n#line 2 \"Utility/Dice.cpp\"\n#include <tuple>\n#include <iostream>\n\nstruct\
    \ Dice {\n\tint top, front, right, left, back, bottom;\n\tDice(int _top = 1, int\
    \ _front = 2, int _right = 3, int _left = 4, int _back = 5,\n\t     int _bottom\
    \ = 6)\n\t    : top(_top), front(_front), right(_right), left(_left), back(_back),\
    \ bottom(_bottom) {}\n\tbool operator==(const Dice& d) const {\n\t\treturn std::tuple(top,\
    \ front, right, left, back, bottom) ==\n\t\t    std::tuple(d.top, d.front, d.right,\
    \ d.left, d.back, d.bottom);\n\t}\n\tbool operator!=(const Dice& d) const {\n\t\
    \treturn !(*this == d);\n\t}\n\tvoid roll_left() {\n\t\tstd::tie(top, right, bottom,\
    \ left) = std::tuple(right, bottom, left, top);\n\t}\n\tvoid roll_right() {\n\t\
    \tstd::tie(top, right, bottom, left) = std::tuple(left, top, right, bottom);\n\
    \t}\n\tvoid roll_front() {\n\t\tstd::tie(top, front, bottom, back) = std::tuple(back,\
    \ top, front, bottom);\n\t}\n\tvoid roll_back() {\n\t\tstd::tie(top, front, bottom,\
    \ back) = std::tuple(front, bottom, back, top);\n\t}\n\tDice rolled_left() const\
    \ {\n\t\tDice x(*this);\n\t\tx.roll_left();\n\t\treturn x;\n\t}\n\tDice rolled_right()\
    \ const {\n\t\tDice x(*this);\n\t\tx.roll_right();\n\t\treturn x;\n\t}\n\tDice\
    \ rolled_front() const {\n\t\tDice x(*this);\n\t\tx.roll_front();\n\t\treturn\
    \ x;\n\t}\n\tDice rolled_back() const {\n\t\tDice x(*this);\n\t\tx.roll_back();\n\
    \t\treturn x;\n\t}\n\tvoid roll(char c) {\n\t\tswitch (c) {\n\t\t\tcase 'W':\n\
    \t\t\tcase 'L':\n\t\t\t\troll_left();\n\t\t\t\tbreak;\n\t\t\tcase 'E':\n\t\t\t\
    case 'R':\n\t\t\t\troll_right();\n\t\t\t\tbreak;\n\t\t\tcase 'S':\n\t\t\tcase\
    \ 'D':\n\t\t\t\troll_front();\n\t\t\t\tbreak;\n\t\t\tcase 'N':\n\t\t\tcase 'U':\n\
    \t\t\t\troll_back();\n\t\t\t\tbreak;\n\t\t}\n\t}\n\tDice rolled(char c) const\
    \ {\n\t\tDice x(*this);\n\t\tx.roll(c);\n\t\treturn x;\n\t}\n\tvoid rotate_left()\
    \ {\n\t\tstd::tie(front, right, back, left) = std::tuple(right, back, left, front);\n\
    \t}\n\tvoid rotate_right() {\n\t\tstd::tie(front, right, back, left) = std::tuple(left,\
    \ front, right, back);\n\t}\n\tDice rotated_left() const {\n\t\tDice x(*this);\n\
    \t\tx.rotate_left();\n\t\treturn x;\n\t}\n\tDice rotated_right() const {\n\t\t\
    Dice x(*this);\n\t\tx.rotate_right();\n\t\treturn x;\n\t}\n\tbool same(Dice other)\
    \ const {\n\t\tDice d(*this);\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.rotate_left();\n\t\t}\n\t\td.roll_left();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.roll_front();\n\t\
    \t}\n\t\td.rotate_right();\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.roll_right();\n\t\t}\n\t\td.rotate_right();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.roll_front();\n\t\
    \t}\n\t\td.rotate_right();\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.roll_right();\n\t\t}\n\t\td.roll_back();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.rotate_left();\n\
    \t\t}\n\t\treturn false;\n\t}\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const Dice& d) {\n\t\treturn os << \"(top: \" << d.top << \", front: \"\
    \ << d.front << \", right: \" << d.right\n\t\t          << \", left: \" << d.left\
    \ << \", back: \" << d.back << \", bottom: \" << d.bottom\n\t\t          << \"\
    )\";\n\t}\n\tfriend std::istream& operator>>(std::istream& is, Dice& d) {\n\t\t\
    return is >> d.top >> d.front >> d.right >> d.left >> d.back >> d.bottom;\n\t\
    }\n};\n#line 4 \"test/Dice1.test.cpp\"\nusing namespace std;\n\nint main() {\n\
    \tint a, b, c, d, e, f;\n\tcin >> a >> b >> c >> d >> e >> f;\n\tstring s;\n\t\
    cin >> s;\n\tDice dice(a, b, c, d, e, f);\n\tfor (char c : s) {\n\t\tdice.roll(c);\n\
    \t}\n\tcout << dice.top << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_A\"\
    \n#include \"./../Utility/Dice.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint a, b, c, d, e, f;\n\tcin >> a >> b >> c >> d >> e >> f;\n\
    \tstring s;\n\tcin >> s;\n\tDice dice(a, b, c, d, e, f);\n\tfor (char c : s) {\n\
    \t\tdice.roll(c);\n\t}\n\tcout << dice.top << endl;\n}"
  dependsOn:
  - Utility/Dice.cpp
  isVerificationFile: true
  path: test/Dice1.test.cpp
  requiredBy: []
  timestamp: '2021-04-06 14:24:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Dice1.test.cpp
layout: document
redirect_from:
- /verify/test/Dice1.test.cpp
- /verify/test/Dice1.test.cpp.html
title: test/Dice1.test.cpp
---
