class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mostClosest = nums[0] + nums[1] + nums.back();
        
        if(nums.size() > 2)
        {
             if(nums[0]>=0 && nums[0]>=target)
                {
                 return nums[0]+nums[1]+nums[2];
                 }
           if (nums[nums.size()-1]<=0 && target>=nums[nums.size()-1])
               {
               return nums[nums.size()-1]+nums[nums.size()-2]+nums[nums.size()-3];
               }
        }
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int beg = i+1;
            int end = nums.size()-1;
            while (beg < end) {
                int n = nums[i] + nums[beg] + nums[end];

                bool state = abs(target-n) < abs(target-mostClosest);
                if (state)
                    mostClosest = n;
                
                if (n == target) return n;
                if (n < target)
                    ++beg;
                else
                    --end;
            }
            if (nums[i] * 3 > target)  // 因為排序的關係，所以後面就不會再有
                return mostClosest;
        }

        return mostClosest;
    }
};