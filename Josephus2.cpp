//accepeted
//uses queue and a flag var to check if current element has to be popped to added at the end of the queue for next round
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		q.push(i);
	bool flag = false;
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		if (flag)
			cout << a << " ";
		else
			q.push(a);
		flag = !flag; //toggle flag
	}
	cout << endl;
	return 0;
}
