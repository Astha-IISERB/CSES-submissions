#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> coins(n);

	int total_sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> coins[i];
		total_sum += coins[i];
	}
	vector<int> sums(total_sum + 1, 0);
	sums[0] = 1;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int k = total_sum; k >= coins[i]; --k)
		{
			if (sums[k - coins[i]])
				sums[k] = 1;
		}
	}
	for (int k = total_sum; k >= 1; --k)
	{
		if (sums[k] != 0 )
			count++;
	}
	cout << count << "\n";
	for (int k = 1; k <= total_sum; ++k)
	{
		if (sums[k] != 0)
			cout << k << " ";
	}
	cout << endl;
	return 0;
}