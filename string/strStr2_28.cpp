#include <iostream>
#include <string>

using namespace std;

class strStr {

private:
	string source;
	string target;

public:
	strStr(string s, string t):
		source(s), target(t)
	{ }

	int matchFirst();

};


int strStr::matchFirst() 
{
	int tLen = target.size();
	int match[tLen];
	match[0] = -1;
	for (int i = 1; i < tLen; ++i) 
	{
		int j = i - 1;
		while (j > 0 && target[i-1] != target[match[j]])
			j = match[j];
		match[i] = match[j] + 1;
	}

	for (int i = 0; i < tLen; ++i) cout << target[i] << "(" << match[i] << ") "; cout << endl;
	
	int sLen = source.size();
	int it = 0, is = 0;
	while (is < sLen)
	{
		if (it == -1 || target[it] == source[is])
		{
			cout << "(" << target[it] << " " << source[is] << ") ";
			++it; ++is;
			if (it == tLen) return is - tLen;
		}
		else it = match[it];
	}
	return -1;
}

int main() {

	strStr tt("aaaaaaaaaaa", "aaaaab");

	cout << tt.matchFirst() << endl;

	return 0;
}
