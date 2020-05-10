#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class CombinationIterator {
public:
	string str, org;
	int len;
	int ptr[15];
	int pptr;
	int n;
	bool valid;

	CombinationIterator(string characters, int combinationLength) {
		str = characters;
		len = combinationLength;
		for (int i = 0; i < combinationLength; i++) {
			ptr[i] = i;
		}
		pptr = 0;
		n = str.size();
		valid = false;
	}

	string next() {
		string rvalue;

		if (!valid)
		{
			valid = true;

			for (int i = 0; i < len; i++) {
				rvalue.push_back(str[ptr[i]]);
			}

			return rvalue;
		}

		for (int i = len - 1; i >= 0; i--) {
			if (ptr[i] != n - len + i) {

				ptr[i]++;

				for (int j = i + 1; j < len; j++) {
					ptr[j] = ptr[j - 1] + 1;
				}

				break;
			}
		}

		for (int i = 0; i < len; i++) {
			rvalue.push_back(str[ptr[i]]);
		}

		return rvalue;
	}

	bool hasNext() {
		return (ptr[0] != (n - len));
	}
};

int main()
{
	CombinationIterator *iterator = new CombinationIterator("abc", 2); // creates the iterator->

	iterator->next(); // returns "ab"
	iterator->hasNext(); // returns true
	iterator->next(); // returns "ac"
	iterator->hasNext(); // returns true
	iterator->next(); // returns "bc"
	iterator->hasNext(); // returns false

	return 0;
}