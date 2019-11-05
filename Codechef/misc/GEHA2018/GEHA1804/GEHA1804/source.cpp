#include<cstdio>

using namespace std;

int main()
{
	int n, q;
	unsigned long long *arr;
	long long *cnt;
	unsigned long long value1, value2;
	int opcode;
	long long op1, op2;
	int i, j;
	int start, max;
	bool valid;

	scanf("%d %d", &n, &q);

	arr = new unsigned long long[n + 1];
	cnt = new long long[n + 1];

	for (i = 1; i <= n; i++)
	{
		arr[i] = 0;
		
		cnt[i] = 0;
	}

	for (i = 0; i < q; i++)
	{
		scanf("%d %lld %lld", &opcode, &op1, &op2);

		if (opcode == 1)
		{
			value1 = (arr[op1] >> (op2 - 1)) % 2;

			value2 = !value1;

			cnt[op1] += (long long)value2 - (long long)value1;

			if (value2)
			{
				value2 = 1ULL << (op2 - 1);

				arr[op1] |= value2;
			}

			else
			{
				value2 = 1ULL << (op2 - 1);

				value2 = ~value2;

				arr[op1] &= value2;
			}
		}

		else
		{
			valid = false;
			max = 0;

			for (j = op1; j <= op2; j++)
			{
				if (!valid)
				{
					if (cnt[j] == 3)
					{
						valid = true;
						
						start = j;
					}
				}

				if (valid)
				{
					if (cnt[j] != 3)
					{
						valid = false;

						if (j - start > max)
						{
							max = j - start;
						}
					}
				}
			}

			if (valid)
			{
				if (cnt[j] < 3)
				{
					if (j - start > max)
					{
						max = j - start;
					}
				}
			}

			printf("%d\n", max);
		}
	}

	return 0;
}