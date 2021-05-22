/*
712. 两个字符串的最小ASCII删除和
给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。

输入: s1 = "sea", s2 = "eat"
输出: 231
解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
示例 2:

输入: s1 = "delete", s2 = "leet"
输出: 403
解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。

*/

package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minimumDeleteSum(s1 string, s2 string) int {
	u1 := []rune(s1)
	u2 := []rune(s2)

	lth1 := len(u1)
	lth2 := len(u2)
	ret := 0

	if lth1 == 0 {
		for _, v := range u2 {
			ret += int(v)
		}
		return ret
	}

	if lth2 == 0 {
		for _, v := range u1 {
			ret += int(v)
		}
		return ret
	}
	dp := make([]int, 0)
	dp = append(dp, 0)
	for i := 1; i <= lth2; i++ {
		dp = append(dp, dp[i-1]+int(u2[i-1]))
	}

	for i := 1; i <= lth1; i++ {
		_ij := dp[0]
		dp[0] = _ij + int(u1[i-1])
		for j := 1; j <= lth2; j++ {
			tmpj := dp[j]
			if u1[i-1] == u2[j-1] {
				dp[j] = _ij
			} else {
				dp[j] = min(dp[j]+int(u1[i-1]), dp[j-1]+int(u2[j-1]))
			}
			_ij = tmpj
		}
	}

	return dp[lth2]
}

func main() {
	fmt.Println(">>>", minimumDeleteSum("delete", "leet"))
}
