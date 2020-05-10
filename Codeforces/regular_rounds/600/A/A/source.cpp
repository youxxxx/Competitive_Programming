#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		vector<int> a, b;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			a.push_back(input);
		}

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			b.push_back(input);
		}

		bool start = false, end = false;
		int diff;
		bool valid = true;

		for (int i = 0; i < n; i++)
		{
			if (a[i] > b[i])
			{
				valid = false;

				break;
			}

			if (!start)
			{
				if (a[i] < b[i])
				{
					diff = a[i] - b[i];

					start = true;
				}
			}

			else
			{
				if (!end)
				{
					if (a[i] < b[i])
					{
						if (a[i] - b[i] != diff)
						{
							valid = false;

							break;
						}
					}

					else
					{
						end = true;
					}
				}

				else if (a[i] != b[i])
				{
					valid = false;

					break;
				}
			}
		}

		if (valid)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}