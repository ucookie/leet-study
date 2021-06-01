/*
198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
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
func rob(nums []int) int {
	lth := len(nums)
	pre2 := 0
	pre1 := 0

	switch lth {
	case 0:
		return 0
	case 1:
		return nums[0]
	case 2:
		return max(nums[0], nums[1])
	default:
		pre2 = nums[0]
		pre1 = max(nums[0], nums[1])
		for i := 2; i < lth; i++ {
			fmt.Println(i, "_", pre2, pre1)
			tmp := max(pre2+nums[i], pre1)
			pre2 = pre1
			pre1 = tmp
		}
	}
	return pre1
}

func main() {
	fmt.Println(">>>", rob([]int{1, 2, 3, 1}))
}
