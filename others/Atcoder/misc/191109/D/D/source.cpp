#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<queue>

using namespace std;

bool func(pair<pair<int, int>, long long> &a, pair<pair<int, int>, long long> &b)
{
	return a.first.first < b.first.first;
}

int main()
{
	int n, m;
	vector<pair<pair<int, int>, long long>> arr;
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int l, r;
		long long c;

		scanf("%d %d %lld", &l, &r, &c);

		arr.push_back(make_pair(make_pair(l, r), c));
	}



	return 0;
}