#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long n, t;
	long long i;
	long long index;
	vector<long long> a[2];
	long long input;
	long long start;
	long long cur;
	long long sum;
	long long q, r;
	long long cnt = 0;
	bool change = true;

	scanf("%I64d %I64d", &n, &t);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		if (input <= t)
		{
			a[0].push_back(input);
		}
	}

	cur = 0;

	while (!a[cur].empty())
	{
		//change = false;
		sum = 0;

		for (i = 0; i < a[cur].size(); i++)
		{
			if (sum + a[cur][i] > t)
			{
				break;
			}

			sum += a[cur][i];
		}

		if (i == a[cur].size())
		{
			q = t / sum;

			cnt += a[cur].size()*q;

			t -= q*sum;

			change = true;

			sum = 0;

			for (i = 0; i < a[cur].size(); i++)
			{
 				if (sum + a[cur][i] > t)
				{
					break;
				}

				sum += a[cur][i];
			}
		}

		t -= sum;

		cnt += i;

		index = i;

		for (i = 0; i < a[cur].size(); i++)
		{
			if (a[cur][(i + index) % a[cur].size()] <= t)
			{
				a[!cur].push_back(a[cur][(i + index) % a[cur].size()]);
			}
		}

		a[cur].clear();

		cur = !cur;
	}

	printf("%I64d\n", cnt);

	return 0;
}