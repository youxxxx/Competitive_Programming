#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

#define N 200000

long long tree[N + 2] = { 0, };

void add(long long idx, long long val)
{
	for (; idx <= N; idx += (idx&-idx))
	{
		tree[idx] += val;
	}
}

long long get(long long idx)
{
	long long rvalue = 0;

	for (; idx; idx -= (idx&-idx))
	{
		rvalue += tree[idx];
	}

	return rvalue;
}

long long psum(long long l, long long r)
{
	return get(r) - get(l);
}

long long ntree[N + 2] = { 0, };

void nadd(long long idx, long long val)
{
	for (; idx <= N; idx += (idx&-idx))
	{
		ntree[idx] += val;
	}
}

long long nget(long long idx)
{
	long long rvalue = 0;

	for (; idx; idx -= (idx&-idx))
	{
		rvalue += ntree[idx];
	}

	return rvalue;
}

long long npsum(long long l, long long r)
{
	return nget(r) - nget(l);
}

long long ltree[N + 2] = { 0, };

void ladd(long long idx, long long val)
{
	for (; idx <= N; idx += (idx&-idx))
	{
		ltree[idx] += val;
	}
}

long long lget(long long idx)
{
	long long rvalue = 0;

	for (; idx; idx -= (idx&-idx))
	{
		rvalue += ltree[idx];
	}

	return rvalue;
}

long long lpsum(long long l, long long r)
{
	return lget(r) - lget(l);
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;
	pair<int, long long> query[N + 1];
	map<long long, int> list;
	vector<long long> arr;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int sp;
		long long val;

		scanf("%d %lld", &sp, &val);

		query[i] = { sp,val };

		if (val > 0)
		{
			//list.insert(val);

			arr.push_back(val);
		}
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		list[arr[i]] = i + 1;
	}

	int lightning = 0;
	int spells = 0;

	for (int i = 0; i < n; i++)
	{
		int sp;
		long long val;

		sp = query[i].first;
		val = query[i].second;

		const int idx = list[abs(val)];

		if (val > 0)
		{
			nadd(idx, 1);
			add(idx, val);

			if (sp)
			{
				lightning++;

				ladd(idx, 1);
			}

			spells++;
		}

		else
		{
			nadd(idx, -1);
			add(idx, val);

			if (sp)
			{
				lightning--;

				ladd(idx, -1);
			}

			spells--;
		}

		long long sol = get(n);

		const int powerup = lightning - (spells == lightning);

		if (powerup <= 0)
		{
			printf("%lld\n", sol);

			continue;
		}

		int flight;

		{
			int lb = 0, ub = n;

			for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
			{
				long long num = lget(next);

				if (num == 0)
				{
					lb = next;
				}

				else
				{
					ub = next;
				}
			}

			flight = ub;
		}

		const long long temp = psum(flight - 1, flight);
		add(flight, -temp);
		nadd(flight, -1);

		int lb = 0, ub = n;

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
		{
			long long num = npsum(next, n);

			if (num == powerup)
			{
				lb = next;
				
				break;
			}

			if (num < powerup)
			{
				ub = next;
			}

			else
			{
				lb = next;
			}
		}

		printf("%lld\n", sol + psum(lb, n));

		add(flight, temp);
		nadd(flight, 1);
	}

	return 0;
}