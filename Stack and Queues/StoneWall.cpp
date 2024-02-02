
#include <stack>
int solution(std::vector<int>& H) {
    std::stack<int> st;
    int numberOfBlock{ 0 };
    for (unsigned int i = 0; i < H.size(); ++i)
    {
        while (st.size() > 0)
        {
            if (st.top() > H[i])
            {
                st.pop();
                numberOfBlock++;
            }
            else
            {
                break;
            }
        }
        if (st.empty())
        {
            st.push(H[i]);
            continue;
        }
        if (st.top() < H[i])
        {
            st.push(H[i]);
        }
    }
    numberOfBlock += st.size();
    return numberOfBlock;
}
