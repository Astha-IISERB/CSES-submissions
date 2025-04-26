#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXK = 30;

int main()
{
	int n, q;
	cin >> n >> q;
	//succ = k x n preprocessed table

	vector<vector<int>> succ(MAXK, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i)
		cin >> succ[0][i]; //2^0 = 1 jump = succ(x,1)

	//succ(x, k) = succ(succ(x, k/2)k/2) for k>1. k=2^j
	for (int j = 1; j < MAXK; ++j)
	{
		for (int i = 1; i <= n; ++i)
			succ[j][i] = succ[j - 1][succ[j - 1][i]];
	}
	while (q--)
	{
		int x, k;
		cin >> x >> k;
		for (int j = 0; j < MAXK; ++j)
		{
			if (k & (1 << j))
				x = succ[j][x];
		}
		cout << x << "\n";
	}
	cout << endl;
	return 0;
}