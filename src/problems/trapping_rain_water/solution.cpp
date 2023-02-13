class Solution {
public:
    int trap(vector<int>& height) {
        int lPos =0, ans = 0;
        int rPos = height.size()-1;
        int leftWall = height[lPos];
        int rightWall = height[rPos];

        // 可以從最大雨水量那題思考
        while(lPos <= rPos){
            // 選擇從左或是從右邊看到的最大值當牆壁
            // 有可能會是中間的牆比較矮外面的比較高(中間的當作沙子被減去)
            // 所以【選擇留下最大值】
            leftWall = max(leftWall, height[lPos]);
            rightWall = max(rightWall, height[rPos]);
            
            // 如果lPos或是rPos還在牆壁的位置，那就會被減去
            // 水只可能留在較矮牆壁的高度之內所以加上較矮牆壁高度的水量
            // 減去rPos或是lPos位置較小值的原因是要減去沙子高度
            // 並且每次疊代一定有一個位置是牆壁，而較高的位置會是牆，較低會是沙子
            ans += min(leftWall, rightWall) - min(height[lPos], height[rPos]);
            
            // 更新較矮的那個，因為當下較高的牆比較適合當作牆壁
            if(height[lPos] < height[rPos]) ++lPos;
            else --rPos;
        }

        return ans;
    }
};