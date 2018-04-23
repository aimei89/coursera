#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int maximum(int a, int b, int c) {
	return std::max(std::max(a, b), c);
}

int lcs2(vector<int> &a, vector<int> &b) {
	//write your code here
	vector < vector<int>> D;
	D.resize(a.size() + 1, vector<int>(b.size() + 1, 0));
	
	for (int j = 1; j <= b.size(); j++) {
		for (int i = 1; i <= a.size(); i++) {
			if (a[i - 1] == b[j - 1])
				D[i][j] = D[i - 1][j - 1] + 1;
			else
				D[i][j] = maximum(D[i][j - 1], D[i - 1][j], D[i - 1][j - 1]);
		}
	}
	return D[a.size()][b.size()];
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::cout << lcs2(a, b) << std::endl;
	return 0;
}
