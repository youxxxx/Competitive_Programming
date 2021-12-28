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

int temp[500001];
int arr[500001];
long long sol;

void dnc(long long l, long long r) {
	if (r - l == 1) {
		return;
	}

	const long long mid = (l + r) / 2;

	long long ptr = 0;
	long long lptr = l;
	long long rptr = mid;

	dnc(l, mid);
	dnc(mid, r);

	while (lptr != mid&&rptr != r) {
		if (arr[lptr] <= arr[rptr]) {
			sol += ptr - (lptr - l);

			temp[ptr++] = arr[lptr++];
		}

		else {
			temp[ptr++] = arr[rptr++];
		}
	}

	while (lptr != mid) {
		sol += ptr - (lptr - l);

		temp[ptr++] = arr[lptr++];
	}

	while (rptr != r) {
		temp[ptr++] = arr[rptr++];
	}

	for (long long i = l; i < r; i++) {
		arr[i] = temp[i - l];
	}
}

int main()
{
	io();

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++) {
		int n;

		scanf("%d", &n);

		bool dup = false;

		int check[500001];

		fill(&check[0], &check[n + 1], 0);

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);

			if (check[arr[i]]) {
				dup = true;
			}

			check[arr[i]] = 1;
		}

		sol = 0;

		dnc(0, n);

		if (!sol) {
			printf("YES\n");

			continue;
		}

		if (n < 3) {
			printf("NO\n");

			continue;
		}

		if (dup || !(sol % 2)) {
			printf("YES\n");

			continue;
		}

		printf("NO\n");
	}

	return 0;
}