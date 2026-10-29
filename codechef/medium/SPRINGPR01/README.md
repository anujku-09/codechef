# SPRINGPR01

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Product Catalog REST API (CRUD)

 **Instructions:** 

- Complete your code first.
- Click on "Run" to start the server and make sure it runs correctly.
- If you make any changes to the code after running, you must run the server again.
- Only after running the server with the latest changes, your submission will reflect the updated solution.
- Do not submit if the server is not running; otherwise, your solution will fail.

 **Goal :** 

Understand how to build a complete CRUD REST API using `@RestController`, `@GetMapping`, `@PostMapping`, `@PutMapping` and `@DeleteMapping`, and how to return the correct HTTP status codes. Data is stored in an in-memory `ArrayList` (no database).

 **Available Endpoints** 
The following endpoints need to be implemented in the application:

- Get all products

```
GET /api/products

```

- Get product by ID

```
GET /api/products/{id}

```

- Create a new product

```
POST /api/products

```

- Update an existing product

```
PUT /api/products/{id}

```

- Delete a product

```
DELETE /api/products/{id}

```

 **Product Details :** 

Field	Type	Description
id	int	Unique product ID
name	String	Name of the product
price	double	Price of the product

 **Your Task :** 

- Use an in-memory ArrayList<Product> to store the products. Do not use any database.
- Use @RestController for the controller class.
- Implement all 5 endpoints using the matching annotations: @GetMapping, @PostMapping, @PutMapping and @DeleteMapping.
- Use @PathVariable to read the id from the URL and @RequestBody to read the product data from the request body.
- Return the following HTTP status codes:
Endpoint	Scenario	Status Code	Response
`GET /api/products`	Always	`200 OK`	List of all products
`GET /api/products/{id}`	Product found	`200 OK`	The product
`GET /api/products/{id}`	Product not found	`404 Not Found`	"Product not found"
`POST /api/products`	Product created	`201 Created`	The created product
`PUT /api/products/{id}`	Product updated	`200 OK`	The updated product
`PUT /api/products/{id}`	Product not found	`404 Not Found`	"Product not found"
`DELETE /api/products/{id}`	Product deleted	`200 OK`	"Product deleted successfully"
`DELETE /api/products/{id}`	Product not found	`404 Not Found`	"Product not found"

 **Note:**  Please do not delete any existing products. If you want to test deleting a product, create your own product first and delete that one instead. Only products you created yourself should be deleted.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-29T18:52:57.489Z  

```cpp
    if (product != null) {
        return ResponseEntity.ok(product);
    }
    return ResponseEntity.status(404).body("Product not found");
    }

    // TODO: POST /api/products -> 201 with created product
    @PostMapping
    public ResponseEntity<Product> createProduct( @RequestBody Product product) {
    product.setId(getNextId());
    products.add(product);

    return ResponseEntity.status(201).body(product);
    }

    // TODO: PUT /api/products/{id} -> 200 with updated product, 404 "Product not found"
@PutMapping("/{id}")
    public ResponseEntity<?> updateProduct(@PathVariable int id, @RequestBody Product updatedProduct) {
    Product product = findById(id);

    if (product == null) {
        return ResponseEntity.status(404).body("Product not found");
    }
```

---

[View on CodeChef](https://www.codechef.com/problems/SPRINGPR01)