#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

int main()
{
	int n, m;
	vector<pair<int, int>> card;
	int i;
	int input1, input2;
	int cnt = 1, prev;
	int lmax = 0, rmin = 100000;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &input1, &input2);

		if (input1 > lmax)
		{
			lmax = input1;
		}

		if (input2 < rmin)
		{
			rmin = input2;
		}
	}

	printf("%d\n", lmax > rmin ? 0 : rmin - lmax + 1);

	return 0;
}