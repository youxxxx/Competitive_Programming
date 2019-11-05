#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

int main()
{
	int n, i, q, m;
	vector<long long> arr, acc;
	vector<long long>::iterator low;
	set<long long> interv;
	set<long long>::iterator it, it2;
	int ptr;
	long long input, input2;
	long long term;
	long long cnt = 0;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		interv.insert(input);
	}

	m = interv.size() - 1;

	it = interv.begin();
	it++;

	while (it != interv.end())
	{
		it2 = it;
		it2--;

		arr.push_back(*it - *it2);

		it++;
	}

	sort(arr.begin(), arr.end());

	acc.push_back(0);

	for (i = 1; i <= m; i++)
	{
		acc.push_back(acc[i - 1] + arr[i - 1]);
	}

	scanf("%d", &q);

	for (i = 0; i < q; i++)
	{
		scanf("%I64d %I64d", &input, &input2);

		term = input2 - input + 1;

		/*
		it2 = it = interv.begin();

		it2++;

		cnt = 0;

		while (it2 != interv.end())
		{
			if (*it + term < *it2)
			{
				cnt += term + 1;
			}

			else
			{
				cnt += *it2 - *it;
			}
			
			it++;
			it2++;
		}
		*/
		
		low = lower_bound(arr.begin(), arr.end(), term);

		ptr = low - arr.begin();

		cnt = acc[ptr] + (m - ptr)*term + term;

		printf("%I64d ", cnt);
	}

	return 0;
}