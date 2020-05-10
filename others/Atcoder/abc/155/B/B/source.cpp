#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	bool valid = true;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int input;

		scanf("%d", &input);

		if (!(input % 2) && input % 3 && input % 5)
		{
			valid = false;
		}
	}

	if(valid)
	{
		printf("APPROVED\n");
	}

	else
	{
		printf("DENIED\n");
	}

	return 0;
}