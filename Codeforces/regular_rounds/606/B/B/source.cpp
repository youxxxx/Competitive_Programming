#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		map<int, int> list;

		for (int i = 0; i < n; i++)
		{
			map<int, int>::iterator ret;

			int input;

			scanf("%d", &input);

			int cnt = 0;

			while (!(input % 2))
			{
				input /= 2;

				cnt++;
			}

			ret = list.find(input);

			if (ret == list.end())
			{
				list[input] = cnt;
			}

			else if (ret->second < cnt)
			{
				ret->second = cnt;
			}
		}

		int sol = 0;

		for (map<int, int>::iterator it = list.begin(); it != list.end(); it++)
		{
			sol += it->second;
		}

		printf("%d\n", sol);
	}

	return 0;
}