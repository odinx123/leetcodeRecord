# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findTarget(self, root, k):
        hash_map = set()
    
        def dfs(root, k):
            # Base Case
            if root == None: return False;
            # in has priority over minus
            if (k - root.val) in hash_map: return True;

            # Recursion relation
            hash_map.add(root.val)

            return dfs(root.left, k) | dfs(root.right, k);
        
        return dfs(root, k);