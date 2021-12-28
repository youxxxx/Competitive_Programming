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

#define N 500000

map<pair<int, int>, int> rrank;
map<pair<int, int>, pair<int, int>> group;
int cnt[N + 1] = { 0, };

pair<int, int> uf(pair<int, int> a) {
	if (group[a] == a) {
		return a;
	}

	return group[a] = uf(group[a]);
}

int main()
{
	io();

	int n;

	scanf("%d", &n);

	vector<pair<int, int>> arr;

	for (int i = 0; i < n; i++) {
		int op;

		scanf("%d", &op);

		if (op == 1) {
			int x;

			scanf("%d", &x);

			arr.push_back({ x,cnt[x] });

			if (rrank.find({ x,cnt[x] }) == rrank.end()) {
				rrank[{x, cnt[x]}] = 1;

				group[{x, cnt[x]}] = { x,cnt[x] };
			}
		}

		else {
			int x, y;

			scanf("%d %d", &x, &y);

			group[{x, cnt[x]}] = {y, cnt[y]};

			if (rrank.find({ y,cnt[y] }) == rrank.end()) {
				rrank[{y, cnt[y]}] = 1;

				group[{y, cnt[y]}] = { y,cnt[y] };
			}

			cnt[x]++;
		}
	}

	for (int i = 0; i < (int)arr.size(); i++) {

		printf("%d ", uf(arr[i]).first);
	}

	printf("\n");

	return 0;
}