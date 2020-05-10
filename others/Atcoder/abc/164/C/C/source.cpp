#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	set<string> list;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		string str;
		char input[11];

		scanf("%s", input);
		str = input;

		list.insert(str);
	}

	printf("%d\n", list.size());

	return 0;
}