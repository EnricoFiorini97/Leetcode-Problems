'''
Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: TreeNode, nodes: List[int]) -> int:
        if root:
            self.dfs(root.left, nodes)
            nodes.append(root.val)
            self.dfs(root.right, nodes)
        
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        keys = []
        self.dfs(root, keys)
        keys.sort()
        return keys[k - 1]

