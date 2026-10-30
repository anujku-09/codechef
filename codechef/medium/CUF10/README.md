# CUF10

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Library Circulation Desk
### Goal
- The library runs on a paper register. Books are catalogued in MongoDB already, but every issue and return is written by hand, so nobody knows which copies are out or which are overdue.
- Build the circulation desk: the routes that add books, issue copies, take them back, and report what is currently out — then the two tables the librarian works from.
- The hard part is not the forms. Issuing a copy changes two collections at once: a loan is created and the book's availability drops. That rule lives in the route, not the UI.
### By the end, you'll have
- A route that adds a book to the catalogue
- A route that issues a copy to a student and decrements availability
- A route that takes a copy back and restores availability
- A route that reports every copy currently out, with overdue copies flagged
- A catalogue table with an add form and an issue button on every book
- A circulation table with a return button on every active loan
### Book Document Fields
Field	Type
`title`	String
`author`	String
`isbn`	String
`total_copies`	Number
`available_copies`	Number
### Loan Document Fields
Field	Type
`book_id`	ObjectId, referencing a book
`student_name`	String
`roll_number`	String
`issued_on`	Date
`due_on`	Date, fourteen days after `issued_on`
`returned_on`	Date, or `null` while the copy is still out
### Required Test Hooks
- Two buttons must carry a data-testid, exactly as written, or the grader cannot tell them apart from the others on the page: Issue button on a book row — data-testid="issue-button" Return button on a loan row — data-testid="return-button"
- Give every input a name attribute matching its field, in both the add-book form and the issue form.
### Task 1 — Add a Book
- In backend/routes.js, declare a POST route on /books that: Inserts the book from req.body into the books collection Stores total_copies as a Number — the form sends every field as a string Sets available_copies equal to total_copies, whatever the request body says Responds with 201 and the inserted document, _id included Handles failure the same way the GET route does
### Task 2 — Issue a Copy
- In backend/routes.js, declare a POST route on /loans that reads book_id, student_name and roll_number from req.body and: Converts book_id to an ObjectId before looking the book up Rejects with 409 and { error: "No copies available" } when that book's available_copies is 0, writing nothing to either collection Otherwise inserts a loan with issued_on set to the current date and time, due_on set to fourteen days later, and returned_on set to null Decrements that book's available_copies by 1 in the same request Responds with 201 and the inserted loan, _id included Handles failure the same way the GET route does
### Task 3 — Take a Copy Back
- In backend/routes.js, declare a PUT route on /loans/:id/return that: Converts req.params.id to an ObjectId first Rejects with 409 and { error: "Already returned" } when that loan's returned_on is not null, changing nothing Otherwise sets returned_on to the current date and time Increments that book's available_copies by 1 Responds with 200 and the loan as it stands after the update Handles failure the same way the GET route does
### Task 4 — Active Loans
- In backend/routes.js, declare a GET route on /loans/active that: Returns only loans whose returned_on is null Adds the borrowed book's title to each loan as a book_title field Adds an overdue field set to true when due_on is in the past, false otherwise Sorts results by due_on ascending, so the most overdue appears first Responds with 200 and a JSON array Is declared before any route with a path parameter, so /loans/active is not swallowed by /loans/:id Handles failure the same way the GET route does
### Task 5 — Catalogue Table and Add Form
- In src/App.jsx, build a controlled <form> above the catalogue that: Holds one <label> and <input> per field — title, author, isbn, total_copies — each input carrying a name attribute matching its field Keeps all four fields in state and updates only the edited one as the user types POSTs to /api/books as JSON with the Content-Type: application/json header set Clears itself once the request succeeds
- Then fill the catalogue <tbody> so that: Each book is one row — title, author, ISBN, then availability written as available_copies / total_copies Rows are keyed by _id Each row carries an issue button with data-testid="issue-button" The issue button opens a form asking for student_name and roll_number, each input carrying a name attribute matching its field, and POSTs to /api/loans with that book's _id A rejected issue shows the server's error message on the page and changes nothing A successful add or issue updates the tables without a page reload
### Task 6 — Active Loans Table
- In src/App.jsx, fill the circulation <tbody> so that: Each loan is one row — book title, student name, roll number, due date Rows are keyed by _id An overdue loan is marked by giving its row className="overdue" Each row carries a return button with data-testid="return-button" that PUTs to /api/loans/:id/return A returned loan disappears from the list, and that book's availability in the catalogue goes up by one, both without a page reload
### Notes
- You will not write any CSS. App.css styles plain <form>, <label>, <input>, <button> and <table> elements directly, so correct markup is styled automatically.
- initDB() reseeds the catalogue and the loan register on every server start, so restarting the server discards anything issued through the UI.
### Expected Behaviour

 **On load** 

- Catalogue shows five books with availability, e.g. "Clean Code" 2 / 3, "Design Patterns" 0 / 1
- Copies out shows two loans — Aarav Mehta and Diya Nair. Aarav's row is red, his copy was due six days ago
- Rohan Iyer is absent, his copy is already back

 **Adding a book** 

- Submit the form — the book appears instantly, fully available (6 / 6 for 6 copies), and the form clears

 **Issuing a copy** 

- Click Issue, fill in student name and roll number, submit
- Availability drops by one, a new row appears in Copies out, due two weeks from today
- On "Design Patterns" (0 / 1) it fails instead: a red No copies available message, nothing changes

 **Returning a copy** 

- Click Return — the row disappears and the book's availability goes up by one

 **After a server restart** 

- Everything resets to the seeded books and loans

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-30T17:16:34.390Z  

```cpp
  request succeeds.
  ===========================================
  */
  const [errorMessage, setErrorMessage] = useState("");

  /*
  ===========================================
  TASK 5 — add-book form state and handlers

  TODO: hold title, author, isbn and total_copies in state,
  update only the edited field as the user types, POST them
  to `${API_URL}/books` as JSON, and clear the form once the
  const [status, setStatus] = useState("loading");
  const [books, setBooks] = useState([]);
  const [loans, setLoans] = useState([]);

const API_URL = "/api";

export default function App() {
import React,{ useEffect, useState } from "react";
import "./App.css";

const [bookForm, setBookForm] = useState({
  title: "",
  author: "",
  isbn: "",
```

---

[View on CodeChef](https://www.codechef.com/problems/CUF10)