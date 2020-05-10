#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	int cases;
	int n;

	scanf("%d %d", &cases, &n);

	for (int tc = 1; tc <= cases; tc++)
	{
		int sol[101];
		int idx = 1;
		int cnt = 0;
		int same = -1, diff = -1;

		while (cnt < 150 && idx <= n / 2)
		{
			if (!(cnt % 10) && (same != -1 || diff != -1))
			{
				if (same != -1 && diff != -1)
				{
					int input;
					bool comp = false, rev = false;

					printf("%d\n", same);
					fflush(stdout);

					scanf("%d", &input);

					if (sol[same] != input)
					{
						comp = true;
					}

					printf("%d\n", diff);
					fflush(stdout);

					scanf("%d", &input);

					if (comp&&sol[diff] == input || !comp&&sol[diff] != input)
					{
						rev = true;
					}

					if (rev)
					{
						for (int i = 0; i < idx; i++)
						{
							int temp;

							temp = sol[i];
							sol[i] = sol[n - i + 1];
							sol[n - i + 1] = temp;
						}
					}

					if (comp)
					{
						for (int i = 0; i < idx; i++)
						{
							sol[i] = !sol[i];

							sol[n - i + 1] = !sol[n - i + 1];
						}
					}
				}

				else if (same != -1)
				{
					int input;
					bool comp = false;

					printf("%d\n", same);
					fflush(stdout);

					scanf("%d", &input);

					if (sol[same] != input)
					{
						comp = true;
					}

					printf("%d\n", same);
					fflush(stdout);

					scanf("%d", &input);

					if (comp)
					{
						for (int i = 0; i < idx; i++)
						{
							sol[i] = !sol[i];

							sol[n - i + 1] = !sol[n - i + 1];
						}
					}
				}

				else
				{
					int input;
					bool comp = false;

					printf("%d\n", diff);
					fflush(stdout);

					scanf("%d", &input);

					if (sol[diff] != input)
					{
						comp = true;
					}

					printf("%d\n", diff);
					fflush(stdout);

					scanf("%d", &input);

					if (comp)
					{
						for (int i = 0; i < idx; i++)
						{
							sol[i] = !sol[i];

							sol[n - i + 1] = !sol[n - i + 1];
						}
					}
				}

				cnt += 2;
			}

			else
			{
				printf("%d\n", idx);
				fflush(stdout);
				scanf("%d", &sol[idx]);

				printf("%d\n", n - idx + 1);
				fflush(stdout);
				scanf("%d", &sol[n - idx + 1]);

				if (sol[idx] == sol[n - idx + 1])
				{
					same = idx;
				}

				else
				{
					diff = idx;
				}

				idx++;
				cnt += 2;
			}
		}

		if (idx <= n / 2)
		{
			for (int i = 0; i < n; i++)
			{
				printf("0");
			}

			printf("\n");
			fflush(stdout);
		}

		else
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d", sol[i]);
			}

			printf("\n");
			fflush(stdout);
		}

		char test[2];

		scanf("%s", test);

		if (test[0] == 'N')
		{
			return 0;
		}
	}

	return 0;
}