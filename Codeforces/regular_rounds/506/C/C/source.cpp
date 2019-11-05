#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(pair<long long int, long long int> &a, pair<long long int, long long int> &b)
{
	return a.second < b.second || a.second == b.second&&a.second < b.second;
}

int main()
{
	int n;
	vector<pair<long long int,long long int>> seg;
	int input1, input2;
	long long int lb, ub;
	long long int max0 = 0, max1 = 0;
	long long int cur;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		seg.push_back(pair<int,int>(input1,input2));
	}

	sort(seg.begin(), seg.end());

	cur = seg[0].second;

	for (i = 1; i < n; i++)
	{

	}

	printf("%I64d", max1);

	return 0;
}