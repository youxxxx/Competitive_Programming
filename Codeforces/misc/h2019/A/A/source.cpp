#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string card;
	string hand;
	char input[4];
	int i;
	bool valid = false;

	scanf("%s", input);

	card = input;

	for (i = 0; i < 5; i++)
	{
		scanf("%s", input);

		hand = input;

		if (card[0] == hand[0] || card[1] == hand[1])
		{
			valid = true;
		}
	}

	if (valid)
	{
		printf("YES\n");
	}

	else
	{
		printf("NO\n");
	}

	return 0;
}

