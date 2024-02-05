/*
EquiLeader: Find the index S such that the leaders of the sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N - 1] are the same.
****************************************************************************************************************************************************
A non-empty array A consisting of N integers is given.

The leader of this array is the value that occurs in more than half of the elements of A.

An equi leader is an index S such that 0 ≤ S < N − 1 
and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

For example, given array A such that:
    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
we can find two equi leaders:
  *  0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
  *  2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
The goal is to count the number of equi leaders.

Write a function:
  int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

For example, given:
    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
the function should return 2, as explained above.

Write an efficient algorithm for the following assumptions:
  *  N is an integer within the range [1..100,000];
  *  each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
*/
#include <map>
#include <vector>
#include <algorithm>

std::map<int, int> makeAMap(std::vector<int>& A, int begin, int end) {

    std::map<int, int> B;

    for (; begin < end; ++begin)
    {
        if (!B.try_emplace(A[begin], 1).second)
        {
            B[A[begin]]++;
        }
    }
    return B;
}

int findLeader(std::map<int, int>& m, int size)
{
    auto value = std::max_element(std::begin(m), std::end(m),
        [](const std::map<int, int>::value_type a, const std::map<int, int>::value_type b) 
        { return a.second < b.second; });
    int halfSize = size / 2;
    if (value->second > halfSize)
    {
        return value->first;
    }
    return -1;
}

int add(std::map<int, int>& m, int element, int& frontLeader, size_t size)
{
    if (!m.try_emplace(element, 1).second)
    {
        m[element]++;
    }
    if (frontLeader == element)
    {
        return frontLeader;
    }
    frontLeader = findLeader(m, size);
    return frontLeader;
}

int remove(std::map<int, int>& m, int element, int& backLeader, size_t size)
{
    m[element]--;

    backLeader =  findLeader(m, size);
    return backLeader;

}

int solution(std::vector<int>& A)
{
    if (A.size() < 2)
    {
        return 0;
    }
    std::map<int, int> front{ };
    front.emplace(A[0], 1);
    std::map<int, int> back = makeAMap(A, 1, A.size());
    int frontLeader{A[0]};
    int backLeader{ findLeader(back, A.size() - 1) };
    if (backLeader == -1)
    {
        return 0;
    }
    int result{0};
    if (frontLeader == backLeader)
    {
        result++;
    }
    for (unsigned int i = 1; i < A.size() - 1; ++i)
    {
        if (add(front, A[i], frontLeader, i + 1) == remove(back, A[i], backLeader, A.size() - 1 - i))
        {
            if (frontLeader == -1) continue;
            result++;
        }
    }
    return result;
}
