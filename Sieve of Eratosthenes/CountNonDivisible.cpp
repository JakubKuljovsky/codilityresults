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
