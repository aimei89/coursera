#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool compare(string A, string B) {
	int a = stoi(A);
	int b = stoi(B);
	int d1, d2;
	if (a / 100 > 0) d1 = 2;
	else if (a / 10 > 0) d1 = 1;
	else d1 = 0;
	if (b / 100 > 0) d2 = 2;
	else if (b / 10 > 0) d2 = 1;
	else d2 = 0;
	int n, m;
	if (d2 == 2) n = a * 1000 + b;
	else if (d2 == 1) n = a * 100 + b;
	else n = a * 10 + b;
	if (d1 == 2) m = b * 1000 + a;
	else if (d1 == 1) m = b * 100 + a;
	else m = b * 10 + a;
	return n > m;
}

string largest_number(vector<string> a) {
	//write your code here
	std::sort(a.begin(), a.begin() + a.size(), compare);
	std::stringstream ret;
	for (size_t i = 0; i < a.size(); i++) {
		ret << a[i];
	}
	string result;
	ret >> result;
	return result;
}

int main() {
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	std::cout << largest_number(a);
	return 0;
}
