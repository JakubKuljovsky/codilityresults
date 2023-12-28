/*
MissingElement: Find the smallest positive integer that does not occur in a given sequence.
-----------------------------------------------------------------------------------------------------------------------------------
This is a demo task.

Write a function:
  int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer
(greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:
 * N is an integer within the range [1..100,000];
 * each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

int solution(vector<int> &A) {
    std::vector<bool> bVec(A.size() + 1, false);
    for (unsigned i = 0; i < A.size(); ++i)
    {
        if (A[i] > 0 and A[i] <= A.size())
        {
            bVec[A[i]] = true;
        }
    }
    if (bVec.empty()) return 1;
    for (unsigned i = 1; i <= A.size(); ++i)
    {
        if (bVec[i] == false) return i;
    }
    return bVec.size();
}
