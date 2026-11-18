# GENPAREN

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Generate All Well-Formed Parentheses

You are given an integer  **n**, representing the number of pairs of parentheses. Your task is to  **generate all possible combinations**  of well-formed (balanced) parentheses using exactly  **n pairs**.

A parentheses string is considered  **well-formed**  if:

- Every opening bracket '(' has a corresponding closing bracket ')'.
- The brackets are correctly nested.

Return all valid combinations  **in lexicographical order**.

### Lexicographical order:

Lexicographical order is the  **dictionary order**  of strings.

- Characters are compared left to right
- '(' comes before ')' in ASCII '(' = ASCII 40 ')' = ASCII 41
- So any string with '(' at an earlier position is smaller
## Function Declaration
### Function Name

$generate$ – This function generates all possible combinations of well-formed (balanced) parentheses using exactly $n$ pairs and returns them in lexicographical order.

### Parameters
- $n$ : A number representing the number of pairs of parentheses.
### Return Value
- Returns a collection (array) of strings.
- Each string represents a valid well-formed parentheses combination using exactly $n$ pairs.
- The returned collection is sorted in lexicographical order.
## Constraints
- $1 \leq n \leq 8$
- Only characters '(' and ')' are allowed
- All valid combinations must be generated exactly once
### Input Format
- The first line contains a single integer $n$ — the number of pairs of parentheses.
### Output Format
- Print all valid parentheses combinations.
- Each combination should be printed on a new line.
- Output must be in lexicographical order.
### Sample 1:
Input
Output

```
2

```

```
(())
()()

```

### Sample 2:
Input
Output

```
3

```

```
((()))
(()())
(())()
()(())
()()()

```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T09:41:24.886Z  

```c_cpp
void solve(int open, int close, int n, string s, vector<string>& ans) {
    if (open == n && close == n) {
        ans.push_back(s);
        return;
    }
    if (open < n) solve(open + 1, close, n, s + "(", ans);
    if (close < open) solve(open, close + 1, n, s + ")", ans);
}

vector<string> generate(int n) {
    vector<string> ans;
    solve(0, 0, n, "", ans);
    return ans;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/GENPAREN)