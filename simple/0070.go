/*70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
*/

package main

import (
	"fmt"
)

func climbStairs(n int) int {
	if n <= 2 {
		return n
	}

	pre2 := 1
	pre1 := 2
	curr := 0
	for i := 3; i <= n; i++ {
		curr = pre1 + pre2
		pre2 = pre1
		pre1 = curr
	}
	return curr
}

func main() {
	aa := climbStairs(3)
	fmt.Println(">>", aa)
}
