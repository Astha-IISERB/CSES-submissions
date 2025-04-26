//accepted
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> task(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> task[i].first >> task[i].second;
	}
	sort(task.begin(), task.end());//sorts by duration
	ll sum = 0;
	ll f = 0; //current finish time;
	for (int i = 0; i < n; ++i)
	{
		f += task[i].first;
		sum += task[i].second - f;
	}
	cout << sum << endl;
	return 0;
}