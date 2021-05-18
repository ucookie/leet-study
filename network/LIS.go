/*
Longes Increasing Subsequence

给定一些标记了宽度和高度的信封，宽度和高度以整数对形式（w, h）出现。当
另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封
里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放
到另一个信封里面）。

说明：
不允许旋转信封。

示例：

 输入：envelopes = [[5,4], [6,4], [6,7], [2Z3]]
 输出：3
 解释：最多信封的个数为3,组合为：[2,3] => [5,4] => [6,7]。

*/

package main

import (
	"fmt"
	"sort"
)

type enve [][]int

func (e enve) Len() int { return len(e) }
func (e enve) Less(i, j int) bool {
	if e[i][0] == e[j][0] {
		return e[i][1] > e[j][1]
	}
	return e[i][0] < e[j][0]
}
func (e enve) Swap(i, j int) {
	e[i], e[j] = e[j], e[i]
}

func maxEnvelopes(e enve) int {
	fmt.Println("排序前:", e)
	sort.Stable(e)
	h := []int{}
	for _, v := range e {
		h = append(h, v[1])
	}
	fmt.Println("排序后:", e)
	return lthOfLis2(h)
}

func lthOfLis(nums []int) int {
	piles := 0
	top := make([]int, len(nums))
	for _, v := range nums {
		left := 0
		right := piles
		for left < right {
			mid := (left + right) / 2
			if top[mid] >= v {
				right = mid
			} else {
				left = mid + 1
			}
		}
		if left == piles {
			piles += 1
		}
		top[left] = v
	}
	fmt.Println(top)
	return piles
}

func lthOfLis2(nums []int) int {
	lth := len(nums)
	if lth == 1 {
		return 1
	}

	dp := make([]int, lth)
	dp[0] = 1
	for i := 1; i < lth; i++ {
		maxDP := 0
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] && dp[j] > maxDP {
				maxDP = dp[j]
			}
		}
		dp[i] = maxDP + 1
	}
	maxLth := 0
	for _, v := range dp {
		if v > maxLth {
			maxLth = v
		}
	}

	return maxLth
}
func main() {
	envelopes := [][]int{
		[]int{5, 4},
		[]int{6, 4},
		[]int{6, 7},
		[]int{2, 3},
	}
	fmt.Println("测试子序列:", lthOfLis2([]int{3, 4, 7, 4}))

	fmt.Println("最多信封:", maxEnvelopes(envelopes))

}
