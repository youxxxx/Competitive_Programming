#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int main()
{
	map<string, long long> list;
	long long n, m;
	vector<string> arr;

	scanf("%lld %lld", &n, &m);

	for (long long i = 0; i < n; i++)
	{
		char input[31];

		scanf("%s", input);

		string str;

		str = input;

		map<string, long long>::iterator ret;

		ret = list.find(str);

		if (ret == list.end())
		{
			list[str] = 1;
		}

		else
		{
			ret->second++;
		}

		arr.push_back(str);
	}

	map<string, long long>::iterator it;

	long long sol = 0;

	for (it = list.begin(); it != list.end(); it++)
	{
		long long add;

		if (it->second >= 3)
		{
			add = it->second*(it->second - 1)*(it->second - 2);

			sol += add;
		}
	}

	bool taken[256] = { 0, };

	for (long long i = 0; i < n; i++)
	{
		for (long long j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}

			if (arr[i] == arr[j])
			{
				continue;
			}

			string target;

			for (long long k = 0; k < m; k++)
			{
				if (arr[i][k] == arr[j][k])
				{
					target.push_back(arr[i][k]);
				}
				
				else
				{

					taken[arr[i][k]] = 1;
					taken[arr[j][k]] = 1;

					if (!taken['S'])
					{
						target.push_back('S');
					}

					else if (!taken['E'])
					{
						target.push_back('E');
					}

					else if (!taken['T'])
					{
						target.push_back('T');
					}

					taken[arr[i][k]] = 0;
					taken[arr[j][k]] = 0;
				}
			}

			map<string, long long>::iterator ret;

			ret = list.find(target);

			if (ret != list.end())
			{
				sol += ret->second;
			}
		}
	}

	printf("%lld\n", sol / 6);

	return 0;
}