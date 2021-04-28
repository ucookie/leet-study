/*
56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*/
package main

import (
	"fmt"
	"sort"
)

func merge(intervals [][]int) [][]int {
	if len(intervals) == 1 {
		return intervals
	}

	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] > intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})

	ret := make([][]int, 0)
	tmp := intervals[0]
	for _, v := range intervals[1:] {
		if v[0] <= tmp[1] && v[1] >= tmp[1] {
			tmp[1] = v[1]
			continue
		}
		if v[0] > tmp[1] {
			ret = append(ret, tmp)
			tmp = v
		}
	}
	ret = append(ret, tmp)
	return ret
}

func main() {
	var intervals = [][]int{}
	intervals = append(intervals, []int{1, 3})
	intervals = append(intervals, []int{2, 6})
	intervals = append(intervals, []int{8, 10})
	intervals = append(intervals, []int{15, 18})
	aa := merge(intervals)

	fmt.Println(">>>", aa)
}
