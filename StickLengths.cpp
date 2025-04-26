//accepted
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	ll cost = 0LL;
	int a = (int)floor(n / 2);
	a = arr[a];

	for (int i = 0; i < n; ++i)
		cost += 1LL * abs(arr[i] - a);

	cout << cost << endl;
	return 0;
}