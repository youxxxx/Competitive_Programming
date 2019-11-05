#include<cstdio>
#include<vector>

using namespace std;

long long int cnt;
int n;
vector<int>* graph;

void dfs(int target, int parent, int acc)
{
	int i, next;
	int newa;

	newa = acc + 1;

	cnt += newa / 3;

	newa -= newa / 3 * 2;

	for (i = 0; i < graph[target].size();i++)
	{
		next = graph[target][i];

		if (next == parent)
		{
			continue;
		}

		dfs(next, target, newa);
	}
}

int main()
{
	int n;
	int i;
	int input1, input2;
	
	scanf("%d", &n);

	cnt = 0;

	graph = new vector<int>[n+1];

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &input1, &input2);

		graph[input1].push_back(input2);
		graph[input2].push_back(input1);
	}

	for (i = 0; i < graph[1].size(); i++)
	{
		dfs(graph[1][i], 1, 0);
	}

	printf("%I64d", cnt);

	return 0;
}