/*
583. 两个字符串的删除操作
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"

*/

package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func minDistance(word1 string, word2 string) int {
	u1 := []rune(word1)
	u2 := []rune(word2)

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

	return lth1 + lth2 - 2*dp[lth2]

}

func main() {
	fmt.Println(minDistance("sea", "eat"))
}
