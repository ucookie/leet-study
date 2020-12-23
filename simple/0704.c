// 二分查找
// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
// 示例 1:
// 输入: nums = [-1,0,3,5,9,12], target = 9
// 输出: 4
// 解释: 9 出现在 nums 中并且下标为 4
// 示例 2:
// 输入: nums = [-1,0,3,5,9,12], target = 2
// 输出: -1
// 解释: 2 不存在 nums 中因此返回 -1

#include <stdio.h>
#include <stdlib.h>

int search(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1; // 注意

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}

int left_bound(int *nums, int lth, int target) {
    if (lth == 0) return -1;
    int left = 0;
    int right = lth; // 注意

    while (left < right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意
        }
    }
    return left;
}

// 开区间搜索
int search2(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid]==target){
            return mid;
        } else if (nums[mid]<target) {
            left = mid + 1;
        } else if (nums[mid]>target){
            right = mid;
        }
    }
    if (left >= numsSize) {
        return -1;
    }
    return nums[left] == target ? left : -1;
}


int main(int argc, char const *argv[])
{
    int numsSize = 6;
    int* nums = (int*)malloc(numsSize*sizeof(int));
    nums[0] = -1;
    nums[1] = 0;
    nums[2] = 3;
    nums[3] = 5;
    nums[4] = 9;
    nums[5] = 12;

    printf("%d\n",search2(nums, numsSize, 13));
    printf("\n");
    return 0;
}
