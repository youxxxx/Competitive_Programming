#include<cstdio>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main()
{
	int n, q, k;
	int i;
	int val;
	char *input;
	vector<int> cnt, max;
	vector<bool> a;
	string str;
	int offset = 0;
	int cur = 0;
	int lmax;
	int s;
	bool valid = false;
	bool orval = false;
	queue<int> seq;
	priority_queue<int> p;

	scanf("%d %d %d", &n, &q, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &val);

		a.push_back(bool(val));

		orval = orval || val;

		cnt.push_back(0);
	}

	cnt.push_back(0);

	input = new char[q + 1];

	scanf("%s", input);

	str = input;

	if (!orval)
	{
		for (i = 0; i < q; i++)
		{
			if (str[i] == '?')
			{
				printf("0\n");
			}
		}

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		if (!valid&&a[i])
		{
			valid = true;

			cur = i;
		}

		else if (valid && !a[i])
		{
			s = i - cur;

			seq.push(s);

			if (!cnt[s])
			{
				p.push(s);
			}

			cnt[s]++;

			valid = false;
		}
	}

	if (valid)
	{
		s = n - cur;

		seq.push(s);

		/*
		if (!cnt[s])
		{
			p.push(s);
		}

		cnt[s]++;

		valid = false;
		*/
	}

	lmax = 0;

	if (!p.empty())
	{
		lmax = p.top();
	}

	if (seq.back() > lmax)
	{
		lmax = seq.back();
	}

	if (lmax > k)
	{
		lmax = k;
	}

	max.push_back(lmax);

	for (i = 1; i < n; i++)
	{
		if (a[i - 1])
		{
			if (valid)
			{
				seq.back()++;
			}

			else
			{
				seq.push(1);
			}

			cnt[seq.front()]--;

			if (!p.empty() && !cnt[seq.front()]&&p.top()==seq.front())
			{
				p.pop();
			}

			cnt[--seq.front()]++;

			if (!seq.front())
			{
				seq.pop();
			}

			lmax = 0;

			if (!p.empty())
			{
				lmax = p.top();
			}

			if (seq.front() > lmax)
			{
				lmax = seq.front();
			}

			if (seq.back() > lmax)
			{
				lmax = seq.back();
			}

			if (lmax > k)
			{
				lmax = k;
			}

			valid = true;
		}

		else
		{
			if (valid)
			{
				if (!cnt[seq.back()])
				{
					p.push(seq.back());
				}

				cnt[seq.back()]++;
			}

			valid = false;
		}

		max.push_back(lmax);
	}

	for (i = 0; i < q; i++)
	{
		if (str[i] == '?')
		{
			printf("%d\n", max[offset]);
		}

		else
		{
			offset = (offset + n - 1) % n;
		}
	}

	return 0;
}