#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

bool func(const pair<int, long long> &a, const pair<int, long long> &b)
{
	return a.second < b.second;
}

int main()
{
	int t, z;
	long long m;
	long long i, j;
	vector<long long> list;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld", &m);

		list.clear();

		for (i = 1; i < 20000; i++)
		{
			for (j = i; j <= 20000; j++)
			{
				if (i*j == m*(i + j))
				{
					list.push_back(i);

					break;
				}
			}
		}

		printf("%d\n", list.size());

		for (i = 0; i < list.size(); i++)
		{
			printf("%lld\n", list[i]);
		}
	}

	return 0;
}