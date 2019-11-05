#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	vector<vector<int>> tree;
	int n, m;
	int i;
	int input1, input2;
	vector<int> cur;
	vector < vector <long long>> q;
	vector<long long> cur2;

	scanf("%d", &n);

	for (i = 0; i <= n; i++)
	{
		tree.push_back(cur);
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &input1, &input2);

		tree[input1].push_back(input2);
		tree[input2].push_back(input1);
	}

	scanf("%d", &m);

	for (i = 1; i <= n; i++)
	{

	}
}
