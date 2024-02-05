def containsDuplicate(nums):
    seen = set()

    for num in nums:
        if num in seen:
            return True
        seen.add(num)

    return False

# Example usage:
nums1 = [1, 2, 3, 4, 5]
nums2 = [1, 2, 3, 4, 1]

print("Array 1:", nums1)
print("Contains duplicates:", containsDuplicate(nums1))

print("Array 2:", nums2)
print("Contains duplicates:", containsDuplicate(nums2))
