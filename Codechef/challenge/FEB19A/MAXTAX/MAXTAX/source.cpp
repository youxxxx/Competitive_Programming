#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;


vector<int> *graph;
vector<int> *revgraph;
vector<long long> *val;
int *cidx;
long long *budget;
bool *visited, *visited2;
/*
vector<int> graph[100001];
vector<int> revgraph[100001];
vector<long long> val[100001];
int cidx[100001];
long long budget[100001];
bool visited[100001], visited2[100001];
*/

stack<int> s;
queue<int> q;

void dfs(int cur, int idx)
{
	int i;
	int next;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (!visited[next])
		{
			visited[next] = true;

			dfs(next, idx);
		}
	}

	s.push(cur);
}

void dfs2(int cur, int idx)
{
	int i;
	int next;

	cidx[cur] = idx;

	val[idx].push_back(budget[cur]);

	for (i = 0; i < revgraph[cur].size(); i++)
	{
		next = revgraph[cur][i];

		if (visited[next] && !visited2[next])
		{
			visited2[next] = true;

			dfs2(next, idx);
		}
	}
}

int main()
{
	int n, m, k;
	int t, z;
	register int i, j, h;
	long long input;
	int u, v;
	int cnt;
	long long lmax;
	long long curmax;
	long long sum; 
	int cur;
	int ptr, preidx;
	long long preval;
	int premax;

	set<long long> *link;
	set<long long>::iterator it;
	pair<set<long long>::iterator, bool> ret;
	long long *indeg;
	long long **add;
	long long **base;
	int *maxk;

	/*
	set<long long> link[100001];
	set<long long>::iterator it;
	pair<set<long long>::iterator, bool> ret;
	long long indeg[100001];
	long long add[100001][201];
	long long base[100001][201];
	int maxk[100001];
	*/

	graph = new vector<int>[100001];
	revgraph = new vector<int>[100001];
	budget = new long long[100001];
	visited = new bool[100001];
	visited2 = new bool[100001];
	cidx = new int[100001];
	val = new vector<long long>[100001];
	add = new long long*[100001];	
	base = new long long*[100001];
	indeg = new long long[100001];
	link = new set<long long>[100001];
	maxk = new int[100001];
	
	for (i = 0; i <= 100000; i++)
	{
		add[i] = new long long[201];
		base[i] = new long long[201];
	}
	
	//freopen("input.txt", "r", stdin);

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		cnt = 0;
		lmax = 0;

		scanf("%d %d %d", &n, &m, &k);

		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &input);

			budget[i] = input;

			visited[i] = false;
			visited2[i] = false;
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			revgraph[v].push_back(u);
		}

		for (i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;

				dfs(i, cnt);

				while (!s.empty())
				{
					cur = s.top();

					s.pop();

					if (!visited2[cur])
					{
						visited2[cur] = true;

						dfs2(cur, cnt);

						sort(val[cnt].begin(), val[cnt].end());

						cnt++;
					}
				}
			}
		}

		//dp[1][0] = 0;

		for (i = 0; i < cnt; i++)
		{
			for (j = 0; j <= k; j++)
			{
				add[i][j] = 0;
				base[i][j] = 0;
			}

			indeg[i] = 0;
		}

		for (i = 1; i <= n; i++)
		{
			for (j = 0; j < graph[i].size(); j++)
			{
				if (cidx[graph[i][j]] != cidx[i])
				{
					ret = link[cidx[i]].insert(cidx[graph[i][j]]);

					if (ret.second)
					{
						indeg[cidx[graph[i][j]]]++;
					}
				}
			}
		}

		for (i = 0; i < cnt; i++)
		{
			if (indeg[i] == 0)
			{
				q.push(i);
			}

			preidx = 0;
			preval = val[i][0];
			curmax = 0;

			for (j = 1; j < val[i].size() && j <= k; j++)
			{
				if (val[i][j] != preval)
				{
					/*
					for (h = 0; h + preidx <= k; h++)
					{
						if (base[i][h + preidx] < preval*(val[i].size() - preidx))
						{
							base[i][h + preidx] = preval*(val[i].size() - preidx);;

							if (indeg[i] == 0)
							{
								add[i][h + preidx] = base[i][h + preidx];
							}

							if (base[i][h + preidx] > lmax)
							{
								lmax = base[i][h + preidx];
							}
						}
					}
					*/

					if (preval*(val[i].size() - preidx) > curmax)
					{
						curmax = preval*(val[i].size() - preidx);

						base[i][preidx] = curmax;

						maxk[i] = preidx;

						if (curmax > lmax)
						{
							lmax = curmax;
						}
					}

					if (indeg[i] == 0)
					{
						add[i][preidx] = base[i][preidx];
					}

					preval = val[i][j];
					preidx = j;
				}
			}

			/*
			if (base[i][h + preidx] < preval*(val[i].size() - preidx))
			{
				base[i][h + preidx] = preval*(val[i].size() - preidx);

				if (indeg[i] == 0)
				{
					add[i][h + preidx] = base[i][h + preidx];
				}

				if (base[i][h + preidx] > lmax)
				{
					lmax = base[i][h + preidx];
				}
			}
			*/

			if (preval*(val[i].size() - preidx) > curmax)
			{
				curmax = preval*(val[i].size() - preidx);

				base[i][preidx] = curmax;

				maxk[i] = preidx;

				if (curmax > lmax)
				{
					lmax = curmax;
				}
			}

			if (indeg[i] == 0)
			{
				add[i][preidx] = base[i][preidx];
			}
		}

		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			for (it = link[cur].begin(); it != link[cur].end(); it++)
			{
				//for (j = 0; j <= k; j++)
				premax = maxk[*it];

				for (j = 0; j <= maxk[cur]; j++)
				{
					if (add[cur][j] != 0)
					{
						curmax = 0;

						for (h = 0; j + h <= k && h <= premax; h++)
						{
							if (base[*it][h] + add[cur][j] > curmax)
							{
								curmax = base[*it][h] + add[cur][j];

								if (curmax > lmax)
								{
									lmax = curmax;
								}

								if (h + j > maxk[*it])
								{
									maxk[*it] = h + j;
								}
							}

							if (add[*it][h + j] < curmax)
							{
								add[*it][h + j] = curmax;
							}
						}

						preval = val[cur][j];
						preidx = j;
					}
				}

				//maxk[*it] = maxk[cur] + maxk[*it] < 200 ? maxk[cur] + maxk[*it] : 200;

				if (--indeg[*it] == 0 && link[*it].size() != 0)
				{
					q.push(*it);
				}
			}
		}
		/*
		for (i = 0; i < cnt; i++)
		{
			ptr = 0;
			preidx = 0;
			preval = val[i][0];

			for (j = 1; j < val[i].size(); j++)
			{
				if (val[i][j] != preval)
				{
					for (h = 0; h + preidx <= k; h++)
					{
						if (dp[!(i % 2)][h] != -1 && dp[i % 2][h + preidx] < dp[!(i % 2)][h] + preval*(val[i].size() - preidx))
						{
							dp[i % 2][h + preidx] = dp[!(i % 2)][h] + preval*(val[i].size() - preidx);

							if (dp[i % 2][h + preidx] > lmax)
							{
								lmax = dp[i % 2][h + preidx];
							}
						}
					}

					preval = val[i][j];
					preidx = j;
				}
			}

			for (h = 0; h + preidx <= k; h++)
			{
				if (dp[!(i % 2)][h] != -1 && dp[i % 2][h + preidx] < dp[!(i % 2)][h] + preval*(val[i].size() - preidx))
				{
					dp[i % 2][h + preidx] = dp[!(i % 2)][h] + preval*(val[i].size() - preidx);

					if (dp[i % 2][h + preidx] > lmax)
					{
						lmax = dp[i % 2][h + preidx];
					}
				}
			}
		}
		*/

		printf("%lld\n", lmax % 1000000021);

		for (i = 1; i <= n; i++)
		{
			graph[i].clear();
			revgraph[i].clear();
		}

		for (i = 0; i < cnt; i++)
		{
			val[i].clear();
			link[i].clear();
		}
	}

	return 0;
}