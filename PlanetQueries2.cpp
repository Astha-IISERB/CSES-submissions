#include <bits/stdc++.h>
using namespace std;

vector<int> tele;

int solve(int a, int b, int n)
{
	vector<int> dist(n + 1, -1);
	queue<int> q;
	q.push(a);
	dist[a] = 0;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		if (curr == b)
			return dist[curr];
		int next = tele[curr];//getting to next planet thru teleporter
		if (dist[next] == -1) // if we havent visited this planet yet
		{
			dist[next] = dist[curr] + 1;
			q.push(next);
		}
	}
	return -1;
}

int main()
{
	int n, q;
	cin >> n >> q;
	tele.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> tele[i];
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << solve(a, b, n) << "\n";
	}
	cout << endl;
	return 0;
}