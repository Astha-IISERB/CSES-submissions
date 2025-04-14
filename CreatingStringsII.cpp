#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector<ll> fact;

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	int maxm = n;

	vector<int> count(26, 0);

	for (int i = 0; i < n; ++i)
	{
		count[s[i] - 97]++;
		if (count[s[i] - 97] > maxm)
			maxm = count[s[i] - 97];
	}
	fact.resize(maxm + 1);
	fact[0] = 1;
	fact[1] = 1;

	for (int i = 2; i <= maxm; ++i)
		fact[i] = i * fact[i - 1];
	ll result = fact[n];
	for (int i = 0; i < 26; ++i)
	{
		if (count[i] != 0)
		{
			ll t = fact[count[i]];
			result /= t;
		}
	}
	cout << result % MOD << endl;
	return 0;
}