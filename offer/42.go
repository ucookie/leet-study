/*
剑指 Offer 42. 连续子数组的最大和
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

*/

package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

const (
	MIN_INT = -100
)

func maxSubArray(nums []int) int {
	lth := len(nums)
	if lth == 1 {
		return nums[0]
	}

	dp := nums[0]
	maxNum := dp
	for i := 1; i < lth; i++ {
		dp = max(dp+nums[i], nums[i])
		if dp > maxNum {
			maxNum = dp
		}
	}

	return maxNum
}
func main() {
	a := []int{-2, -1}
	// a := []int{-3, 4, -1, 2, -6, 1, 4}
	fmt.Println(maxSubArray(a))
}
