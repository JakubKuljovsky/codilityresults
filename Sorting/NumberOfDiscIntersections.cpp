/*
NumberOfDiscIntersections: Compute the number of intersections in a sequence of discs.
------------------------------------------------------------------------------------------
We draw N discs on a plane. The discs are numbered from 0 to N − 1. 
An array A of N non-negative integers, specifying the radiuses of the discs, is given.
The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have 
at least one common point (assuming that the discs contain their borders).

Write a function:
  int solution(vector<int> &A);

that, given an array A describing N discs as explained above, returns the number of (unordered)
pairs of intersecting discs. The function should return −1 if the number of intersecting pairs
exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:
 * N is an integer within the range [0..100,000];
 * each element of array A is an integer within the range [0..2,147,483,647].
*/
#include <algorithm>

int solution(std::vector<int>& A) {
    int totalIntersec{ 0 };
    int size = static_cast<int>(A.size());
    std::vector<int> Begin(size, 0);
    std::vector<int> End(size, 0);

    for (unsigned int i = 0; i < size; ++i)
    {
        Begin[std::max(0, static_cast<int>(i - A[i]))]++;
        End[std::min(static_cast<size_t>(i + A[i]), static_cast<size_t>(size - 1))]++;
    }

    int active{ 0 };
    for (unsigned int i = 0; i < size; ++i)
    {
        totalIntersec += active * Begin[i] + (Begin[i] * (Begin[i] - 1)) / 2;
        if (totalIntersec > 10'000'000)
        {
            return -1;
        }
        active += Begin[i] - End[i];
    }
    return totalIntersec;
}
