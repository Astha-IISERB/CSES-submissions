#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n - 1);
	ll sum = 0LL;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	ll total  = (1LL * n * (n + 1)) / 2;
	cout << total - sum << endl;
	return 0;
}