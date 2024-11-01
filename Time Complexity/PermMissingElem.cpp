/*
PermMissingElem: Find the missing element in a given permutation.
--------------------------------------------------------------------------------------------------------------------
An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)],
which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:
  int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:
 * N is an integer within the range [0..100,000];
 * the elements of A are all distinct;
 * each element of array A is an integer within the range [1..(N + 1)].
*/

#include <numeric>

// Here we add the series 1 .. n + 1 and put it in the difference
// with the sum of all the numbers of the series, 
// from which we get the missing element.
int solution(vector<int> &A) {
    return  ((1 + A.size() + 1) * (A.size() + 1) / 2) - std::accumulate(A.begin(), A.end(), 0);
}
