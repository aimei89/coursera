#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
	int x = a[l];
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= x) {
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	return j;
}

void partition(vector<int> &a, int l, int r, int &j, int &k) {
	int x = a[l];
	j = l;
	k = 0;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < x) {
			j++;
			swap(a[i], a[j]);
			if(k > 0)
				swap(a[i], a[j + k]);
		}
		else if (a[i] == x) {
			k++;
			swap(a[i], a[j + k]);
		}
	}
	swap(a[l], a[j]);
}

void randomized_quick_sort2(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m, n;
	partition(a, l, r, m, n);

	randomized_quick_sort2(a, l, m - 1);
	randomized_quick_sort2(a, m + n + 1, r);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m = partition2(a, l, r);

	randomized_quick_sort(a, l, m - 1);
	randomized_quick_sort(a, m + 1, r);
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	randomized_quick_sort2(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}
	return 1;
}
