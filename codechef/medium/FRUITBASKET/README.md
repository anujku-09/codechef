# FRUITBASKET

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Put fruits into basket

You have a row of fruit trees planted in a straight line, from left to right. An integer array $fruits$ represents the trees, where $fruits[i]$ denotes the type of fruit produced by the $i^\text{th}$ tree.

You have  **two baskets**, and each basket can carry  **only one type of fruit**, but there is no limit on the quantity of fruit in each basket. You want to collect the  **maximum number of fruits**  by following these rules:

- You can start picking fruits from any tree and must move to the right.
- You pick exactly one fruit from each tree you visit.
- You can only pick fruits that fit into your two baskets. Once you encounter a fruit type that doesn’t match the two types already in your baskets, you must stop collecting.

Return the  **maximum number of fruits**  you can collect for each test case.

## Function Declaration
### Function Name

$totalFruits$ – This function determines the maximum number of fruits that can be collected using at most two baskets, where each basket can hold only one type of fruit.

### Parameters
- $fruits$ : A reference to an integer array where $fruits[i]$ represents the type of fruit on the $i^{th}$ tree.
### Return Value
- Returns an integer representing the maximum number of fruits that can be collected following the given rules.
## Constraints
- $1 \leq t \leq 10^5$
- $1 \leq n \leq 10^5$
- The total number of elements across all test cases will not exceed $10^5$.
### Input Format
- The first line contains a single integer $t$ — the number of test cases.
- For each test case: The first line contains an integer $n$ — the number of trees. The second line contains $n$ integers representing the array $fruits$.
### Output Format
- For each test case, print a single integer — the maximum number of fruits that can be collected.
### Sample 1:
Input
Output

```
2
5
3 3 2 1 3
4
1 2 1 2
```

```
3
4
```

### Explanation:

 **Test case 1:**  `[3, 3, 2, 1, 3]`

- Start at the first tree: baskets can hold 3 and 2.
- You can pick 3, 3, 2 before encountering 1, which doesn’t fit.
- Maximum fruits collected: 3.

 **Test case 2:**  `[1, 2, 1, 2]`

- Start at the first tree: baskets hold 1 and 2.
- You can pick all four fruits 1, 2, 1, 2.
- Maximum fruits collected: 4.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T14:23:50.535Z  

```c_cpp
class Solution {
public:
    int totalFruits(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int mx_fruits = 0;
        int l = 0;
        for(int r = 0; r < fruits.size(); r++){
            basket[fruits[r]]++;
            
            while(basket.size() > 2){
                basket[fruits[l]]--;
                if(basket[fruits[l]] == 0){
                    basket.erase(fruits[l]);
                }
                l++;
            }
            mx_fruits = max(mx_fruits, r - l + 1);
        }
        return mx_fruits;
    }
};

```

---

[View on CodeChef](https://www.codechef.com/problems/FRUITBASKET)