/*
116. 填充每个节点的下一个右侧节点指针
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

进阶：
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
*/
package main

import (
	"fmt"
)

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

func print(root *Node) {
	if root == nil {
		return
	}

	print(root.Left)
	fmt.Printf("%d, ", root.Val)
	print(root.Right)
}
func c2(left, right *Node) {
	if left == nil || right == nil {
		return
	}
	left.Next = right

	c2(left.Left, left.Right)
	c2(right.Left, right.Right)
	c2(left.Right, right.Left)
}

func connect(root *Node) *Node {
	if root == nil {
		return root
	}
	c2(root.Left, root.Right)
	return root
}

func main() {
	root := &Node{
		Val: 4,
		Left: &Node{
			Val: 2,
			Left: &Node{
				Val: 1,
			},
			Right: &Node{
				Val: 3,
			},
		},
		Right: &Node{
			Val: 7,
			Left: &Node{
				Val: 6,
			},
			Right: &Node{
				Val: 9,
			},
		},
	}

	print(root)
}
