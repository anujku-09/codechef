# JCWDLM14

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Create & Run a Simple Script using package.json

When building Node.js applications, one key file you’ll use is `package.json`. It acts as a  **blueprint**  for your project and helps manage dependencies and scripts.

### What’s inside package.json?

This file is written in JSON and includes:

- name & version: Identify your project.
- main: Entry point of your app (e.g., index.js).
- scripts: Custom commands like "start": "node index.js".
- dependencies & devDependencies: Packages your project needs.
### Why is it useful?
- 📦 Tracks dependencies
- ⚙️ Automates tasks with scripts
- 📁 Helps others set up your project easily with npm install
### What is node_modules?

When you install packages using `npm install`, they are downloaded into a folder called  **`node_modules`**.

- It contains all third-party packages your project depends on.
- It’s automatically generated based on your package.json.
- You shouldn’t edit anything inside node_modules.
- It is usually ignored in version control using.gitignore.

Example:

```
npm install express

```

- This adds express to node_modules
- And adds an entry under "dependencies" in your package.json.
### Let’s Create a Script with package.json

 **Step 1: Initialize `package.json`** 

Run this in your project folder:

```
npm init -y

```

This creates a default `package.json` file.

 **Step 2: Add a Script to `package.json`** 

In `package.json`, update the `scripts` section:

```
"scripts": {
  "start": "node index.js"
}

```

 **Step 3: Run the Script** 

Now run:

```
npm start

```

This runs the `start` script, which executes `node index.js`. You should see:

```
Hello from my Node.js script!

```

You’ve now created a working project with a script and learned how dependencies are handled in Node.js!

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T17:10:58.412Z  

```cpp
console.log("Hello from my Node.js script!");
```

---

[View on CodeChef](https://www.codechef.com/problems/JCWDLM14)