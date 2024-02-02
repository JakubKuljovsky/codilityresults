

#include <stack>

int solution(std::vector<int>& A, std::vector<int>& B) {
    std::stack<std::pair<int, int>> liveFishs;

    for (unsigned int i = 0; i < A.size(); ++i)
    {
        if (liveFishs.size() > 0)
        {
            if (liveFishs.top().second == B[i] or B[i] == 1)
            {
                liveFishs.push(std::make_pair(A[i], B[i]));
                continue;
            }

            while (liveFishs.size() > 0)
            {
                if (liveFishs.top().second == B[i])
                {
                    liveFishs.push(std::make_pair(A[i], B[i]));
                    break;
                }

                if (liveFishs.top().first < A[i])
                {
                    liveFishs.pop();
                }
                else
                {
                    break;
                }
            }

            if (liveFishs.size() == 0)
            {
                liveFishs.push(std::make_pair(A[i], B[i]));
            }

        }
        else
        {
            liveFishs.push(std::make_pair(A[i], B[i]));
        }
    }
    return liveFishs.size();
}
