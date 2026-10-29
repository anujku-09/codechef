# BTCONSTRUCT

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T10:17:49.012Z  

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
    Node* createBST(vector<int> &nums) {
        if (nums.empty())
            return NULL;

        int mid = nums.size() / 2;

        Node* root = new Node(nums[mid]);

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());

        root->left = createBST(left);
        root->right = createBST(right);

        return root;
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/BTCONSTRUCT)