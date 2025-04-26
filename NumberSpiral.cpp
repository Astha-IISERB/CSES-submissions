//accepted
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll y, x;
		cin >> y >> x;
		ll val = 1LL * max(y, x);
		ll diag = (val * val) - (val - 1);

		if (y == x)
			cout << diag << "\n";
		else if (y > x)
		{
			//row > col: lower triangle
			if (y % 2 == 1)
				cout << diag - (y - x) << "\n";//subtract in odd rows
			else
				cout << diag + (y - x) << "\n";//add in even rows
		}
		else
		{
			//row < col: upper triangle
			if (x % 2 == 1)
				cout << diag + (x - y) << "\n";//add in odd col
			else
				cout << diag - (x - y) << "\n";//sub in even col
		}
	}
}