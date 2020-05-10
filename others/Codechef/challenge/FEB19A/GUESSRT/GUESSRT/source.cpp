#include<cstdio>
#include<vector>

#define PR 1000000007

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b)
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
	vector<long long> bits, mbits;
	long long n, k, m;
	long long i, j;
	long long temp, temp2;
	long long t, z;
	long long sol;
	long long p, q;
	long long div;
	long long pwn, pwn1;
	vector<long long> pvec, qvec;
	long long pleft, qleft;

	temp = PR - 2;

	while (temp)
	{
		bits.push_back(temp % 2);

		temp /= 2;
	}

	scanf("%lld", &t);

	for (z = 0; z < t; z++)
	{
		sol = 1;

		scanf("%lld %lld %lld", &n, &k, &m);

		if (n == 1)
		{
			printf("1\n");

			continue;
		}

		if (m == 1)
		{
			temp = n;

			for (i = 0; i < bits.size(); i++)
			{
				if (bits[i])
				{
					sol = (sol * temp) % PR;
				}

				temp = (temp*temp)%PR;
			}

			printf("%lld\n", sol);

			continue;
		}

		if (m == 2)
		{
			p = (n - 1) + (n + k);
			q = n*(n + k);
			
			div = gcd(p, q);

			p /= div;
			q /= div;

			temp = q;

			q = 1;

			for (i = 0; i < bits.size(); i++)
			{
				if (bits[i])
				{
					q = (q * temp) % PR;
				}

				temp = (temp*temp)%PR;
			}

			sol = (p*q) % PR;

			printf("%lld\n", sol);

			continue;
		}

		if (m % 2)
		{
			m = (m + 1) / 2;

			temp = m;

			while (temp)
			{
				mbits.push_back(temp % 2);

				temp /= 2;
			}

			pwn = 1;

			temp = n;

			for (i = 0; i < mbits.size(); i++)
			{
				if (mbits[i])
				{
					pwn = (pwn * temp) % PR;
				}

				temp = (temp*temp)%PR;
			}

			pwn1 = 1;

			temp = n-1;

			for (i = 0; i < mbits.size(); i++)
			{
				if (mbits[i])
				{
					pwn1 = (pwn1 * temp) % PR;
				}

				temp = (temp*temp)%PR;
			}

			p = (PR + pwn - pwn1) % PR;

			q = 1;

			temp = pwn;

			for (i = 0; i < bits.size(); i++)
			{
				if (bits[i])
				{
					q = (q * temp) % PR;
				}

				temp = (temp*temp)%PR;
			}

			mbits.clear();

			sol = (p*q) % PR;

			printf("%lld\n", sol);
		}

		else
		{
			m = m / 2;

			pleft = n + k - 1;
			qleft = n + k;

			temp = qleft;

			for (i = 0; i < m; i++)
			{
				div = gcd(n - 1, temp);

				if (div == 1)
				{
					break;
				}

				pvec.push_back((n - 1) / div);

				temp /= div;
			}

			qleft = temp;

			temp = pleft;

			for (i = 0; i < m; i++)
			{
				div = gcd(n, temp);

				if (div == 1)
				{
					break;
				}

				qvec.push_back(n / div);

				temp /= div;
			}

			pleft = temp;

			temp = m - pvec.size();

			while (temp)
			{
				mbits.push_back(temp % 2);

				temp /= 2;
			}

			p = pleft;

			temp = n - 1;

			for (i = 0; i < mbits.size(); i++)
			{
				if (mbits[i])
				{
					p = (p * temp) % PR;
				}

				temp = (temp * temp) % PR;
			}

			for (i = 0; i < pvec.size(); i++)
			{
				p = (p*pvec[i]) % PR;
			}

			mbits.clear();

			temp = m - qvec.size();

			while (temp)
			{
				mbits.push_back(temp % 2);

				temp /= 2;
			}

			q = qleft;

			temp = n;

			for (i = 0; i < mbits.size(); i++)
			{
				if (mbits[i])
				{
					q = (q * temp) % PR;
				}

				temp = (temp * temp) % PR;
			}

			for (i = 0; i < qvec.size(); i++)
			{
				q = (q*qvec[i]) % PR;
			}

			p = (PR + q - p) % PR;

			temp = q;

			q = 1;

			for (i = 0; i < bits.size(); i++)
			{
				if (bits[i])
				{
					q = (q * temp) % PR;
				}

				temp = (temp*temp) % PR;
			}

			mbits.clear();

			sol = (p*q) % PR;

			printf("%lld\n", sol);

			pvec.clear();
			qvec.clear();
		}
	}

	return 0;
}