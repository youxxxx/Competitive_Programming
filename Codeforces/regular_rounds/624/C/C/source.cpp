#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		char input[200001];

		string s;

		scanf("%s", input);

		s = input;

		int prefix[26][200001];

		for (int j = 0; j < 26; j++)
		{
			prefix[j][0] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				prefix[j][i + 1] = prefix[j][i] + (s[i] == j + 'a');
			}
		}

		int sol[26] = { 0, };

		for (int j = 0; j < 26; j++)
		{
			sol[j] += prefix[j][n];
		}

		for (int i = 0; i < m; i++)
		{
			int input;

			scanf("%d", &input);

			for (int j = 0; j < 26; j++)
			{
				sol[j] += prefix[j][input];
			}
		}

		for (int i = 0; i < 26; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}