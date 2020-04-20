// shortcut : Compression
// description : 座標圧縮 0-indexedの配列に
template<class T>void Compression(vector<T>& a) {
	auto v = a;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto& i : a)i = lower_bound(v.begin(), v.end(), i) - v.begin();
}