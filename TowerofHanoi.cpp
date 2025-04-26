//accepted
#include <bits/stdc++.h>
using namespace std;
void hanoi(int n, int from, int to, int aux, vector<pair<int, int>> &moves)
{
	if (n == 0)
		return;
	hanoi(n - 1, from, aux, to, moves);
	moves.push_back({from, to});
	hanoi(n - 1, aux, to, from, moves);
}

int solve(int n)
{
	if (n == 1) return 1;
	else return ((int)pow(2, n)) - 1;
}

int main()
{
	int n;
	cin >> n;
	int k = solve(n);
	vector<pair<int, int>> moves;
	hanoi(n, 1, 3, 2, moves);
	cout << k << endl;
	for (auto move : moves)
		cout << move.first << " " << move.second << "\n";
	return 0;
}