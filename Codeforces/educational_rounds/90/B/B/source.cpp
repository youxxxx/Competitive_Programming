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

	scanf("%lld", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[101];
		string str;

		scanf("%s", input);
		str = input;

		const int n = str.size();

		int cnt[2] = { 0, };

		for (int i = 0; i < n; i++)
		{
			cnt[str[i] - '0']++;
		}

		int sol = cnt[0] < cnt[1] ? cnt[0] : cnt[1];

		if (sol % 2)
		{
			printf("DA\n");
		}

		else
		{
			printf("NET\n");
		}
	}

	return 0;
}