//incomplete

#include <bits/stdc++.h>
using namespace std;
#define PQ priority_queue
typedef long long ll;
const ll MAXD = 1e18;
vector<vector<pair<int, ll>>> adj;
vector<pair<ll, ll>> dist; //{dist to node i without coupon, dist to node i with coupon}

int main()
{
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	dist.assign(n + 1, {MAXD, MAXD});
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	PQ < pair<ll, pair<int, int>> pq; //{cost, {node, 1 or 0}}
	//pq is a heap based on the cost
	pq.push{0, {1, 0}}
	dist[1] = {0, 0};
	while (!pq.empty())
	{
		ll pd = pq.top().first;
		int pn = pq.top().second.first;//parent node
		int pcoup = pq.top().second.second;//parent coupon status
		pq.pop();

		if (pcoup && pd > dist[pn].second) continue;
		if (!pcoup && pd > dist[pn].first) continue;

		for (auto c : adj[pn])
		{
			int cn = c.first;
			ll cc = c.second;//without coupon
			ll cdc = c.second / 2; //with coupon

			if (!pcoup)
			{
				if (pd + cc < dist[cn].first)
				{
					pq.push({pd + cc, {cn, 0}});
					dist[cn].first = pd + cc;
				}

			}
		}
	}
}