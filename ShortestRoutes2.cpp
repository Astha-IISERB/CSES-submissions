//incomplete
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, ll>>> adj;

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	adj.resize(n + 1, vector<pair<int, ll>>);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
}