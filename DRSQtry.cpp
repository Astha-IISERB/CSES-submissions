#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> arr;
vector<ll> seg;

void build(int node, int start, int end)
{
	if (start == end)
		seg[node] = arr[start];
	else
	{
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
	}
}

int main()
{
	cin >> n >> q;
	arr.resize(n);
	seg.resize(4 * n);

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
			update();
		}
		else if (type == 2)
		{
			int a, b;
			cin >> a >> b;
			cout << query() << "\n";
		}
	}
	cout << endl;
	return 0;
}