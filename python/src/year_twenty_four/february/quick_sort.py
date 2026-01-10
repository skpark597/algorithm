from typing import List


def partition(nums: List[int], pivot: int, right: int):
    low, high = pivot + 1, right

    while low <= high:
        while nums[pivot] >= nums[low]:
            low += 1
        while nums[pivot] < nums[high]:
            high -= 1

        if low <= high:
            nums[low], nums[high] = nums[high], nums[low]

    nums[pivot], nums[high] = nums[high], nums[pivot]

    return high


def quick_sort(nums: List[int], left: int, right: int):
    if left >= right:
        return

    pivot = partition(nums, left, right)

    quick_sort(nums, left, pivot - 1)
    quick_sort(nums, pivot + 1, right)


if __name__ == "__main__":
    nums0 = [3, 2, 1, 5, 7, 9, 6]
    nums1 = [1, 5, 7, 2, 3, 4, 8, 6]

    quick_sort(nums0, 0, len(nums0) - 1)
    quick_sort(nums1, 0, len(nums1) - 1)

    print(nums0)
    print(nums1)
