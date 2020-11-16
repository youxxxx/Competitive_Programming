#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	int n;
	int arr[100001];

	scanf("%d", &n);

	bool valid = true;

	//bool visited[100001];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);

		//visited[i] = false;

		if (arr[i] > i + 1)
		{
			printf("-1\n");

			return 0;
		}
	}

	int sol[100001];
	int cur = 0;
	int ptr = -1;
	int used = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > cur)
		{
			/*
			if (arr[i] - cur > i - ptr - used)
			{
				printf("-1\n");

				return 0;
			}
			*/

			int num = cur + 1;

			int next = -1;

			for (int j = ptr + 1; j < i; j++)
			{
				next = j - 1;

				if (sol[j] != 100001)
				{
					used--;

					continue;
				}

				/*
				while (visited[num] && num < arr[i])
				{
					num++;
				}

				visited[num] = true;
				*/

				if (num == arr[i])
				{
					break;
				}

				sol[j] = num++;
			}

			if (num != arr[i])
			{
				printf("-1\n");

				return 0;
			}

			if (next == -1)
			{
				next = ptr;
			}

			ptr = next;

			sol[i] = cur;

			//visited[cur] = true;

			cur = arr[i];

			used++;
		}

		else
		{
			sol[i] = 100001;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}

	printf("\n");

	return 0;
}