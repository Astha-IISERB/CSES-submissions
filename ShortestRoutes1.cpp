//accepted
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PQ priority_queue
const ll INF = 1e18;

vector<vector<pair<int , int>>> adj;
vector<bool> visited;

int main()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	visited.assign(n + 1, false);

	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
	}

	vector<ll> dist(n + 1, INF);
	dist[1] = 0;

	PQ<pair<ll, int>> pq;
	pq.push({0, 1}); //{dist, city}

	while (!pq.empty())
	{
		ll d = -pq.top().first;
		int c = pq.top().second;
		pq.pop();

		if (d > dist[c]) continue;

		for (auto [u, w] : adj[c])
		{
			if (dist[u] > dist[c] + w)
			{
				dist[u] = dist[c] + w;
				pq.push({ -dist[u], u});
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << dist[i] << " ";
	cout << endl;
	return 0;
}