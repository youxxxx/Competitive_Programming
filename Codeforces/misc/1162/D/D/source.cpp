#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

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

int main()
{
	long long n, m;
	long long a, b;
	long long i, j;
	long long idx[50001];
	long long cnt = -1;
	vector<long long> type, emp;
	vector<vector<long long>> sector;
	set<long long> points;
	set<long long>::iterator it, it2;
	long long size;
	long long start, dist;
	long long lcm = 1;
	long long curl;

	freopen("input.txt", "r", stdin);

	scanf("%I64d %I64d", &n, &m);

	for (i = 0; i <= 50000; i++)
	{
		idx[i] = -1;
	}

	for (i = 0; i < m; i++)
	{
		scanf("%I64d %I64d", &a, &b);

		a--;
		b--;

		size = (n + (b - a)) % n < (n + (a - b)) % n ? (n + (b - a)) % n : (n + (a - b)) % n;

		if (size == (n + (b - a)) % n)
		{
			start = a;
		}

		else
		{
			start = b;
		}

		if (idx[size] == -1)
		{
			idx[size] = ++cnt;

			type.push_back(size);

			sector.push_back(emp);
		}

		sector[idx[size]].push_back(start);
	}

	for (i = 0; i < sector.size(); i++)
	{
		if (sector[i].size() == 1)
		{
			if (!(n % 2) && type[i] == n / 2)
			{
				lcm = lcm / gcd(lcm, n / 2)*(n / 2);

				continue;
			}

			printf("No\n");

			return 0;
		}

		/*
		if (n%sector[i].size() || (sector[i].size() == 1 && ((n % 2) || type[i] != n / 2)))
		{
			printf("No\n");

			return 0;
		}
		*/

		/*
		sort(sector[i].begin(), sector[i].end());

		curl = 1;

		for (j = 0; j < sector[i].size() - 1; j++)
		{
			dist = sector[i][j + 1] - sector[i][j];

			curl = curl / gcd(curl, dist)*dist;
		}

		dist = n + sector[i][0] - sector[i].back();

		curl = curl / gcd(curl, dist)*dist;
		*/

		points.clear();

		for (j = 0; j < sector[i].size(); j++)
		{
			points.insert(sector[i][j]);
			points.insert((sector[i][j] + type[i]) % n);
		}

		curl = 1;

		for (it = points.begin();; it++)
		{
			it2 = it;
			it2++;

			if (it2 == points.end())
			{
				break;
			}

			dist = *it2 - *it;

			curl = curl / gcd(curl, dist)*dist;
		}

		it2 = points.end();
		it2--;

		it = points.begin();

		dist = (n + *it - *it2) % n;

		curl = curl / gcd(curl, dist)*dist;

		lcm = lcm / gcd(lcm, curl)*curl;

		if (lcm > n)
		{
			printf("No\n");

			return 0;
		}
	} 

	if (lcm > n)
	{
		printf("No\n");

		return 0;
	}

	printf("Yes\n");

	return 0;
}