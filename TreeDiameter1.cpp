//method 2: using 2 dfs
//test-35-20001.cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int maxDist, farthest;

void dfs(int s, int dist)
{
	visited[s] = true;
	if (dist > maxDist)
	{
		maxDist = dist;
		farthest = s;
	}
	for (auto u : adj[s])
	{
		if (!visited[u])
		{
			dfs(u, dist + 1);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	adj.resize(n + 1);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//first DFS run
	visited.assign(n + 1, false);
	maxDist = 0;
	dfs(1, 0);

	//second DFS run
	visited.assign(n + 1, false);
	maxDist = 0;
	dfs(farthest, 0);

	cout << maxDist << endl;
	return 0;
}
