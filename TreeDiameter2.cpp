#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> toLeaf;
vector<int> maxLength;
int Diam = 0;

void computeToLeaf(int s, int e) {
	// Using DFS to get the max depth from s to any leaf
	int maxDepth = 0;
	for (int u : adj[s]) {
		if (u != e) {
			computeToLeaf(u, s);
			maxDepth = max(maxDepth, toLeaf[u] + 1);
		}
	}
	toLeaf[s] = maxDepth;
}

void computeMaxLength(int s, int e) {
	vector<int> depths;
	for (int u : adj[s]) {
		if (u != e) {
			computeMaxLength(u, s);
			depths.push_back(toLeaf[u] + 1);
		}
	}

	// Sort depths in descending order
	sort(depths.rbegin(), depths.rend());

	if (depths.size() >= 2)
		maxLength[s] = depths[0] + depths[1]; // Sum of two longest children
	else if (depths.size() == 1)
		maxLength[s] = depths[0]; // Only one child
	else
		maxLength[s] = 0; // Leaf node

	Diam = max(Diam, maxLength[s]); // Update diameter
}

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << "0\n"; // Tree with one node has diameter 0
		return 0;
	}

	adj.resize(n + 1);
	toLeaf.resize(n + 1, 0);
	maxLength.resize(n + 1, 0);

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	computeToLeaf(1, -1);
	computeMaxLength(1, -1);

	cout << Diam << endl;
	return 0;
}
