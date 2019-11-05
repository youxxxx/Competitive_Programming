#include<cstdio>
#include<vector>

using namespace std;

void mult(long long a[][2], long long b[][2], long long res[][2])
{
	int i, j, k;
	long long sum;
	
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			sum = 0;

			for (k = 0; k < 2; k++)
			{
				sum = (sum + a[i][k] * b[k][j]) % 1000000007;
			}

			res[i][j] = sum % 1000000007;
		}
	}
}

void copy(long long a[][2], long long b[][2])
{
	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

int main()
{
	long long n, m;
	long long fibp = 0, fibn = 1, temp;
	long long cnt = 1;
	long long period;
	long long start;
	long long target;
	vector<long long> arr;
	vector<long long> bits;
	long long mat[2][2] = { 1,1,1,0 };
	long long res1[2][2] = { 1,0,0,1 }, res2[2][2] = { 1,0,0,1 };
	long long buf1[2][2], buf2[2][2], buf3[2][2];
	long long sol;
	int i;

	scanf("%I64d %I64d", &n, &m);

	if (n < m)
	{
		printf("1\n");

		return 0;
	}

	target = n - m + 2;

	temp = target;

	while (temp)
	{
		bits.push_back(temp % 2);

		temp /= 2;
	}
	
	for (i = 0; i < bits.size(); i++)
	{
		if (bits[i])
		{
			copy(res1, buf1);
			copy(mat, buf2);
			mult(buf1, buf2, buf3);
			copy(buf3, res1);
		}

		copy(mat, buf1);
		copy(mat, buf2);
		mult(buf1, buf2, buf3);
		copy(buf3, mat);
	}

	printf("%lld\n", (res1[1][0] + res1[1][1]) % 1000000007);

	return 0;
}