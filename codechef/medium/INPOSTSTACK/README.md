# INPOSTSTACK

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Infix to postfix using stack

You are given a string $S$ representing a  **valid infix arithmetic expression**.
Your task is to transform this expression into its corresponding  **postfix form**, also known as  **Reverse Polish Notation (RPN)**.

The expression may contain:

- Operands: Single lowercase English letters $(a \text{ to } z)$ Single-digit integers $(0 \text{ to } 9)$
- Binary operators: $+$, $-$, $*$, $/$, $\^{}$
- Parentheses: $(\text{ and })$ used to control grouping and precedence
### Operator Precedence (highest to lowest)
- $\^{}$ (Exponentiation)
- $*$, $/$ (Multiplication and Division)
- $+$, $-$ (Addition and Subtraction)
### Associativity Rules
- $\^{}$ is right-associative
- All other operators are left-associative
- Parentheses override the standard precedence rules
### Output Requirement

Return the equivalent postfix expression as a string.

- The resulting expression must contain no spaces
- No separators are allowed between characters
### Function Declarations

 **Function Name**  `infixToPostfix` – Transforms a valid infix arithmetic expression into its corresponding postfix form (Reverse Polish Notation).

- Parameters S : A string representing the valid infix arithmetic expression containing operands, binary operators, and parentheses.
- Return Value Returns a string representing the equivalent postfix expression. The resulting expression must contain no spaces and no separators between characters.
### Input Format
- The first line contains a single integer $T$, denoting the number of test cases.
- Each test case consists of one line containing a string $S$, representing a valid infix expression.
### Output Format

Return a string representing the equivalent postfix expression.

- The resulting expression must contain no spaces
- No separators are allowed between characters
### Constraints
- $1 \le T \le 10^4$
- $1 \le |S| \le 10^5$
- $S$ contains only: Lowercase letters $(a \text{ to } z)$ Digits $(0 \text{ to } 9)$ Operators $+, -, *, /, \^{}$ Parentheses $(\text{ and })$
- The expression $S$ is guaranteed to be valid.
- The sum of $|S|$ over all test cases does not exceed $10^6$.
### Sample 1:
Input
Output

```
3
a+b
(a+b)*c
a^b^c
```

```
ab+
ab+c*
abc^^
```

### Explanation:
- a+b $\rightarrow$ operands a and b with + $\rightarrow$ postfix ab+.
- (a+b) *c $\rightarrow$ parentheses force a+b first $\rightarrow$ postfix of (a+b) is ab+, then multiply by c $\rightarrow$ ab+c*.
- a^b^c $\rightarrow$ ^ is right-associative, so a^(b^c) is parsed. Postfix: a b c ^ ^ -> abc^^. (Associativity matters: if ^ were left-associative we'd get (a^b)^c $\rightarrow$ ab^c^, but here it's abc^^.)
### Sample 2:
Input
Output

```
2
a+b*c
3+42/(1-5)^2^3
```

```
abc*+
34215-23^^/+
```

### Explanation:
- a+b *c $\rightarrow$*  has higher precedence than +, so compute b *c first $\rightarrow$ postfix bc*, then a and + $\rightarrow$ abc*+.
- 3+4 *2/(1-5)^2^3 — step-by-step using precedence and associativity: 4* 2 $\rightarrow$ 42 *(1-5) $\rightarrow$ 15- ^ is right-associative, so 2^3 $\rightarrow$ 23^, then (1-5) ^ (2^3) $\rightarrow$ 15-23^^ Division by that result: 42*  15-23^^ / $\rightarrow$ 42 *15-23^^/ Finally 3 + (that) $\rightarrow$ prefix 3 then rest then + $\rightarrow$ 342* 15-23^^/+ Concise postfix: 342 *15-23^^/+ (matches printed output 342* 15-23^^/+).

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-17T18:12:09.837Z  

```c_cpp
class InfixToPostfix {
  int prec(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return 0;
    }
public:
    string infixToPostfix(string s) {
      stack<char> st;
        string ans = "";
        for (char c : s) {
            if (isalnum(c)) {
                ans += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && prec(st.top()) >= prec(c) && !(c == '^' && st.top() == '^')) {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
```

---

[View on CodeChef](https://www.codechef.com/problems/INPOSTSTACK)