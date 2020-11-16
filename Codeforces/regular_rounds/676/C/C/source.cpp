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

	char input[100001];

	scanf("%s", input);

	const string str = input;

	const int n = str.size();
	int len = n;

	printf("4\n");
	printf("L 2\n");
	len++;
	printf("R %d\n", len - 1);
	len++;
	printf("R 2\n");
	len += len - 2;
	printf("R %d\n", len - 1);

	return 0;
}