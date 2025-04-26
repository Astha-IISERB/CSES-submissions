//accepted
//solved using sliding window - O(n) time
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

	int l = 0, r = 0, maxl = 0;
	set<ll> seen;
	for (r = 0; r < n; ++r)
	{
		while (seen.count(arr[r])) //arr[r] is already present in window
		{
			//shifting the left pointer till the current window has unique elements
			seen.erase(arr[l]);
			l++;
		}
		seen.insert(arr[r]);
		maxl = max(maxl, r - l + 1);
	}
	cout << maxl << endl;
	return 0;
}