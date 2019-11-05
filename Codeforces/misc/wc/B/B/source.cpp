#include <string>
using namespace std;

int solution(string dirs)
{
	int answer;
	bool vpath[11][11] = { 0, };
	bool hpath[11][11] = { 0, };
	int vcoord = 5, hcoord = 5;
	int nextv, nexth;
	int vadd[4] = { 1, -1 , 0, 0 };
	int hadd[4] = { 0, 0, 1, -1 };
	int direction;
	int i;
	int cnt=0;

	for (i = 0; i < dirs.size(); i++)
	{
		switch (dirs[i])
		{
		case 'D':
			direction = 0;
			break;
		case 'U':
			direction = 1;
			break;
		case 'R':
			direction = 2;
			break;
		case 'L':
			direction = 3;
			break;
		}

		nextv = vcoord + vadd[direction];
		nexth = hcoord + hadd[direction];

		if (nextv >= 0 && nextv <= 10 && nexth >= 0 && nexth <= 10)
		{
			vcoord = nextv;
			hcoord = nexth;

			if (!(direction / 2) && !vpath[vcoord - !(direction % 2)][hcoord])
			{
				vpath[vcoord - !(direction % 2)][hcoord] = true;

				cnt++;
			}

			else if (direction / 2 && !hpath[vcoord][hcoord - !(direction % 2)])
			{
				hpath[vcoord][hcoord - !(direction % 2)] = true;

				cnt++;
			}
		}
	}

	answer = cnt;

	return answer;
}

int main()
{
	string input = "DDDDDDDDDDDDDDRRRRRRRRRRRRRRRRRRRRRRRRRRRUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUULLLLLLLLLLLLLLLLLLLLL";
	int answer;

	answer = solution(input);

	return 0;
}