#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[100001];
		string str;

		scanf("%s", input);

		str = input;

		switch (str.back())
		{
		case 'o':
			printf("FILIPINO\n");
			break;
		case 'u':
			printf("JAPANESE\n");
			break;
		default:
			printf("KOREAN\n");
			break;
		}
	}

	return 0;
}