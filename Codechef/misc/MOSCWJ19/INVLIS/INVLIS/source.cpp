#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, k;
	int *arr;
	vector<int> seq;
	int i, j;
	int input;
	int lptr, uptr;
	int pre;
	int t, z;

	arr = new int[100001];

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &k);

		for (i = 0; i < k; i++)
		{
			scanf("%d", &input);

			seq.push_back(input);
		}

		if (k == 1)
		{
			if (n == 1)
			{
				printf("YES\n1\n");
			}

			else
			{
				printf("NO\n");
			}
		}

		else if (k == 2 && seq[0] + 1 != seq[1])
		{
			if (n == 2)
			{
				printf("YES\n1 2\n");
			}

			else
			{
				printf("NO\n");
			}
		}

		else
		{
			lptr = 0;
			uptr = n + 1;

			for (i = n; i >= seq[k - 1] + 1; i--)
			{
				arr[i] = ++lptr;
			}

			for (i = seq[k - 1] - 1; i >= seq[k - 2] + 1; i--)
			{
				arr[i] = ++lptr;
			}

			pre = 0;

			for (i = 0; i < seq.size() - 1; i++)
			{
				for (j = pre + 1; j < seq[i]; j++)
				{
					arr[j] = --uptr;
				}

				arr[seq[i]] = ++lptr;

				pre = seq[i];
			}

			arr[seq[k - 1]] = ++lptr;

			printf("YES\n");

			for (i = 1; i <= n; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
		}

		seq.clear();
	}

	return 0;
}