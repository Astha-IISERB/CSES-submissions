#include <bits/stdc++.h>
using namespace std;

int nX[4] = {0, 0, 1, -1}; //up, down, left, right
int nY[4] = {1, -1, 0, 0};

int n, m, ans = 0;
vector<vector<bool>> visited;
vector<vector<char>> grid;

bool isValid (int y, int x)
{
	if (y < 0) return false;
	if (x < 0) return false;
	if (y >= n) return false;
	if (x >= m) return false;
	if (grid[y][x] == '#') return false;
	return true;
}

void DFS(int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		int newX = x + nX[i];
		int newY = y + nY[i];
		if (isValid(newX, newY))
		{
			if (!visited[newX][newY])
				DFS(newX, newY);
		}
	}
}

int main()
{
	cin >> n >> m;
	visited.assign(n, vector<bool>(m, false));
	grid.resize(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] == '.' && !visited[i][j])
			{
				DFS(i, j);
				ans++;
			}
	cout << ans << endl;
	return 0;
}