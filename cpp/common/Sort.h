#include <vector>
#include <iostream>

using namespace std;

namespace sort{
	// 이후 template을 이용하여 일반적인 클래스에 대해 구현할 계획
	void swap(vector<int> &nums, int idx1, int idx2);
	void quickSort(vector<int> &nums);
	void quickSortInternal(vector<int> &nums, int start, int end);
};
