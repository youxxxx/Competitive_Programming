#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long n;
	vector<long long> arr;
	long long input;
	long long i;
	long long cur = 0;
	long long add;

	scanf("%I64d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	printf("%I64d\n", n + 1);

	for (i = n - 1; i >= 0; i--)
	{
		add = (i + n - (cur + arr[i]) % n) % n;

		printf("1 %I64d %I64d\n", i + 1, add);

		cur = (cur + add) % n;
	}

	printf("2 %I64d %I64d\n", n, n);

	return 0;
}