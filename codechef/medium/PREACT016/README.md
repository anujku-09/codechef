# PREACT016

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Props in React

We have already created a greeting card in the last lesson! Now, we will use  **components and props**  to make the solution more efficient and reusable.

#### Your Task:
- Create a reusable component <GreetingCard /> that takes name, age, and greeting as props.
- Use instances of <GreetingCard /> inside the App component with values for name, age, and greeting.
- Make sure not change the messages.

 **Note - Make sure to take the** `styles` **and** `jsx` **from the App component.** 
Once you're done, submit your solution and check it's correct not.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-03T18:24:03.838Z  

```cpp
    <div style={cardStyle}>
        

    return (
    };
        fontSize: "20px"
        color: "blue",
    const headingStyle = {
    }; 
  
        boxShadow: "2px 2px 10px rgba(0,0,0,0.1)"
        textAlign: "center",
        width: "250px",
        borderRadius: "10px", 
export function GreetingCard({ name, age, greeting }) {
    const cardStyle = {
        border: "2px solid #333", 
        padding: "20px", 
// Task: Convert this code to use a reusable component `<GreetingCard />`  
// Instead of hardcoding values, pass `name`, `age`, and `greeting` as props  
// Use instances of `<GreetingCard />` inside `App` 

```

---

[View on CodeChef](https://www.codechef.com/problems/PREACT016)