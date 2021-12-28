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

		int arr[200001];

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		int rmax = arr[n - 1];
		int sol = 0;

		for (int i = n - 2; i >= 0; i--) {
			if (arr[i] > rmax) {
				rmax = arr[i];

				sol++;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}