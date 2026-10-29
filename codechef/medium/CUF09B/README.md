# CUF09B

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Student Directory Add and Remove
### Goal

The directory is online but read-only — it fetches the list and displays nothing else. The database connection, seed data, GET route and stylesheet are built. Everything that creates or destroys a record is missing, on both the backend and the frontend.

Build the two routes, then the form and the delete button that use them.

You won't write any CSS. Read `App.css` to find the class names the markup needs.

### By the end, you'll have
- A POST route that inserts a student into MongoDB
- A DELETE route that removes one by _id
- A form that adds a student without reloading the page
- A delete button on every row that clears the record from the table and the database
### Student Document Fields
Field	Type
`name`	String
`roll_number`	String
`department`	String
`cgpa`	Number
`year`	Number
### Task 1 — POST Route

In `routes.js`, declare a POST route on `/` that:

- Inserts the student from req.body into the students collection
- Stores cgpa and year as Numbers — the form sends every field as a string
- Responds with 201 and the inserted document, _id included
- Handles failure the same way the GET route does
### Task 2 — DELETE Route

In `routes.js`, declare a DELETE route on `/:id` that:

- Deletes the matching document from the students collection
- Converts req.params.id to an ObjectId first — the URL gives a string, MongoDB stores an ObjectId
- Responds with 200 and { deleted: true }
- Handles failure the same way the GET route does
### Task 3 — Add-Student Form

In `App.jsx`, build a controlled form above the loading, error and empty blocks that:

- Keeps all five fields in state and updates only the edited one as the user types
- POSTs to /api/students as JSON with the Content-Type: application/json header set
- Clears itself once the request succeeds
- Puts the new student in the table without a page reload
### Task 4 — Table Rows and Delete

In `App.jsx`, fill the empty `<tbody>` so that:

- Each student renders as one row — the five fields in the order above, then a delete button
- Rows are keyed by _id
- The button sends a DELETE to /api/students/:id for its own student
- The row disappears without a page reload, and the record is gone from MongoDB too — reopening the page must not bring it back

 **Note:**  `initDB()` reseeds three students on every server start, so restarting the server discards anything added through the form.

### Expected Behaviour

 **On load** 

- The table shows three students — Aarav Mehta, Diya Nair, Rohan Iyer — sorted by name, with a delete button on each row

 **Adding a student** 

- Fill the five fields and submit — the student appears in the table instantly, no page reload, and the form clears
- CGPA and year show as numbers, not text, because the route converts them

 **Deleting a student** 

- Click Delete — the row disappears immediately
- Refresh the page and it stays gone, because the record was removed from MongoDB too

 **After a server restart** 

- Back to the same three seeded students; anything added through the form is gone

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T10:42:19.258Z  

```cpp
            body: JSON.stringify(formData)
        });

        if (!res.ok) {
            throw new Error("Failed to add student");
        }

        const student = await res.json();

        setStudents((prev) =>
            [...prev, student].sort((a, b) =>
                a.name.localeCompare(b.name)
            )
        );

        setFormData({ ...emptyForm });
        setErrorMessage("");
        setStatus("loaded");
    } catch (err) {
        setErrorMessage(err.message);
        setStatus("error");
    }
}

async function handleDelete(id) {
    try {
        const res = await fetch(`${API_URL}/${id}`, {
            method: "DELETE"
        });

        if (!res.ok) {
            throw new Error("Failed to delete student");
        }

        await res.json();

        setStudents((prev) =>
            prev.filter((student) => student._id !== id)
```

---

[View on CodeChef](https://www.codechef.com/problems/CUF09B)