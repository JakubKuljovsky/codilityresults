/*
AbsDistinct: Compute number of distinct absolute values of sorted array elements.
******************************************************************************************************************************************************
A non-empty array A consisting of N numbers is given. The array is sorted in non-decreasing order. 
The absolute distinct count of this array is the number of distinct absolute values among the elements of the array.

For example, consider array A such that:
  A[0] = -5
  A[1] = -3
  A[2] = -1
  A[3] =  0
  A[4] =  3
  A[5] =  6
The absolute distinct count of this array is 5, because there are 5 distinct absolute values among the elements of this array,
namely 0, 1, 3, 5 and 6.

Write a function:
    int solution(vector<int> &A);

that, given a non-empty array A consisting of N numbers, returns absolute distinct count of array A.

For example, given array A such that:
  A[0] = -5
  A[1] = -3
  A[2] = -1
  A[3] =  0
  A[4] =  3
  A[5] =  6
the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:
  *  N is an integer within the range [1..100,000];
  *  each element of array A is an integer within the range [−2,147,483,648..2,147,483,647];
  *  array A is sorted in non-decreasing order.
*/

// To find number absolute distinct numbers, we use std::set,
// which tells us whether the entered number is already in the set 
// of absolute distinct numbers in log(n) complexity.
#include <set>

int solution(vector<int> &A) {
    // set of absolute distinct numbers
    std::set<int> numbers;

    for (auto a: A)
    {
        // for all numbers in vector A
        // if absolute value of number is not yet in numbers set,      
        // then add him into set.
        numbers.insert(abs(a));
    }
  
    // return size of absolute distinct numbers set
    return numbers.size();
}
