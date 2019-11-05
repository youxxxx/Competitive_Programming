#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int i;
	int n;
	char input[100];
	string str, sol;
	char target;
	bool toggle = false;

	scanf("%s",input);
	str = input;

	toggle = (bool)(str.size() % 2);

	n = str.size();

	for (i = 0; i < n; i++)
	{
		if (!toggle)
		{
			target = str.back();
			str.pop_back();
		}

		else
		{
			target = str.front();
			str.erase(str.begin());
		}

		sol.insert(sol.begin(),target);

		toggle = !toggle;
	}

	printf("%s\n", sol.c_str());

	return 0;
}