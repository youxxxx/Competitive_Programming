#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int i;
	char input[60];
	string str, sol;
	int ptr = 0;

	scanf("%d %s", &n, input);
	str = input;

	m = (int)sqrt((double)n * 2.0);

	for (i = 0; i < m; i++)
	{
		sol.push_back(str[ptr]);
		
		ptr += (i + 1);
	}

	printf("%s\n", sol.c_str());

	return 0;
}