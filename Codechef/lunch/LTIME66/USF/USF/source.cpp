#include<cstdio>
#include<vector>

using namespace std;

int num(vector<vector<int>> fact, vector<int> prime, vector<int> use, int ptr, int cur, int lim)
{
	int max = 0;
	int cand;
	int i, j;
	vector<vector<int>> temp, temp2;
	bool divisible;

	if (ptr == prime.size() || fact.empty())
	{
		return 0;
	}

	//if (cur*prime[ptr] <= lim)
	if (prime[ptr] <= lim)
	{
		//max = num(fact, prime, use, ptr + 1, cur, lim);

		/*
		cur *= prime[ptr];

		for (i = 0; i < arr.size(); i++)
		{
			if (!(arr[i] % cur))
			{
				temp.push_back(arr[i] / cur);
			}
		}
		*/

		for (i = 0; i < fact.size(); i++)
		{
			divisible = false;

			for (j = 0; j < fact[i].size(); j++)
			{
				if (fact[i][j] == prime[ptr])
				{
					fact[i].erase(fact[i].begin() + j);

					temp.push_back(fact[i]);

					divisible = true;

					break;
				}
			}

			if (!divisible)
			{
				temp2.push_back(fact[i]);
			}
		}

		if (!temp2.empty())
		{
			//max = num(temp2, prime, use, ptr + 1, cur, lim);
		}

		use.push_back(ptr);

		if (!temp.empty())
		{
			if (!temp[0].empty() && temp[0][0] > 316)
			{
				for (i = 0; i < (int)temp.size() - 1; i++)
				{
					if (temp[i].empty() || temp[i + 1].empty() || temp[i].back() != temp[i + 1].back())
					{
						break;
					}
				}

				if (i == temp.size() - 1)
				{
					cand = (use.size() + 1)*temp.size();
				}

				else
				{
					cand = (use.size())*temp.size();
				}

				if (cand > max)
				{
					max = cand;
				}
			}

			else
			{
				cand = (use.size())*temp.size();

				if (cand > max)
				{
					max = cand;
				}

				for (i = temp.size() - 1; i >= 0; i--)
				{
					if (temp[i].empty())
					{
						temp.erase(temp.begin() + i);
					}
				}

				//cand = num(arr, prime, use, ptr + 1, cur, lim);
				cand = num(temp, prime, use, ptr + 1, cur, lim);

				if (cand > max)
				{
					max = cand;
				}
			}
		}

		if (!temp2.empty())
		{
			use.pop_back();

			temp.insert(temp.end(), temp2.begin(), temp2.end());

			cand = num(temp, prime, use, ptr + 1, cur, lim);

			if (cand > max)
			{
				max = cand;
			}
		}

		return max;
	}

	return 0;
}

int main()
{
	int t, z;
	int n, i, j;
	vector<int> prime;
	bool isprime;
	vector<int> arr, emp;
	vector<vector<int>> fact;
	int lmax;
	int input;

	prime.push_back(2);

	for (i = 3; i <= 316; i += 2)
	{
		isprime = true;

		for (j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
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
	/*
	for (i = 317; i < 100000; i += 2)
	{
		for (j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}

			if (isprime)
			{
				prime.push_back(i);
			}
		}

		if (isprime)
		{
			prime.push_back(i);
		}
	}
	*/

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		lmax = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);

			fact.push_back(emp);

			for (j = 0; j < prime.size() && prime[j] <= arr[i]; j++)
			{
				/*
				while (!(arr[i] % prime[j]) && !(arr[i] / prime[j] % prime[j]))
				{
					arr[i] /= prime[j];
				}
				

				if (arr[i] > lmax)
				{
					lmax = arr[i];
				}
				*/

				if (!(arr[i] % prime[j]))
				{
					fact[i].push_back(prime[j]);

					while (!(arr[i] % prime[j]))
					{
						arr[i] /= prime[j];
					}
				}
			}

			if (!fact[i].empty() && fact[i].back() > lmax)
			{
				lmax = fact[i].back();
			}

			if (arr[i] != 1)
			{
				fact[i].push_back(arr[i]);
			}
		}

		printf("%d\n", num(fact, prime, emp, 0, 1, lmax));

		arr.clear();
		fact.clear();
	}

	return 0;
}