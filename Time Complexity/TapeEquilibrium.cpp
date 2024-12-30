/*
TapeEquilibrium: Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
--------------------------------------------------------------------------------------------------------
A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1]
and A[P], A[P + 1], ..., A[N − 1].
The difference between the two parts is the value of:
|(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of
the second part.

For example, consider array A such that:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
  
We can split this tape in four places:
 * P = 1, difference = |3 − 10| = 7
 * P = 2, difference = |4 − 9| = 5
 * P = 3, difference = |6 − 7| = 1
 * P = 4, difference = |10 − 3| = 7

Write a function:
  int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the minimal difference that
can be achieved.

For example, given:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:
 * N is an integer within the range [2..100,000];
 * each element of array A is an integer within the range [−1,000..1,000].
*/
#include <numeric>  // For std::accumulate
#include <cmath> // For std::abs


int solution(vector<int> &A) {
    // Initialize the sum the first element from the left 
    int sum_from_the_left{A[0]};
    // Calculate the sum of all elements from the second element to the end of the array
    int sum_from_the_right{std::accumulate(A.begin() + 1, A.end(), 0)};
    // Calculate the initial difference between the sum from the left and the sum from right
    int lowest_difference_between_sums{std::abs(sum_from_the_left - sum_from_the_right)};
  
    // Iterate through the array from the second element to the second-to-last element
    for (unsigned i = 1; i < A.size() - 1 ; ++i)
    {
        // Add the current element to the sum from the left
        sum_from_the_left += A[i];
        // Subtract the current element from the sum from the right
        sum_from_the_right -= A[i];
        // Calculate the current difference between the sum from the left and the sum from the right
        int difference_between_sums{std::abs(sum_from_the_left - sum_from_the_right)};
         // If the current difference is smaller than the smallest difference found so far, update the lowest difference
        if (difference_between_sums < lowest_difference_between_sums)
        {
            lowest_difference_between_sums = difference_between_sums;
        }
    }
    // Return lowest found difference
    return lowest_difference_between_sums;
}
