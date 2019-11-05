#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	long long n, m;
	long long max1, max2;
	long long i;
	long long input, flag;
	vector<long long> taxi, rider, total;
	long long *answer;
	long long ptr;


	scanf("%I64d %I64d", &n, &m);

	answer = new long long[m];

	for (i = 0; i < m; i++)
	{
		answer[i] = 0;
	}

	for (i = 0; i < n + m; i++)
	{
		scanf("%I64d", &input);

		total.push_back(input);
	}

	for (i = 0; i < n + m; i++)
	{
		scanf("%I64d", &flag);

		if (flag)
		{
			taxi.push_back(total[i]);
		}

		else
		{
			rider.push_back(total[i]);
		}
	}

	sort(taxi.begin(), taxi.end());
	sort(rider.begin(), rider.end());

	ptr = 0;

	for (i = 0; i < n; i++)
	{
		while(ptr < m - 1 && abs(rider[i] - taxi[ptr + 1]) < abs(rider[i] - taxi[ptr]))
		{
			ptr++;
		}

		answer[ptr]++;
	}

	for (i = 0; i < m; i++)
	{
		printf("%I64d ", answer[i]);
	}

	return 0;
}