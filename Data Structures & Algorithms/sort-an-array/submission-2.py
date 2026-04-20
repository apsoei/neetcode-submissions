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
    
    def mergeSort(self, arr, left, right):
        if left >= right:
            return [arr[left]]
        
        mid = left + (right - left) // 2
        L = self.mergeSort(arr, left, mid)
        R = self.mergeSort(arr, mid + 1, right)

        return self.merge(L, R)

    def merge(self, L, R):
        res = []
        i = j = 0
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                res.append(L[i])
                i += 1
            else:
                res.append(R[j])
                j += 1
        
        res.extend(L[i:])
        res.extend(R[j:])

        return res


    def sortArray(self, nums: List[int]) -> List[int]:
        # self.quickSort(nums, 0, len(nums) - 1)
        # return nums
        return self.mergeSort(nums, 0, len(nums) - 1)
