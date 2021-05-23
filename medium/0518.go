/*
518. 零钱兑换 II
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。

*/

package main

import (
	"fmt"
)

func change(amount int, coins []int) int {
	dp := make([][]int, 0)
	lth := len(coins)

	dp = append(dp, make([]int, amount+1))
	for i := 1; i <= lth; i++ {
		tmp := []int{1}
		for j := 1; j <= amount; j++ {
			tmp = append(tmp, 0)
		}
		dp = append(dp, tmp)
	}

	for i := 1; i <= lth; i++ {
		for j := 1; j <= amount; j++ {
			if j-coins[i-1] >= 0 {
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]
			} else {
				dp[i][j] = dp[i-1][j]
			}
		}
	}
	fmt.Println(dp)
	return dp[lth][amount]
}

func change2(amount int, coins []int) int {
	lth := len(coins)

	dp := [5001]int{}
	dp[0] = 1

	for i := 0; i < lth; i++ {
		for j := 1; j <= amount; j++ {
			idx := j - coins[i]
			if idx >= 0 {
				dp[j] = dp[idx] + dp[j]
			}
		}
	}
	fmt.Println(dp)
	return dp[amount]
}

func main() {
	amount := 3
	coins := []int{2}
	aa := change2(amount, coins)
	fmt.Println(">>>>", aa)
}
