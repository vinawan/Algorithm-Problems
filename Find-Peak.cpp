/*
    Author: Alvin Nawa
    Date: May 16, 2017
    Problem: Find Peak of an Array
    Peak Definition: Given an int array A, a peak is when A[i] >= A[i-1] and A[i+1]
    For edge elements, it's a peak if A[0] >= A[1] or A[len-1] >= A[len-2]
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

const int row = 10;
const int col = 10;

/*
    Find peak on a 1-D Array - Brute Force solution
    Time Complexity = O(n)
*/
int BF_FindPeak(vector<int> nums)
{
    // Base Case
    if (nums[0] >= nums[1]) return nums[0]; // 1st Element Peak
    if (nums[nums.size()-1] >= nums[nums.size()-2]) return nums[nums.size()-1]; // Last Element Peak

    for (int i = 1; i < nums.size() - 1; i++)
    {
        // Check if this number is higher than left and right, if yes, return peak
        if (nums[i] >= nums[i-1] && nums[i] >= nums[i+1]) return nums[i];
    }

    return -1;
}

/*
    Find peak on a 1-D Array - Divide and Conquer Solution
    Time Complexity = O(logn)
*/
int RecFindPeak(vector<int> nums, int lo, int hi)
{
    int mid = lo + (hi - lo) / 2;

    if (mid != 0 && nums[mid] < nums[mid - 1]) return RecFindPeak(nums, lo, mid - 1);
    else if (mid != 0 && nums[mid] < nums[mid + 1]) return RecFindPeak(nums, mid + 1, hi);
    else return nums[mid];
}

/*
    Healper Function: Find greatest element in an Array
    Returns the index
*/
int FindGreatest(int arr[])
{
    int max = 0;
    int length = col;

    for (int i = 1; i < length; i++)
    {
        if (arr[i] > arr[max]) max = i;
    }

    return max;
}

/*
    Find Peak on a 2-D Array - Divide an Conquer Solution
    Time Complexity = O(nlog(m))
*/
int RecFindPeak2D(int arr[row][col], int lo, int hi)
{
    int mid = lo + (hi - lo)/2;

    int GlobalMax = FindGreatest(arr[mid]);

    if (arr[mid][GlobalMax] < arr[mid - 1][GlobalMax]) return (arr, lo, mid - 1);
    else if (arr[mid][GlobalMax] < arr[mid + 1][GlobalMax]) return (arr, mid + 1, hi);
    else return arr[mid][GlobalMax];
}

int main()
{
    // 1-D
    // Initialize vector -- Print Vector to check our Answers
    vector<int> nums;
    for (int i = 0; i < 20; i++)
    {
        nums.push_back(rand() % 100 + 1);
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << "Brute Force Peak 1-D: " << BF_FindPeak(nums) << endl;

    cout << "Recursive Peak 1-D: " << RecFindPeak(nums, 0, nums.size() - 1) << endl;

    cout << endl << endl;

    // 2-D
    // Initialize array -- Print vector to chech our Answers
    int matrix[row][col];

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            matrix[i][j] = rand() % 100 + 1;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Greatest: " << FindGreatest(matrix[0]) << endl;
    cout << "Recursive Peak 2-D: " << RecFindPeak2D(matrix, 0, row - 1) << endl;

    return 0;
}