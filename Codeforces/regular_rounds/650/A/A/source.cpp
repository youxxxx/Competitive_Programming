#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[101];
		string str;

		scanf("%s", input);
		str = input;

		string sol;

		const int n = str.size();

		for (int i = 0; i < n; i+=2)
		{
			sol.push_back(str[i]);
		}

		sol.push_back(str.back());

		printf("%s\n", sol.c_str());
	}

	return 0;
}