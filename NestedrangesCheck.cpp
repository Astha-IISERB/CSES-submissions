//not yet complete
#include <bits/stdc++.h>
using namespace std;

bool comp1(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
	auto [a1, a2, a3] = a;
	auto [b1, b2, b3] = b;
	if (a1 != b1) return a1 < b1; //comparing starts in ascending order
	return a2 > b2; //comparing ends in descending order
}

bool comp2(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
	auto [a1, a2, a3] = a;
	auto [b1, b2, b3] = b;
	if (a1 != b1) return a1 > b1; //comparing starts in descending order
	return a2 < b2; //comparing ends in ascending order
}

int main()
{
	int n;
	cin >> n;
	vector<tuple<int, int, int>> ranges(n);

	//two sets of end points, for both checks
	multiset<int> x;
	multiset<int> y;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		ranges.push_back({a, b, i});
		x.insert(b);
		y.insert(b);
	}
	sort(ranges.begin(), ranges.end(), comp);

	vector<int> ans(n);
	for (auto [a, b, i] : ranges)
	{
		y.erase(y.find(b));
		if (y.upper_bound(b) != y.begin)

		}



}