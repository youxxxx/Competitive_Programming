#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

#define SIZE 100003

using namespace std;

class UndergroundSystem {
public:
	string hashtable[SIZE];

	int s2i(string str)
	{
		int n;
		int rvalue = 0;

		for (int i = 0; i < n; i++) {
			rvalue = (rvalue + str[i]) % SIZE;
			rvalue = rvalue * 31 % SIZE;
		}
	}

	void put(string str)
	{
		int key;

		key = s2i(str);

		while (!hashtable[key].empty())
		{
			if (hashtable[key] == str)
			{
				return;
			}

			key = (key + 1) % SIZE;
		}

		hashtable[key] = str;
	}

	string get(int key)
	{
		return hashtable[key];
	}

	unordered_map<pair<long long, long long>, pair<long long, long long>> list;
	pair<string, long long> loc[1000001];
	UndergroundSystem() {
	}

	void checkIn(int id, string stationName, int t) {
		loc[id].first = stationName;
		loc[id].second = t;
	}

	void checkOut(int id, string stationName, int t) {
		unordered_map<pair<long long, long long>, pair<long long, long long>>::iterator ret;

		ret = list.find({ loc[id].first,stationName });

		if (ret == list.end()) {
			list[{ loc[id].first, stationName}] = { (long long)(t - loc[id].second),1 };
		}

		else {
			ret->second.first += (long long)(t - loc[id].second);
			ret->second.second++;
		}
	}

	double getAverageTime(string startStation, string endStation) {
		unordered_map<pair<long long, long long>, pair<long long, long long>>::iterator ret;

		ret = list.find({ startStation,endStation });

		return (double)ret->second.first / (double)ret->second.second;
	}
};

int main()
{
	UndergroundSystem undergroundSystem;
	undergroundSystem.checkIn(45, "Leyton", 3);
	undergroundSystem.checkIn(32, "Paradise", 8);
	undergroundSystem.checkIn(27, "Leyton", 10);
	undergroundSystem.checkOut(45, "Waterloo", 15);
	undergroundSystem.checkOut(27, "Waterloo", 20);
	undergroundSystem.checkOut(32, "Cambridge", 22);
	undergroundSystem.getAverageTime("Paradise", "Cambridge");       // return 14.0. There was only one travel from "Paradise" (at time 8) to "Cambridge" (at time 22)
	undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.0. There were two travels from "Leyton" to "Waterloo", a customer with id=45 from time=3 to time=15 and a customer with id=27 from time=10 to time=20. So the average time is ( (15-3) + (20-10) ) / 2 = 11.0
	undergroundSystem.checkIn(10, "Leyton", 24);
	undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.0
	undergroundSystem.checkOut(10, "Waterloo", 38);
	undergroundSystem.getAverageTime("Leyton", "Waterloo");

	return 0;
}