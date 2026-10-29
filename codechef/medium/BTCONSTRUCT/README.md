# BTCONSTRUCT

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Construct Binary Tree

Construct and return a binary tree using two integer arrays, `preorder` and `inorder`. The `preorder` array represents the preorder traversal of the binary tree, while the `inorder` array represents the inorder traversal of the same tree.

 **Example:** 
`Preorder` array: [1, 2, 3, 4, 5]
`Inorder` array: [2, 1, 4, 3, 5]

The constructed tree

### Input Format
- The first line of the input contains a single integer $N$ — the number of nodes in the binary tree.
- The next line contains $N$ space separated integers, the preorder array.
- The next line contains $N$ space separated integers, the inorder array.
### Output Format

Complete the given function in the IDE which returns the root of the constructed binary tree. Output will be `Well Done!` if the tree is constructed correctly, otherwise Runtime errors.

### Constraints
- $1 \leq N \leq 10000$
- $1 \leq preorder_i \leq 100000$
- $1 \leq inorder_i \leq 100000$
### Sample 1:
Input
Output

```
5
1 2 3 4 5
2 1 4 3 5
```

```
Well Done!
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T10:20:06.787Z  

```c_cpp
/*
struct Node {
    int val; 
    Node *left;
    Node *right;

    Node(int node_value) {
        val = node_value;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    int idx = 0;

    Node* build(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start > end)
            return NULL;

        Node* root = new Node(preorder[idx]);
        idx++;

        int pos = start;
        while (inorder[pos] != root->val)
            pos++;

        root->left = build(preorder, inorder, start, pos - 1);
        root->right = build(preorder, inorder, pos + 1, end);

        return root;
    }
    Node* constructBinaryTree(vector<int> &preorder, vector<int> inorder) {
        idx = 0;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/BTCONSTRUCT)