#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first || a.first == b.first && a.second < b.second;
}

int main()
{
	long long n, m;
	vector<long long> val;
	vector<vector<pair<long long, long long>>> sp;
	vector<pair<long long, long long>> emp;
	vector<pair<long long, long long>> sorted;
	long long ptr = 0;
	bool visited[200001] = { false, };
	long long i, j;
	long long input1, input2, input3;
	long long sum = 0;
	set<long long> tree;
	set<long long>::iterator it;
	long long min, min2, midx, midx2;
	

	scanf("%I64d %I64d", &n, &m);

	val.push_back(0);
	sp.push_back(emp);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input1);

		val.push_back(input1);
		sp.push_back(emp);
		sorted.push_back(pair<long long, long long>(input1, i + 1));
	}

	sort(sorted.begin(), sorted.end(), func);

	for (i = 0; i < m; i++)
	{
		scanf("%I64d %I64d %I64d", &input1, &input2, &input3);

		if (input3 < val[input1] + val[input2])
		{
			sp[input1].push_back(pair<long long, long long>(input2, input3));
			sp[input2].push_back(pair<long long, long long>(input1, input3));
		}
	}

	visited[sorted[0].second] = true;
	tree.insert(sorted[0].second);

	for (i = 0; i < n - 1; i++)
	{
		min = min2 = 2000000000001;

		for (it = tree.begin(); it != tree.end(); it++)
		{
			for (j = 0; j < sp[*it].size(); j++)
			{
				if (!visited[sp[*it][j].first] && sp[*it][j].second < min)
				{
					min = sp[*it][j].second;

					midx = sp[*it][j].first;
				}
			}
		}
		
		while (visited[sorted[ptr].second])
		{
			ptr++;
		}

		if (sorted[0].first + sorted[ptr].first < min)
		{
			min = sorted[0].first + sorted[ptr].first;

			midx = sorted[ptr].second;
		}

		visited[midx] = true;

		tree.insert(midx);

		sum += min;
	}

	printf("%I64d\n", sum);

	return 0;
}