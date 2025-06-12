#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        // const int heightSize = heights.size();
        // int first = 0;
        // int second = 1;
        // int length = 0;
        // int area = 0;
        // int width = 2;
        // while (second<heightSize) {
        //     length = min(heights[first],heights[second]);
        //     area = max(area,length*width);
        //     first++;
        //     second++;
        // }
        // return area;

        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            int currHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
