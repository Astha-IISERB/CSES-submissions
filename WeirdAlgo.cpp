#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	while (1) {
		cout << n << " ";
		if (n == 1)
			break;
		if (n & 1)
			n = 3 * n + 1;
		else
			n = n / 2;
	}
	cout << endl;
	return 0;
}