#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	
public:
	string longestPalindrome(string s) {
		
		int slen = s.size();
		int firstpos = 0, maxLen = 0;
		for (int i = 0; i < slen; ++i) {

			int left = i;
			int right = i;
			while (right < slen && s[right] == s[right+1]) 
				++right;
			i = right;
			while (left > 0 && right < slen - 1
					&& s[left-1] == s[right+1]) {
				--left; 
				++right;
			}
				
			if (right - left + 1 > maxLen) {
				maxLen = right - left + 1;
				firstpos = left;
			}
		}
		return s.substr(firstpos, maxLen);
	}
};

int main() {
	Solution s;
	vector<string> st = {"ababc", "abba", "ababaababa",
		"abcdefg", "abcdexyxfp", "", "a", "ccc"
	};
	for (auto &si : st) 
		cout << si << " : " <<  s.longestPalindrome(si) << endl;
	return 0;
}
