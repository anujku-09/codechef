# FOMQGS04

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Simulating a Delayed Greeting

Let's create a program that simulates a delayed greeting. We'll use both synchronous and asynchronous operations to illustrate the difference.

 **The Task:** 

We want to print three greetings: "Hello!", "World!", and "Goodbye!". However, we want to delay the "World!" greeting by 1 second using `setTimeout`. This will demonstrate how asynchronous operations allow the program to continue executing while waiting for the timer to complete.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T19:06:29.446Z  

```cpp
console.log("Hello!");

// complete the code from here:
setTimeout(() => {
    console.log("World!");
}, 1000);
console.log("Goodbye!")
```

---

[View on CodeChef](https://www.codechef.com/problems/FOMQGS04)