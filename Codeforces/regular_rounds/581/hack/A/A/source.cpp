#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;

	while (cin >> s)
	{
		int sum = 0, cnt = 0;

		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == '1')
			{
				cnt = 1;

				break;
			}
		}

		sum = (s.size() - 1) / 2;
		if (cnt == 1 || (s.size() - 1) % 2 == 1)
		{
			sum++;
		}

		cout << sum << endl;
	}

	return 0;
}