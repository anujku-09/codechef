# UAAIW01

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Chef Finds Divisible Subset

Chef has a set of distinct positive integers and wants to find the largest subset from this set with a special property: for every pair of integers $(a, b)$ in the subset, either $a$ divides $b$ or $b$ divides $a$. Chef wants to identify such a subset that contains the maximum possible number of elements. Help Chef by writing a function that returns any one of these largest divisible subsets sorted in ascending order.

## Function Declaration
### Function Name

$findLargestDivisibleSubset$ - This function finds the largest subset of the given numbers where for every pair $(a, b)$ in the subset, either $a$ divides $b$ or $b$ divides $a$.

### Parameters
- $inputNumbers$: A reference to a vector of integers representing the input set of numbers.
- The input contains distinct positive integers with no guaranteed order.
### Return Value
- Returns a number containing the largest divisible subset.
- The returned subset is sorted in ascending order.
- The subset represents the maximal collection of numbers where each pair satisfies the divisibility condition.
## Constraints
- $1 \leq N \leq 1000$
- $1 \leq \text{inputNumbers}[i] \leq 2 \times 10^{9}$
- All integers in $inputNumbers$ are unique.
## Input Format
- The first line contains a single integer $T$ — the number of test cases.
- For each test case: The first line contains an integer $N$ — the size of Chef's number array. The second line contains $N$ space-separated integers representing Chef's number array.
## Output Format
- For each test case, print a single line containing the elements of the largest divisible subset in ascending order, separated by spaces.
- If multiple solutions exist, Chef can print any one of them.
### Sample 1:
Input
Output

```
2
5
1 3 6 24 36
4
2 5 10 20
```

```
1 3 6 24 36
2 10 20
```

### Explanation:
- For the first test case, the entire set {1, 3, 6, 24, 36} forms a divisible chain since each number divides the next one.
- For the second test case, {2, 10, 20} is the largest subset where each element divides the next, excluding 5 which breaks the chain.
### Sample 2:
Input
Output

```
3
3
1 2 3
6
1 2 4 8 16 32
5
3 5 15 30 60
```

```
1 2
1 2 4 8 16 32
3 15 30 60
```

### Explanation:
- For input [1, 2, 3], the largest divisible subset is [1, 2] because 2 is divisible by 1, but 3 is not divisible by 2 or 1.
- For input [1, 2, 4, 8, 16, 32], all numbers form a chain where each number divides the next, so the entire array is the largest subset.
- For input [3, 5, 15, 30, 60], the subset [3, 15, 30, 60] is largest since each element divides the next, while 5 breaks the chain.
### Sample 3:
Input
Output

```
1
7
7 14 28 56 112 224 448
```

```
7 14 28 56 112 224 448
```

### Explanation:
- The input array is already sorted and each number divides the next one (7 divides 14, 14 divides 28, and so on).
- Hence, the entire array forms the largest divisible subset.
- Output is the full array: 7 14 28 56 112 224 448.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T14:15:13.723Z  

```c_cpp
vector<int> findLargestDivisibleSubset(vector<int>& inputNumbers) {
    int n = inputNumbers.size();
    if(n == 0) return {};
    
    
    
    sort(inputNumbers.begin(), inputNumbers.end());
    vector<int> dp(n, 1);
    vector<int> parent(n, -1);
    
    int mx_len = 1;
    int max_idx = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(inputNumbers[i] % inputNumbers[j] == 0) {
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if(dp[i]  > mx_len) {
            mx_len = dp[i];
            max_idx = i;
        }
    }
    vector<int> res;
    int curr = max_idx;
    while(curr != -1) {
        res.push_back(inputNumbers[curr]);
        curr = parent[curr];
    }
    return res;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/UAAIW01)