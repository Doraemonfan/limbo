#include <iostream>
#include <string>
using namespace std;

class Solution {

public:
	int strStr(string haystack, string needle)
	{
		if (needle.empty()) return 0;
		int nLen = needle.size();
		int hLen = haystack.size();

		int match[nLen];
		match[0] = -1;
		for (int i = 1; i < nLen; ++i)
		{
			int j = i - 1;
			while (j > 0 && needle[i-1] != needle[match[j]])
				j = match[j];
			match[i] = match[j] + 1;
		}

		int in = 0, ih = 0;
		while (ih < hLen)
		{
			if (in == -1 || needle[in] == haystack[ih])
			{
				++in; ++ih;
				if (in == nLen) return ih - nLen;
			}
			else in = match[in];
		}
		return -1;
	}
};

int main() {
	Solution a;
	cout << a.strStr("abcd", "") << endl;

	return 0;
}
