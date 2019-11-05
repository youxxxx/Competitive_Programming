#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int t, z;
	int n, i;
	char *input;
	string str;
	int psum, max;

	input = new char[100001];
	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		scanf("%s", input);

		str = input;

		psum = 0;
		max = 0;

		for (i = 0; i < n; i++)
		{
			if (input[i] == '0')
			{
				psum++;
			}

			else
			{
				psum--;
			}

			if (psum < 0)
			{
				psum = 0;
			}

			if (psum > max)
			{
				max = psum;
			}
		}

		if (max == 0)
		{
			max = -1;
		}

		printf("%d\n", max);
	}

	return 0;
}