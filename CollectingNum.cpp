//accepted
#include <bits/stdc++.h>
using namespace std;

int  main()
{
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	arr[0] = -1;
	for (int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		arr[a] = i;
	}

	int ans = 1;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i + 1] < arr[i])
			ans++;
	}
	cout << ans << endl;
	return 0;
}