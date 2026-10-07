# JDBCEPROJ1

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Practice Problem - Library Book Management
### Instructions:
- Complete your code first.
- Click on "Run" to compile and run the program, and make sure it runs correctly.
- If you make any changes to the code after running, you must run the program again.
- At last, after running the code, click on "Submit".
### Goal :

Connect to an H2 database using JDBC and display all records from the `Book` table, using an MVC structure. All files are already provided. Complete the code in each file as described below. Do not rename any class or method.

### Project Structure :

```
book-jdbc/
├── pom.xml (H2 dependency already added)
└── src/main/java/com/example/
    ├── Main.java (already complete)
    ├── util/
    │   ├── DBConnection.java
    │   └── DatabaseInitializer.java
    ├── model/
    │   └── Book.java
    ├── dao/
    │   └── BookDAO.java
    ├── view/
    │   └── BookView.java
    └── controller/
        └── BookController.java

```

### Your Task :
### 1. util/DBConnection.java
- Complete getConnection() to return a connection using DriverManager.
- URL: jdbc:h2:./bookdb, Username: sa, Password: ""
### 2. model/Book.java
- Complete the constructor Book(int bookId, String title, String author, double price) and the getters and setters.
### 3. util/DatabaseInitializer.java
- Complete initialize() to create the Book table (BookID INT PRIMARY KEY, Title VARCHAR(150), Author VARCHAR(100), Price DECIMAL(10,2)) if it does not exist.
- Insert these rows only if the table is empty:
BookID	Title	Author	Price
201	Clean Code	Robert C. Martin	499.00
202	Effective Java	Joshua Bloch	650.50
203	Head First Java	Kathy Sierra	575.00
204	The Pragmatic Programmer	Andrew Hunt	720.25
### 4. dao/BookDAO.java
- Complete getAllBooks() to fetch all rows from the Book table ordered by BookID in ascending order and return them as a List<Book>.
- Return an empty list, not null, if the table has no rows.
### 5. view/BookView.java
- Complete displayBooks(List<Book>) to print all records, with prices shown to 2 decimal places, followed by Total books: <count>.
- If the list is empty, print No records found in Book table.
- Complete displayError(String message) to print Error: <message> to System.err.
### 6. controller/BookController.java
- Complete showAllBooks() to get the books from the DAO and pass them to the view.
- If a SQLException occurs, catch it and call view.displayError(...).
### Expected Output :

```
| BookID | Title                    | Author           |  Price |
| -----: | ------------------------ | ---------------- | -----: |
|    201 | Clean Code               | Robert C. Martin | 499.00 |
|    202 | Effective Java           | Joshua Bloch     | 650.50 |
|    203 | Head First Java          | Kathy Sierra     | 575.00 |
|    204 | The Pragmatic Programmer | Andrew Hunt      | 720.25 |

Total books: 4

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-07T08:37:35.335Z  

```cpp
        System.out.println(line);
        for (Book b : books) {
            System.out.printf("| %-6d | %-26s | %-18s | %10.2f |%n",
                    b.getBookId(), b.getTitle(), b.getAuthor(), b.getPrice());
        }
        System.out.println(line);
        System.out.println("Total books: " + books.size());
    }

    public void displayError(String message) {
        System.err.println("Error: " + message);
    }
}

```

---

[View on CodeChef](https://www.codechef.com/problems/JDBCEPROJ1)