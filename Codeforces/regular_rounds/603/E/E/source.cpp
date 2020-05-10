#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

#define N 1000001

using namespace std;

class minmaxstack
{
public:
	int lmin;
	int lmax;
	int curval;
	stack<int> stk;
	int cnt[1000001] = { 0, };

	minmaxstack()
	{
		lmin = 0;
		lmax = 0;
		curval = 0;
	}

	int top()
	{
		return stk.top();
	}

	void push(int input)
	{
		curval += input;

		if (curval > lmax)
		{
			lmax = curval;
		}

		if (curval < lmin)
		{
			lmin = curval;
		}

		cnt[curval+500000]++;

		stk.push(input);
	}

	void pop()
	{
		int prevval;

		prevval = curval;

		curval -= stk.top();

		if (--cnt[prevval + 500000] == 0)
		{
			if (prevval == lmax&&curval < prevval)
			{
				lmax--;
			}

			if (prevval == lmin&&curval > prevval)
			{
				lmin++;
			}
		}

		stk.pop();
	}
};

int main()
{
	int cursor = 0, cursormax = 0;
	int n;
	char input[1000001];
	string str;
	minmaxstack left, right;

	//freopen("input.txt","r",stdin);

	scanf("%d", &n);
	scanf("%s", input);
	str = input;

	left.push(0);

	for (int i = 0; i < n; i++)
	{
		int prev, val, diff;

		switch (str[i])
		{
		case 'L':
			if (cursor > 0)
			{
				right.push(-left.top());
				left.pop();

				cursor--;
			}
			break;
		case 'R':
			if (cursor + 1 > cursormax)
			{
				left.push(0);

				cursormax++;
			}
			
			else
			{
				left.push(-right.top());
				right.pop();
			}

			cursor++;
			break;
		default:
			switch (str[i])
			{
			case '(':
				val = 1;
				break;
			case ')':
				val = -1;
				break;
			default:
				val = 0;
				break;
			}

			left.pop();
			left.push(val);
			break;
		}

		if (left.lmin >= 0 && right.lmin >= 0 && left.curval == right.curval)
		{
			printf("%d ", left.lmax > right.lmax ? left.lmax : right.lmax);
		}

		else
		{
			printf("-1 ");
		}
	}

	return 0;
}