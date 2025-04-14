#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;  // Larger INF to prevent overflow

typedef vector<vector<ll>> Matrix;

Matrix multiply(Matrix &A, Matrix &B, int n)
{
	Matrix C(n, vector<ll>(n, INF)); // Initialize with INF
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (A[i][k] < INF && B[k][j] < INF) // Ensure valid paths
					C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
	return C;
}

Matrix matrixExpo(Matrix A, int k, int n)
{
	Matrix res(n, vector<ll>(n, INF)); // Initialize with INF
	for (int i = 0; i < n; ++i)
		res[i][i] = 0; // Identity matrix: 0 on diagonal

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

	// Adjacency matrix
	Matrix A(n, vector<ll>(n, INF));

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		ll w;
		cin >> a >> b >> w;
		a--, b--; // Convert to 0-based index
		A[a][b] = min(A[a][b], w); // Handle multiple edges between same nodes
	}

	Matrix result = matrixExpo(A, k, n);
	ll ans = result[0][n - 1];

	if (ans >= INF) cout << "0" << endl; // No path exists
	else cout << ans << endl;

	return 0;
}
