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
	ll best, sum;
	best = -1000000007; sum = 0;

	for (int i = 0; i < n; ++i)
	{
		sum = max(arr[i], sum + arr[i]);
		best = max(best, sum);
	}
	cout << best << endl;
	return 0;
}