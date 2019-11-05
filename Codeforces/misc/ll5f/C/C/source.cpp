#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first;
}

bool func2(const pair<long long, pair<long long, long long>> &a, const pair<long long, pair<long long, long long>> &b)
{
	return a.first < b.first || a.first == b.first&&a.second.first < b.second.first;
}

class comp
{
public:
	bool operator() (pair<long long, long long> &a, pair<long long, long long> &b)
	{
		return a.second > b.second;
	}
};

int main()
{
	int n, m;
	int i;
	vector<long long> v;
	vector<pair<long long, long long>> h;
	vector<pair<long long, pair<long long, long long>>> preproc;
	long long input;
	long long input1, input2;
	long long prev = 0;
	long long start, end;
	long long row;
	long long min;
	int ptr = 0;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, comp> pq;
	
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		v.push_back(input);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%I64d %I64d %I64d", &input1, &input2, &input);

		preproc.push_back(pair<long long, pair<long long, long long>>(input, pair<long long, long long>(input1 - 1, input2)));
	}

	sort(preproc.begin(), preproc.end(), func2);

	if (m == 0)
	{
		printf("0\n");

		return 0;
	}

	row = preproc[0].first;
	start = preproc[0].second.first;
	end = preproc[0].second.second;

	for (i = 1; i < m; i++)
	{
		if (preproc[i].first != row || preproc[i].second.first != end)
		{
			h.push_back(pair<long long, long long>(start, end));

			row = preproc[i].first;
			start = preproc[i].second.first;
			end = preproc[i].second.second;
		}

		else
		{
			end = preproc[i].second.second;
		}
	}

	h.push_back(pair<long long, long long>(start, end));

	min = n + m;

	sort(v.begin(), v.end());
	sort(h.begin(), h.end(), func);

	while (ptr < h.size() && h[ptr].first == 0)
	{
		pq.push(h[ptr++]);
	}

	for (i = 0; i < n; i++)
	{
		while (!pq.empty() && pq.top().second < v[i])
		{
			pq.pop();
		}

		if (i + pq.size() < min)
		{
			min = i + pq.size();
		}

		while (ptr < h.size() && h[ptr].first <= v[i])
		{
			pq.push(h[ptr++]);
		}
	}

	while (!pq.empty() && pq.top().second < 1000000000)
	{
		pq.pop();
	}

	if (n + pq.size() < min)
	{
		min = n + pq.size();
	}

	printf("%I64d\n", min);

	return 0;
}