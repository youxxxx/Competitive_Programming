#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int n, m;

	vector<string> a, b;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		char input[20];

		scanf("%s", input);

		string str;

		str = input;

		a.push_back(str);
	}

	for (int i = 0; i < m; i++)
	{
		char input[20];

		scanf("%s", input);

		string str;

		str = input;

		b.push_back(str);
	}

	int k;

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int year;

		scanf("%d", &year);

		printf("%s%s\n", a[(year + n - 1) % n].c_str(), b[(year + m - 1) % m].c_str());
	}

	return 0;
}