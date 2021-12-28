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

void io()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
}

int main()
{
	io();

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++) {
		char input[51];
		scanf("%s", input);
		const string str = input;
		const int n = str.size();

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			cnt += (str[i] == 'N');
		}

		if (cnt == 1) {
			printf("NO\n");

			continue;
		}

		printf("YES\n");
	}

	return 0;
}