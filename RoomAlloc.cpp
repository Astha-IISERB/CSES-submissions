//accepted
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n ;
	vector<tuple<int, int, int>> cust(n);

	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		cust[i] = {a, b, i};
	}

	sort(cust.begin(), cust.end()); //sorts by arrival time
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int count = 0;
	vector<int> ans(n);

	for (auto [a, d, i] : cust)
	{
		if (!pq.empty() && pq.top().first < a)
		{
			int room = pq.top().second;
			pq.pop();
			pq.push({d, room});
			ans[i] = room;
		}
		else
		{
			count++;
			pq.push({d, count});
			ans[i] = count;
		}
	}
	cout << count << "\n";
	for (int room : ans) cout << room << " ";
	cout << endl;
	return 0;
}