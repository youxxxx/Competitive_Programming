#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases, tc;
	vector<int> odd;
	int k;
	int n;
	int i;
	int parity;
	int input;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &n, &k);

		parity = 0;

		odd.clear();

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			if (input % 2)
			{
				odd.push_back(i + 1);

				parity = !parity;
			}
		}

		if (parity != k % 2 || odd.size() < k)
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");

		for (i = odd.size() - k; i < odd.size() - 1; i++)
		{
			printf("%d ", odd[i]);
		}

		printf("%d\n", n);
	}

	return 0;
}