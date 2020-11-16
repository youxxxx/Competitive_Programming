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
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, k;
	vector<int> a, b, ab;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		int t, al, bl;

		scanf("%d %d %d", &t, &al, &bl);

		if (al&&bl)
		{
			ab.push_back(t);
		}

		else if (al)
		{
			a.push_back(t);
		}

		else if (bl)
		{
			b.push_back(t);
		}
	}

	if (ab.size() + a.size() < k || ab.size() + b.size() < k)
	{
		printf("-1\n");

		return 0;
	}

	sort(ab.begin(), ab.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int sol = 0;
	vector<int> books;

	for (int i = 0; i < k&&i < ab.size(); i++)
	{
		sol += ab[i];

		books.push_back(ab[i]);
	}

	int ptr = -1;

	for (int i = 0; i < k - books.size(); i++)
	{
		sol += a[i] + b[i];
		ptr = i;
	}

	int cur = sol;

	for (int i = ptr + 1; i < a.size() && i < b.size() && !books.empty(); i++)
	{
		cur += a[i] + b[i] - books.back();

		if (cur < sol)
		{
			sol = cur;
		}

		books.pop_back();
	}

	printf("%d\n", sol);

	return 0;
}