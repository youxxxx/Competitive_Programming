#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main()
{
	vector<long long> arr;
	int i, j;
	int n;
	long long input;
	long long pxor = 0;
	map<long long, long long> val[2];
	map<long long, long long>::iterator it, ret;

	long long cnt = 0;

	val[0].insert(pair<long long, long long>(0, 1));

	scanf("%d", &n);

	arr.push_back(0);

	for (i = 1; i <= n; i++)
	{
		scanf("%I64d", &input);

		pxor ^= input;

		//arr.push_back(pxor);

		ret = val[i % 2].find(pxor);

		if (ret == val[i % 2].end())
		{
			val[i%2].insert(pair<long long, long long>(pxor, 1));
		}

		else
		{
			ret->second++;
		}
	}

	for (i = 0; i < 2; i++)
	{
		for (it = val[i].begin(); it != val[i].end(); it++)
		{
			cnt += (it->second * (it->second - 1)) / 2;
		}
	}

	printf("%I64d\n", cnt);

	return 0;
}