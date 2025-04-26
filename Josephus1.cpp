//not accepeted
//uses queue and a flag var to check if current element has to be popped to added at the end of the queue for next round
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> arr;
	int len = sqrt(n);
	int row = 0, col =  0, count = 0;
	vector<int> temp;
	for (int i = 1; i <= n; ++i)
	{
		if (count > len)
		{
			arr.push_back(temp);
			temp.clear();
			count = 0;
		}
		temp.push_back(i);
		count++;
	}
	if (!temp.empty())
		arr.push_back(temp);

	for (int i = 0; i < n; ++i)
	{
		//each iteration means elimination of 1 member
		//so in i-th iteration, (n-i) members are present
		int j = k % (n - i);

		while (j)
		{
			if (col + j < arr[row].size())
			{
				col += j;
				j = 0;
			}
			else
			{
				j -= arr[row].size() - col;
				col = 0;
				row++;
			}
			if (row >= arr.size())
				row = 0;
		}
	}

	while (arr[row].size() <= col)
	{
		col = 0;
		row++;
		if (row >= arr.size())
			row = 0;
	}

	cout << arr[row][col] << " ";
	if (i != n - 1)

	}

cout << endl;
return 0;
}
