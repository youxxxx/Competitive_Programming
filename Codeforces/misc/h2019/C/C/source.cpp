#include<cstdio>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	int n;
	vector<string> arr;
	int i, j;
	char input[500005];
	string str;
	map<int, int> tot;
	map<int, int>::iterator it, it2, ret;
	int cnt, low, high;
	int min;
	int sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		arr.push_back(str);
	}

	for (i = 0; i < n; i++)
	{
		cnt = 0;
		low = 0;
		high = 0;

		for (j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] == '(')
			{
				cnt++;
			}

			else
			{
				cnt--;
			}

			if (cnt < low)
			{
				low = cnt;
			}

			if (cnt > high)
			{
				high = cnt;
			}
		}

		if (cnt < 0 && low == cnt)
		{
			ret = tot.find(cnt);

			if (ret == tot.end())
			{
				tot[cnt] = 1;
			}

			else
			{
				ret->second++;
			}
		}

		else if (low >= 0 && cnt >= 0)
		{
			ret = tot.find(cnt);

			if (ret == tot.end())
			{
				tot[cnt] = 1;
			}

			else
			{
				ret->second++;
			}
		}
	}

	it2 = tot.end();
	it2--;

	for (it = tot.begin(); it != tot.end() && it->first != 0; it++)
	{
		while (it2 != it&&it->first + it2->first > 0)
		{
			it2--;
		}

		if (it == it2)
		{
			break;
		}

		if (it->first + it2->first == 0)
		{
			min = it->second;

			if (it2->second < min)
			{
				min = it2->second;
			}

			sum += min;
		}
	}

	if (it != tot.end() && it->first == 0)
	{
		sum += it->second / 2;
	}

	printf("%d\n", sum);

	return 0;
}