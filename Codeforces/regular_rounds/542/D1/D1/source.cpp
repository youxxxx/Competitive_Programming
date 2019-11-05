#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int i, j;
	vector<int> mat[101];
	vector<int> temp[101];
	vector<int> full;
	int input1, input2;
	int idx[101];
	int sol[101];
	int emptycnt = 0;
	int cnt = 0;
	int target;
	int max = 0;
	int lmax = 0;
	int start = 0;
	int last;
	int ptr;
	queue<int> q;

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &input1, &input2);

		input1--;
		input2--;

		mat[input1].push_back((n + input2 - input1) % n);

		if (mat[input1].size() > max)
		{
			max = mat[input1].size();
		}
	}

	for (i = 0; i < n; i++)
	{
		sort(mat[i].begin(), mat[i].end());
	}

	for (i = 0; i < n; i++)
	{
		if (mat[i].size() == max)
		{
			full.push_back(i);

			idx[i] = full.size() - 1;

			/*
			if (i + mat[i][0] > lmax)
			{
				lmax = i + mat[i][0];
			}
			*/

			last = i;
		}
	}

	for (i = 0; i < full.size() - 1; i++)
	{
		if ((n + full[i] - last) % n + mat[full[i]][0] > lmax)
		{
			lmax = (n + full[i] - last) % n + mat[full[i]][0];
		}
	}

	sol[last] = lmax + n * (max - 1);

	if (n + mat[last][0] > max)
	{
		lmax = n + mat[last][0];
	}
	
	for (i = 0; i < full.size(); i++)
	{
		lmax -= (n + full[i] - last) % n;

		for (j = last + 1; j != full[i]; j = (j + 1) % n)
		{
			sol[j] = n * (max - 1)+(n + full[i] - j) % n;
		}

		if (n + mat[full[i]][0] > max)
		{
			lmax = n + mat[full[i]][0];
		}

		last = full[i];
	}
	/*
	for (i = 0; i < n; i++)
	{
		ptr = (last + i) % n;

		if (mat[ptr].size() == max)
		{
			lmax -= (n + ptr - start) % n;

			for (j = start; j <= ptr; j++)
			{
				sol[j] = n * (max)+(n + ptr - j) % n;
			}

			if (n + mat[ptr][0] > max)
			{
				lmax = n + mat[ptr][0];
			}

			start = i;
		}
	}
	*/

	for (i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}
	
	return 0;
}