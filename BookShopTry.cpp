#include <bits/stdc++.h>
using namespace std;
vector<int> h;
vector<int> s;

int main()
{
	int n, x;
	cin >> n >> x;
	h.resize(n);
	s.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> h[i];

	for (int i = 0; i < n; ++i)
		cin >> s[i];

	//dp[i][j] = max val(num of pages) upto i books with max budget j
	//we want dp[n][x]
	//dp[i][j] = either pick book j or drop book j
	//dp[i][j] = dp[i-1][j-price(i-th book)]+pages(i-th book) + dp[i-1][j]
	//dp[i][0] = 0;
	//dp[0][j] = 0;

	vector<vector<int>> dp(n + 1, vector<int>(x + 1));

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= x; ++j)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (j - h[i - 1] >= 0)
				dp[i][j] = max(s[i - 1] + dp[i - 1][j - h[i - 1]], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][x] << endl;
	return 0;
}