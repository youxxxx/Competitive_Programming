#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int a, b;
	int amax, bmax;
	int input;
	vector<int> arr;
	int n, i;

	scanf("%d %d %d", &n, &bmax, &amax);

	a = amax;
	b = bmax;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (!a && !b)
		{
			break;
		}

		else if (input)
		{
			if (b && a < amax)
			{
				b--;
				a++;
			}

			else
			{
				a--;
			}
		}

		else
		{
			if (a)
			{
				a--;
			}

			else
			{
				b--;
			}
		}
	}

	printf("%d\n", i);

	return 0;
}