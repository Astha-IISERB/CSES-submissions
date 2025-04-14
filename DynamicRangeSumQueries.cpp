#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, q;
vector<int> arr;
vector<ll> segtree;

void build(int node, int start, int end)
{
	if (start == end)
		segtree[node] = arr[start];
	else
	{
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);

		segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
	}
}

ll query(int node, int start, int end, int a, int b)
{
	if (b < start || a > end) return 0;
	if (a <= start && b >= end) return segtree[node];

	int mid = (start + end) / 2;
	return query(2 * node, start, mid, a, b) + query(2 * node + 1, mid + 1, end, a, b);
}

void update(int node, int start, int end, int k, int u)
{
	if (start == end) //leaf node
		segtree[node] = u;
	else
	{
		int mid = (start + end) / 2;
		if (k <= mid)
			update(2 * node, start, mid, k, u);
		else
			update(2 * node + 1, mid + 1, end, k, u);
		segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
	}
}

int main()
{
	cin >> n >> q;
	arr.resize(n);
	segtree.resize(4 * n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	build(1, 0, n - 1);
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int k, u;
			cin >> k >> u;
			update(1, 0, n - 1, k - 1, u);
		}
		else if (type == 2)
		{
			int a, b;
			cin >> a >> b;
			cout << query(1, 0, n - 1, a - 1, b - 1) << "\n";
		}
	}
	return 0;
}