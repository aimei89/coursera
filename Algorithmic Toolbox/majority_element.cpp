#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
	//write your code here
	if (right - left == 1) {
		if (a[left] == a[right]) return a[left];
		else return -1;
	}
	else if (left == right) return a[left];
	int elem1 = get_majority_element(a, left, left + floor((right - left) / 2));
	int elem2 = get_majority_element(a, left + floor((right - left) / 2), right);
	if (elem1 == -1 && elem2 >= 0) return elem2;
	else if (elem1 >= 0 && elem2 == -1) return elem1;
	if (elem1 == elem2) return elem1;
	return -1;
}

int get_majority_element_map(vector<int> &a) {
	std::map<int, unsigned> freq;
	for (size_t i = 0; i < a.size(); ++i)
		freq[a[i]]++;
	for (auto it = freq.cbegin(); it != freq.cend(); ++it) {
		if (it->second > a.size() / 2) return 1;
	}
	return 0;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	//int majority = get_majority_element(a, 0, a.size() - 1);
	//if (majority == -1) return 0;
	//int count = 0;
	//for (size_t i = 0; i < a.size(); ++i)
	//	if (a[i] == majority) count++;
	//std::cout << (count > a.size() / 2) << '\n';
	std::cout << get_majority_element_map(a) << '\n';
	return 0;
}
