#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, q;
	int i, j, k;
	vector<int> arr, narr;
	int input;
	int lb, ub;
	int start0;
	bool seq0;
	bool init, term, impos = false;

	scanf("%d %d", &n, &q);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	narr = arr;

	for (i = q; i >= 1; i--)
	{
		init = false;
		term = false;
		seq0 = false;
		start0 = -1;

		for (j = 0; j < n; j++)
		{
			if (narr[j] == i)
			{
				if (term)
				{
					impos = true;

					break;
				}

				if (!init)
				{
					init = true;

					lb = j;

					if (seq0)
					{
						for (k = start0; k < j; k++)
						{
							narr[k] = 0;

							if (arr[k] == 0)
							{
								arr[k] = i;
							}
						}
					}
				}

				narr[j] = 0;

				seq0 = false;
			}

			else if (narr[j] != 0)
			{
				if (init)
				{
					term = true;
				}

				seq0 = false;
			}

			else
			{
				if (!init && !seq0)
				{
					seq0 = true;

					start0 = j;
				}

			    else if (init && !term)
				{
					narr[j] = 0;

					if (arr[j] == 0)
					{
						arr[j] = i;
					}
				}
			}
		}

		if (impos)
		{
			break;
		}

		if (!init)
		{
			if (seq0)
			{
				for (j = start0; j < n; j++)
				{
					narr[j] = 0;

					if (arr[j] == 0)
					{
						arr[j] = i;
					}
				}
			}

			else if (start0 == -1)
			{
				impos = true;

				break;
			}

			else
			{
				arr[start0] = i;
			}
		}
	}

	if (impos)
	{
		printf("NO");
	}

	else
	{
		printf("YES\n");

		for (i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}