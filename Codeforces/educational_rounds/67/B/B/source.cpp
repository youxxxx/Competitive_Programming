#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	char input[200001];
	string str, name;
	int i, j;
	int cnt[26];
	int tot;
	vector<int> ptr[26];
	int lmax;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (i = 0; i < n; i++)
	{
		ptr[str[i] - 'a'].push_back(i + 1);
	}

	scanf("%d", &m);
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 26; j++)
		{
			cnt[j] = 0;
		}

		scanf("%s", input);

		name = input;

		tot = 0;

		for (j = 0; j < name.size(); j++)
		{
			if (cnt[name[j] - 'a']++ == 0)
			{
				tot++;
			}
		}

		/*
		for (j = 0; j < str.size(); j++)
		{
			if (cnt[str[j] - 'a'] > 0)
			{
				if (--cnt[str[j] - 'a'] == 0)
				{
					tot--;
				}
			}

			if (tot == 0)
			{
				break;
			}
		}
		*/

		lmax = 0;

		for (j = 0; j < 26; j++)
		{
			if (cnt[j]>0 && ptr[j][cnt[j] - 1] > lmax)
			{
				lmax = ptr[j][cnt[j] - 1];
			}
		}

		printf("%d\n", lmax);
	}

	return 0;
}