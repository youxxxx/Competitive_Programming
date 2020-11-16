#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

#define N 200000

long long tree[N + 2] = { 0, };

void add(int idx, long long val)
{
	for (; idx <= N; idx += (idx&(-idx)))
	{
		tree[idx] += val;
	}
}

long long get(int idx)
{
	long long rvalue = 0;

	for (; idx; idx -= (idx&(-idx)))
	{
		rvalue += tree[idx];
	}

	return rvalue;
}

long long psum(int r, int l)
{
	return get(r) - get(l);
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m;

	scanf("%d %d", &n, &m);

	vector<int> arr;
	priority_queue<pair<long long, int>> diff;
	vector<int> tot;

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		arr.push_back(input);

		tot.push_back(input);
	}

	sort(arr.begin(), arr.end());
	pair<int, int> query[100001];
	map<int, int> list;
	int val[N + 1];

	for (int i = 0; i < m; i++)
	{
		int op, num;

		scanf("%d %d", &op, &num);

		query[i] = { op,num };

		tot.push_back(num);
	}

	sort(tot.begin(), tot.end());

	int acnt = 1;
	int prev = -1;

	for (int i = 0; i < n + m; i++)
	{
		if (tot[i] != prev)
		{
			prev = tot[i];

			val[acnt] = tot[i];

			list[tot[i]] = acnt++;
		}
	}

	long long curdiff[N + 1] = { 0, };
	priority_queue<long long, vector<long long>, greater<long long>> leftmost;
	priority_queue<long long> rightmost;

	for (int i = 0; i < n; i++)
	{
		long long cur = list[arr[i]];

		add(cur, 1);

		if (i > 0)
		{
			diff.push({ arr[i] - arr[i - 1],cur });

			curdiff[cur] = arr[i] - arr[i - 1];
		}

		leftmost.push(cur);
		rightmost.push(cur);
	}

	long long sum = arr[n - 1] - arr[0];

	if (n == 1)
	{
		printf("0\n");
	}

	else
	{
		printf("%lld\n", sum - diff.top().first);
	}

	long long cnt = n;

	for (int i = 0; i < m; i++)
	{
		const int op = query[i].first;
		const long long loc = query[i].second;
		const long long idx = list[query[i].second];

		if (op)
		{
			cnt++;

			add(idx, 1);

			const long long ret = get(idx);

			long long left = 0, right = 0;

			leftmost.push(idx);
			rightmost.push(idx);

			if (ret == cnt)
			{
				right = -1;
			}

			if (ret == 1)
			{
				left = -1;
			}

			if (left != -1)
			{
				int lb = 0, ub = idx - 1;

				for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
				{
					const long long ret2 = get(next);

					if (ret2 >= ret - 1)
					{
						ub = next;
					}

					else
					{
						lb = next;
					}
				}

				left = ub;
			}

			if (right != -1)
			{
				int lb = idx, ub = N;

				for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
				{
					const long long ret2 = get(next);

					if (ret2 < ret + 1)
					{
						lb = next;
					}

					else
					{
						ub = next;
					}
				}

				right = ub;
			}

			if (left != -1)
			{
				curdiff[idx] = val[idx] - val[left];

				diff.push({ val[idx] - val[left],idx });
			}

			if (right != -1)
			{
				curdiff[right] = val[right] - val[idx];

				diff.push({ val[right] - val[idx],right });
			}

			while (!diff.empty() && curdiff[diff.top().second] != diff.top().first)
			{
				diff.pop();
			}

			if (diff.empty())
			{
				printf("0\n");
			}

			else
			{
				printf("%lld\n", val[rightmost.top()] - val[leftmost.top()] - diff.top().first);
			}
		}

		else
		{
			cnt--;

			add(idx, -1);

			const long long ret = get(idx);

			long long left = 0, right = 0;

			while (!leftmost.empty() && !psum(leftmost.top(), leftmost.top() - 1))
			{
				leftmost.pop();
			}

			while (!rightmost.empty() && !psum(rightmost.top(), rightmost.top() - 1))
			{
				rightmost.pop();
			}

			if (ret == cnt)
			{
				right = -1;
			}

			if (ret == 0)
			{
				left = -1;
			}

			if (left != -1)
			{
				int lb = 0, ub = idx - 1;

				for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
				{
					const long long ret2 = get(next);

					if (ret2 >= ret)
					{
						ub = next;
					}

					else
					{
						lb = next;
					}
				}

				left = ub;
			}

			if (right != -1)
			{
				int lb = idx, ub = N;

				for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
				{
					const long long ret2 = get(next);

					if (ret2 < ret + 1)
					{
						lb = next;
					}

					else
					{
						ub = next;
					}
				}

				right = ub;
			}

			curdiff[idx] = 0;

			if (right != -1)
			{
				if (left == -1)
				{
					curdiff[right] = 0;
				}

				else
				{
					curdiff[right] = val[right] - val[left];

					diff.push({ val[right] - val[left],right });
				}
			}

			while (!diff.empty() && curdiff[diff.top().second] != diff.top().first)
			{
				diff.pop();
			}

			if (diff.empty())
			{
				printf("0\n");
			}

			else
			{
				printf("%lld\n", val[rightmost.top()] - val[leftmost.top()] - diff.top().first);
			}
		}
	}

	return 0;
}