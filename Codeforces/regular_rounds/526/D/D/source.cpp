#include<cstdio>
#include<vector>

using namespace std;

vector<vector<pair<long long, long long>>> graph;
vector<pair<long long, long long>> emp;
vector<long long> gas;
long long input, input2, input3;
long long n;
long long start;
long long max = 0;

long long rec(long long cur, long long parent, long long stock)
{
	long long i;
	long long lmax = 0, lmax2 = 0;
	long long gr;
	long long rvalue;

	if (graph[cur].size() == 1 && parent != 0)
	{
		return 0;
	}

	for (i = 0; i < graph[cur].size(); i++)
	{
		if (graph[cur][i].first == parent)
		{
			continue;
		}

		gr = stock > gas[cur] ? stock : gas[cur];

		if (graph[cur][i].second + gr > lmax)
		{
			lmax = graph[cur][i].second + gr;
		}
		
		rvalue = rec(graph[cur][i].first, cur, gr + graph[cur][i].second);

		if (rvalue > lmax)
		{
			lmax = rvalue;
		}

		if (lmax > max)
		{
			max = lmax;
		}
	}

	return lmax;
}

int main()
{
	long long i, j;
	long long sol;

	scanf("%I64d", &n);

	graph.push_back(emp);
	gas.push_back(0);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		gas.push_back(input);

		graph.push_back(emp);
	}

	for (i = 1; i < n; i++)
	{
		scanf("%I64d %I64d %I64d", &input, &input2, &input3);

		graph[input].push_back(pair<long long, long long>(input2, gas[input2] - input3));
		graph[input2].push_back(pair<long long, long long>(input, gas[input] - input3));
	}

	for (i = 1; i <= n; i++)
	{
		if (graph[i].size() == 1)
		{
			break;
		}
	}

	sol = rec(i, 0, gas[i]);

	if (sol < 0)
	{
		sol = 0;
	}

	printf("%I64d\n", sol);
}