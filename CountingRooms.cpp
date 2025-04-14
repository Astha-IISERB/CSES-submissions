#include <bits/stdc++.h>
using namespace std;

int N, M;

void isConnected(int i, int j, vector<vector<char>> &A)
{
	//we want these changes to happen in the original grid
	//so we use '&' operator
	queue<pair<int, int>> q;
	q.push({i, j});
	while (q.size() > 0)
	{
		pair<int, int> pos = q.front();
		q.pop();
		i = pos.first, j = pos.second;
		A[i][j] = '#';
		if (i + 1 < N)
		{
			if (A[i + 1][j] == '.') //moving down
				q.push({i + 1, j});
		}
		if (j + 1 < M)
		{
			if (A[i][j + 1] == '.') //moving to right
				q.push({i, j + 1});
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	cin.ignore();

	N = n, M = m;

	vector<vector<char>> A(n, vector<char> (m));
	for (int i = 0; i < n; i++)
	{
		string num;
		getline(cin, num);

		for (int j = 0; j < m; ++j)
			A[i][j] = num[j];
	}
	int rooms = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (A[i][j] == '.')
			{
				rooms++;
				isConnected(i, j, A);
			}
		}
	}
	cout << rooms << endl;
	return 0;
}