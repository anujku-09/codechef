# CUPRB2

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Books Management APIs

 **Problem: Book Management API (Filter & Delete)** 

You are given a partially implemented  **Express.js backend**  that manages a list of books stored  **in memory**  (no database is used).
Your task is to implement  **two API endpoints**  to filter and delete books.

## Given Data

The application maintains the following in-memory list of books:

```
[
  { title: "The Great Gatsby", author: "F. Scott Fitzgerald", publicationYear: 1925 },
  { title: "To Kill a Mockingbird", author: "Harper Lee", publicationYear: 1960 },
  { title: "1984", author: "GeoddddOrwell", publicationYear: 1949 },
  { title: "Pride and Prejudice", author: "Jane Austen", publicationYear: 1813 },
  { title: "The Catcher in the Rye", author: "J.D. Salinger", publicationYear: 1951 },
  { title: "Moby Dick", author: "Herman Melville", publicationYear: 1851 },
  { title: "Brave New World", author: "Aldous Huxley", publicationYear: 1932 },
  { title: "The Hobbit", author: "J.R.R. Tolkien", publicationYear: 1937 },
  { title: "The Lord of the Rings", author: "J.R.R. Tolkien", publicationYear: 1954 },
  { title: "Fahrenheit 451", author: "Ray Bradbury", publicationYear: 1953 },
  { title: "The Alchemist", author: "Paulo Coelho", publicationYear: 1988 },
  { title: "Animal Farm", author: "George Orwell", publicationYear: 1945 },
  { title: "The Da Vinci Code", author: "Dan Brown", publicationYear: 2003 },
  { title: "The Girl with the Dragon Tattoo", author: "Stieg Larsson", publicationYear: 2005 },
  { title: "Harry Potter and the Sorcerer's Stone", author: "J.K. Rowling", publicationYear: 1997 }
]

```

## Tasks
### 1. Filter Books by Author

 **Endpoint:** 
`GET /books`

 **Behavior:** 

- If no query parameter is provided → return all books
- If author is provided → return only the books written by that author
- Matching must be exact
### 2. Delete Book by Title

 **Endpoint:** 
`DELETE /books/:title`

 **Behavior:** 

- If the book exists: Remove it from the in-memory list Return: { "message": "Book deleted successfully" }
- If the book does not exist: Return HTTP 404 Return: { "message": "Book not found" }

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-14T12:42:48.846Z  

```cpp
});
      return res.status(404).json({
        message: "Book not found"
      });
    }

    books.splice(index, 1);

    res.json({
      message: "Book deleted successfully"
    });
  } catch (error) {
    res.status(500).json({
      message: "Error deleting book",
      error: error.message
    });
  }

// Server
app.listen(PORT, () => {
  console.log(`🚀 Server running at http://localhost:${PORT}`);
});

export default app;


```

---

[View on CodeChef](https://www.codechef.com/problems/CUPRB2)