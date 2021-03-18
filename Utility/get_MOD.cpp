#pragma once
constexpr long long get_MOD() {
#ifdef SET_MOD
	return SET_MOD;
#else
	return 1000000007;
#endif
}
