/*
MinAbsSum: Given array of integers, find the lowest absolute sum of elements.
************************************************************************************************************************************************************************************************************

For a given array A of N integers and a sequence S of N integers from the set {−1, 1}, 
we define val(A, S) as follows:
   val(A, S) = |sum{ A[i]*S[i] for i = 0..N−1 }|

(Assume that the sum of zero elements equals zero.)

For a given array A, we are looking for such a sequence S that minimizes val(A,S).

Write a function:
    int solution(vector<int> &A);

that, given an array A of N integers, computes the minimum value of val(A,S) from all possible values of val(A,S) for all possible sequences S of N integers from the set {−1, 1}.

For example, given array:
  A[0] =  1
  A[1] =  5
  A[2] =  2
  A[3] = -2
your function should return 0, since for S = [−1, 1, −1, 1], val(A, S) = 0, which is the minimum possible value.

Write an efficient algorithm for the following assumptions:
  *  N is an integer within the range [0..20,000];
  *  each element of array A is an integer within the range [−100..100].
*/
#include <numeric>

int solution(vector<int> &A) {
    
    if (A.size() < 2)
    {
        if (A.size() == 0) return 0;
        return A[0];
    }

    for (unsigned i = 0; i < A.size(); ++i)
    {
        A[i] = std::abs(A[i]);
    }

    std::sort(A.begin(),A.end());

    int result{std::abs(std::accumulate(A.begin(), A.end(), 0))};
    int temp_result{result};
    for (unsigned i = A.size(); temp_result <= result and i > 1; --i)
    {
        result = temp_result;
        temp_result = std::abs(temp_result - 2 * A[i - 1]);
    }

    return std::min(result, temp_result);
}
