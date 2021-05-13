/*
416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
*/
package main

import (
	"fmt"
)

func canPartition(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	if sum%2 != 0 {
		return false
	}

	lth := len(nums)
	dp := [201][101]bool{}
	for i := 0; i <= lth; i++ {
		dp[i][0] = true
	}

	for i := 1; i <= lth; i++ {
		for j := 1; j <= sum; j++ {
			if j-nums[i-1] >= 0 {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]
			}
		}
	}
	return dp[lth][sum]
}

func canPartition2(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	if sum%2 != 0 {
		return false
	}

	sum = sum / 2

	lth := len(nums)
	dp := [100 * 200]bool{}
	dp[0] = true

	for i := 0; i < lth; i++ {
		for j := sum; j >= 0; j-- {
			if j-nums[i] >= 0 {
				dp[j] = dp[j] || dp[j-nums[i]]
			}
		}
	}
	return dp[sum]
}

func main() {
	nums := []int{1, 5, 11, 5}
	aa := canPartition2(nums)
	fmt.Println("->", aa)
}
