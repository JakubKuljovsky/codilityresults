
#include <map>
int solution(vector<int> &A) {
    if (A.size() == 1)
    {
        return 0;
    }
    std::map<int, int> B;
    int moereThanHalf{(static_cast<int>(A.size()) / 2) + 1};

    for (unsigned int i = 0; i < A.size(); ++i)
    {
        if(!B.try_emplace(A[i], 1).second)
        {
            B[A[i]]++;
            if (B[A[i]] == moereThanHalf)
            {
                return i;
            }
        }
    }
    return -1;
}
