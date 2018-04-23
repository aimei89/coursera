#include <iostream>
#include <vector>

using std::vector;

int get_change(int m, int coins[]) {
	//write your code here
	vector<int> minNum(m + 1);
	minNum[0] = 0;
	for (int i = 1; i <= m; i++) {
		minNum[i] = -1;
		for (int j = 0; j < 3; j++) {
			if (i >= coins[j]) {
				int num = minNum[i - coins[j]] + 1;
				if (num < minNum[i] || minNum[i] == -1)
					minNum[i] = num;
			}
		}
	}
	return minNum[m];
}

int main() {
	int m;
	std::cin >> m;
	int coins[3] = { 1, 3, 4 };
	std::cout << get_change(m, coins) << '\n';
	return 0;
}
