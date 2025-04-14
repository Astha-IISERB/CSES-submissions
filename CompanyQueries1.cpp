#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> up;

void preprocess(int n)
{
	for (int j = 1; j < LOG; ++j)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (up[i][j - 1] != -1)
			{
				up[i][j] = up[up[i][j - 1]][j - 1];
			}
		}
	}
}

int kAncestor(int x, int k)
{
	for (int j = 0; j < LOG; ++j)
	{
		if (k & (1 << j))
		{
			x = up[x][j];
			if (x == -1) return -1; //we reached root
		}
	}
	return x;
}

int main()
{
	int n, q;
	cin >> n >> q;
	up.assign(n + 1, vector<int>(LOG, -1));

	for (int i = 2; i <= n; ++i)
	{
		int boss;
		cin >> boss;
		up[i][0] = boss; //direct boss
		//up[i][j] = 2^j-th ancestor of i
	}
	preprocess(n);

	while (q--)
	{
		int x, k;
		cin >> x >> k;
		cout << kAncestor(x, k) << "\n";
	}
	return 0;
}