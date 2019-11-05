#include<cstdio>

int main()
{
	long long max = -1;
	long long input;
	long long n;
	long long index = -1;
	long long i;
	bool miss = false;

	scanf("%I64d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		if (!miss)
		{
			if (input > max + 1)
			{
				index = i + 1;

				miss = true;
			}

			else
			{
				if (input > max)
				{
					max = input;
				}
			}
		}		
	}

	printf("%I64d", index);

	return 0;
}