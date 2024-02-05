def singleNumber(nums):
    result = 0

    for num in nums:
        result ^= num

    return result

# Example usage:
nums = [4, 2, 1, 2, 1]

print("Array:", nums)
print("Single non-repeating element:", singleNumber(nums))
