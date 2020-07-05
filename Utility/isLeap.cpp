// description : うるう年判定
bool isLeap(int y) {
	return !(y % 4) && (y % 100 || !(y % 400));
}