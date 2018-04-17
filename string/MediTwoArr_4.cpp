#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

static const auto _____ = []()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        return nullptr;
 }();

class Solution {

public:
	double findMedianSortedArrays(
		vector<int>& nums1, vector<int>& nums2) {
	//	cout << endl;
	//	for (auto i : nums1) cout << i << " "; cout << endl;
	//	for (auto i : nums2) cout << i << " "; cout << endl;
		vector<int> *longP, *shortP;
		if (nums1.size() > nums2.size()) {
			longP = &nums1;
			shortP = &nums2;
		}
		else {
			longP = &nums2;
			shortP = &nums1;
		}

		int ll = 0, lr = longP->size() - 1;
		int sl = 0, sr = shortP->size() - 1;
		
		while (sr - sl > 1) {
			double lmv = ((*longP)[(ll+lr)/2] 
				+ (*longP)[(ll+lr+1)/2]) / 2.0;
			double smv = ((*shortP)[(sl+sr)/2]
				+ (*shortP)[(sl+sr+1)/2]) / 2.0;
			cout << lmv << " # " << smv << endl;
			if (lmv == smv) return lmv;
			else if (lmv > smv) { 
				lr -= (sr - sl) / 2;
				sl = (sl + sr) / 2;
			}
			else {
				ll += (sr - sl) / 2;
				sr = (sl + sr + 1) / 2;
			}
			cout << ll << "-" << lr << " " 
				<< sl << "-" << sr << endl;
		}

		vector<int> mini;
		for (int i = (ll+lr)/2-1; i <= (ll+lr+1)/2+1; ++i) 
			if (i >= ll && i <= lr)
				mini.push_back((*longP)[i]);
	//	for (auto i : mini) cout << i << " "; cout << endl;
		for (int i = sl; i <= sr; ++i)
			mini.push_back((*shortP)[i]);		
		sort(mini.begin(), mini.end());
		int len = mini.size();
		return (mini[(len-1)/2] + mini[len/2]) / 2.0;
	}
};

void test(int b1, int e1, int b2, int e2) {
	Solution a;
	vector<int> n1;
	vector<int> n2;
	for (int i = b1; i <= e1; ++i) n1.push_back(i);
	for (int i = b2; i <= e2; ++i) n2.push_back(i);
	cout << "(" << b1 << "," << e1 << ") (" << b2 << "," << e2 << ") : ";
	cout << a.findMedianSortedArrays(n1, n2) << endl;
}

int main() {
	ifstream fin("in.txt");
	int b1, e1, b2, e2;
	Solution t;
	vector<int> x{1, 3};
	vector<int> y{2};
	cout << "$ " << t.findMedianSortedArrays(x, y) << endl;
	while (fin >> b1 >> e1 >> b2 >>  e2) 
		test(b1, e1, b2, e2);
	return 0;
}
