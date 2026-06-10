class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        max1 = max2 = float("-inf")
        index = -1

        for i in range(len(nums)):
            if nums[i] > max1:
                max2 = max1
                max1 = nums[i]
                index = i

            elif nums[i] > max2:
                max2 = nums[i]

        return index if max1 >= 2 * max2 else -1
