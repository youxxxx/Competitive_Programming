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
		char input[101];

		scanf("%s", input);
		string str = input;
		const int n = str.size();
		int lmin = 101, lmax = 0;
		int cur = 0;
		int tot = 0;
		int free = 0;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '(')
			{
				tot++;
			}

			else if (str[i] == ')')
			{
				tot--;
			}

			else
			{
				free++;
			}
		}

		if (abs(tot) > free || abs(tot) % 2 != free % 2)
		{
			printf("NO\n");

			continue;
		}

		int pos = 0l;

		if (tot > 0)
		{
			pos = abs(tot) + (free - abs(tot)) / 2;
		}

		else
		{
			pos = (free - abs(tot)) / 2;
		}

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '(')
			{
				cur++;
			}
			
			else if (str[i] == ')')
			{
				cur--;
			}

			else
			{
				if (pos > 0)
				{
					pos--;

					cur++;
				}

				else
				{
					cur--;
				}
			}

			if (cur < 0)
			{
				break;
			}
		}

		if (cur)
		{
			printf("NO\n");
		}

		else
		{
			printf("YES\n");
		}
	}

	return 0;
}