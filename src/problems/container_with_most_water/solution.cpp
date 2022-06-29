class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int beg = 0, end = height.size() - 1;
        
        while (beg < end) {
            area = max(area, min(height[beg], height[end])*(end-beg));
            height[beg] > height[end] ? --end : ++beg;
        }
        return area;
    }
};