/*
437. 路径总和 III
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

*/
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSum(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	return pathSumStartWithRoot(root, targetSum) + pathSum(root.Left, targetSum) + pathSum(root.Right, targetSum)
}

func pathSumStartWithRoot(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	ret := 0
	if root.Val == targetSum {
		ret += 1
	}

	ret += pathSumStartWithRoot(root.Left, targetSum-root.Val) + pathSumStartWithRoot(root.Right, targetSum-root.Val)
	return ret
}

func main() {

}
