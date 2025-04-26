//accepted
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arrival(n);
	vector<int> depart(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arrival[i] >> depart[i];
	}

	sort(arrival.begin(), arrival.end());
	sort(depart.begin(), depart.end());

	int curr = 0, maxm = 0;
	int a = 0, d = 0;

	while (a < n && d < n)
	{
		if (arrival[a] < depart[d])
		{
			curr++;
			maxm = max(curr, maxm);
			a++;
		}
		else
		{
			curr--;
			d++;
		}
	}
	cout << maxm << endl;
	return 0;
}