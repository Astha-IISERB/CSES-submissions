#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int x, vector<int> price, vector<int> pages)
{
	vector<vector<int>> dp(n + 1, vector<int>(x + 1));
	for (int i = 0; i <= n; ++i)
	{
		for (int cost = 0; cost <= x; ++cost)
		{
			if (i == 0 || cost == 0)
				dp[i][cost] = 0;
			else if (cost - price[i - 1] >= 0)
				dp[i][cost] = max(pages[i - 1] + dp[i - 1][cost - price[i - 1]], dp[i - 1][cost]);
			else
				dp[i][cost] = dp[i - 1][cost];
		}
	}
	return dp[n][x];
}

int main()
{
	int n, x;
	cin >> n >> x;
	cin.ignore();
	vector<int> price(n);
	vector<int> pages(n);

	for (int i = 0; i < n; ++i)
		cin >> price[i];
	for (int i = 0; i < n; ++i)
		cin >> pages[i];

	int result = knapsack(n, x, price, pages);
	cout << result << endl;
}