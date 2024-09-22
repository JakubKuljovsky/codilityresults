/*
CountNonDivisible: Calculate the number of elements of an array that are not divisors of each element.
*************************************************************************************************************************************************************

You are given an array A consisting of N integers.

For each number A[i] such that 0 ≤ i < N,
we want to count the number of elements of the array that are not the divisors of A[i].
We say that these elements are non-divisors.

For example, consider integer N = 5 and array A such that:
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
For the following elements:
  *  A[0] = 3, the non-divisors are: 2, 6,
  *  A[1] = 1, the non-divisors are: 3, 2, 3, 6,
  *  A[2] = 2, the non-divisors are: 3, 3, 6,
  *  A[3] = 3, the non-divisors are: 2, 6,
  *  A[4] = 6, there aren't any non-divisors.

Write a function:
    vector<int> solution(vector<int> &A);

that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.

Result array should be returned as an array of integers.

For example, given:
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
the function should return [2, 4, 3, 2, 0], as explained above.

Write an efficient algorithm for the following assumptions:
  *  N is an integer within the range [1..50,000];
  *  each element of array A is an integer within the range [1..2 * N].
*/

//only 88%

#include <algorithm>
#include <cmath>
#include <map>


std::vector<int> solution(std::vector<int>& A) {
    int sizeA = A.size();
    std::vector<int> solution;
    std::vector<int> counters(*std::max_element(A.begin(), A.end()) + 1, 0);
    std::map<int, int> m;

    for (unsigned int i = 0; i < sizeA; ++i)
    {
        counters[A[i]]++;

        if (counters[A[i]] == 2)
        {
            m.try_emplace(A[i], 0);
        }
    }
    for (unsigned int i = 0; i < sizeA; ++i)
    {
        auto it = m.find(A[i]);
        if (it != m.end())
        {
            if (it->second != 0)
            {
                solution.push_back(it->second);
                continue;
            }
      
        }

        int sum = 0;
        for (unsigned int j = 1; j <= sqrt(A[i]); ++j)
        {
            if (A[i] % j == 0)
            {
                sum += counters[j];

                if (A[i] / j > j)
                {
                    sum += counters[A[i] / j];
                }
            }
        }

        solution.push_back(sizeA - sum);

        if (it != m.end())
        {
            it->second = solution.back();
        }
    }
 

    return solution;
}
