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
		int n;

		scanf("%d", &n);

		int height = 1;
		int prev = -1;

		for (int i = 0; i < n; i++) {
			int input;

			scanf("%d", &input);

			if (height == -1) {
				continue;
			}

			if (input) {
				if (i&&prev == i - 1) {
					height += 5;
				}

				else {
					height++;
				}

				prev = i;
			}

			else {
				if (prev == i - 2) {
					height = -1;
				}
			}
		}

		printf("%d\n", height);
	}

	return 0;
}