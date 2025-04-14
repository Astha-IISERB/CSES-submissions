#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> pos(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
		cin >> pos[i];

	set<int> indices;
	for (int i = 0; i < n; ++i)
		indices.insert(i);

	for (int i = 0; i < n; ++i)
	{
		auto it = indices.begin();
		advance(it, pos[i] - 1);
		int idx = *it;
		cout << arr[idx] << " ";
		indices.erase(it);
	}

	cout << endl;
	return 0;
}