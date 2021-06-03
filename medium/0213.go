/**/

package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func rob(nums []int) int {
	lth := len(nums)

	switch lth {
	case 0:
		return 0
	case 1:
		return nums[0]
	case 2:
		return max(nums[0], nums[1])
	default:
		return max(deal(nums, 0, lth-2), deal(nums, 1, lth-1))
	}
}

func deal(nums []int, begin, end int) int {
	pre2 := 0
	pre1 := 0
	for i := begin; i <= end; i++ {
		cur := max(pre1, pre2+nums[i])
		pre2 = pre1
		pre1 = cur
	}
	return pre1
}
func main() {
	fmt.Println(">>>", rob([]int{2, 3, 2}))
}
