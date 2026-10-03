# PREACT018

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Task

In this task, you will create a  **Profile Card**  component using React. This will involve  **JSX, React components, props, and basic CSS styling**.

#### 1. Create a ProfileCard Component
- This component should receive the following props: name → The person’s name bio → A short description about the person avatarUrl → URL of the person's profile image
- Inside the component, display these props properly using JSX.
#### 2. Use the ProfileCard Component inside App.js
- Inside the App component, render the ProfileCard component.
- Pass appropriate values for name, bio, and avatarUrl (make sure name, bio, avatarUrl not be null).

your final project should be like this

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-03T18:31:31.647Z  

```cpp
  const bio = "Frontend Developer | React Enthusiast | CodeChef User";

  return (
    <div>

      <h1 style={{ textAlign: "center", fontFamily: "Arial, sans-serif" }}>
        Profile Card
      </h1>

      {/* Render the ProfileCard component with user details */}
      <ProfileCard name = {name} bio = {bio} avatarUrl={avatarUrl} />

    </div>
  );
  const name = "John Doe";
  // update the user name and bio

};
  const avatarUrl = "https://cdn.codechef.com/images/problems/PREACT018/a29545c678c75e59bc684868407b1d13.webp";
const App = () => {
// Update the App component - Renders the ProfileCard component

```

---

[View on CodeChef](https://www.codechef.com/problems/PREACT018)