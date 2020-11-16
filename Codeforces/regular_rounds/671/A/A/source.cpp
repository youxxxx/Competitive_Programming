#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		char input[1001];

		scanf("%s", input);

		string str = input;

		int win[2] = { 0, };

		for (int i = 0; i < n; i += 2)
		{
			if ((str[i] - '0') % 2)
			{
				win[0] = 1;

				break;
			}
		}

		for (int i = 1; i < n; i += 2)
		{
			if (!((str[i] - '0') % 2))
			{
				win[1] = 1;

				break;
			}
		}

		if (n % 2)
		{
			if (win[0])
			{
				printf("1\n");
			}

			else
			{
				printf("2\n");
			}
		}

		else
		{
			if (win[1])
			{
				printf("2\n");
			}

			else
			{
				printf("1\n");
			}
		}
	}

	return 0;
}