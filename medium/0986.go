/*
986. 区间列表的交集
给定两个由一些 闭区间 组成的列表，firstList 和 secondList ，
其中 firstList[i] = [starti, endi] 而 secondList[j] = [startj, endj] 。每个区间列表都是成对 不相交 的，并且 已经排序 。
返回这 两个区间列表的交集 。
形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b 。
两个闭区间的 交集 是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3] 。

示例 1：
输入：firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
*/

package main

import (
	"fmt"
)

func intervalIntersection(firstList [][]int, secondList [][]int) [][]int {
	// 构造序列
	ret := make([][]int, 0)
	var i, j int
	for i < len(firstList) && j < len(secondList) {
		if firstList[i][1] > secondList[j][0] || secondList[j][1] > firstList[i][0] {
			s, e := max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])
			if s <= e {
				ret = append(ret, []int{s, e})
			}
		}
		if firstList[i][1] < secondList[j][1] {
			i++
		} else {
			j++
		}
	}
	return ret
}

func max(i, j int) int {
	if i >= j {
		return i
	}
	return j
}
func min(i, j int) int {
	if i <= j {
		return i
	}
	return j
}

func main() {
	var firstList = [][]int{[]int{0, 2}, []int{5, 10}, []int{13, 23}, []int{24, 25}}
	var secondList = [][]int{[]int{1, 5}, []int{8, 12}, []int{15, 24}, []int{25, 26}}
	aa := intervalIntersection(firstList, secondList)
	fmt.Println(">>>", aa)
}
