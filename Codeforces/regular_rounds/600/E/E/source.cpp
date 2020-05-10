#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	int n, m;
	int left[100002], right[100002];
	int vacant[100002] = { 0, };
	vector<pair<int, int>> interv;

	memset(left, -1, sizeof(left));
	memset(right, -1, sizeof(right));

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int input1, input2;

		scanf("%d %d", &input1, &input2);

		interv.push_back(make_pair(input1 - input2, input1 + input2));
	}

	sort(interv.begin(), interv.end());

	int prev = 0;

	vector<int> remove;

	for (int i = 0; i < n; i++)
	{
		if (interv[i].first > prev + 1)
		{
			for (int j = prev + 1; j < interv[i].first; j++)
			{
				vacant[j] = 1;
			}
		}

		if (interv[i].second <= prev)
		{
			remove.push_back(i);
		}

		else
		{
			prev = interv[i].second;
		}
	}

	for (int i = remove.size() - 1; i >= 0; i--)
	{
		interv.erase(interv.begin() + remove[i]);
	}

	for (int i = prev + 1; i <= m; i++)
	{
		vacant[i] = 1;
	}

	int lb;

	bool full = true;

	for (int i = 1; i <= m; i++)
	{
		if (vacant[i])
		{
			full = false;

			lb = i;

			break;
		}
	}

	if (full)
	{
		printf("0\n");

		return 0;
	}

	int ub;

	for (int i = m; i >= 1; i--)
	{
		if (vacant[i])
		{
			ub = i;

			break;
		}
	}

	for (int i = 0; i < interv.size(); i++)
	{
		int start;

		start = lb;

		if (interv[i].first > lb)
		{
			int dist = abs(interv[i].first - lb);

			int otherside;

			otherside = interv[i].second + dist < ub ? interv[i].second + dist : ub;

			if (left[otherside] == -1 || dist < left[otherside])
			{
				left[otherside] = dist;
			}

			for (int j = lb; j <= otherside; j++)
			{
				if (left[j] == -1 || dist < left[j])
				{
					left[j] = dist;
				}
			}
		}

		for (int j = lb; j < interv[i].first; j++)
		{
			int dist = abs(interv[i].first - j);
			int otherside;

			otherside = interv[i].second + dist < ub ? interv[i].second + dist : ub;

			if (left[j] != -1)
			{
				if (left[otherside] == -1 || left[j] + dist < left[otherside])
				{
					left[otherside] = left[j] + dist;
				}
			}
		}

		for (int j = interv[i].second; j <= ub; j++)
		{
			int dist = abs(interv[i].second - j);
			int otherside;

			otherside = interv[i].first - dist > lb ? interv[i].first - dist : lb;

			if (otherside == lb)
			{
				if (left[j] == -1 || dist < left[j])
				{
					left[j] = dist;
				}
			}

			else if (left[otherside] != -1)
			{
				if (left[otherside] + dist < left[j])
				{
					left[j] = left[otherside] + dist;
				}
			}
		}
	}

	for (int i = interv.size() - 1; i >= 0; i--)
	{
		int start;

		start = ub;

		if (interv[i].second < ub)
		{
			int dist = abs(interv[i].second - ub);

			int otherside;

			otherside = interv[i].first - dist > lb ? interv[i].first - dist : lb;

			if (right[otherside] == -1 || dist < right[otherside])
			{
				right[otherside] = dist;
			}

			for (int j = otherside; j <= ub; j++)
			{
				if (right[j] == -1 || dist < right[j])
				{
					right[j] = dist;
				}
			}
		}

		for (int j = ub; j > interv[i].second; j--)
		{
			int dist = abs(interv[i].second - j);
			int otherside;

			otherside = interv[i].first - dist > lb ? interv[i].first - dist : lb;

			if (right[j] != -1)
			{
				if (right[otherside] == -1 || right[j] + dist < right[otherside])
				{
					right[otherside] = right[j] + dist;
				}
			}
		}

		for (int j = interv[i].first; j >= lb; j--)
		{
			int dist = abs(interv[i].second - j);
			int otherside;

			otherside = interv[i].second + dist < ub ? interv[i].second + dist : ub;

			if (otherside == ub)
			{
				if (right[j] == -1 || dist < right[j])
				{
					right[j] = dist;
				}
			}

			else if (right[otherside] != -1)
			{
				if (right[otherside] + dist < right[j])
				{
					right[j] = right[otherside] + dist;
				}
			}
		}
	}

	int lmin = 200000;

	left[0] = 0;
	right[m + 1] = 0;

	for (int i = 0; i <= m; i++)
	{
		if (left[i] != -1 && right[i + 1] != -1 && left[i] + right[i + 1] < lmin)
		{
			lmin = left[i] + right[i + 1];
		}
	}

	printf("%d\n", lmin);

	return 0;
}