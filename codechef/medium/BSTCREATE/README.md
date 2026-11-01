# BSTCREATE

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Create BST from given sorted array

Create a height-balanced binary search tree from the given sorted integer array.

(**Note:**  A height-balanced binary tree is defined as a binary tree in which the depth difference between the two subtrees of every node is never more than one.)

For eg., the BST that can be created from the sorted array [1, 2, 3, 4, 5, 6, 7] is as follows:

### Input Format
- The first line of the input contains s single integer $N$ — the number of integers in the sorted array.
- Next line contains $N$ space separated sorted integers of the array.
### Output Format

Complete the given function which returns the root of created BST.

### Constraints
- $1 \leq N \leq 10000$
- $1 \leq nums_i \leq 100000$
### Sample 1:
Input
Output

```
13
13 26 54 59 69 71 76 78 84 91 95 96 100 
```

```
Successfully created BST!
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-01T16:25:58.405Z  

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
  Node* buildBST(const vector<int>& nums, int l, int r) {
        if (l > r) {
            return NULL;
        }

        int mid = l + (r - l) / 2;
        Node* root = new Node(nums[mid]);

        root->left = buildBST(nums, l, mid - 1);
        root->right = buildBST(nums, mid + 1, r);

        return root;
    }
    
  public:
    Node* createBST(vector<int> &nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/BSTCREATE)