# PRHARD

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Observer Pattern with Spring Data JPA

 **Instructions:** 

- Complete your code first.
- Click on "Run" to start the server and make sure it runs correctly.
- If you make any changes to the code after running, you must run the server again.
- Only after running the server with the latest changes, your submission will reflect the updated solution.
- Do not submit if the server is not running; otherwise, your solution will fail.

 **Goal :** 
Create a  **Product Catalog API**  using Spring Boot and Spring Data JPA, and apply the  **Observer design pattern**.
Users can create, read, update and delete products from the database.
When a  **new product is added**, all subscribed services (`InventoryService` and `EmailService`) are notified automatically.
Each Product should contain:

- id (Auto-generated Primary Key)
- name
- price
- quantity

 **Your Task :** 
Complete the code given in the IDE by following the requirements below :

 **1. Create Entity** 
Create a class `Product.java`.
Fields:

- id
- name
- price
- quantity

Use the following annotations:

- @Entity
- @Id
- @GeneratedValue

 **2. Create Repository** 
Create `ProductRepository.java`.
Extend:

```
JpaRepository<Product, Long>

```

Do not write any implementation.

 **3. Create the Observer Pattern**  \

- Create a ProductObserver interface with a method that receives the newly added product.
- Create InventoryService and EmailService as Spring beans that implement ProductObserver.
- Each observer records one message in the shared NotificationLog:
Observer	Message recorded when a product is added
`InventoryService`	`Inventory updated for product: <name>`
`EmailService`	`Email sent for new product: <name>`
- Create a ProductPublisher class that receives a List<ProductObserver> through constructor injection and notifies every observer. Inventory must be notified before email.
- Do not call InventoryService or EmailService directly from the controller. Use the publisher.

 **4. Create Controllers** 
Create `ProductController.java` with base path:

```
/api/products

```

Create `NotificationController.java` with base path:

```
/api/notifications

```

 **5. Implement APIs** 
Implement the following APIs using built-in repository methods.

Method	Endpoint	Description	Success	Error
GET	`/api/products`	Get all products	`200 OK` with the list	n/a
GET	`/api/products/{id}`	Get product by ID	`200 OK` with the product	`404 Not Found` with "Product not found"
POST	`/api/products`	Add a product and notify observers	`201 Created` with the product and its generated ID	n/a
PUT	`/api/products/{id}`	Update a product	`200 OK` with the updated product	`404 Not Found` with "Product not found"
DELETE	`/api/products/{id}`	Delete a product	`200 OK` with "Product deleted successfully"	`404 Not Found` with "Product not found"
GET	`/api/notifications`	Get all notification messages in the order they were sent	`200 OK` with the list	n/a

Observers must be notified  **only**  when a product is added with `POST`. `PUT` and `DELETE` must not add notifications.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-02T18:40:25.274Z  

```cpp
package com.example.demo.controller;

import com.example.demo.observer.NotificationLog;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

// TODO: mark this class as a REST controller
// TODO: set the base path to /api/notifications
@RestController
@RequestMapping("/api/notifications")
public class NotificationController {

    private final NotificationLog log;

    public NotificationController(NotificationLog log) {
        this.log = log;
    }
```

---

[View on CodeChef](https://www.codechef.com/problems/PRHARD)