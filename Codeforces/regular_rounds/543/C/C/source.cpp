#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

class comp
{
public:

	bool operator() (const pair<int,int> &a, const pair<int, int> &b) const
	{
		return a.first > b.first;
	}
};

int main()
{
	int n, k;
	vector<int> arr;
	priority_queue<pair<int, int>,vector<pair<int,int>>,comp> pq, temp;
	pair<int, int> cur, cur2;
	int input;
	int elapsed = 0;
	int percentage;
	int done = 0;
	int i, j;
	int cnt = 0;
	bool interesting[1001] = { false, };
	vector<pair<int,int>> complete;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);
	}

	for (i = 0; i < k&&i < n; i++)
	{
		pq.push(pair<int, int>(arr[i], i));
	}

	for (i = 0; i < n - k; i++)
	{
		if (pq.size() < k)
		{
			pq.push(pair<int, int>(arr[i + k] + elapsed, i + k));

			continue;
		}

		percentage = (int)((double)done / (double)n*100.0 + 0.5);

		cur = pq.top();
		pq.pop();

		complete.push_back(cur);

		while (!pq.empty() && pq.top().first == cur.first)
		{
			cur = pq.top();
			pq.pop();

			complete.push_back(cur);
		}

		if (percentage)
		{
			for (j = 0; j < complete.size(); j++)
			{
				if (percentage > arr[complete[j].second] - (complete[j].first - elapsed) && percentage <= arr[complete[j].second])
				{
					interesting[complete[j].second] = true;
				}
			}
		}

		temp = pq;

		while (!temp.empty())
		{
			cur2 = temp.top();
			temp.pop();

			if (percentage > (arr[cur2.second] - (cur2.first - elapsed)) && percentage <= arr[cur2.second] - (cur2.first - cur.first))
			{
				interesting[cur2.second] = true;
			}
		}

		done += complete.size();

		complete.clear();

		elapsed = cur.first;

		pq.push(pair<int, int>(arr[i + k] + elapsed, i + k));
	}

	while (!pq.empty())
	{
		percentage = (int)((double)done / (double)n*100.0 + 0.5);

		cur = pq.top();
		pq.pop();

		complete.push_back(cur);

		while (!pq.empty() && pq.top().first == cur.first)
		{
			cur = pq.top();
			pq.pop();

			complete.push_back(cur);
		}

		if (percentage)
		{
			for (j = 0; j < complete.size(); j++)
			{
				if (percentage > arr[complete[j].second] - (complete[j].first - elapsed) && percentage <= arr[complete[j].second])
				{
					interesting[complete[j].second] = true;
				}
			}
		}

		temp = pq;

		while (!temp.empty())
		{
			cur2 = temp.top();
			temp.pop();

			if (percentage > (arr[cur2.second] - (cur2.first - elapsed)) && percentage <= arr[cur2.second] - (cur2.first - cur.first))
			{
				interesting[cur2.second] = true;
			}
		}

		done += complete.size();

		complete.clear();

		elapsed = cur.first;
	}

	for (i = 0; i < n; i++)
	{
		cnt += (int)interesting[i];
	}

	printf("%d\n", cnt);
	
 	return 0;
}