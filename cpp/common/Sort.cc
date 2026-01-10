#include "Sort.h"

namespace sort {
	void swap(vector<int> &nums, int idx1, int idx2) {
		int temp = nums[idx2];
		nums[idx2] = nums[idx1];
		nums[idx1] = temp;
	}

	void quickSort(vector<int> &nums) {
		quickSortInternal(nums, 0, nums.size()-1);
	}

	void quickSortInternal(vector<int> &nums, int start, int end) {
		int middle = (start + end) / 2;
		int pivot = nums[middle];
		int left = start;
		int right = end;

		if (start >= end) return;

		while (left < right) {
			if (nums[left] >= pivot && nums[right] <= pivot) {
				swap(nums, left, right);
			}

			if (nums[left] <= pivot) left++;
			if (nums[right] >= pivot) right--;
		}
	
		quickSortInternal(nums, start, right);
		quickSortInternal(nums, left, end);
	}

} // namespace sort

/* int main() {
	vector<int> nums0 {7,5,1,10,6,3};
	vector<int> nums1 {2,1,6,4,5,3,7};
	vector<int> nums2 {1,1,1,5,3,2};
	vector<int> nums3 {1,8,4,9,10,3,11};
	vector<int> nums4 {1,1,3,9,5,3,2,7,7};
	vector<int> nums5 {1,1,2,6,100,23,4,5,7,10,11,2,2,5};
	vector<int> nums6 {1,3,4,1,1,1,7,2,1,8};

	sort::quickSort(nums0);
	sort::quickSort(nums1);
	sort::quickSort(nums2);
	sort::quickSort(nums3);
	sort::quickSort(nums4);
	sort::quickSort(nums5);
	sort::quickSort(nums6);

	for (int iter : nums0) {
		cout << iter << " ";
	} cout << endl;

	for (int iter : nums1) {
		cout << iter << " ";
	} cout << endl;

	for (int iter : nums2) {
		cout << iter << " ";
	} cout << endl;

	for (int iter : nums3) {
		cout << iter << " ";
	} cout << endl;

	for (int iter : nums4) {
		cout << iter << " ";
	} cout << endl;

	for (int iter : nums5) {
		cout << iter << " ";
	} cout << endl;

	for (int iter : nums6) {
		cout << iter << " ";
	} cout << endl;

} */
