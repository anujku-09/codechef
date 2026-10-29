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