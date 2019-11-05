#include<cstdio>
#include<string>
#include<queue>

using namespace std;

int main()
{
	int n, q, k;
	char input[100001];
	string str;
	int i, z;
	queue<int> d, m, sub;
	long long sum, offset;


	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	scanf("%d", &q);

	for (z = 0; z < q; z++)
	{
		scanf("%d", &k);

		sum = 0;

		offset = 0;

		for (i = 0; i < n; i++)
		{
			while (!d.empty() && i - d.front() >= k)
			{
				d.pop();

				offset += m.front();

				m.pop();
			}

			while (!m.empty() && m.front() < d.front())
			{
				m.pop();
			}

			if (input[i] == 'D')
			{
				d.push(i);

				offset -= m.size();

				sub.push(m.size());
			}

			else if (input[i] == 'M')
			{
				m.push(i);
			}

			else if (input[i] == 'C')
			{
				sum += (long long)d.size() * (long long)m.size() + offset;
			}
 
		}

		printf("%lld\n", sum);

		while (!d.empty())
		{
			d.pop();
		}

		while (!m.empty())
		{
			m.pop();
		}

		while (!sub.empty())
		{
			sub.pop();
		}
	}

	return 0;
}