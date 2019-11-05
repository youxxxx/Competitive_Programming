#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(int &a,int &b)
{
	return a > b;
}

int main()
{
	vector<int> arr;
	vector<long long> partsum;
	int input;
	int t;
	int n;
	int i, j;
	long long cur;
	int cnt;

	scanf("%d", &t);

	for (j = 0; j < t; j++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);
		}

		//sort(arr.begin()+1, arr.end(), func);

		partsum.push_back(arr[0]);

		for (i = 1; i < n; i++)
		{
			partsum.push_back(partsum[i - 1] + (long long)arr[i]);
		}

		cur = 1;
		cnt = 0;

		while (cur < n)
		{
			cur += partsum[cur - 1];

			cnt++;
		}

		printf("%d\n", cnt);

		arr.clear();
		partsum.clear();
	}

	return 0;
}
