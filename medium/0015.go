/*
 */
package main

import (
	"fmt"
	"sort"
)

func twoSum(nums []int, start, target int) [][]int {

	lo := start
	hi := len(nums) - 1

	ret := make([][]int, 0)
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
				lo--
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
	return ret
}

func threeSum(nums []int) [][]int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	lth := len(nums)
	ret := make([][]int, 0)
	for i := 0; i < lth; i++ {
		towRet := twoSum(nums, i+1, 0-nums[i])
		for _, v := range towRet {
			ret = append(ret, append(v, nums[i]))
		}
		for i < lth-1 && nums[i] == nums[i+1] {
			i++
		}
	}
	return ret
}

func main() {

	var nums = []int{-1, 0, 1, 2, -1, -4}
	// var target =
	// aa := twoSum(nums, target)
	aa := threeSum(nums)
	fmt.Println(aa)
}
