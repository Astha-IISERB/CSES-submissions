//not accepted
//check calculation of num[]

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define PQ priority_queue
#define MOD 100000007

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> adj(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}

	vector<ll> dist(n + 1, INF); //min dist to node 1
	vector<ll> num(n + 1, 0); //num of min dist routes to each node;
	vector<bool> visited(n + 1, false);
	vector<int> max_flights(n + 1, 0);
	vector<int> min_flights(n + 1, 0);

	dist[1] = 0;
	num[1] = 1;

	PQ<pair<ll, int>> pq; //(-dist, node) pairs in max heap
	pq.push({ -dist[1], 1});
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		if (!visited[u])
		{
			visited[u] = true;
			for (auto [v, cost] : adj[u])
			{
				ll alt = dist[u] + cost;
				if (alt < dist[v])
				{
					dist[v] = alt;
					num[v] = num[u];
					min_flights[v] = min_flights[u] + 1;
					max_flights[v] = max_flights[u] + 1;
					pq.push({ -dist[v], v});
				}
				if (alt == dist[v])
				{
					num[v] = (num[v] + num[u]);
					min_flights[v] = min(min_flights[v], min_flights[u] + 1);
					max_flights[v] = max(max_flights[v], max_flights[u] + 1);
				}
			}
		}
	}
	cout << dist[n] << " " << (num[n]) << " " << min_flights[n] << " " << max_flights[n] << endl;
	return 0;
}