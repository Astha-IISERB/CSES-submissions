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
	ll moves = 0LL;
	ll diff = 0ll;
	for (int i = 1; i < n; ++i)
	{
		diff = arr[i - 1] - arr[i];
		if (diff > 0)
		{
			moves += diff;
			arr[i] = arr[i - 1];
		}
	}
	cout << moves << endl;
	return 0;
}