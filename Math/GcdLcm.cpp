// shortcut : GcdLcm
// description : 最大公約数 最小公約数
template<class T>T Gcd(T n, T m) {
    return m ? Gcd(m, n % m) : n;
}
template<class T>T Lcm(T n, T m) {
    return n / Gcd(n, m) * m;
}