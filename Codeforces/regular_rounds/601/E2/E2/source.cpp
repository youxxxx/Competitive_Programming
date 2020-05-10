#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long n;
	vector<long long> arr, val, org;
	long long cnt = 0;
	long long allval[1000001], allorg[1000001];
	vector<long long> prime;

	prime.push_back(2);

	for (long long i = 3; i < 1000000; i += 2)
	{
		bool isprime = true;

		for (long long j = 0; j < prime.size() && prime[j]*prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if (isprime)
		{
			prime.push_back(i);
		}
	}

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		allorg[i] = allval[i] = input;

		if (input)
		{
			cnt += input;

			arr.push_back(i);

			org.push_back(input);

			val.push_back(input);
		}
	}

	if (cnt == 1)
	{
		printf("-1\n");

		return 0;
	}

	long long sol = 999999999999999999;

	long long ub = (long long)sqrt((double)cnt);

	/*

	vector<long long> divd;

	for (long long i = 2; i <= ub; i++)
	{
		if (!(cnt%i))
		{
			long long chunk;

			chunk = i;

			long long start = -1;
			long long end;
			long long acc = 0;
			long long subt[1000001] = { 0, };
			long long left;
			long long cand = 0;

			for (long long j = 0; j < val.size(); j++)
			{
				val[j] = org[j] % chunk;

				allval[arr[j]] = allorg[arr[j]] % chunk;
			}

			for (long long j = 0; j < arr.size(); j++)
			{
				if (cand > sol)
				{
					break;
				}

 				if (start == -1)
				{
					start = j;
				}

				if (acc + val[j] - subt[j] >= chunk)
				{
					end = j;

					long long take;

					long long nextsub;

					take = (acc + val[j] - subt[j]) / chunk*chunk;

					left = (acc + val[j] - subt[j]) - take;

					nextsub = val[j] - left;

					subt[j] = left;

					if (start == end)
					{
						if (left)
						{
							start = j;

							acc = left;
						}

						else
						{
							start = -1;

							acc = 0;
						}
					}

					else
					{
						long long toadd, tosubt = 0;
						long long addcnt = 1, subtcnt = 0;
						long long cost = 0, locmin;
						
						toadd = val[start] - subt[start];

						for (long long k = start + 1; k <= end; k++)
						{
							tosubt += val[k] - subt[k];

							subtcnt++;

							cost += abs(arr[k] - arr[start])*(val[k] - subt[k]);
						}

						locmin = cost;

						for (long long k = arr[start] + 1; k <= arr[end]; k++)
						{
							cost = cost + toadd - tosubt;

							if (cost < locmin)
							{
								locmin = cost;
							}

							if (allval[k])
							{
								long long diffval;

								diffval = allval[k];

								if (k == arr[end])
								{
									diffval -= subt[end];
								}

								toadd += diffval;
								tosubt -= diffval;

								addcnt++;
								subtcnt--;
							}
						}

						cand += locmin;

						if (left)
						{
							start = j;

							acc = left;
						}

						else
						{
							start = -1;

							acc = 0;
						}
					}

					subt[j] = nextsub;
				}

				else
				{
					acc += val[j];
				}
			}

			if (cand < sol)
			{
				sol = cand;
			}

			divd.push_back(cnt / i);
		}
	}
	*/

	bool found = false;

	vector<long long> divd;
	long long temp;

	temp = cnt;

	for (long long i = 0; i < prime.size(); i++)
	{
		if (!(temp%prime[i]))
		{
			while (!(temp%prime[i]))
			{
				temp /= prime[i];
			}

			divd.push_back(prime[i]);
		}
	}

	if (temp != 1)
	{
		divd.push_back(temp);
	}

	for (long long i = 0; i < divd.size(); i++)
	{
		long long chunk;

		chunk = divd[i];

		if (cnt%chunk)
		{
			continue;
		}

		found = true;

		long long start = -1;
		long long end;
		long long acc = 0;
		long long subt[1000001] = { 0, };
		long long left;
		long long cand = 0;

		for (long long j = 0; j < val.size(); j++)
		{
			val[j] = org[j] % chunk;

			allval[arr[j]] = allorg[arr[j]] % chunk;
		}

		for (long long j = 0; j < arr.size(); j++)
		{
			if (cand > sol)
			{
				break;
			}

			if (start == -1)
			{
				start = j;
			}

			if (acc + val[j] - subt[j] >= chunk)
			{
				end = j;

				long long take;

				long long nextsub;

				take = (acc + val[j] - subt[j]) / chunk*chunk;

				left = (acc + val[j] - subt[j]) - take;

				nextsub = val[j] - left;

				subt[j] = left;

				if (start == end)
				{
					if (left)
					{
						start = j;

						acc = left;
					}

					else
					{
						start = -1;

						acc = 0;
					}
				}

				else
				{
					long long toadd, tosubt = 0;
					long long addcnt = 1, subtcnt = 0;
					long long cost = 0, locmin;

					toadd = val[start] - subt[start];

					for (long long k = start + 1; k <= end; k++)
					{
						tosubt += val[k] - subt[k];

						subtcnt++;

						cost += abs(arr[k] - arr[start])*(val[k] - subt[k]);
					}

					locmin = cost;

					for (long long k = arr[start] + 1; k <= arr[end]; k++)
					{
						cost = cost + toadd - tosubt;

						if (cost < locmin)
						{
							locmin = cost;
						}

						if (allval[k])
						{
							long long diffval;

							diffval = allval[k];

							if (k == arr[end])
							{
								diffval -= subt[end];
							}

							toadd += diffval;
							tosubt -= diffval;

							addcnt++;
							subtcnt--;
						}
					}

					cand += locmin;

					if (left)
					{
						start = j;

						acc = left;
					}

					else
					{
						start = -1;

						acc = 0;
					}
				}

				subt[j] = nextsub;
			}

			else
			{
				acc += val[j];
			}
		}

		if (cand < sol)
		{
			sol = cand;
		}
	}
	/*
	long long chunk;
	long long toadd, tosub;

	for (long long j = 0; j < val.size(); j++)
	{
		val[j] = org[j];

		allval[arr[j]] = allorg[arr[j]];
	}

	toadd = val[0];
	tosub = cnt - toadd;

	long long cand = 0;

	for (long long j = 0; j < arr.size(); j++)
	{
		cand += abs(arr[j] - arr[0])*val[j];
	}

	for (long long j = arr.front() + 1; j <= arr.back(); j++)
	{
		cand = cand + toadd - tosub;

		if (cand < sol)
		{
			sol = cand;
		}

		if (allval[j])
		{
			toadd += allval[j];
			tosub -= allval[j];
		}
	}

	if (cand < sol)
	{
		sol = cand;
	}
	*/

	printf("%lld\n", sol);

	return 0;
}