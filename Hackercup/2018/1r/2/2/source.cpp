#include<cstdio>
#include<cstdlib>
#include<vector>

using namespace std;

int t, k, n;
pair<int, int> tree[2001];
int label[2001];
bool visited[2001];
vector<int> pre, post;
vector<int> graph[2001];
int mark;
int cnt;

void preorder(int cur)
{
	pre.push_back(cur);

	if (tree[cur].first)
	{
		preorder(tree[cur].first);
	}

	if (tree[cur].second)
	{
		preorder(tree[cur].second);
	}
}

void postorder(int cur)
{
	if (tree[cur].first)
	{
		postorder(tree[cur].first);
	}

	if (tree[cur].second)
	{
		postorder(tree[cur].second);
	}

	post.push_back(cur);
}

void dfs(int cur)
{
	int i;
	int next;

	label[cur] = mark;
	cnt++;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (!visited[next])
		{
			visited[next] = true;

			dfs(next);
		}
	}
}

int main()
{
	FILE *in, *out;
	int i, j;

	in = fopen("ethan_traverses_a_tree.txt", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &t);

	for (i = 0; i < t; i++)
	{
		mark = 0;
		cnt = 1;

		fscanf(in, "%d %d", &n, &k);

		for (j = 1; j <= n; j++)
		{
			visited[j] = false;

			fscanf(in, "%d %d", &tree[j].first, &tree[j].second);
		}

		pre.push_back(0);
		post.push_back(0);

		preorder(1);

		postorder(1);

		for (j = 1; j <= n; j++)
		{
			graph[pre[j]].push_back(post[j]);
			graph[post[j]].push_back(pre[j]);
		}

		for (j = 1; j <= n; j++)
		{
			if (!visited[j])
			{
				mark += (mark < k);

				visited[j] = true;

				cnt--;

				dfs(j);
			}
		}

		fprintf(out, "Case #%d:", i + 1);

		if (mark < k)
		{
			fprintf(out, " Impossible");
		}

		else
		{
			for (j = 1; j <= n; j++)
			{
				fprintf(out, " %d", label[j]);
			}
		}

		fprintf(out, "\n");

		pre.clear();
		post.clear();

		for (j = 1; j <= n; j++)
		{
			graph[j].clear();
		}
	}

	return 0;
}