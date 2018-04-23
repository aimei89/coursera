#include <iostream>
#include <vector>

using std::vector;

/*
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	long long number_of_inversions = 0;
	if (right <= left + 1) return number_of_inversions;
	size_t ave = left + (right - left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, ave);
	number_of_inversions += get_number_of_inversions(a, b, ave, right);
	//write your code here
	return number_of_inversions;
}
*/

long long merge(vector<int> &a, int l, int m, int r) {
	vector<int> b(r - l + 1);
	int i = l, j = m + 1, k = 0;
	long long count = 0;
	while (i <= m && j <= r) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else {
			count += (m + 1 - i);
			b[k++] = a[j++];
		}
	}
	while (i <= m) 
		b[k++] = a[i++];
	while (j <= r)
		b[k++] = a[j++];
	for (k = 0, i = l; i <= r; k++, i++)
		a[i] = b[k];
	return count;
}

long long mergeSort(vector<int> &a, int l, int r) {
	if (l >= r)
		return 0;
	int m = (r + l) / 2;
	long long count = mergeSort(a, l, m);
	count += mergeSort(a, m + 1, r);
	count += merge(a, l, m, r);
	return count;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	//for (size_t i = 0; i < a.size(); ++i)
	//	std::cout << a[i] << ' ';
	//std::cout << '\n';
	std::cout << mergeSort(a, 0, a.size() - 1) << '\n';
	return 0;
	//vector<int> b(a.size());
	//std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
