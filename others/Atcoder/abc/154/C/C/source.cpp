#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	bool dup = false;
	int n;
	set<int> list;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		set<int>::iterator ret;

		int input;

		scanf("%d", &input);

		ret = list.find(input);

		if (ret == list.end())
		{
			list.insert(input);
		}

		else
		{
			dup = true;
		}
	}

	if (dup)
	{
		printf("NO\n");
	}

	else
	{
		printf("YES\n");
	}

	return 0;
}