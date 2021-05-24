/*435. 无重叠区间
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

*/

package main

import (
	"fmt"
	"sort"
)

type obj [][]int

func (e obj) Len() int { return len(e) }
func (e obj) Less(i, j int) bool {
	return e[i][1] < e[j][1]
}
func (e obj) Swap(i, j int) {
	e[i], e[j] = e[j], e[i]
}
func eraseOverlapIntervals(intervals [][]int) int {
	ii := obj(intervals)
	sort.Sort(ii)
	fmt.Println(ii)

	count := 1
	x_end := ii[0][1]
	for i := 1; i < ii.Len(); i++ {
		start := ii[i][0]
		if start >= x_end {
			count += 1
			x_end = ii[i][1]
		}
	}
	return ii.Len() - count
}

func main() {
	intervals := [][]int{
		[]int{1, 2},
		[]int{2, 3},
		[]int{3, 4},
		[]int{1, 3},
	}
	aa := eraseOverlapIntervals(intervals)
	fmt.Println(">>>", aa)
}
