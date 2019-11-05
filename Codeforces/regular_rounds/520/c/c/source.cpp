#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int> num[2];
	string str;
	int i, j;
	int n, q;
	int index1, index2;
	long long res, sum, r0;
	char input[100001];
	long long n0, n1;

	scanf("%d %d", &n, &q);

	scanf("%s", input);

	str = input;

	num[0].push_back(0);
	num[1].push_back(1);

	for (i = 0; i < n; i++)
	{
		num[0].push_back(num[0][i]);
		num[1].push_back(num[1][i]);
		num[str[i] - '0'][i + 1]++;
	}

	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &index1, &index2);

		n0 = (long long)num[0][index2] - (long long)num[0][index1 - 1];
		n1 = (long long)num[1][index2] - (long long)num[1][index1 - 1];

		res = !!n1;
		r0 = 0;

		sum = 0;

		for (j = 0; j < n1 - 1; j++)
		{
			sum = (sum + res) % 1000000007;

			r0 = (r0 + res) % 1000000007;

			res = (res * 2) % 1000000007;
		}

		if (n1 > 0)
		{
			r0 = (r0 + res) % 1000000007;

			sum = (sum + res) % 1000000007;
		}

		sum = (sum + r0*n0) % 1000000007;

		printf("%I64d\n", sum);
	}

	return 0;
}