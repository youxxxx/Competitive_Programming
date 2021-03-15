
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	vector<string> arr;
	vector<pair<int, int>> coord[10];

	for (int tc = 0; tc < cases; tc++)
	{
		long long n;

		scanf("%lld", &n);

		if (n % 2)
		{
			printf("-1\n");

			continue;
		}

		long long temp = n / 2;
		vector<long long> arr;

		while (temp)
		{
			arr.push_back(temp % 3);

			temp /= 3;
		}

		long long cnt = 0;

		bool valid = true;

		for (long long i = 0; i < arr.size(); i++)
		{
			cnt += (i + 1)*arr[i];

			if (cnt > 2000)
			{
				valid = false;

				break;
			}
		}

		if (!valid)
		{
			printf("-1\n");

			continue;
		}

		printf("%d\n", cnt);

		for (long long i = 0; i < arr.size(); i++)
		{
			for (int k = 0; k < arr[i]; k++)
			{
				printf("1 ");

				for (long long j = 0; j < i; j++)
				{
					printf("0 ");
				}
			}
		}

		printf("\n");
	}

	return 0;
}