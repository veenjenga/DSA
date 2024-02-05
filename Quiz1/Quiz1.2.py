def rotate(nums, k):
    n = len(nums)
    k %= n  # To handle cases where k is larger than the length of the array
    
    # Rotate the array using slicing
    nums[:] = nums[-k:] + nums[:-k]

# Example usage:
nums = [1, 2, 3, 4, 5, 6, 7]
k = 3

print("Original array:", nums)

rotate(nums, k)

print("Array after rotation:", nums)
