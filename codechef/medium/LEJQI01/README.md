# LEJQI01

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Chef Builds Stack

Chef wants to design a special stack that not only supports the usual stack operations but also allows retrieving the  **minimum element**  instantly.
To achieve this, Chef needs a stack implementation that can perform all operations in constant time  **$O(1)$**.

The stack should efficiently handle a large number of operations without delay.

### Class Description

Chef will implement a class named  **$minimumStack$**.

The class supports the following operations:

- $addValue(val)$ Adds the integer $val$ onto the stack.
- $removeTopValue()$ Removes the top element from the stack.
- $getTopValue()$ Returns the top element of the stack.
- $getMinimumValue()$ Returns the minimum element currently present in the stack.
### Constraints
- $-2^{31} \le val \le 2^{31} - 1$
- Operations $removeTopValue$, $getTopValue$, and $getMinimumValue$ will always be called on a non-empty stack.
- At most $3 \times 10^4$ calls will be made to: $addValue$ $removeTopValue$ $getTopValue$ $getMinimumValue$
### Input Format
- The first line contains a single integer $T$ — the number of test cases.
- For each test case: A sequence of operations is performed on the $minimumStack$. Each operation is one of the following: addValue val removeTopValue getTopValue getMinimumValue
### Output Format
- For each operation that returns a value ($getTopValue$, $getMinimumValue$), print the integer result on a new line.
- For operations that do not return a value ($addValue$, $removeTopValue$), print None.
### Sample 1:
Input
Output

```
2
7
push -2
push 0
push -3
getMin
pop
top
getMin
2
push -3
getMin
```

```
None
None
None
-3
None
0
-2
None
-3
```

### Explanation:
### Explanation
#### Test Case 1

Initially, the stack is empty.

- push -2 The value -2 is pushed onto the stack. Since the stack was empty, -2 is also the minimum element. Output: None
- push 0 The value 0 is pushed onto the stack. The minimum element remains -2. Output: None
- push -3 The value -3 is pushed onto the stack. Since -3 is smaller than the current minimum, it becomes the new minimum. Output: None
- getMin The current minimum element in the stack is -3. Output: -3
- pop The top element -3 is removed from the stack. The minimum element updates back to -2. Output: None
- top The current top element of the stack is 0. Output: 0
- getMin The current minimum element in the stack is -2. Output: -2

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-17T17:49:57.654Z  

```c_cpp
class minimumStack {
    stack<int> st, minSt;
public:
    minimumStack() {}

    void addValue(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
        else
            minSt.push(minSt.top());
    }

    void removeTopValue() {
        st.pop();
        minSt.pop();
    }

    int getTopValue() {
        return st.top();
    }

    int getMinimumValue() {
        return minSt.top();
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/LEJQI01)