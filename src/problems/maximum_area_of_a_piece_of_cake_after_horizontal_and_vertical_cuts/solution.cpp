class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        int height = horizontalCuts[0], width = verticalCuts[0];
        
        
        for (int i = 1; i < horizontalCuts.size(); ++i)
            height = max(height, horizontalCuts[i]-horizontalCuts[i-1]);
            
        for (int i = 1; i < verticalCuts.size(); ++i)
            width = max(width, verticalCuts[i]-verticalCuts[i-1]);
        
        cout << width << " " << height << endl;
        return 1LL*width*height%1000000007;
    }
};