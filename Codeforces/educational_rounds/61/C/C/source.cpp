#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

bool func(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first;
}

int main()
{
	int n, q;
	vector<pair<int,int>> arr;
	int input1, input2;
	int i, j;
	int level[5001] = { 0, };
	priority_queue<int, vector<int>, greater<int>> exit;
	int curlev = 1;
	int cur, prev = 0;
	int acc1[5001], acc2[5001];
	pair<int, int> interv1, interv2, temp;
	int over1, over2;
	int last = 0, sum;
	int cand;
	int lmax = 0;

	scanf("%d %d", &n, &q);

	for (i = 0; i < q; i++)
	{
		scanf("%d %d", &input1, &input2);

		arr.push_back(pair<int, int>(input1, input2));

		for (j = input1; j <= input2; j++)
		{
			level[j]++;
		}
	}

	sort(arr.begin(), arr.end(), func);

	sum = n;

	for (i = 0; i < q; i++)
	{
		if (arr[i].first > prev + 1)
		{
			sum -= arr[i].first - (prev + 1);
		}

		if (arr[i].second > prev)
		{
			prev = arr[i].second;
		}
	}

	sum -= n - prev;

	/*
	exit.push(0);

	for (i = 0; i < q; i++)
	{
		while (!exit.empty() && arr[i].first > exit.top())
		{
			cur = exit.top();
			exit.pop();
			curlev--;

			for (j = prev + 1; j <= cur; j++)
			{
				level[j] = curlev;
			}

			prev = cur;
		}

		exit.push(arr[i].second);
		curlev++;
	}
	*/

	acc1[0] = acc2[0] = 0;

	for (i = 1; i <= n; i++)
	{
		acc1[i] = acc1[i - 1] + (level[i] == 1);
		acc2[i] = acc2[i - 1] + (level[i] == 2);
	}

	for (i = 0; i < q - 1; i++)
	{
		for (j = i + 1; j < q; j++)
		{
			interv1 = arr[i];
			interv2 = arr[j];
			over1 = 1;
			over2 = 0;

			/*
			if (interv1.first > interv2.first)
			{
				temp = interv1;
				interv1 = interv2;
				interv2 = temp;
			}
			*/

			if (interv2.first <= interv1.second)
			{
				over1 = interv2.first;

				if (interv2.second < interv1.second)
				{
					over2 = interv2.second;
				}

				else
				{
					over2 = interv1.second;
				}
			}

			cand = sum - ((acc1[interv1.second] - acc1[interv1.first - 1]) + (acc1[interv2.second] - acc1[interv2.first - 1])) - (acc2[over2] - acc2[over1 - 1]);
			
			if (cand > lmax)
			{
				lmax = cand;
			}
		}
	}

	printf("%d\n", lmax);

	return 0;
}