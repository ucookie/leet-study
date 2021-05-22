/*
1143. 最长公共子序列
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

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

func longestCommonSubsequence(text1 string, text2 string) int {

	u1 := []rune(text1)
	u2 := []rune(text2)

	lth1 := len(u1)
	lth2 := len(u2)
	if lth1 == 0 || lth2 == 0 {
		return 0
	}

	dp := make([][]int, 0)
	for i := 0; i <= lth1; i++ {
		tmp := []int{}
		for j := 0; j <= lth2; j++ {
			tmp = append(tmp, 0)
		}
		dp = append(dp, tmp)
	}

	for i := 1; i <= lth1; i++ {
		for j := 1; j <= lth2; j++ {
			if u1[i-1] == u2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	return dp[lth1][lth2]
}

func longestCommonSubsequence2(text1 string, text2 string) int {

	u1 := []rune(text1)
	u2 := []rune(text2)

	lth1 := len(u1)
	lth2 := len(u2)
	if lth1 == 0 || lth2 == 0 {
		return 0
	}

	dp := make([]int, 0)
	for i := 0; i <= lth2; i++ {
		dp = append(dp, 0)
	}

	for i := 1; i <= lth1; i++ {
		_ij := 0
		for j := 1; j <= lth2; j++ {
			tmpj := dp[j]
			if u1[i-1] == u2[j-1] {
				dp[j] = _ij + 1
			} else {
				dp[j] = max(dp[j], dp[j-1])
			}
			_ij = tmpj
		}
	}
	fmt.Println(dp)
	return dp[lth2]
}

func main() {
	text1 := "bsbininm"
	text2 := "jmjkbkjkv"
	aa := longestCommonSubsequence2(text1, text2)

	fmt.Println("结果:", aa)
}
