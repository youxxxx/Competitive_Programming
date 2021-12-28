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

#define N 1000000

int tree[N + 2];

void add(int idx, int val) {
	if (!idx) {
		return;
	}

	for (; idx <= N; idx += idx&-idx) {
		tree[idx] += val;
	}
}

int get(int idx) {
	int rvalue = 0;

	for (; idx; idx -= idx&-idx) {
		rvalue += tree[idx];
	}

	return rvalue;
}

int psum(int r, int l) {
	return get(r) - get(l);
}

int num[N + 1];

vector<int> graph[N + 1];

int cnt;

void dfs(int cur) {
	num[cur] = cnt++;

	for (auto &next : graph[cur]) {
		dfs(next);
	}
}

bool func(vector<int> &a, vector<int> &b) {
	return num[a[0]] < num[b[0]];
}

int tot[N + 1];
int uni[N + 2];
int ptr[N + 1];
int numcnt[N + 1];
queue<int> q[N + 1];

vector<vector<int>> queries;
int sol[N + 1];

int qptr;

int n;
int arr[N + 1];

void solve(int cur) {
	if (qptr == (int)queries.size()) {
		return;
	}

	{
		const int prevcnt = numcnt[arr[cur]];
		const int curcnt = prevcnt + 1;

		tot[prevcnt]--;
		tot[curcnt]++;

		if (tot[prevcnt] == 1) {
			while (!q[prevcnt].empty() && tot[q[prevcnt].front()] != prevcnt) {
				q[prevcnt].pop();
			}

			uni[prevcnt] = q[prevcnt].front();
		}

		else {
			uni[prevcnt] = 0;
		}

		q[curcnt].push(arr[cur]);

		if (tot[curcnt] == 1) {
			uni[curcnt] = arr[cur];
		}

		else {
			uni[curcnt] = 0;
		}

		add(prevcnt, -1);
		add(curcnt, 1);

		numcnt[arr[cur]]++;
	}

	while (qptr != (int)queries.size()) {
		const int v = queries[qptr][0];
		const int l = queries[qptr][1];
		const int k = queries[qptr][2];
		const int idx = queries[qptr][3];

		if (num[v] > num[cur]) {
			break;
		}

		const int tot = get(n);

		if (tot < k) {
			sol[idx] = -1;
		}

		else {
			int lb = 0;
			int ub = n + 1;

			const int leftovers = tot - k;

			for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2) {
				const int ret = get(next);
				if (ret > leftovers) {
					ub = next;
				}

				else {
					lb = next;
				}
			}

			if (get(lb) == leftovers && uni[lb + 1]) {
				sol[idx] = uni[lb + 1];
			}

			else {
				sol[idx] = -1;
			}
		}

		qptr++;
	}

	if (qptr == (int)queries.size()) {
		return;
	}

	if (ptr[cur] == (int)graph[cur].size()) {
		{
			const int prevcnt = numcnt[arr[cur]] - 1;
			const int curcnt = prevcnt + 1;

			tot[prevcnt]++;
			tot[curcnt]--;

			if (tot[curcnt] == 1) {
				while (!q[curcnt].empty() && tot[q[curcnt].front()] != curcnt) {
					q[curcnt].pop();
				}

				uni[curcnt] = q[curcnt].front();
			}

			else {
				uni[curcnt] = 0;
			}

			q[prevcnt].push(arr[cur]);

			if (tot[prevcnt] == 1) {
				uni[prevcnt] = arr[cur];
			}

			else {
				uni[prevcnt] = 0;
			}

			numcnt[arr[cur]]--;

			add(prevcnt, 1);
			add(curcnt, -1);
		}

		return;
	}

	solve(graph[cur][ptr[cur]++]);

	{
		const int prevcnt = numcnt[arr[cur]] - 1;
		const int curcnt = prevcnt + 1;

		tot[prevcnt]++;
		tot[curcnt]--;

		if (tot[curcnt] == 1) {
			while (!q[curcnt].empty() && tot[q[curcnt].front()] != curcnt) {
				q[curcnt].pop();
			}

			uni[curcnt] = q[curcnt].front();
		}

		else {
			uni[curcnt] = 0;
		}

		q[prevcnt].push(arr[cur]);

		if (tot[prevcnt] == 1) {
			uni[prevcnt] = arr[cur];
		}

		else {
			uni[prevcnt] = 0;
		}

		numcnt[arr[cur]]--;

		add(prevcnt, 1);
		add(curcnt, -1);
	}
}

int main()
{
	io();

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++) {
		int m;

		scanf("%d %d", &n, &m);

		fill(&tree[0], &tree[n + 1], 0);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);

			graph[i].clear();
		}

		for (int i = 2; i <= n; i++) {
			int parent;

			scanf("%d", &parent);

			graph[parent].push_back(i);

			while (!q[i].empty()) {
				q[i].pop();
			}
		}

		cnt = 0;

		dfs(1);

		queries.clear();

		for (int i = 0; i < m; i++) {
			vector<int> cur;

			for (int j = 0; j < 3; j++) {
				int input;

				scanf("%d", &input);

				cur.push_back(input);
			}

			cur.push_back(i);

			queries.push_back(cur);
		}

		sort(queries.begin(), queries.end(), func);

		fill(&tot[1], &tot[N + 1], 0);
		fill(&uni[0], &uni[N + 2], 0);
		fill(&ptr[0], &ptr[N + 1], 0);
		fill(&numcnt[0], &numcnt[N + 1], 0);

		tot[0] = n;

		qptr = 0;

		solve(1);

		for (int i = 0; i < m; i++) {
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

 	return 0;
}