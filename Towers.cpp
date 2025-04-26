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

	vector<int> tops;
	for (auto a : arr)
	{
		//performs a binary search to find the first element greater than a given value in a sorted range
		auto it = upper_bound(tops.begin(), tops.end(), a);
		if (it == tops.end())
			tops.push_back(a);//no tower found, make new tower
		else
			*it = a;//replace top of that tower
	}

	cout << tops.size() << endl;
	return 0;
}