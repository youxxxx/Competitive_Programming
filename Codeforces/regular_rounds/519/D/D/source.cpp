#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	vector<int> arr[10];
	int *rev[10];
	vector<int> *seq;
	vector<int> cur;
	int input;
	int i, j, k, l;
	queue<int> q;
	long long sum = 0;
	int ptr;

	scanf("%d %d", &n, &m);

	seq = new vector<int>[n + 1];

	for (i = 0; i < m; i++)
	{
		rev[i] = new int[n + 1];

		arr[i].push_back(0);

		for (j = 0; j < n; j++)
		{
			scanf("%d", &input);
			
			arr[i].push_back(input);

			rev[i][input] = j + 1;
		}
	}
	/*
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			seq[arr[0][j]].push_back(arr[0][i]);
		}
	}

	for (i = 1; i < m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 1; k < seq[arr[i][j]].size() && j + k <= n; k++)
			{
				if (seq[arr[i][j]][k] != arr[i][j + k])
				{
					break;
				}
			}

			if (k < seq[arr[i][j]].size())
			{
				seq[arr[i][j]].erase(seq[arr[i][j]].begin() + k, seq[arr[i][j]].end());
			}
		}
	}
	*/

	for (i = 1; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			cur.push_back(arr[0][j]);
		}

		for (j = 1; j < m; j++)
		{
			ptr = rev[j][cur[0]];

			for(k=1;k<cur.size()&&ptr+k<=n;k++)
			{
				if (cur[k] != arr[j][ptr + k])
				{
					break;
				}
			}

			if (k < cur.size())
			{
				cur.erase(cur.begin() + k, cur.end());
			}
		}

		sum += (long long)(cur.size());

		cur.clear();
	}

	/*
	for (i = 1; i <= n; i++)
	{
		sum += (long long)(seq[i].size());
	}
	*/
	printf("%I64d", sum);

	return 0;
}