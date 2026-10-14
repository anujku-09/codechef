# KSUBARRAYS

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Subarray with k distinct number

You are given an integer array $arr$ and an integer $k$. Your task is to find the number of contiguous subarrays in $arr$ that contain  **exactly k distinct integers**.

A subarray is defined as a continuous and non-empty sequence of elements within the array.

## Function Declaration
### Function Name

$subarraysWithKDistinct$ – This function computes the number of contiguous subarrays that contain exactly  **k distinct integers**.

### Parameters
- $arr$ : A list/array of integers of length $n$, representing the input sequence.
- $k$ : An integer representing the required number of distinct elements.
### Return Value

Returns an integer: The total number of contiguous subarrays that contain exactly  **k distinct integers**. If there are no such  **good arrays**  then return $0$ value.

### Constraints:
- $1 \leq T \leq 100$
- $1 \leq n \leq 2 \cdot 10^4$
- $1 \leq k \leq n$
- $1 \leq nums[i] \leq n$ for each $1 \leq i \leq n$
- The sum of $n$ over all test cases won't exceed $2 \cdot 10^5$

 **The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled automatically** 

### Input Format
- The first line contains an integer $T$, the number of test cases.
- For each test case: The first line contains two integers: $n$ (the size of the array) and $k$. The second line contains $n$ integers representing the array elements.
### Output Format

For each test case, output a single integer — the number of good subarrays.

### Sample 1:
Input
Output

```
2
5 2
4 5 4 5 1
4 3
1 2 2 3
```

```
7
1
```

### Explanation:
- Test case 1: Array [4, 5, 4, 5, 1] Good subarrays with exactly 2 distinct integers are: [4,5], [5,4], [4,5], [5,1], [4,5,4], [5,4,5], [4,5,4,5] -> 7 subarrays
- Test case 2: Array [1, 2, 2, 3] Good subarrays with exactly 3 distinct integers are: [1,2,2,3] -> 1 subarrays

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-14T12:50:51.237Z  

```c_cpp
class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        if (k <= 0) return 0;
        
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        int left = 0, distinct = 0, count = 0;
        
        for (int right = 0; right < n; right++) {
            if (freq[nums[right]] == 0) {
                distinct++;
            }
            freq[nums[right]]++;
            
            while (distinct > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    distinct--;
                }
                left++;
            }
            
            count += (right - left + 1);
        }
        
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/KSUBARRAYS)