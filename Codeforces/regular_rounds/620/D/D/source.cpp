#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		char input[200001];
		string str;

		scanf("%d", &n);

		scanf("%s", input);
		str = input;

		int high = 1;

		for (int i = 0; i < n - 1; i++)
		{
			if (str[i] == '>')
			{
				high++;
			}
		}

		vector<int> lmax, lmin;

		int low;

		low = high - 1;

		lmax.push_back(high++);

		for (int i = 0; i < n - 1; i++)
		{
			if (str[i] == '<')
			{
				lmax.push_back(high++);
			}

			else
			{
				lmax.push_back(low--);
			}
		}

		int acc[200001];

		int cur = 1, add = 0;
		acc[n - 1] = 1;

		for (int i = n - 2; i >= 0; i--)
		{
			add++;

			if (str[i] == '>')
			{
				acc[i + 1] = cur;

				cur += add;

				add = 0;
			}
		}

		acc[0] = cur;

		int val;

		val = acc[0];

		lmin.push_back(val);

		for (int i = 1; i < n; i++)
		{
			if (str[i - 1] == '>')
			{
				val = acc[i];
			}

			else
			{
				val++;
			}

			lmin.push_back(val);
		}

		for (int i = 0; i < n; i++)
		{
			printf("%d ", lmin[i]);
		}

		printf("\n");

		for (int i = 0; i < n; i++)
		{
			printf("%d ", lmax[i]);
		}

		printf("\n");
	}

	return 0;
}