# THREESUM

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Zero Sum Triplets

Chef is arranging dishes on a table.
You are given an array of dishes with $N$ dishes. Each dish has a number (positive, negative, or zero).

Chef wants to know:
 **Can we pick any 3 different dishes indices such that their total is exactly 0?** 

Your task is to find all such unique triplets.

- A valid triplet contains 3 different numbers (on different indices) from the array.
- The same triplet should not repeat.
- Print each triplet in non-decreasing order.
- If no triplet exists return empty array that will be treated as print -1.
## Function Declaration
### Function Name

$findZeroSumTriplets$ – This function finds all unique triplets in the array whose sum is exactly zero.

### Parameters
- $nums$ : A reference to an integer array containing $N$ elements, where each element can be positive, negative, or zero.
### Return Value
- Returns a 2D array containing all unique triplets whose sum is 0.
- Each triplet is sorted in non-decreasing order.
- If no such triplet exists, return an empty array (this will be treated as printing -1).
## Constraints
- $3 \leq N \leq 3000$
- $-100000 \leq nums[i] \leq 100000$
### Input Format
- The first line contains a single integer $N$ — the number of elements in the array.
- The second line contains $N$ space-separated integers representing the array elements.
### Output Format
- Print all valid triplets, one triplet per line.
- Each triplet should contain three space-separated integers.
- If no triplet exists, print -1.
### Sample 1:
Input
Output

```
5
2 -2 0 1 -1

```

```
-2 0 2
-1 0 1
```

### Explanation:

Triplet `(-2, 0, 2)` -> sum = 0
Triplet `(-1, 0, 1)` -> sum = 0
These are the only unique triplets.

### Sample 2:
Input
Output

```
4
5 -3 -2 1

```

```
-3 -2 5

```

### Explanation:

Triplet `(-3, -2, 5)` -> sum = 0
No other triplet exists.

### Sample 3:
Input
Output

```
4
1 2 3 4

```

```
-1

```

### Explanation:

No three numbers add up to 0, so output is `-1`.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-17T19:07:47.460Z  

```c_cpp
vector<vector<int>> findZeroSumTriplets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            } else {
                ans.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            }
        }
    }
    return ans;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/THREESUM)