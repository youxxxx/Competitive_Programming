#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int cnt[100001] = { 0, };

		for (int i = 0; i < n; i++)
		{
			int val;

			scanf("%d", &val);

			cnt[val]++;
		}

		vector<pair<int,int>> arr;

		for (int i = 1; i <= n; i++)
		{
			if (cnt[i])
			{
				arr.push_back({ cnt[i], i });
			}
		}

		int lb = 1, ub = n;

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (ub + lb) / 2)
		{
			priority_queue<pair<int, int>> pq2;
			priority_queue<pair<int, int>> pq;
			queue<pair<int,pair<int, int>>> q;

			for (int i = 0; i < arr.size(); i++)
			{
				pq2.push(arr[i]);
			}

			bool valid = true;

			for (int i = 0; i < n; i++)
			{
				while (!q.empty() && q.front().first <= i - next)
				{
					pq.push(q.front().second);
					q.pop();
				}

				if (pq.empty())
				{
					if (pq2.empty())
					{
						valid = false;

						break;
					}

					const int left = pq2.top().first;
					const int num = pq2.top().second;
					pq2.pop();

					if (left != 1)
					{
						q.push({i,{left-1,num}});
					}
				}

				else
				{
					if (-pq.top().first > i - next)
					{
						if (pq2.empty())
						{
							valid = false;

							break;
						}

						const int left = pq2.top().first;
						const int num = pq2.top().second;
						pq2.pop();

						if (left != 1)
						{
							q.push({i,{left-1,num}});
						}
					}

					else if(pq2.empty() || pq.top().first > pq2.top().first)
					{
						const int left = pq.top().first;
						const int num = pq.top().second;
						pq.pop();

						if (left != 1)
						{
							q.push({i,{left-1,num}});
						}
					}

					else
					{
						const int left = pq2.top().first;
						const int num = pq2.top().second;
						pq2.pop();

						if (left != 1)
						{
							q.push({i,{left-1,num}});
						}
					}
				}
			}

			if (valid)
			{
				lb = next;
			}

			else
			{
				ub = next;
			}
		}

		printf("%d\n", lb - 1);
	}

	return 0;
}