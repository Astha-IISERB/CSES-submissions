//time limit exceeded
#include <bits/stdc++.h>
using namespace std;

int nX[4] = {0, 0, 1, -1}; //R, L, D, U
int nY[4] = {1, -1, 0, 0};
char dir[4] = {'R', 'L', 'D', 'U'};

int n, m, ans = 0;
vector<vector<bool>> visited;
vector<vector<char>> grid;
vector<vector<pair<int, int>>> parent;

bool isValid (int y, int x)
{
	if (y < 0) return false;
	if (x < 0) return false;
	if (y >= n) return false;
	if (x >= m) return false;
	if (grid[y][x] == '#') return false;
	return true;
}

void BFS(pair<int, int> a)
{
	queue<pair<int, int>> q;
	q.push(a);
	visited[a.first][a.second] = true;

	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int newX = x + nX[i];
			int newY = y + nY[i];
			if (isValid(newX, newY))
			{
				visited[newX][newY] = true;
				parent[newX][newY] = {x, y};
				q.push({newX, newY});
			}
		}
	}
}

string Path(pair<int, int> A, pair<int, int> B)
{
	string path;
	pair<int, int> cur = B;
	while (cur != A)
	{
		auto [px, py] = parent[cur.first][cur.second];
		for (int i = 0; i < 4; ++i)
		{
			if (px + nX[i] == cur.first && py + nY[i] == cur.second)
			{
				path += dir[i];
				break;
			}
		}
		cur = {px, py};
	}
	reverse(path.begin(), path.end());
	return path;
}

int main()
{
	cin >> n >> m;
	visited.assign(n, vector<bool>(m, false));
	grid.resize(n, vector<char>(m));
	parent.assign(n, vector<pair<int, int>>(m, { -1, -1}));
	pair<int, int> A, B;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'A') A = {i, j};
			if (grid[i][j] == 'B') B = {i, j};
		}

	BFS(A);
	if (visited[B.first][B.second])
	{
		cout << "YES\n";
		string path = Path(A, B);
		cout << path.length() << "\n" << path << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}