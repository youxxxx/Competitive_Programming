#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	vector<int> len;
	string str;
	char input[1000];
	int i, j;
	int cnt[2];
	char cur;
	int parity[2];
	int k;
	int sol;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		len.clear();

		k = 0;
		sol = 0;

		cnt[0] = cnt[1] = 0;
		
		for (i = 0; i < n; i++)
		{
			scanf("%s", input);

			str = input;

			for (j = 0; j < str.size(); j++)
			{
				cnt[str[j] - '0']++;
			}

			len.push_back(str.size());

			if (str.size() % 2)
			{
				k++;
			}

			else
			{
				sol++;
			}
		}

		parity[0] = cnt[0] % 2;
		parity[1] = cnt[1] % 2;

		if ((parity[0] + parity[1]) % 2 == k % 2 && ((!parity[0] || !parity[1]) || k))
		{
			sol += k;
		}

		else
		{
			sol += k - 1;
		}

		printf("%d\n", sol);
	}

	return 0;
}