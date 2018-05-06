#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static const auto ____ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {

public:
	string convert(string s, int numRows) {

		if (numRows == 1) return s;
		int sz = s.size();
		string part[numRows];

		int k = 0, c = 1;
		for (int i = 0; i < sz; ++i) {
			part[k].push_back(s[i]);
			if (k + c == numRows) 
				c = -1;
			else if (k + c == -1)
				c = 1;
			k += c;
		}

		for (int i = 1; i < numRows; ++i) 
			part[0] += part[i];
		
		return part[0];
	}
};

void test(string s, int n) {
	Solution solu;
	cout << solu.convert(s, n) << endl;
}


int main() {
	ifstream fin("in.txt");
	string s;
	int n;
	while (fin >> s >> n)
		test(s, n);

	return 0;
}
