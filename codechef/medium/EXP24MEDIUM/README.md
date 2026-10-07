# EXP24MEDIUM

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Practice Problem - Product Management API
### Instructions:
- Complete your code first.
- Click on "Run" to compile and run the application.
- Use the menu displayed in the console to test the product operations.
- If you make any changes to the code after running, you must run the application again.
- At last, after running the code, click on "Submit".
### Goal :

Build a Java application that manages product records using JDBC and MVC architecture.

The application must store product data in an H2 database and provide CRUD operations through a simple menu-driven interface. Use transactions so that data stays correct when an operation fails.

The application should use:

- Product as the model.
- ProductDAO for database operations.
- ProductController to handle product operations.
- ProductView for the menu-driven user interface.
- DBConnection to establish the database connection.
- DatabaseInitializer to create the database table.

All files are already provided. Complete the code marked `TODO`. Do not rename any class or method.

### Project Structure :

```
product-jdbc-mvc/
├── pom.xml    (H2 dependency already added)
└── src/main/
    └── java/com/example/
        ├── Main.java
        ├── model/
        │   └── Product.java
        ├── controller/
        │   └── ProductController.java
        ├── dao/
        │   └── ProductDAO.java
        ├── view/
        │   └── ProductView.java
        └── util/
            ├── DBConnection.java
            └── DatabaseInitializer.java

```

### Your Task :
### 1. model/Product.java

Create the `Product` model with the following fields:

Field	Type
`productId`	`int`
`productName`	`String`
`price`	`double`
`quantity`	`int`

Implement:

- A default constructor.
- A parameterized constructor: Product(int productId, String productName, double price, int quantity)
- Getters and setters for all four fields.
### 2. util/DBConnection.java

Complete `getConnection()` to return a database connection using `DriverManager`.

- URL: jdbc:h2:./productdb
- Username: sa
- Password: ""
### 3. util/DatabaseInitializer.java

Complete `initialize()` to create the `Product` table if it does not already exist. The table should initially be  **empty**.

```
ProductID    INT PRIMARY KEY
ProductName  VARCHAR(100) NOT NULL
Price        DECIMAL(10, 2) NOT NULL CHECK (Price >= 0)
Quantity     INT NOT NULL CHECK (Quantity >= 0)

```

### 4. dao/ProductDAO.java

Implement the database operations using JDBC. Use `PreparedStatement` for all database operations.

 **Every write must run inside a transaction:**  call `setAutoCommit(false)`, then `commit()` on success, or `rollback()` and rethrow the `SQLException` on failure.

Method	Description
`addProduct(Product)`	Inserts one product.
`addProducts(List<Product>)`	Inserts all products in  **one**  transaction. If any insert fails, no product is saved.
`getAllProducts()`	Returns all products ordered by `ProductID`. Returns an empty list if no products exist.
`getProductById(int)`	Returns the product with the given ID, or `null` if not found.
`updateProduct(Product)`	Updates the product's name, price and quantity. Returns `true` if updated, otherwise `false`.
`deleteProduct(int)`	Deletes the product with the given ID. Returns `true` if deleted, otherwise `false`.
### 5. controller/ProductController.java

The controller should use `ProductDAO` to perform all product operations.

Method	Description
`addProduct(Product)`	Adds a product.
`addProducts(List<Product>)`	Adds multiple products in one transaction.
`getAllProducts()`	Retrieves all products.
`getProductById(int)`	Retrieves a product by ID.
`updateProduct(Product)`	Updates a product.
`deleteProduct(int)`	Deletes a product.

Each method should pass the operation to `ProductDAO`.

### 6. view/ProductView.java

Create a menu-driven interface for managing products. Display the following menu:

```
===== Product Management System =====
1. Add Product
2. Add Multiple Products
3. View All Products
4. View Product by ID
5. Update Product
6. Delete Product
7. Exit
Enter your choice:

```

After completing an operation, the menu should be displayed again until the user selects

 **7. Exit**.

### Option 1: Add Product

Ask the user for the Product ID, Name, Price and Quantity, then add the product to the database. On success, display:

```
Product added successfully.

```

### Option 2: Add Multiple Products

Ask the user how many products to add, then collect each product's ID, Name, Price and Quantity. Add all products in a single transaction. On success, display:

```
<N> products added successfully.

```

If the transaction fails, display:

```
Transaction failed, no products were added.

```

### Option 3: View All Products

Display all products in the following format:

```
ID    Name    Price    Quantity

```

If there are no products, display:

```
No products available

```

### Option 4: View Product by ID

Ask for the Product ID and display the product's details. If the product does not exist, display:

```
Product not found

```

### Option 5: Update Product

Ask for the Product ID, then the new Name, Price and Quantity, and update the product record. On success, display:

```
Product updated successfully.

```

If the product does not exist, display:

```
Product not found

```

### Option 6: Delete Product

Ask for the Product ID and delete the record. On success, display:

```
Product deleted successfully.

```

If the product does not exist, display:

```
Product not found

```

### Option 7: Exit

Terminate the menu-driven application and display:

```
Exiting application...

```

### Invalid Choice

If the user enters a choice other than `1` to `7`, display:

```
Invalid choice.

```

### 7. Main.java

The `Main` class should start the application in the following order:

- Initialize the database using DatabaseInitializer.
- Create a ProductController.
- Create a ProductView using the controller.
- Start the menu-driven application.

The database must be initialized before the menu is displayed.

### Example Interaction :

When the application starts:

```
===== Product Management System =====
1. Add Product
2. Add Multiple Products
3. View All Products
4. View Product by ID
5. Update Product
6. Delete Product
7. Exit
Enter your choice:

```

To add a product:

```
Enter your choice: 1
Enter Product ID: 1
Enter Name: Laptop
Enter Price: 55000
Enter Quantity: 10
Product added successfully.

```

To view all products:

```
Enter your choice: 3
ID    Name    Price    Quantity
1     Laptop  55000.0  10

```

To view a product by ID:

```
Enter your choice: 4
Enter Product ID: 1
Product ID: 1
Name: Laptop
Price: 55000.0
Quantity: 10

```

To update a product:

```
Enter your choice: 5
Enter Product ID: 1
Enter new Name: Laptop Pro
Enter new Price: 65000
Enter new Quantity: 8
Product updated successfully.

```

To delete a product:

```
Enter your choice: 6
Enter Product ID: 1
Product deleted successfully.

```

To exit:

```
Enter your choice: 7
Exiting application...

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-07T08:34:48.690Z  

```cpp
        if (controller.deleteProduct(productId)) {
            System.out.println("Product deleted successfully.");
        } else {
            System.out.println("Product not found");
        }
    }

    private void displayProduct(Product product) {
        System.out.println("Product ID: " + product.getProductId());
        System.out.println("Name: " + product.getProductName());
        System.out.println("Price: " + product.getPrice());
        System.out.println("Quantity: " + product.getQuantity());
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/EXP24MEDIUM)