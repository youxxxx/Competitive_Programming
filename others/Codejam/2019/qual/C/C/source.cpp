#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b != 0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

bool func(pair<long long, int> &a, pair<long long, int> &b)
{
	return a.first < b.first;
}

bool func2(pair<char, int> &a, pair<char, int> &b)
{
	return a.second < b.second;
}

int main()
{
	int t, z;
	int n, l;
	int i;
	long long input1, input2;
	vector<long long> crypt;
	vector<pair<long long, int>> arr;
	vector<pair<char, int>> sol;
	long long base, base1, base2, prev;
	int idx;
	int cnt;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &l);

		for (i = 0; i < l; i++)
		{
			scanf("%I64d", &input1);

			crypt.push_back(input1);
		}

		idx = -1;

		while (++idx < l - 1 && crypt[idx] == crypt[idx + 1]);

		base = gcd(crypt[idx], crypt[idx + 1]);

		base1 = crypt[idx] / base;
		base2 = crypt[idx + 1] / base;

		arr.push_back(pair<long long, int>(base1, idx));

		arr.push_back(pair<long long, int>(base, idx + 1));

		arr.push_back(pair<long long, int>(base2, idx + 2));

		for (i = idx - 1; i >= 0; i--)
		{
			base1 = crypt[i] / base1;

			arr.insert(arr.begin(), pair<long long, int>(base1, i));
		}

		for (i = idx + 2; i < l; i++)
		{
			base2 = crypt[i] / base2;

			arr.push_back(pair<long long, int>(base2, i + 1));
		}

		sort(arr.begin(), arr.end(), func);

		sol.push_back(pair<char, int>('A', arr[0].second));

		prev = arr[0].first;

		cnt = 0;

		for (i = 1; i <= l; i++)
		{
			cnt += (arr[i].first != prev);

			sol.push_back(pair<char, int>('A' + (char)cnt, arr[i].second));

			prev = arr[i].first;
		}

		sort(sol.begin(), sol.end(), func2);

		printf("Case #%d: ", z + 1);

		for (i = 0; i <= l; i++)
		{
			printf("%c", sol[i].first);
		}

		printf("\n");

		crypt.clear();
		arr.clear();
		sol.clear();
	}

	return 0;
}