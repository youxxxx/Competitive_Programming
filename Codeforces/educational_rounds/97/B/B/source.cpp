#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		char input[100001];

		scanf("%s", input);

		const string str = input;

		int cnt[2] = { 0, };

		for (int i = 1; i < n; i++)
		{
			if (str[i] == str[i - 1])
			{
				cnt[str[i] - '0']++;
			}
		}

		printf("%d\n", max(cnt[0], cnt[1]));
	}

	return 0;
}