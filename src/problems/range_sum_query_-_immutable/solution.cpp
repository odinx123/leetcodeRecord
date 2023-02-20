class NumArray {
public:
    NumArray(vector<int>& nums) {
        num = nums;
        for (int i = 1; i < nums.size(); ++i)
            num[i] = num[i-1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return num[right] - (left > 0 ? num[left-1] : 0);
    }

private:
    vector<int> num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */