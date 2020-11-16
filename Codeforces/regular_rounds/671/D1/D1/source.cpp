#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	int arr[100001];
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(&arr[0], &arr[n]);

	int sol[100001];
	int cnt = 0;

	for (int i = 1; i < n; i+=2)
	{
		sol[i] = arr[cnt++];
	}

	for (int i = 0; i < n; i += 2)
	{
		sol[i] = arr[cnt++];
	}

	printf("%d\n", (n - 1) / 2);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", sol[i]);
	}

	printf("\n");

	return 0;
}