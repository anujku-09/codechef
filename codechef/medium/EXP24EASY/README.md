# EXP24EASY

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Practice Problem - Employee Records with JDBC
### Goal :

Connect to an H2 database using JDBC and display all records from the `Employee` table, using an MVC structure. All files are already provided. Complete the code in each file as described below. Do not rename any class or method.

### Project Structure :

```
employee-jdbc/
├── pom.xml (H2 dependency already added)
└── src/main/java/com/example/
    ├── Main.java (already complete)
    ├── util/
    │   ├── DBConnection.java
    │   └── DatabaseInitializer.java
    ├── model/
    │   └── Employee.java
    ├── dao/
    │   └── EmployeeDAO.java
    ├── view/
    │   └── EmployeeView.java
    └── controller/
        └── EmployeeController.java

```

### Your Task :
### 1. util/DBConnection.java
- Complete getConnection() to return a connection using DriverManager.
- URL: jdbc:h2:./employeedb, Username: sa, Password: ""
### 2. model/Employee.java
- Complete the constructor Employee(int empId, String name, double salary) and the getters and setters.
### 3. util/DatabaseInitializer.java
- Complete initialize() to create the Employee table (EmpID INT PRIMARY KEY, Name VARCHAR(100), Salary DECIMAL(10,2)) if it does not exist.
- Insert these rows only if the table is empty:
EmpID	Name	Salary
101	Asha Rao	55000.00
102	Rahul Mehta	62000.00
103	Priya Nair	71000.50
104	Karan Singh	48000.00
### 4. dao/EmployeeDAO.java
- Complete getAllEmployees() to fetch all rows from Employee table ordered by EmpID in ascending order and return them as a List<Employee>.
- Return an empty list, not null, if the table has no rows.
### 5. view/EmployeeView.java
- Complete displayEmployees(List<Employee>) to print all records, with salaries shown to 2 decimal places, followed by Total records: <count>.
- If the list is empty, print No records found in Employee table.
- Complete displayError(String message) to print Error: <message> to System.err.
### 6. controller/EmployeeController.java
- Complete showAllEmployees() to get the employees from the DAO and pass them to the view.
- If a SQLException occurs, catch it and call view.displayError(...).
### Expected Output :

```
+--------+----------------------+--------------+
| EmpID  | Name                 |       Salary |
+--------+----------------------+--------------+
| 101    | Asha Rao             |     55000.00 |
| 102    | Rahul Mehta          |     62000.00 |
| 103    | Priya Nair           |     71000.50 |
| 104    | Karan Singh          |     48000.00 |
+--------+----------------------+--------------+
Total records: 4

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-06T16:49:18.007Z  

```cpp
    // URL: jdbc:h2:./employeedb   Username: sa   Password: (empty)
    private static final String URL = "dbc:h2:./employeedb";
    private static final String USER = "sa";
    private static final String PASSWORD = "";

    private DBConnection() { }

    public static Connection getConnection() throws SQLException {
        // TODO: Return a connection using DriverManager.getConnection(URL, USER, PASSWORD)
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/EXP24EASY)