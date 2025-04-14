#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll modPow(ll a, ll b, ll mod)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll BinoCoeff(int n, int k)
{
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = 1;
		if (i <= k)
			dp[i][i] = 1;
	}
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; j <= min(i, k); ++j)
			if (i != j)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
	}
	return dp[n][k];
}

int main()
{
	int n;
	cin >> n;
	ll final;
	if (n & 1) final = 0;
	else
	{
		n /= 2;
		ll result = BinoCoeff(2 * n, n);
		final = (1LL * result * modPow(n + 1, MOD - 2, MOD)) % MOD;
	}
	cout << final << endl;
	return 0;
}
