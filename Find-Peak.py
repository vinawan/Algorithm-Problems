# Author: Alvin Nawa
# Date: May 16, 2017
# Problem: Find peak of an array
# Peak Definition: Given an int array A, a peak is when A[i] >= A[i-1] and A[i+1]
# For edge elements, it's a peak if A[0] >= A[1] or A[len-1] >= A[len-2]

from random import randint

def RecPeakFinder (nums, lo, hi):
    mid = lo + (hi - lo)//2

    if (mid != 1 and nums[mid] < nums[mid - 1]):
        return RecPeakFinder(nums, lo, mid - 1)
    elif (mid != 1 and nums[mid] < nums[mid + 1]):
        return RecPeakFinder(nums, mid + 1, hi)
    else:
        return nums[mid]
    

def RecPeakFinder2D (matrix, lo, hi):
    mid = lo + (hi - lo)//2

    GlobalMaxInRowMid = matrix[mid].index(max(matrix[mid]))

    if (matrix[mid][GlobalMaxInRowMid] < matrix[mid][GlobalMaxInRowMid - 1]):
        return RecPeakFinder2D(matrix, lo, GlobalMaxInRowMid - 1)
    elif (matrix[mid][GlobalMaxInRowMid] < matrix[mid][GlobalMaxInRowMid + 1]):
        return RecPeakFinder2D(matrix, GlobalMaxInRowMid + 1, hi)
    else:
        return matrix[mid][GlobalMaxInRowMid]

def main():
    nums = []
    for i in range (10):
        nums.append(randint(1, 100))
    print (nums)
    print (RecPeakFinder(nums, 0, 10))
    print ('\n\n\n')

    row, cols = 10, 10
    matrix = [[randint(1, 100) for x in range (row)] for y in range (cols)]
    print (matrix)
    print (RecPeakFinder2D(matrix, 0, 10))

if __name__ == "__main__":
    main()
