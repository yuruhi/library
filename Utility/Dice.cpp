#pragma once
#include <tuple>
#include <iostream>
using namespace std;

struct Dice {
	int top, front, right, left, back, bottom;
	Dice(int _top = 1, int _front = 2, int _right = 3, int _left = 4, int _back = 5,
	     int _bottom = 6)
	    : top(_top),
	      front(_front),
	      right(_right),
	      left(_left),
	      back(_back),
	      bottom(_bottom) {}
	bool operator==(const Dice& d) const {
		return tuple(top, front, right, left, back, bottom) ==
		    tuple(d.top, d.front, d.right, d.left, d.back, d.bottom);
	}
	bool operator!=(const Dice& d) const {
		return !(*this == d);
	}
	void roll_left() {
		tie(top, right, bottom, left) = tuple(right, bottom, left, top);
	}
	void roll_right() {
		tie(top, right, bottom, left) = tuple(left, top, right, bottom);
	}
	void roll_front() {
		tie(top, front, bottom, back) = tuple(back, top, front, bottom);
	}
	void roll_back() {
		tie(top, front, bottom, back) = tuple(front, bottom, back, top);
	}
	Dice rolled_left() const {
		Dice x(*this);
		x.roll_left();
		return x;
	}
	Dice rolled_right() const {
		Dice x(*this);
		x.roll_right();
		return x;
	}
	Dice rolled_front() const {
		Dice x(*this);
		x.roll_front();
		return x;
	}
	Dice rolled_back() const {
		Dice x(*this);
		x.roll_back();
		return x;
	}
	void roll(char c) {
		switch (c) {
			case 'W':
			case 'L':
				roll_left();
				break;
			case 'E':
			case 'R':
				roll_right();
				break;
			case 'S':
			case 'D':
				roll_front();
				break;
			case 'N':
			case 'U':
				roll_back();
				break;
		}
	}
	Dice rolled(char c) const {
		Dice x(*this);
		x.roll(c);
		return x;
	}
	void rotate_left() {
		tie(front, right, back, left) = tuple(right, back, left, front);
	}
	void rotate_right() {
		tie(front, right, back, left) = tuple(left, front, right, back);
	}
	Dice rotated_left() const {
		Dice x(*this);
		x.rotate_left();
		return x;
	}
	Dice rotated_right() const {
		Dice x(*this);
		x.rotate_right();
		return x;
	}
	bool same(Dice other) const {
		Dice d(*this);
		for (int i = 4; i--;) {
			if (d == other) return true;
			d.rotate_left();
		}
		d.roll_left();
		for (int i = 4; i--;) {
			if (d == other) return true;
			d.roll_front();
		}
		d.rotate_right();
		for (int i = 4; i--;) {
			if (d == other) return true;
			d.roll_right();
		}
		d.rotate_right();
		for (int i = 4; i--;) {
			if (d == other) return true;
			d.roll_front();
		}
		d.rotate_right();
		for (int i = 4; i--;) {
			if (d == other) return true;
			d.roll_right();
		}
		d.roll_back();
		for (int i = 4; i--;) {
			if (d == other) return true;
			d.rotate_left();
		}
		return false;
	}
	friend ostream& operator<<(ostream& os, const Dice& d) {
		return os << "(top: " << d.top << ", front: " << d.front << ", right: " << d.right
		          << ", left: " << d.left << ", back: " << d.back
		          << ", bottom: " << d.bottom << ")";
	}
	friend istream& operator>>(istream& is, Dice& d) {
		return is >> d.top >> d.front >> d.right >> d.left >> d.back >> d.bottom;
	}
};