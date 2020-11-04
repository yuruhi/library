---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/Dice.cpp
    title: Utility/Dice.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_B
  bundledCode: "#line 1 \"test/Dice2.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_B\"\
    \n#line 2 \"Utility/Dice.cpp\"\n#include <tuple>\n#include <iostream>\nusing namespace\
    \ std;\n\nstruct Dice {\n\tint top, front, right, left, back, bottom;\n\tDice(int\
    \ _top = 1, int _front = 2, int _right = 3, int _left = 4, int _back = 5, int\
    \ _bottom = 6)\n\t    : top(_top), front(_front), right(_right), left(_left),\
    \ back(_back), bottom(_bottom) {}\n\tbool operator==(const Dice& d) const {\n\t\
    \treturn tuple(top, front, right, left, back, bottom) == tuple(d.top, d.front,\
    \ d.right, d.left, d.back, d.bottom);\n\t}\n\tbool operator!=(const Dice& d) const\
    \ {\n\t\treturn !(*this == d);\n\t}\n\tvoid roll_left() {\n\t\ttie(top, right,\
    \ bottom, left) = tuple(right, bottom, left, top);\n\t}\n\tvoid roll_right() {\n\
    \t\ttie(top, right, bottom, left) = tuple(left, top, right, bottom);\n\t}\n\t\
    void roll_front() {\n\t\ttie(top, front, bottom, back) = tuple(back, top, front,\
    \ bottom);\n\t}\n\tvoid roll_back() {\n\t\ttie(top, front, bottom, back) = tuple(front,\
    \ bottom, back, top);\n\t}\n\tvoid roll(char c) {\n\t\tswitch (c) {\n\t\t\tcase\
    \ 'W':\n\t\t\t\troll_left();\n\t\t\t\tbreak;\n\t\t\tcase 'E':\n\t\t\t\troll_right();\n\
    \t\t\t\tbreak;\n\t\t\tcase 'S':\n\t\t\t\troll_front();\n\t\t\t\tbreak;\n\t\t\t\
    case 'N':\n\t\t\t\troll_back();\n\t\t\t\tbreak;\n\t\t}\n\t}\n\tvoid rotate_left()\
    \ {\n\t\ttie(front, right, back, left) = tuple(right, back, left, front);\n\t\
    }\n\tvoid rotate_right() {\n\t\ttie(front, right, back, left) = tuple(left, front,\
    \ right, back);\n\t}\n\tbool same(Dice other) const {\n\t\tDice d(*this);\n\t\t\
    for (int i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.rotate_left();\n\
    \t\t}\n\t\td.roll_left();\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.roll_front();\n\t\t}\n\t\td.rotate_right();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.roll_right();\n\t\
    \t}\n\t\td.rotate_right();\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other)\
    \ return true;\n\t\t\td.roll_front();\n\t\t}\n\t\td.rotate_right();\n\t\tfor (int\
    \ i = 4; i--;) {\n\t\t\tif (d == other) return true;\n\t\t\td.roll_right();\n\t\
    \t}\n\t\td.roll_back();\n\t\tfor (int i = 4; i--;) {\n\t\t\tif (d == other) return\
    \ true;\n\t\t\td.rotate_left();\n\t\t}\n\t\treturn false;\n\t}\n\tfriend ostream&\
    \ operator<<(ostream& os, const Dice& d) {\n\t\treturn os << \"(top: \" << d.top\
    \ << \", front: \" << d.front << \", right: \" << d.right << \", left: \" << d.left\n\
    \t\t          << \", back: \" << d.back << \", bottom: \" << d.bottom << \")\"\
    ;\n\t}\n\tfriend istream& operator>>(istream& is, Dice& d) {\n\t\treturn is >>\
    \ d.top >> d.front >> d.right >> d.left >> d.back >> d.bottom;\n\t}\n};\n#line\
    \ 4 \"test/Dice2.test.cpp\"\nusing namespace std;\n\nint main() {\n\tint a, b,\
    \ c, d, e, f;\n\tcin >> a >> b >> c >> d >> e >> f;\n\tDice dice(a, b, c, d, e,\
    \ f);\n\tint n;\n\tcin >> n;\n\twhile (n--) {\n\t\tint a, b;\n\t\tcin >> a >>\
    \ b;\n\t\tif (dice.left == a) dice.roll_right();\n\t\tif (dice.right == a) dice.roll_left();\n\
    \t\twhile (dice.top != a)\n\t\t\tdice.roll_front();\n\t\twhile (dice.front !=\
    \ b)\n\t\t\tdice.rotate_left();\n\t\tcout << dice.right << endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_11_B\"\
    \n#include \"./../Utility/Dice.cpp\"\n#include <iostream>\nusing namespace std;\n\
    \nint main() {\n\tint a, b, c, d, e, f;\n\tcin >> a >> b >> c >> d >> e >> f;\n\
    \tDice dice(a, b, c, d, e, f);\n\tint n;\n\tcin >> n;\n\twhile (n--) {\n\t\tint\
    \ a, b;\n\t\tcin >> a >> b;\n\t\tif (dice.left == a) dice.roll_right();\n\t\t\
    if (dice.right == a) dice.roll_left();\n\t\twhile (dice.top != a)\n\t\t\tdice.roll_front();\n\
    \t\twhile (dice.front != b)\n\t\t\tdice.rotate_left();\n\t\tcout << dice.right\
    \ << endl;\n\t}\n}"
  dependsOn:
  - Utility/Dice.cpp
  isVerificationFile: true
  path: test/Dice2.test.cpp
  requiredBy: []
  timestamp: '2020-11-03 20:31:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Dice2.test.cpp
layout: document
redirect_from:
- /verify/test/Dice2.test.cpp
- /verify/test/Dice2.test.cpp.html
title: test/Dice2.test.cpp
---
