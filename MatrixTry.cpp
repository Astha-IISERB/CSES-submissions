#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Matrix;

const ll INF = 1e18;
Matrix multiply(Matrix &A, Matrix &B, int n)
{
	Matrix C(n, vector<ll>(n, INF));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (A[i][k] < INF && B[k][j] < INF)
					C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
	return C;
}

Matrix matrixExpo(Matrix A, int k, int n)
{
	//we have to calculate A^k
	Matrix res(n, vector<ll>(n, INF));

	for (int i = 0; i < n; ++i)
		res[i][i] = 0; //0 on diagonal, INF elsewhere
	while (k)
	{
		if (k & 1)
			res = multiply(res, A, n);
		A = multiply(A, A, n);
		k >>= 1;
	}
	return res;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		ll w;
		cin >> a >> b >> w;
		a--, b--;
		A[a][b] = min(A[a][b], w);
	}

	Matrix result = matrixExpo(A, k, n);
	ll ans = result[0][n - 1];
}