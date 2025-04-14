#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> matched;
int matching = 0;

void dfs(int s, int e)
{
	visited[s] = true;
	for (auto u : adj[s])
	{
		if (!visited[u])
		{
			dfs(u, s);
		}
	}
	if (e != -1 && !matched[s] && !matched[e])
	{
		matched[e] = true;
		matched[s] = true;
		matching++;
	}
}

int main()
{
	int n;
	cin >> n;
	adj.resize(n + 1);
	matched.assign(n + 1, false);
	visited.assign(n + 1, false);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	cout << matching << endl;
	return 0;
}