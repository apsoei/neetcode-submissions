import random

class Solution:
    def quickSort(self, arr, left, right):
        if left >= right:
            # sorted
            return
        
        # random pivot
        pivot_idx = random.randint(left, right)
        arr[pivot_idx], arr[right] = arr[right], arr[pivot_idx]

        pivotVal = arr[right]
        partitionIndex = left
        for i in range(left, right):
            if arr[i] < pivotVal:
                arr[i], arr[partitionIndex] = arr[partitionIndex], arr[i]
                partitionIndex += 1

        arr[partitionIndex], arr[right] = arr[right], arr[partitionIndex]
        self.quickSort(arr, left, partitionIndex - 1)
        self.quickSort(arr, partitionIndex + 1, right)

    def sortArray(self, nums: List[int]) -> List[int]:
        self.quickSort(nums, 0, len(nums) - 1)
        return nums