---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Dice1.test.cpp
    title: test/Dice1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dice2.test.cpp
    title: test/Dice2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dice3.test.cpp
    title: test/Dice3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dice4.test.cpp
    title: test/Dice4.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Utility/Dice.cpp\"\n#include <tuple>\n#include <iostream>\n\
    using namespace std;\n\nstruct Dice {\n\tint top, front, right, left, back, bottom;\n\
    \tDice(int _top = 1, int _front = 2, int _right = 3, int _left = 4, int _back\
    \ = 5,\n\t     int _bottom = 6)\n\t    : top(_top), front(_front), right(_right),\
    \ left(_left), back(_back), bottom(_bottom) {}\n\tbool operator==(const Dice&\
    \ d) const {\n\t\treturn tuple(top, front, right, left, back, bottom) ==\n\t\t\
    \    tuple(d.top, d.front, d.right, d.left, d.back, d.bottom);\n\t}\n\tbool operator!=(const\
    \ Dice& d) const {\n\t\treturn !(*this == d);\n\t}\n\tvoid roll_left() {\n\t\t\
    tie(top, right, bottom, left) = tuple(right, bottom, left, top);\n\t}\n\tvoid\
    \ roll_right() {\n\t\ttie(top, right, bottom, left) = tuple(left, top, right,\
    \ bottom);\n\t}\n\tvoid roll_front() {\n\t\ttie(top, front, bottom, back) = tuple(back,\
    \ top, front, bottom);\n\t}\n\tvoid roll_back() {\n\t\ttie(top, front, bottom,\
    \ back) = tuple(front, bottom, back, top);\n\t}\n\tDice rolled_left() const {\n\
    \t\tDice x(*this);\n\t\tx.roll_left();\n\t\treturn x;\n\t}\n\tDice rolled_right()\
    \ const {\n\t\tDice x(*this);\n\t\tx.roll_right();\n\t\treturn x;\n\t}\n\tDice\
    \ rolled_front() const {\n\t\tDice x(*this);\n\t\tx.roll_front();\n\t\treturn\
    \ x;\n\t}\n\tDice rolled_back() const {\n\t\tDice x(*this);\n\t\tx.roll_back();\n\
    \t\treturn x;\n\t}\n\tvoid roll(char c) {\n\t\tswitch (c) {\n\t\t\tcase 'W':\n\
    \t\t\tcase 'L':\n\t\t\t\troll_left();\n\t\t\t\tbreak;\n\t\t\tcase 'E':\n\t\t\t\
    case 'R':\n\t\t\t\troll_right();\n\t\t\t\tbreak;\n\t\t\tcase 'S':\n\t\t\tcase\
    \ 'D':\n\t\t\t\troll_front();\n\t\t\t\tbreak;\n\t\t\tcase 'N':\n\t\t\tcase 'U':\n\
    \t\t\t\troll_back();\n\t\t\t\tbreak;\n\t\t}\n\t}\n\tDice rolled(char c) const\
    \ {\n\t\tDice x(*this);\n\t\tx.roll(c);\n\t\treturn x;\n\t}\n\tvoid rotate_left()\
    \ {\n\t\ttie(front, right, back, left) = tuple(right, back, left, front);\n\t\
    }\n\tvoid rotate_right() {\n\t\ttie(front, right, back, left) = tuple(left, front,\
    \ right, back);\n\t}\n\tDice rotated_left() const {\n\t\tDice x(*this);\n\t\t\
    x.rotate_left();\n\t\treturn x;\n\t}\n\tDice rotated_right() const {\n\t\tDice\
    \ x(*this);\n\t\tx.rotate_right();\n\t\treturn x;\n\t}\n\tbool same(Dice other)\
    \ const {\n\t\tDice d(*this);\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.rotate_left();\n\t\t}\n\t\td.roll_left();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.roll_front();\n\t\
    \t}\n\t\td.rotate_right();\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.roll_right();\n\t\t}\n\t\td.rotate_right();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.roll_front();\n\t\
    \t}\n\t\td.rotate_right();\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.roll_right();\n\t\t}\n\t\td.roll_back();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.rotate_left();\n\
    \t\t}\n\t\treturn false;\n\t}\n\tfriend ostream& operator<<(ostream& os, const\
    \ Dice& d) {\n\t\treturn os << \"(top: \" << d.top << \", front: \" << d.front\
    \ << \", right: \" << d.right\n\t\t          << \", left: \" << d.left << \",\
    \ back: \" << d.back << \", bottom: \" << d.bottom\n\t\t          << \")\";\n\t\
    }\n\tfriend istream& operator>>(istream& is, Dice& d) {\n\t\treturn is >> d.top\
    \ >> d.front >> d.right >> d.left >> d.back >> d.bottom;\n\t}\n};\n"
  code: "#pragma once\n#include <tuple>\n#include <iostream>\nusing namespace std;\n\
    \nstruct Dice {\n\tint top, front, right, left, back, bottom;\n\tDice(int _top\
    \ = 1, int _front = 2, int _right = 3, int _left = 4, int _back = 5,\n\t     int\
    \ _bottom = 6)\n\t    : top(_top), front(_front), right(_right), left(_left),\
    \ back(_back), bottom(_bottom) {}\n\tbool operator==(const Dice& d) const {\n\t\
    \treturn tuple(top, front, right, left, back, bottom) ==\n\t\t    tuple(d.top,\
    \ d.front, d.right, d.left, d.back, d.bottom);\n\t}\n\tbool operator!=(const Dice&\
    \ d) const {\n\t\treturn !(*this == d);\n\t}\n\tvoid roll_left() {\n\t\ttie(top,\
    \ right, bottom, left) = tuple(right, bottom, left, top);\n\t}\n\tvoid roll_right()\
    \ {\n\t\ttie(top, right, bottom, left) = tuple(left, top, right, bottom);\n\t\
    }\n\tvoid roll_front() {\n\t\ttie(top, front, bottom, back) = tuple(back, top,\
    \ front, bottom);\n\t}\n\tvoid roll_back() {\n\t\ttie(top, front, bottom, back)\
    \ = tuple(front, bottom, back, top);\n\t}\n\tDice rolled_left() const {\n\t\t\
    Dice x(*this);\n\t\tx.roll_left();\n\t\treturn x;\n\t}\n\tDice rolled_right()\
    \ const {\n\t\tDice x(*this);\n\t\tx.roll_right();\n\t\treturn x;\n\t}\n\tDice\
    \ rolled_front() const {\n\t\tDice x(*this);\n\t\tx.roll_front();\n\t\treturn\
    \ x;\n\t}\n\tDice rolled_back() const {\n\t\tDice x(*this);\n\t\tx.roll_back();\n\
    \t\treturn x;\n\t}\n\tvoid roll(char c) {\n\t\tswitch (c) {\n\t\t\tcase 'W':\n\
    \t\t\tcase 'L':\n\t\t\t\troll_left();\n\t\t\t\tbreak;\n\t\t\tcase 'E':\n\t\t\t\
    case 'R':\n\t\t\t\troll_right();\n\t\t\t\tbreak;\n\t\t\tcase 'S':\n\t\t\tcase\
    \ 'D':\n\t\t\t\troll_front();\n\t\t\t\tbreak;\n\t\t\tcase 'N':\n\t\t\tcase 'U':\n\
    \t\t\t\troll_back();\n\t\t\t\tbreak;\n\t\t}\n\t}\n\tDice rolled(char c) const\
    \ {\n\t\tDice x(*this);\n\t\tx.roll(c);\n\t\treturn x;\n\t}\n\tvoid rotate_left()\
    \ {\n\t\ttie(front, right, back, left) = tuple(right, back, left, front);\n\t\
    }\n\tvoid rotate_right() {\n\t\ttie(front, right, back, left) = tuple(left, front,\
    \ right, back);\n\t}\n\tDice rotated_left() const {\n\t\tDice x(*this);\n\t\t\
    x.rotate_left();\n\t\treturn x;\n\t}\n\tDice rotated_right() const {\n\t\tDice\
    \ x(*this);\n\t\tx.rotate_right();\n\t\treturn x;\n\t}\n\tbool same(Dice other)\
    \ const {\n\t\tDice d(*this);\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.rotate_left();\n\t\t}\n\t\td.roll_left();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.roll_front();\n\t\
    \t}\n\t\td.rotate_right();\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.roll_right();\n\t\t}\n\t\td.rotate_right();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.roll_front();\n\t\
    \t}\n\t\td.rotate_right();\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.roll_right();\n\t\t}\n\t\td.roll_back();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.rotate_left();\n\
    \t\t}\n\t\treturn false;\n\t}\n\tfriend ostream& operator<<(ostream& os, const\
    \ Dice& d) {\n\t\treturn os << \"(top: \" << d.top << \", front: \" << d.front\
    \ << \", right: \" << d.right\n\t\t          << \", left: \" << d.left << \",\
    \ back: \" << d.back << \", bottom: \" << d.bottom\n\t\t          << \")\";\n\t\
    }\n\tfriend istream& operator>>(istream& is, Dice& d) {\n\t\treturn is >> d.top\
    \ >> d.front >> d.right >> d.left >> d.back >> d.bottom;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Utility/Dice.cpp
  requiredBy: []
  timestamp: '2021-01-01 17:28:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Dice4.test.cpp
  - test/Dice1.test.cpp
  - test/Dice3.test.cpp
  - test/Dice2.test.cpp
documentation_of: Utility/Dice.cpp
layout: document
redirect_from:
- /library/Utility/Dice.cpp
- /library/Utility/Dice.cpp.html
title: Utility/Dice.cpp
---
