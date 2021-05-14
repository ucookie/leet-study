package main

import (
	"fmt"
)

func min2(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func min3(a, b, c int) int {
	d := min2(a, b)
	if d < c {
		return d
	}
	return c
}
func count(s1, s2 string) int {
	lth_1 := len(s1)
	lth_2 := len(s2)

	dp := make([][]int, 0)
	dp = append(dp, []int{0, 1, 2, 3})

	for i := 1; i <= lth_1; i++ {
		tmp := []int{i}
		for j := 1; j <= lth_2; j++ {
			tmp = append(tmp, -1)
		}
		dp = append(dp, tmp)
	}

	_s1 := []byte(s1)
	_s2 := []byte(s2)
	for i := 1; i <= lth_1; i++ {
		for j := 1; j <= lth_2; j++ {
			if _s1[i-1] == _s2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = min3(
					dp[i-1][j]+1,
					dp[i][j-1]+1,
					dp[i-1][j-1]+1,
				)
			}
		}
	}

	return dp[lth_1][lth_2]
}

// 压缩状态
func count2(s1, s2 string) int {
	lth_1 := len(s1)
	lth_2 := len(s2)

	dp := make([]int, 0)
	for i := 0; i <= lth_2; i++ {
		dp = append(dp, i)
	}

	_s1 := []byte(s1)
	_s2 := []byte(s2)
	for i := 1; i <= lth_1; i++ {
		pre := dp[0]
		dp[0] = i
		for j := 1; j <= lth_2; j++ {
			tmp := dp[j]
			if _s1[i-1] == _s2[j-1] {
				dp[j] = pre
			} else {
				dp[j] = min3(
					dp[j]+1,   // dp[i-1][j]
					dp[j-1]+1, // dp[i][j-1]
					pre+1,     // dp[i-1][j-1]
				)
			}
			pre = tmp
		}
	}

	return dp[lth_2]
}

const (
	ACT_SKIP = iota
	ACT_ADD  //增加
	ACT_DEL  //删除
	ACT_REP  //替换
)

type step struct {
	val int //步数
	act int //操作: 跳过,插入,删除,替换
}

func min4(a, b, c step) step {
	if a.val+1 < b.val+1 {
		if a.val+1 < c.val+1 {
			return step{a.val + 1, ACT_DEL}
		} else {
			return step{c.val + 1, ACT_REP}
		}
	} else {
		if b.val+1 < c.val+1 {
			return step{b.val + 1, ACT_ADD}
		} else {
			return step{c.val + 1, ACT_REP}
		}
	}
}

func count3(s1, s2 string) int {
	lth_1 := len([]rune(s1))
	lth_2 := len([]rune(s2))

	dp0 := []step{}
	for i := 0; i <= lth_2; i++ {
		dp0 = append(dp0, step{i, ACT_ADD})
	}

	dp := [][]step{dp0}
	// 初始化
	for i := 1; i <= lth_1; i++ {
		tmp := make([]step, 0)
		tmp = append(tmp, step{i, ACT_DEL})
		for j := 1; j <= lth_2; j++ {
			tmp = append(tmp, step{-1, ACT_SKIP})
		}
		dp = append(dp, tmp)
	}

	_s1 := []rune(s1)
	_s2 := []rune(s2)

	for i := 1; i <= lth_1; i++ {
		for j := 1; j <= lth_2; j++ {
			if _s1[i-1] == _s2[j-1] {
				dp[i][j] = dp[i-1][j-1]
				dp[i][j].act = ACT_SKIP
			} else {
				dp[i][j] = min4(
					dp[i-1][j],
					dp[i][j-1],
					dp[i-1][j-1],
				)
			}
		}
	}

	print_path(s1, s2, dp)
	return dp[lth_1][lth_2].val
}

func print_path(s1, s2 string, dp [][]step) {
	_s1 := []rune(s1)
	_s2 := []rune(s2)

	ret := []string{}
	for i := len(_s1); i >= 0; {
		for j := len(_s2); j >= 0; {
			if i == 0 || j == 0 {
				goto END
			}
			switch dp[i][j].act {
			case ACT_SKIP:
				i--
				j--
				ret = append(ret, fmt.Sprintf("位置 %d 跳过: %c", j, _s2[j]))
			case ACT_REP:
				i--
				j--
				ret = append(ret, fmt.Sprintf("位置 %d 替换: %c->%c", i, _s1[i], _s2[j]))
			case ACT_ADD:
				j--
				ret = append(ret, fmt.Sprintf("位置 %d 增加: %c", j, _s2[j]))
			case ACT_DEL:
				i--
				ret = append(ret, fmt.Sprintf("位置 %d 删除: %c", i, _s1[i]))
			default:
				fmt.Println("错误...")
			}
		}
	}
END:
	// 转换
	for i := len(ret) - 1; i >= 0; i-- {
		fmt.Println(ret[i])
	}
}

func main() {
	s1 := "你好世界"
	s2 := "不好世"
	aa := count3(s1, s2)
	fmt.Println(s1, "->", s2)
	fmt.Println("编辑距离：", aa)
}
