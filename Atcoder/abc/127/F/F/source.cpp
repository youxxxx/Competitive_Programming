#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main()
{
	vector<long long> arr;
	vector<long long>::iterator it, ret;
	long long a, b;
	long long c = 0, d = 0;
	long long cnt = 0;
	long long pos;
	int n;
	int i;
	int op;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &op);

		if (op == 1)
		{
			scanf("%lld %lld", &a, &b);

			c += b;

			cnt++;

			if (arr.empty())
			{
				arr.push_back(a);

				continue;
			}

			ret = lower_bound(arr.begin(), arr.end(), a);
			
			pos = ret - arr.begin();

			if (arr.size() % 2)
			{
				arr.insert(ret, a);

				d += arr[arr.size() / 2] - arr[arr.size() / 2 - 1];

				if (pos <= arr.size() / 2 - 1)
				{
					d += abs(arr[arr.size() / 2 - 1] - a);
				}

				else
				{
					d += abs(arr[arr.size() / 2] - a);
				}
			}

			else
			{
				arr.insert(ret, a);

				d += abs(a - arr[arr.size() / 2]);
			}
		}

		else
		{
			printf("%lld %lld\n", arr[arr.size() / 2 - !(arr.size() % 2)], c + d);
		}
	}

	return 0;
}