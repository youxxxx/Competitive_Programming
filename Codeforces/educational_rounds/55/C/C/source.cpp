#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

bool desc(const long long &a, const long long &b)
{
	return a > b;
}

int main()
{
	long long n, m;
	long long i;
	vector<long long> *cand;
	vector<pair<long long,long long>> valid;
	set<long long> subj;
	set<long long>::iterator it;
	long long input1, input2;
	long long max = 0, lmax, ptr;

	scanf("%I64d %I64d", &n, &m);

	cand = new vector<long long>[m + 1];

	for (i = 0; i < n; i++)
	{
		scanf("%I64d %I64d", &input1, &input2);

		subj.insert(input1);

		cand[input1].push_back(input2);
	}

	for (it=subj.begin();it!=subj.end();it++)
	{
		sort(cand[*it].begin(), cand[*it].end(), desc);

		if (cand[*it][0] > 0)
		{
			valid.push_back(pair<long long, long long>(*it, cand[*it][0]));

			max += cand[*it][0];
		}
	}

	if (valid.empty())
	{
		printf("0\n");

		return 0;
	}

	ptr = 1;

	while (!valid.empty())
	{
		lmax = 0;

		for (i = valid.size() - 1; i >= 0; i--)
		{
			if (cand[valid[i].first].size() < ptr + 1 || valid[i].second + cand[valid[i].first][ptr] < 0)
			{
				valid.erase(valid.begin() + i);
			}

			else
			{
				valid[i].second += cand[valid[i].first][ptr];

				lmax += valid[i].second;
			}
		}

		if (lmax > max)
		{
			max = lmax;
		}

		ptr++;
	}

	printf("%I64d\n", max);

	return 0;
}