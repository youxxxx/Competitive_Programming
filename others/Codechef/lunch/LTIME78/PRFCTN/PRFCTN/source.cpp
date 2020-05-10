#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

bool func(const pair<pair<int,int>, pair<int, int>> &a, const pair<pair<int,int>, pair<int, int>> &b)
{
	return a.first.first > b.first.first;
}

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<int> arr;
		vector<pair<pair<int, int>, pair<int, int>>> task, org;
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			arr.push_back(input);
		}

		int prev;

		prev = arr[0];
		int left = 0;
		int cnt = 0;

		for (int i = 1; i < n; i++)
		{
			if (arr[i] != prev)
			{
				task.push_back({ { prev,cnt },{ left,i - 1 } });
				org.push_back({ { prev,cnt++ },{ left,i - 1 } });

				left = i;

				prev = arr[i];
			}
		}

		task.push_back({ { arr.back(),cnt },{ left,n - 1 } });
		org.push_back({ { arr.back(),cnt },{ left,n - 1 } });

		sort(task.begin(), task.end(),func);

		int sol = 0;

		for (int i = 0; i < task.size(); i++)
		{
			bool l = false, r = false;
			bool ldone = false, rdone = false;
			int curleft, curright, curval;
			int lr, rl;

			curval = org[task[i].first.second].first.first;
			curleft = org[task[i].first.second].second.first;
			curright = org[task[i].first.second].second.second;

			if (org[task[i].first.second].second.first > 0)
			{
				l = true;

				lr = arr[org[task[i].first.second - 1].second.second];
				//lr = org[task[i].first.second - 1].first.first;

				if (lr == curval)
				{
					ldone = true;
				}
			}

			if (org[task[i].first.second].second.second < n - 1)
			{
				r = true;

				rl = arr[org[task[i].first.second + 1].second.first];
				//rl = org[task[i].first.second + 1].first.first;

				if (rl == curval)
				{
					rdone = true;
				}
			}

			if (!l && !r)
			{
				continue;
			}

			if (!(!r&&ldone || !l&&rdone || l&&r&&lr == rl&&lr == curval))
			{
				sol++;
			}

			int newval;

			if (l && !r)
			{
				curleft = org[task[i].first.second - 1].second.first;
				org[task[i].first.second - 1].second.second = curright;

				newval = lr;
			}

			else if (r && !l)
			{
				curright = org[task[i].first.second + 1].second.second;
				org[task[i].first.second + 1].second.first = curleft;

				newval = rl;
			}	

			else if (l&&r)
			{
				if (lr == rl)
				{
					curleft = org[task[i].first.second + 1].second.first = org[task[i].first.second - 1].second.first;
					curright = org[task[i].first.second - 1].second.second = org[task[i].first.second + 1].second.second;

					newval = lr;
				}

				else if (lr > rl)
				{
					curleft = org[task[i].first.second - 1].second.first;
					org[task[i].first.second - 1].second.second = curright;

					newval = lr;
				}

				else
				{
					curright = org[task[i].first.second + 1].second.second;
					org[task[i].first.second + 1].second.first = curleft;

					newval = rl;
				}
			}

			org[task[i].first.second].second.first = curleft;
			org[task[i].first.second].second.second = curright;

			org[task[i].first.second].first.first = newval;
			arr[curleft] = newval;
			arr[curright] = newval;
		}

		printf("%d\n", sol);
	}

	return 0;
}