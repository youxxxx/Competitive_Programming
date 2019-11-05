#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

struct food
{
	long long num;
	long long cost;
	int index;
};

bool func(const food &a, const food &b)
{
	return a.cost < b.cost || a.cost == b.cost&&a.index < b.index;
}

bool func2(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first < b.first;
}

int main()
{
	int n, m;
	vector<food> arr;
	vector<pair<int, int>> sheet;
	food emp;
	int i;
	long long sum = 0, input;
	int ptr = 0;
	bool empty = false;
	int order;
	long long amount, left;
	long long sub;
	int newidx;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		emp.num = input;
		emp.index = i;

		arr.push_back(emp);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr[i].cost = input;
	}

	sort(arr.begin(), arr.end(), func);
	
	for (i = 0; i < n; i++)
	{
		sheet.push_back(pair<int, int>(arr[i].index, i));
	}

	sort(sheet.begin(), sheet.end(), func2);

	for (i = 0; i < m; i++)
	{
		scanf("%d %I64d", &order, &amount);

		if (empty)
		{
			printf("0\n");

			continue;
		}

		newidx = sheet[order - 1].second;

		if (arr[newidx].num >= amount)
		{
			arr[newidx].num -= amount;

			printf("%I64d\n", arr[newidx].cost*amount);
		}

		else
		{
			left = amount;
			sum = 0;

			left -= arr[newidx].num;
			sum += arr[newidx].num*arr[newidx].cost;
			arr[newidx].num = 0;

			while (ptr < n)
			{
				sub = left < arr[ptr].num ? left : arr[ptr].num;

				left -= sub;
				arr[ptr].num -= sub;
				sum += arr[ptr].cost*sub;

				if (!left)
				{
					break;
				}

				ptr++;
			}

			if (ptr == n)
			{
				empty = true;

				printf("0\n");

				continue;
			}

			printf("%I64d\n", sum);
		}
	}

	return 0;
}