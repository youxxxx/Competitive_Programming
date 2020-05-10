#include<cstdio>
#include<string>

using namespace std;

string res(string input)
{
	char ans;
	string left, right, output;
	int lptr = 0, rptr = 0;
	
	if (input.size() < 2)
	{
		return input;
	}	

	left = res(input.substr(0, input.size() / 2));
	right = res(input.substr(left.size(), input.size() - left.size()));

	while (lptr < left.size() && rptr < right.size())
	{
		printf("? %c %c\n", left[lptr], right[rptr]);
		fflush(stdout);

		scanf(" %c", &ans);

		if (ans == '<')
		{
			output.push_back(left[lptr++]);
		}

		else
		{
			output.push_back(right[rptr++]);
		}
	}

	if (lptr < left.size())
	{
		output += left.substr(lptr,left.size()-lptr);
	}

	else
	{
		output += right.substr(rptr, right.size() - rptr);
	}

	return output;
}

int main()
{
	int n, q;
	string str;
	int i;

	scanf("%d %d", &n, &q);

	for (i = 0; i < n; i++)
	{
		str.push_back('A' + (char)i);
	}

	printf("! %s\n", res(str).c_str());
	fflush(stdout);

	return 0;
}