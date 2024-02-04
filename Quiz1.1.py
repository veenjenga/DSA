def removeDuplicates(nums):
    if not nums:
        return 0

    unique_index = 0

    for i in range(1, len(nums)):
        if nums[i] != nums[unique_index]:
            unique_index += 1
            nums[unique_index] = nums[i]

    # The unique elements are now in the front of the array
    # Resize the array to contain only the unique elements
    nums = nums[:unique_index + 1]

    return len(nums)

# Example usage:
nums = [1, 1, 2, 2, 3, 4, 4, 5]

print("Original array:", nums)

new_length = removeDuplicates(nums)

print("Array after removing duplicates:", nums[:new_length])
