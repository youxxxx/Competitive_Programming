#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<functional>
#include<queue>

#define MOD 1000000007

using namespace std;

long long preval[100001];
long long val[100001];
long long len[100001];
long long front[100001];
vector<long long> graph[100001];

class comp
{
public:

	bool operator() (const long long &a, const long long &b) const
	{
		return len[a] < len[b] || len[a] == len[b] && (front[a] * (long long)pow(10, 6 - log10(front[a])) < (front[b] * (long long)pow(10, 5 - log10(front[b]))));
	}
};

int main()
{
	long long n, m;
	priority_queue<long long,vector<long long>,comp> pq;
	long long i, j;
	long long u, v;
	bool visited[100001] = { 0, };
	long long cur, next;
	long long cut, pw;
	long long nextval;

	freopen("input.txt", "r", stdin);

	scanf("%lld %lld", &n, &m);

	val[1] = len[1] = front[1] = 1;
	preval[1] = 0;

	for (i = 0; i < m; i++)
	{
		scanf("%lld %lld", &u, &v);

		graph[u].push_back(v);

		graph[v].push_back(u);
	}

	pq.push(1);

	visited[1] = true;

	while (!pq.empty())
	{
		cur = pq.top();
		pq.pop();

		for (i = 0; i < graph[cur].size(); i++)
		{
			next = graph[cur][i];

			if (!visited[next])
			{
				visited[next] = true;

				pw = (long long)log10(next);

				nextval = val[cur];

				for (j = 0; j <= pw; j++)
				{
					nextval = (nextval * 10) % MOD;
				}

				nextval = (nextval + next) % MOD;

				val[next] = nextval;

				preval[next] = val[cur];

				if (pw + len[cur] > 7)
				{
					front[next] = front[cur] * (long long)pow(10.0, pw) + next;

					front[next] /= pow(10.0, pw + len[cur] - 7);
				}

				else
				{
					len[next] = pw + len[cur];

					front[next] = front[cur] * (long long)pow(10.0, pw) + next;
				}

				pq.push(next);
			}
		}
	}

	for (i = 2; i <= n; i++)
	{
		printf("%lld\n", preval[i]);
	}

	return 0;
}