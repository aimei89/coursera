#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Item {
	int weight;
	int value;
};

bool compare(struct Item a, struct Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

double get_optimal_value(int capacity, vector<Item> items, int n) {
	double value = 0.0;
	std::sort(items.begin(), items.begin() + n, compare);
	int w = 0;
	for (int i = 0; i < n; i++) {
		if (w + items[i].weight <= capacity) {
			w += items[i].weight;
			value += items[i].value;
		}
		else {
			value += items[i].value * ((double)(capacity - w) / (double)items[i].weight);
			break;
		}
	}

	return value;
}

/*double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
	double value = 0.0;

	// write your code here
	int temp;
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if ((double)(values[j] / weights[j]) < (double)(values[j + 1] / weights[j + 1])) {
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
				temp = weights[j];
				weights[j] = weights[j + 1];
				weights[j + 1] = temp;
				swapped = true;
			}
		}
	}

	int w = 0;
	for (int i = 0; i < n; i++) {
		if (w + weights[i] <= capacity) {
			w += weights[i];
			value += values[i];
		}
		else {
			value += values[i] * ((double)(capacity - w) / (double)weights[i]);
			break;
		}
	}
	
	return value;
}
*/
int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	vector<Item> items(n);
	for (int i = 0; i < n; i++) {
		//std::cin >> values[i] >> weights[i];
		std::cin >> items[i].value >> items[i].weight;
	}

	//double optimal_value = get_optimal_value(capacity, weights, values, n);
	double optimal_value = get_optimal_value(capacity, items, n);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
