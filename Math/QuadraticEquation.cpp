// shortcut : QuadraticEquation
// description : y = ax^2 + bx + c
optional<vector<long double>> QuadraticEquation(long long a, long long b, long long c) {
	long double A = a, B = b, C = c;
	if (a == 0 && b == 0 && c == 0) {
		return nullopt;
	} else if (a == 0 && b == 0) {
		return vector<long double>{};
	} else if (a == 0) {
		return vector{ -(C / B) };
	} else {
		long long d = b * b - 4 * a * c;
		long double D = static_cast<long double>(d);
		if (d < 0) {
			return vector<long double>{};
		} else if (d == 0) {
			return vector{ -B / (2 * A) };
		} else {
			long double ans1 = 0, ans2 = 0;
			if (b > 0) {
				ans1 = (-B - sqrt(D)) / (2 * A);
			} else {
				ans1 = (-B + sqrt(D)) / (2 * A);
			}
			ans2 = (C / A) / ans1;
			return vector{ min(ans1,ans2),max(ans1,ans2) };
		}
	}
}