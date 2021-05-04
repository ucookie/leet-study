/*
18. 四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意：答案中不可以包含重复的四元组。

示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

*/
package main

import (
	"fmt"
	"sort"
)

func fourSum(nums []int, target int) [][]int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	return nSum(nums, 4, 0, target)
}

func nSum(nums []int, n, start, target int) [][]int {
	lth := len(nums)
	ret := make([][]int, 0)
	if n < 2 || lth < n {
		return ret
	}

	if n == 2 {
		lo := start
		hi := lth - 1
		for lo < hi {
			left := nums[lo]
			right := nums[hi]
			tmp := left + right
			if tmp < target {
				for lo < hi && nums[lo] == left {
					lo++
				}
			} else if tmp > target {
				for lo < hi && nums[hi] == right {
					hi--
				}
			} else {
				ret = append(ret, []int{nums[lo], nums[hi]})
				for lo < hi && nums[lo] == left {
					lo++
				}
				for lo < hi && nums[hi] == right {
					hi--
				}
			}
		}
	} else {
		for i := start; i < lth; i++ {
			sub := nSum(nums, n-1, i+1, target-nums[i])
			for _, v := range sub {
				ret = append(ret, append(v, nums[i]))
			}
			for i < lth-1 && nums[i] == nums[i+1] {
				i++
			}
		}
	}
	return ret
}
func main() {
	var nums = []int{1, 0, -1, 0, -2, 2}
	var target = 0
	aa := fourSum(nums, target)
	fmt.Println(aa)
}
