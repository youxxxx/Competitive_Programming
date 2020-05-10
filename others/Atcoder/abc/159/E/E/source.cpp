#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int n, m, k;
	vector<string> arr;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++)
	{
		char input[1001];
		string str;

		scanf("%s", input);
		str = input;

		arr.push_back(str);
	}

	int ub;

	ub = (int)pow(2.0, n - 1);

	int lmin = 1000000;

	for (int i = 0; i < ub; i++)
	{
		int bits;
		int add[10];
		int temp;

		temp = i;
		int cnt = 0;

		add[0] = 0;

		int cand = 0;

		for (int j = 1; j < n; j++)
		{
			cnt += temp % 2;

			cand += temp % 2;

			add[j] = cnt;
			
			temp /= 2;
		}

		int acc[10] = { 0, };

		bool valid = true;

		for (int l = 0; l < m; l++)
		{
			bool reset = false;

			for (int j = 0; j < n; j++)
			{
				acc[add[j]] += arr[j][l] - '0';

				if (acc[add[j]] > k)
				{
					if (!reset)
					{
						reset = true;

						cand++;
					}
				}
			}

			if (reset)
			{
				for (int j = 0; j < n; j++)
				{
					acc[add[j]] = 0;
				}

				for (int j = 0; j < n; j++)
				{
					acc[add[j]] += arr[j][l] - '0';
				}

				for (int j = 0; j < n; j++)
				{
					if (acc[add[j]] > k)
					{
						valid = false;

						break;
					}
				}
			}

			if (!valid)
			{
				break;
			}
		}

		if (valid && cand < lmin)
		{
			lmin = cand;
		}
	}

	printf("%d\n", lmin);

	return 0;
}