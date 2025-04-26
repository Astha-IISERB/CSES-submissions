//accepted
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, x;
	cin >> n >> x;
	vector<pair<ll, int>> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end());
	int l = 0, r = n - 1;
	ll sum = 0;
	int flag = 0;
	while (l < r)
	{
		sum = arr[l].first + arr[r].first;
		if (sum == x)
		{
			flag = 1;
			break;
		}
		if (sum > x)
			r--;
		if (sum < x)
			l++;
	}
	if (flag == 1) cout << arr[l].second + 1 << " " << arr[r].second + 1 << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}