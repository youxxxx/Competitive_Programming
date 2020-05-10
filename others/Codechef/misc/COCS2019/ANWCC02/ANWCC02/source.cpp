#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool func(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	int n, m;
	int i;
	vector<int> vault;
	vector<int> key;
	vector<int> val;
	int input;
	long long res = 0;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		vault.push_back(input);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d", &input);

		key.push_back(input);

		val.push_back(0);
	}

	for (i = 0; i < n; i++)
	{
		val[i%m] += vault[i];
	}

	sort(val.begin(), val.end(), func);

	sort(key.begin(), key.end(), func);

	for (i = 0; i < m; i++)
	{
		res += val[i] * key[i];
	}

	printf("%lld\n", res);

	return 0;
}