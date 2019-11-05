#include<cstdio>

using namespace std;

int main()
{
	long long n;
	long long sumx = 0, sumy = 0;
	long long i;
	long long input1, input2;

	scanf("%I64d", &n);

	for (i = 0; i < n * 2; i++)
	{
		scanf("%I64d %I64d", &input1, &input2);

		sumx += input1;
		sumy += input2;
	}

	sumx /= n;
	sumy /= n;

	printf("%I64d %I64d\n", sumx, sumy);

	return 0;
}