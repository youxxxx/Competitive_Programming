#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>

using namespace std;

int main()
{
	int n, m;
	vector<int> arr, disc;
	vector<int>::iterator it;
	int input;
	int i;
	int op;
	int index, val;
	bool prev, cur;

	scanf("%d %d", &n, &m);

	arr.push_back(1000001);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		if (arr[i] % arr[i - 1])
		{
			disc.push_back(i);
		}
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d", &op);

		if (op == 1)
		{
			scanf("%d %d", &index, &val);

			if (index > 1)
			{
				prev = arr[index] % arr[index - 1];
				cur = val % arr[index - 1];

				if (prev && !cur)
				{
					it = lower_bound(disc.begin(), disc.end(), index);

					disc.erase(it);
				}

				else if (!prev&&cur)
				{
					it = lower_bound(disc.begin(), disc.end(), index);

					disc.insert(it, index);
				}
			}

			if (index < n)
			{
				prev = arr[index + 1] % arr[index];
				cur = arr[index + 1] % val;

				if (prev && !cur)
				{
					it = lower_bound(disc.begin(), disc.end(), index + 1);

					disc.erase(it);
				}

				else if (!prev&&cur)
				{
					it = lower_bound(disc.begin(), disc.end(), index + 1);

					disc.insert(it, index + 1);
				}
			}

			arr[index] = val;
		}

		else
		{
			scanf("%d", &index);

			it = lower_bound(disc.begin(), disc.end(), index);

			if (*it == 1)
			{
				printf("1\n");
			}

			else
			{
				printf("%d\n", *(--it));
			}
		}
	}

	return 0;
}