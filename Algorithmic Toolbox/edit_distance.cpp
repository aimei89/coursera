#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

int minimum(int a, int b, int c) {
	return std::min(std::min(a, b), c);
}

vector < vector<int>> D;

int edit_distance(const string &str1, const string &str2) {
	//write your code here
	//vector < vector<int>> D;
	D.resize(str1.length() + 1, vector<int>(str2.length() + 1, 0));
	for (int j = 0; j <= str1.length(); j++) D[j][0] = j;
	for (int j = 0; j <= str2.length(); j++) D[0][j] = j;
	for (int j = 1; j <= str2.length(); j++) {
		for (int i = 1; i <= str1.length(); i++) {
			//int insertion = D[i][j - 1] + 1;
			//int deletion = D[i - 1][j] + 1;
			//int match = D[i - 1][j - 1];
			//int mismatch = D[i - 1][j - 1] + 1;
			if (str1[i - 1] == str2[j - 1])
				D[i][j] = D[i - 1][j - 1];
			else
				D[i][j] = 1 + minimum(D[i][j - 1], D[i - 1][j], D[i - 1][j - 1]);
		}
	}
	return D[str1.length()][str2.length()];
}

void OutputAlignment(int i, int j, const string &str1, const string &str2) {
	if (i == 0 && j == 0) return;
	if (i > 0 && D[i][j] == D[i - 1][j] + 1) {
		OutputAlignment(i - 1, j, str1, str2);
		std::cout << str1[i - 1] << "|- ";
	}
	else if (j > 0 && D[i][j] == D[i][j - 1] + 1) {
		OutputAlignment(i, j - 1, str1, str2);
		std::cout << "-|" << str2[j - 1] << ' ';
	}
	else {
		OutputAlignment(i - 1, j - 1, str1, str2);
		std::cout << str1[i - 1] << '|' << str2[j - 1] << ' ';
	}
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	//OutputAlignment(str1.length(), str2.length(), str1, str2);
	return 0;
}
