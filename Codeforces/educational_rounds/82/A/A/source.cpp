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
		char input[101];
		string s;

		scanf("%s", input);

		s = input;

		int n;

		n = s.size();

		bool exist[2] = { 0, };

		for (int i = 0; i < n; i++)
		{
			exist[s[i] - '0'] = true;
		}

		if (!exist[0] || !exist[1])
		{
			printf("0\n");

			continue;
		}

		int start = -1;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				start = i;

				break;
			}
		}

		int end = -1;

		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == '1')
			{
				end = i;

				break;
			}
		}

		int cnt = 0;

		for (int i = start; i <= end; i++)
		{
			if (s[i] == '0')
			{
				cnt++;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}