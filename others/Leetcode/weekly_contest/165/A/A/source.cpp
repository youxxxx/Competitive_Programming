#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
	string tictactoe(vector<vector<int>>& moves)
	{
		int board[3][3];

		memset(board, -1, sizeof(board));

		for (int i = 0; i < moves.size(); i++)
		{
			board[moves[i][0]][moves[i][1]] = i % 2;
		}

		for (int i = 0; i < 3; i++)
		{
			int sum[2] = { 0, };

			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] >= 0)
				{
					sum[board[i][j]]++;
				}
			}

			if (sum[0] == 3)
			{
				return "A";
			}

			if (sum[1] == 3)
			{
				return "B";
			}
		}

		for (int i = 0; i < 3; i++)
		{
			int sum[2] = { 0, };

			for (int j = 0; j < 3; j++)
			{
				if (board[j][i] >= 0)
				{
					sum[board[j][i]]++;
				}
			}

			if (sum[0] == 3)
			{
				return "A";
			}

			if (sum[1] == 3)
			{
				return "B";
			}
		}

		string sol;

		if (board[0][0] >= 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		{
			sol.push_back(board[0][0] + 'A');

			return sol;
		}

		if (board[0][2] >= 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			sol.push_back(board[0][2] + 'A');

			return sol;
		}

		if (moves.size() == 9)
		{
			return "Draw";
		}

		return "Pending";
	}
};