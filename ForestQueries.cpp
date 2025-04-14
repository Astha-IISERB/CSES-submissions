#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;

	// Reading the forest grid
	vector<string> grid(n);
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}

	// Creating prefix sum matrix
	vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (grid[i - 1][j - 1] == '*' ? 1 : 0);
		}
	}

	// Processing queries
	while (q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int trees = prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1];
		cout << trees << " ";
	}

	return 0;
}
