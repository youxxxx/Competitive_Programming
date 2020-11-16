#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[1001];
		string str;

		scanf("%s", input);
		str = input;

		const int n = str.size();

		int left[2][1001];
		int right[2][1001];

		int cur[2] = { 0, };

		for (int i = 0; i < n; i++)
		{
			cur[str[i] - '0']++;

			left[0][i] = cur[0];
			left[1][i] = cur[1];
		}

		cur[0] = cur[1] = 0;

		right[0][n]=right[1][n] = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			cur[str[i] - '0']++;

			right[0][i] = cur[0];
			right[1][i] = cur[1];
		}
		
		int lmin = n;

		for (int i = 0; i < n; i++)
		{
			if (left[0][i] + right[1][i + 1] < lmin)
			{
				lmin = left[0][i] + right[1][i + 1];
			}

			if (left[1][i] + right[0][i + 1] < lmin)
			{
				lmin = left[1][i] + right[0][i + 1];
			}
		}

		printf("%d\n", lmin);
	}

	return 0;
}