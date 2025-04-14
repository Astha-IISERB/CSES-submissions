#include <bits/stdc++.h>
#define MOD (7+(int)1e9)
using namespace std;

int solve(vector<string> &grid, int n)
{
	if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
		return 0;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int j = 0; j < n; ++j)
	{
		if (grid[0][j] == '*')
			break;
		dp[0][j] = 1;
	}
	for (int i = 0; i < n; ++i)
	{
		if (grid[i][0] == '*')
			break;
		dp[i][0] = 1;
	}
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < n; ++j)
			if (grid[i][j] != '*')
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;


	return dp[n - 1][n - 1];
}

int main()
{
	int n;
	cin >> n;
	vector<string> grid(n);

	for (int i = 0; i < n; ++i)
		cin >> grid[i];

	int result = solve(grid, n);
	cout << result << endl;
}