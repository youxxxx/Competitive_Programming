#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int a[3];
	int i;
	vector<int> arr;
	int sol;

	scanf("%d %d %d", &a[0], &a[1], &a[2]);

	sort(&a[0], &a[3]);
	
	sol = a[2] - a[1] - a[0] + 1;

	if (sol < 0)
	{
		sol = 0;
	}

	printf("%d", sol);

	return 0;
}