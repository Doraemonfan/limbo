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

		if (nums1.size() < nums2.size()) 
			return findMedianSortedArrays(nums2, nums1);

		int ll = 0, lr = nums1.size() - 1;
		int sl = 0, sr = nums2.size() - 1;
		
		while (sr - sl > 1) {
			double lmv = (nums1[(ll+lr)>>1] 
				+ nums1[(ll+lr+1)>>1]) / 2.0;
			double smv = (nums2[(sl+sr)>>1]
				+ nums2[(sl+sr+1)>>1]) / 2.0;
			if (lmv == smv) return lmv;
			else if (lmv > smv) { 
				lr -= (sr - sl) >> 1;
				sl = (sl + sr) >> 1;
			}
			else {
				ll += (sr - sl) >> 1;
				sr = (sl + sr + 1) >> 1;
			}
		}

		vector<int> mini;
		for (int i = ((ll+lr)>>1)-1; i <= ((ll+lr+1)>>1)+1; ++i) 
			if (i >= ll && i <= lr)
				mini.push_back(nums1[i]);
		for (int i = sl; i <= sr; ++i)
			mini.push_back(nums2[i]);		
		sort(mini.begin(), mini.end());
		int len = mini.size();
		return (mini[(len-1)>>1] + mini[len>>1]) / 2.0;
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
