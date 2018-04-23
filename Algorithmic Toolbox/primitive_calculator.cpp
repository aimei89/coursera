#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
	std::vector<int> sequence;
	std::vector<int> steps(n + 1);
	std::vector<int> prev(n + 1);

	steps[1] = 0;
	for (int i = 2; i <= n; i++) {
		steps[i] = steps[i - 1] + 1;
		prev[i] = i - 1;
		if (i % 3 == 0) {
			if (steps[i / 3] < steps[i]) {
				steps[i] = steps[i / 3] + 1;
				prev[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (steps[i / 2] < steps[i]) {
				steps[i] = steps[i / 2] + 1;
				prev[i] = i / 2;
			}
		}
	}

	for (int i = n; i != 0; i = prev[i]) {
		sequence.push_back(i);
	}
	std::reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
	return 0;
}
