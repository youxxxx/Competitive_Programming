#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

#define MOD 1000000007;

using namespace std;

int main()
{
	int n;
	char input[1000001];
	string str;
	vector<string> arr;
	int i, j, k;
	char vowel[5] = { 'a','e','i','o','u' };
	map<int, vector<int>> list;
	map<int, vector<int>>::iterator it, ret, prev, ptr;
	vector<int> emp;
	int last, cnt, val;
	vector<pair<int, int>> match, samenum;
	int temp;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		arr.push_back(input);

		cnt = 0;
		last = 0;

		for (j = 0; j < str.size(); j++)
		{
			for (k = 0; k < 5; k++)
			{
				if (str[j] == vowel[k])
				{
					last = k;
					cnt++;
					break;
				}
			}
		}

		val = cnt * 10 + last;

		ret = list.find(val);

		if (ret == list.end())
		{
			list[val] = emp;

			list[val].push_back(i);
		}

		else
		{
			ret->second.push_back(i);
		}
	}

	ptr = list.end();

	temp = -1;

	for (it = list.begin(); it != list.end(); it++)
	{
		for (i = 0; i + 1 < it->second.size(); i += 2)
		{
			match.push_back(pair<int, int>(it->second[i], it->second[i + 1]));
		}

		if (it->second.size() % 2)
		{
			if (temp == -1)
			{
				temp = it->second.back();

				ptr = it;
			}

			else if (ptr != list.end() && ptr->first / 10 == it->first / 10)
			{
				samenum.push_back(pair<int, int>(temp, it->second.back()));

				temp = -1;
			}

			else
			{
				temp = it->second.back();

				ptr = it;
			}
		}
	}

	if (match.size() <= samenum.size())
	{
		printf("%d\n", match.size());

		for (i = 0; i < match.size(); i++)
		{
			printf("%s %s\n%s %s\n", arr[samenum[i].first].c_str(), arr[match[i].first].c_str(), arr[samenum[i].second].c_str(), arr[match[i].second].c_str());
		}
	}

	else
	{
		printf("%d\n", samenum.size() + (match.size() - samenum.size()) / 2);

		for (i = 0; i < samenum.size(); i++)
		{
			printf("%s %s\n%s %s\n", arr[samenum[i].first].c_str(), arr[match[i].first].c_str(), arr[samenum[i].second].c_str(), arr[match[i].second].c_str());
		}

		for (i = 0; i < (match.size() - samenum.size()) / 2; i++)
		{
			printf("%s %s\n%s %s\n", arr[match[samenum.size() + i*2].first].c_str(), arr[match[samenum.size() + i*2 + 1].first].c_str(), arr[match[samenum.size() + i*2].second].c_str(), arr[match[samenum.size() + i*2 + 1].second].c_str());
		}
	}

	return 0;
}