# RXYOO01

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Chef Finds Palindromic Subsequence

Chef has discovered a mysterious string and wants to explore its hidden palindromic structure. Specifically, Chef wants to find the  **length of the longest palindromic subsequence**  within the string.

A  **subsequence**  is formed by deleting zero or more characters from the string  **without changing the order**  of the remaining characters.

A  **palindromic subsequence**  reads the same forwards and backwards.

Help Chef determine the  **maximum possible length**  of such a subsequence.

## Function Declaration
### Function Name

$findLongestPalindromicSubsequenceLength$

### Parameters
- $inputString$ (string): The string in which the longest palindromic subsequence length is to be found. The string consists of lowercase and/or uppercase English letters.
### Return Value
- Returns an integer $resultLength$
- $resultLength$ represents the length of the longest palindromic subsequence in $inputString$.
## Constraints
- $1 \le T \le 10^5$
- $1 \le |inputString| \le 1000$
- $inputString$ consists only of lowercase and/or uppercase English letters
## Input Format
- The first line contains a single integer $T$ — the number of test cases.
- Each of the next $T$ lines contains a single string $inputString$.
## Output Format
- For each test case, print a single integer — the length of the longest palindromic subsequence in $inputString$.
### Sample 1:
Input
Output

```
3
abca
racecar
abcd
```

```
3
7
1
```

### Explanation:
- Test Case 1: $\texttt{"abca"}$ The longest palindromic subsequence is $\texttt{"aba"}$, so the length is $3$.
- Test Case 2: $\texttt{"racecar"}$ The entire string is a palindrome, so the length is $7$.
- Test Case 3: $\texttt{"abcd"}$ There are no repeating characters, so the longest palindromic subsequence is any single character, and the length is $1$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-22T14:19:20.177Z  

```c_cpp
int findLongestPalindromicSubsequenceLength(string inputString) {
    int n = inputString.size();
    if(n== 0)  return 0;
     vector<int> dp(n, 0);
     for(int i = n - 1; i >= 0; i--) {
         dp[i] = 1;
         int prev = 0;
         for(int j = i + 1; j < n; j++) {
             int temp = dp[j];
             if(inputString[i] == inputString[j]) {
                 dp[j] = 2 + prev;
             } else {
                 dp[j] = max(dp[j], dp[j - 1]);
             }
             prev = temp;
         }
     }
    return dp[n-1];
}
```

---

[View on CodeChef](https://www.codechef.com/problems/RXYOO01)