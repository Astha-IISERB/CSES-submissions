//test-33-20001.cpp
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> subtree;

void dfs(int s, int e)
{
	subtree[s] = 1;
	for (auto u : adj[s])
	{
		if (u == e) continue;
		dfs(u, s);
		subtree[s] += subtree[u];
	}
}

int main()
{
	int n;
	cin >> n;
	adj.resize(n + 1);
	subtree.resize(n + 1);
	for (int i = 2; i <= n; i++)
	{
		int a;
		cin >> a;
		adj[a].push_back(i);
		adj[i].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cout << (subtree[i] - 1) << " ";
		//subtracting one to count only the subordinates
	}
	cout << endl;
	return 0;
}