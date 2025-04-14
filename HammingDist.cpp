/*this code exceeds the time limit of 1 sec
we need to use Prefix Tree (or 'trie') for more efficiency*/

#include <bits/stdc++.h>
using namespace std;

int hamming(int a, int b)
{
	int XOR = a ^ b;
	int d = 0;
	while (XOR)
	{
		XOR = XOR & (XOR - 1);
		d++;
	}
	return d;
}


int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> bits(n);
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		bits[i] = stoi(s, nullptr, 2);
	}

	int minDist = k + 1;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			minDist = min(minDist, hamming(bits[i], bits[j]));

	cout << minDist << endl;
	return 0;
}