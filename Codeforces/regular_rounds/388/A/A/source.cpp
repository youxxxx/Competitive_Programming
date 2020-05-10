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
	int n;

	scanf("%d", &n);

	vector<int> list;

	while (n > 3)
	{
		n -= 2;

		list.push_back(2);
	}

	list.push_back(n);

	printf("%d\n", list.size());

	for (int i = 0; i < list.size(); i++)
	{
		printf("%d ", list[i]);
	}

	return 0;
}
