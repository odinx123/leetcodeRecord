

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int yn = -1;
    *returnSize = 2;
    int *arr = malloc(*returnSize * sizeof(int));
    for(int i = 0;i<numsSize;i++){
        for(int j = 0;j<numsSize;j++){
            if(i!=j)
                if(nums[i]+nums[j]==target){
                    arr[0] = i;
                    arr[1] = j;
                    yn = 1;
                    break;
                }
        }
        if(yn==1)
            break;
    }
    if(yn == -1){
        *returnSize = 0;
        free(arr);
    }
    return arr;
}