#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int findTheLongestSubstring(string s) {
		int n;

		n = s.size();

		int l[2][5] = { 0, };
		char vowel[5] = { 'a','e','i','o','u' };

		for (int i = 0; i < 5; i++) {

			for (int j = 0; j < n; j++) {
				if (s[j] == vowel[i]) {
					l[1][i] = j + 1;

					break;
				}
			}
		}

		int bit[5] = { 0, };

		int lmax = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				if (s[i] == vowel[j]) {
					bit[j] = !bit[j];

					break;
				}
			}

			int left = 0;

			for (int j = 0; j < 5; j++) {
				if (l[bit[j]][j] > left) {
					left = l[bit[j]][j];
				}
			}

			if (i - left + 1 > lmax) {
				lmax = i - left + 1;
			}
		}

		return lmax;
	}
};

int main()
{
	Solution s;

	s.findTheLongestSubstring("tyrwpvlifrgjghlcicyocusukhmjbkfkzsjhkdrtsztchhazhmcircxcauajyzlppedqyzkcqvffyeekjdwqtjegerxbyktzvrxwgfjnrfbwvhiycvoznriroroamkfipazunsabwlseseeiimsmftchpafqkquovuxhhkpvphwnkrtxuiuhbcyqulfqyzgjjwjrlfwwxotcdtqsmfeingsxyzbpvmwulmqfrxbqcziudixceytvvwcohmznmfkoetpgdntrndvjihmxragqosaauthigfjergijsyivozzfrlpndygsmgjzdzadsxarjvyxuecqlszjnqvlyqkadowoljrmkzxvspdummgraiutxxxqgotqnxwjwfotvqglqavmsnmktsxwxcpxhuujuanxueuymzifycytalizwnvrjeoipfoqbiqdxsnclcvoafqwfwcmuwitjgqghkiccwqvloqrxbfjuxwriltxhmrmfpzitkwhitwhvatmknyhzigcuxfsosxetioqfeyewoljymhdwgwvjcdhmkpdfbbztaygvbpwqxtokvidtwfdhmhpomyfhhjorsmgowikpsdgcbazapkmsjgmfyuezaamevrbsmiecoujabrbqebiydncgapuexivgvomkuiiuuhhbszsflntwruqblrnrgwrnvcwixtxycifdebgnbbucqpqldkberbovemywoaxqicizkcjbmbxikxeizmzdvjdnhqrgkkqzmspdeuoqrxswqrajxfglmqkdnlescbjzurknjklikxxqqaqdekxkzkscoipolxmcszbebqpsizhwsxklzulmjotkrqfaeivhsedfynxtbzdrviwdgicusqucczgufqnaslpwzjhgtphnovlrgz");
}