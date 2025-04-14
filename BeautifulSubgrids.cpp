#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;
typedef long long ll;

int f(int x)
{
	return x * (x - 1);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	bitset<3000> grid[n];

	for (int i = 0; i < n; ++i)
		cin >> grid[i];
	ll counts = 0;

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			counts += f((grid[i] & grid[j]).count());

	cout << (counts >> 1) << endl;
	return 0;
}