#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int main()
{
	char input[100001];
	int n;
	string str;
	int l = 0, r = 0;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'L')
		{
			l++;
		}

		else
		{
			r++;
		}
	}

	printf("%d\n", l + r + 1);

	return 0;
}