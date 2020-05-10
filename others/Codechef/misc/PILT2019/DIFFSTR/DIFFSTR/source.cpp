#include<cstdio>
#include<string>
#include<vector>

using namespace std;

class sheet
{
public:
	long long neg[401][26];
	long long tot[401][26];

	sheet()
	{
		long long i, j;

		for (i = 0; i <= 400; i++)
		{
			for (j = 0; j < 26; j++)
			{
				neg[i][j] = 0;
				tot[i][j] = 0;
			}

		}
	}

	sheet(const sheet &other)
	{
		long long i, j;

		for (i = 0; i <= 400; i++)
		{
			for (j = 0; j < 26; j++)
			{
				neg[i][j] = other.neg[i][j];
				tot[i][j] = other.tot[i][j];
			}

		}
	}
};

int main()
{
	long long n, m, q;
	vector<string> arr;
	vector<sheet> inf;
	sheet emp, real;
	char input[401];
	string str;
	long long sum;
	long long let;
	long long i, j, k;
	long long l, r;

	scanf("%lld %lld", &n, &q);

	arr.push_back(str);
	inf.push_back(emp);

	for (i = 1; i <= n; i++)
	{
		scanf("%lld %s", &m, input);

		str = input;

		arr.push_back(str);

		emp = inf[i - 1];

		for (j = 0; j < m; j++)
		{
			for (k = 0; k < str[j]-'a'; k++)
			{
				emp.neg[j][k]++;
			}

			emp.tot[j][str[j] - 'a']++;
		}

		inf.push_back(emp);
	}

	for (i = 0; i < q; i++)
	{
		scanf("%lld %lld %s", &l, &r, input);

		str = input;

		sum = 0;

		m = str.size();

		for (j = 0; j < m; j++)
		{
			for (k = 0; k < 26; k++)
			{
				real.neg[j][k] = inf[r].neg[j][k] - inf[l - 1].neg[j][k];
				real.tot[j][k] = inf[r].tot[j][k] - inf[l - 1].tot[j][k];
			}
		}

		for (j = 0; j < m; j++)
		{
			let = 0;

			for (k = 0; k < str[j] - 'a'; k++)
			{
				sum -= real.tot[j][k] * k;

				let += real.tot[j][k];
			}

			for (k = str[j] - 'a'; k < 26; k++)
			{
				sum += real.tot[j][k] * k;

				let += real.tot[j][k];
			}

			sum += (let - real.neg[j][str[j] - 'a'] * 2)*(str[j] - 'a');
		}

		printf("%lld\n", sum);
	}

	return 0;
}