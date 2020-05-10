#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[101];
		string str;

		scanf("%s", input);
		str = input;

		const int n = str.size();

		bool all0 = true;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '1')
			{
				all0 = false;

				break;
			}
		}

		if (all0)
		{
			printf("%s\n", str.c_str());

			continue;
		}

		bool all1 = true;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '0')
			{
				all1 = false;

				break;
			}
		}

		if (all1)
		{
			printf("%s\n", str.c_str());

			continue;
		}

		string sol;
		int cur;
		int start;
		start = str[0] - '0';

		cur = !(str[0] - '0');
		sol.push_back(str[0]);

		for (int i = 1; i < n; i++) {
			if (str[i] - '0' == cur)
			{
				sol.push_back(str[i]);

				cur = !cur;
			}

			else
			{
				sol.push_back(cur + '0');
				sol.push_back(str[i]);
			}
		}

		if (cur != start)
		{
			sol.push_back(cur + '0');
		}

		printf("%s\n", sol.c_str());
	}

	return 0;
}