//accepted
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void DFS(int start, int e)
{
	if (!visited[start])
	{
		visited[start] = true;
		for (auto u : adj[start])
		{
			if (!visited[u] && u != e)
				DFS(u, start);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	visited.assign(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
		adj[a].push_back(b);
	}
	int c = 0;
	vector<int> representative;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			DFS(i, -1);
			c++;
			representative.push_back(i);
		}
	}
	cout << c - 1 << "\n";
	if (c > 1)
	{
		for (int i = 0; i < representative.size() - 1; ++i)
			cout << representative[i] << " " << representative[i + 1] << "\n";
	}
	cout << endl;
	return 0;
}