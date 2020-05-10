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
	//freopen("input.txt", "r", stdin);

	int n, k;

	scanf("%d %d", &n, &k);

	string str;
	char input[3001];

	scanf("%s", input);
	str = input;

	int acc = 0;
	int prev = -1;
	int lmax = 0;
	int wait = 0;
	int sum = 0;
	int prevtime = 0;
	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'L')
		{
			if (i > acc)
			{
				arr.push_back(i);

				int val;

				if ((i - acc) <= prevtime)
				{
					wait = prevtime - (i - acc) + 1;
				}

				else
				{
					wait = 0;
				}

				val = i - acc + wait;

				if (val > lmax)
				{
					lmax = val;
				}

				sum += i - acc;

				acc++;
				prev = i;
				prevtime = val;
			}

			acc++;
		}
	}

	if (lmax > k || sum < k)
	{
		printf("-1\n");

		return 0;
	}

	int slack;

	slack = k - lmax;

	int ptr = 0;

	while (ptr != arr.size())
	{
		int next;

		next = ptr;

		bool wait = false;

		vector<int> moves;

		for (int i = ptr; i < arr.size(); i++)
		{
			if (i != 0)
			{
				if (arr[i - 1] != arr[i] - 1)
				{
					wait = false;
				}

				else
				{
					wait = true;
				}
			}

			if (!wait)
			{
				if (i == arr.size() - 1)
				{
					if (slack)
					{
						slack--;
					}

					else
					{
						if (arr[i] - 1 == i)
						{
							next = i + 1;
						}

						moves.push_back(i);
					}
				}

				else
				{
					if (arr[i] - 1 == i)
					{
						next = i + 1;
					}

					moves.push_back(i);
				}
			}
		}

		printf("%d", moves.size());

		for (int i = 0; i < moves.size(); i++)
		{
			printf(" %d", arr[moves[i]]--);
		}

		printf("\n");

		ptr = next;
	}

	return 0;
}