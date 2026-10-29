# CUF09C

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Student Directory - full CRUD
### Goal

The directory supports adding and removing students, but nothing else. A typo in a record means deleting it and typing it again, and finding one student in a long list means scrolling.

Build the four routes the directory is missing, then the search box, the editor, and the row controls that use them.

You won't write any CSS. `App.css` styles plain `<form>`, `<label>`, `<input>` and `<button>` elements directly, so correct markup is styled automatically — only the editor needs a class name, and that task says which.

### By the end, you'll have
- A POST route that inserts a student
- A PUT route that updates one by _id
- A DELETE route that removes one by _id
- A search route that filters on name, roll number or department
- A search box that re-queries the server as you type
- An editor that saves changes without a page reload
- A table that matches the database after every add, edit and delete
### Student Document Fields
- name — String
- roll_number — String
- department — String
- cgpa — Number
- year — Number
### Required Test Hooks

Three elements must carry a `data-testid`, exactly as written, or the grader cannot tell them apart from the others on the page:

- Search box — data-testid="search-input"
- Row edit button — data-testid="edit-button"
- Row delete button — data-testid="delete-button"

Give every input a `name` attribute matching its field — `name`, `roll_number`, `department`, `cgpa`, `year` — in both the add form and the editor.

### Task 1 — Search Route

In `routes.js`, declare a GET route on `/search` that:

- Reads the search term from req.query.q
- Returns every student whose name, roll_number or department contains that term — a match on any one of the three is enough
- Matches case-insensitively and on partial words: comp matches Computer Science
- Returns every student when q is missing or empty
- Sorts results by name ascending
- Responds with 200 and a JSON array
- Handles failure the same way the GET route does
- Is declared before any route with a path parameter, so /search is not swallowed by /:id
### Task 2 — POST Route

In `routes.js`, declare a POST route on `/` that:

- Inserts the student from req.body into the students collection
- Stores cgpa and year as Numbers — the form sends every field as a string
- Responds with 201 and the inserted document, _id included
- Handles failure the same way the GET route does
### Task 3 — PUT Route

In `routes.js`, declare a PUT route on `/:id` that:

- Updates the matching document with all five fields from req.body
- Converts req.params.id to an ObjectId first — the URL gives a string, MongoDB stores an ObjectId
- Stores cgpa and year as Numbers
- Responds with 200 and the document as it stands after the update, _id included
- Handles failure the same way the GET route does
### Task 4 — DELETE Route

In `routes.js`, declare a DELETE route on `/:id` that:

- Deletes the matching document from the students collection
- Converts req.params.id to an ObjectId first
- Responds with 200 and { deleted: true }
- Handles failure the same way the GET route does
### Task 5 — Add-Student Form

In `App.jsx`, build a controlled `<form>` above the table that:

- Holds one <label> and <input> per field, each input carrying a name attribute matching its field
- Keeps all five fields in state and updates only the edited one as the user types
- POSTs to /api/students as JSON with the Content-Type: application/json header set
- Clears itself once the request succeeds
- Puts the new student in the table without a page reload
### Task 6 — Live Search

In `App.jsx`, add a search `<input>` carrying `data-testid="search-input"` that:

- Sits on its own, not inside a <form>
- Keeps its term in state and is controlled by it
- Sends the term to /api/students/search as the q query parameter on every change
- Replaces the rendered list with the response
- Shows the full list again when the box is emptied
### Task 7 — Table Rows and Delete

In `App.jsx`, fill the empty `<tbody>` so that:

- Each student renders as one row — the five fields in the order listed above, then a final cell holding an edit button and a delete button
- Rows are keyed by _id
- The edit button carries data-testid="edit-button", the delete button data-testid="delete-button"
- The delete button sends a DELETE to /api/students/:id for its own student
- The row disappears without a page reload, and the record is gone from MongoDB too — reopening the page must not bring it back
- The edit button opens the editor for that student
### Task 8 — Edit a Student

In `App.jsx`, build the editor as a `<div className="modal">` wrapping a `<form>`, so that:

- Opening it loads the selected student's current values into its five inputs
- Every input carries a name attribute matching its field
- It is controlled — typing changes state, not the DOM alone
- Saving PUTs to /api/students/:id as JSON with the Content-Type: application/json header set
- The cancel button is a <button type="button">, so it closes the editor without submitting
- The row shows the new values once the request succeeds, without a page reload
- Cancelling changes nothing
- Only one student is editable at a time

 **Note:**  `initDB()` reseeds six students on every server start, so restarting the server discards anything added or edited through the UI.

### Expected Behaviour

 **On load** 

- The table shows six students sorted by name, each row with an edit and a delete button

 **Adding a student** 

- Submit the form — the student appears instantly and the form clears

 **Searching** 

- Type comp — only the two Computer Science students remain
- Type 1BM22EC — only the two Electronics students remain
- Clear the box — the full list returns

 **Editing a student** 

- Click Edit — a modal opens with that student's current values already filled in
- Save — the row shows the new values without a page reload
- Cancel — the modal closes and nothing changes

 **Deleting a student** 

- Click Delete — the row disappears, and stays gone after a refresh

 **After a server restart** 

- Back to the six seeded students; anything added or edited is gone

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T11:05:33.203Z  

```cpp
            </label>

            <label>
                Department
                <input
                    name="department"
                    value={editForm.department}
                    onChange={handleEditChange}
                    required
                />
            </label>

            <label>
                CGPA
                <input
                    type="number"
                    name="cgpa"
                    value={editForm.cgpa}
                    onChange={handleEditChange}
                    min="0"
                    max="10"
                    step="0.1"
                    required
                />
            </label>

            <label>
                Year
                <input
                    type="number"
                    name="year"
                    value={editForm.year}
                    onChange={handleEditChange}
                    min="1"
                    required
                />
            </label>

            <button type="submit">Save Changes</button>

            <button
                type="button"
                onClick={() => setEditingStudent(null)}
            >
                Cancel
            </button>
        </form>
    </div>
)}

        {status === "loading" && (
          <div className="loading-state" role="status">
            Opening the register…
          </div>
        )}
```

---

[View on CodeChef](https://www.codechef.com/problems/CUF09C)