#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector < string > week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	char input[10];
	string str;

	scanf("%s", input);

	str = input;

	int day;

	for (int i = 0; i < 7; i++)
	{
		if (str == week[i])
		{
			day = i;

			break;
		}
	}

	printf("%d\n",(7 - day));

	return 0;
}