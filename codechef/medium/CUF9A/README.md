# CUF9A

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### React + Express Student List
### Goal
- Build a full-stack student list application using React and Express.
- The Express backend reads student data from backend/db.json and serves it through an API; the React frontend fetches that data and displays it.
### By the end, you'll have
- An Express server exposing a student API with CORS enabled
- A React page that loads students from the API on mount
### Task 1 — Create the Student API
- In backend/server.js: Create an Express server listening on port 4000. Enable CORS for all routes. Create a GET /api/students endpoint. Read the student data from backend/db.json. Return the students as a JSON array, unchanged.
### Task 2 — Fetch Students in React
- In src/pages/Contacts.jsx: Store the students in React state. Fetch the data from http://localhost:4000/api/students when the component first loads. Use useEffect for the request. Do not hard-code the student data in the component.
### Task 3 — Display the Students
- Render every student returned by the API on the page.
- Each student card must show: Name Email Course Age
- All students must be visible on the page without any further navigation or clicks.
### Task 4 — Render the Page
- In src/App.jsx, render the Contacts component.
### Expected Output

 **Note** 

- Please run the code before submitting it.
- backend/db.json is provided with the required student data. Do not modify it.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T10:35:00.326Z  

```cpp
        });
    }
});

export { app };
export default app;

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});

```

---

[View on CodeChef](https://www.codechef.com/problems/CUF9A)