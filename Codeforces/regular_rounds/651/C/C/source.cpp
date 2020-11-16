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

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	vector<int> prime = { 2 };

	for (int i = 3; i < 100000; i += 2)
	{
		bool isprime = true;

		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
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

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<string> name = { "Ashishgup","FastestFinger" };

		int n;

		scanf("%d", &n);

		int winner = 0;

		if (n == 1)
		{
			winner = 1;
		}

		else if (n <= 3)
		{
			winner = 0;
		}
		
		else if (n % 2)
		{
			winner = 0;
		}

		else
		{
			int temp = n;
			int cnt = 0;

			while (!(temp % 2))
			{
				temp /= 2;

				cnt++;
			}

			if (temp == 1)
			{
				winner = 1;
			}

			else if (cnt > 1)
			{
				winner = 0;
			}

			else
			{
				bool isprime = true;

				for (int i = 0; i < prime.size() && prime[i] * prime[i] <= temp; i++)
				{
					if (!(temp%prime[i]))
					{
						isprime = false;

						break;
					}
				}

				if (isprime)
				{
					winner = 1;
				}

				else
				{
					winner = 0;
				}
			}
		}

		printf("%s\n", name[winner].c_str());
	}

	return 0;
}