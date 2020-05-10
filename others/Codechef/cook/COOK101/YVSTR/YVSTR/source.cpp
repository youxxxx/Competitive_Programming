#include<cstdio>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	string str;
	char *input;
	long long sol, cnt;
	int t, z, n;
	int i, j;
	vector<pair<long long, long long>> blocks;
	map<long long, long long> alpha[26][26];
	map<long long, long long>::iterator it, ret;
	pair<map<long long, long long>::iterator, bool> ptr;
	long long a, b, temp;
	long long aval, bval;
	long long max;
	long long lmax[26];


	input = new char[1000001];

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		sol = 0;

		cnt = 1;

		scanf("%d", &n);

		scanf("%s", input);

		str = input;

		for (i = 0; i < 26; i++)
		{
			lmax[i] = 0;
		}

		for (i = 1; i < n; i++)
		{
			if (str[i] != str[i - 1])
			{
				if (cnt > lmax[str[i - 1] - 'a'])
				{
					lmax[str[i - 1] - 'a'] = cnt;
				}

				blocks.push_back(pair<long long, long long>(str[i - 1] - 'a', cnt));

				cnt = 1;
			}

			else
			{
				cnt++;
			}
		}

		if (cnt > lmax[str[n - 1] - 'a'])
		{
			lmax[str[n - 1] - 'a'] = cnt;
		}

		blocks.push_back(pair<long long, long long>(str[n - 1] - 'a', cnt));

		for (i = 0; i < blocks.size() - 1; i++)
		{
			a = blocks[i].first;
			b = blocks[i + 1].first;
			aval = blocks[i].second;
			bval = blocks[i + 1].second;

			/*
			if (a > b)
			{
				temp = a;
				a = b;
				b = temp;
				temp = aval;
				aval = bval;
				bval = temp;
			}
			*/

			it = alpha[a][b].find(aval);

			if (it == alpha[a][b].end())
			{
				ptr = alpha[a][b].insert(pair<long long, long long>(aval, bval));

				//ret = ptr.first;
			}

			else if (bval > it->second)
			{
				it->second = bval;
			}
		}

		for (i = 0; i < 26; i++)
		{
			for (j = 0; j < 26; j++)
			{
				if (alpha[i][j].empty())
				{
					continue;
				}

				it = alpha[i][j].end();
				it--;

				sol += it->first * it->second;

				max = it->second;

				while (it-- != alpha[i][j].begin())
				{
					if (it->second > max)
					{
						sol += it->first * (it->second - max);

						max = it->second;						
					}
				}
			}
		}

		for (i = 0; i < 26; i++)
		{
			sol += lmax[i];
		}

		printf("%lld\n", sol);

		blocks.clear();

		for (i = 0; i < 26; i++)
		{
			for (j = 0; j < 26; j++)
			{
				alpha[i][j].clear();
			}
		}
	}

	return 0;
}