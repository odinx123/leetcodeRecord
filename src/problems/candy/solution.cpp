class Solution {
public:
    int candy(vector<int>& ratings) {
        int num = ratings.size();
        
        int high = 0, down = 0;
        bool duplicate = false;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings.at(i) == ratings.at(i-1)) {  // 把相同數字當作同一點
                duplicate = true;
                down = 0;
                high = 0;
                continue;
            }
            
            // 到這邊一定是遞增或遞減
            if (ratings.at(i) > ratings.at(i-1)) {
                down = 0;
                num += ++high;
                duplicate = false;
            } else {
                if (duplicate && high)  // 如果有重複且之前是遞增
                    num += ++down;  // 就正常加法
                else {
                    while (i < ratings.size() && ratings.at(i) < ratings.at(i-1)) { // 找出遞減多少位數
                        ++i;
                        ++down;  // 遞減位數
                    }
                    --i;  // while會讓i多一位
                    if (high >= down)
                        num += down*(down-1)/2;  // down先減1，在進行梯形公式(最高點之前遞增時算過了)
                    else
                        num += (down+1)*down/2-high;  // 算出遞減的部分有多少再把遞增時多算的減掉
                }
                high = 0;
            }
        }

        
        return num;
    }
};