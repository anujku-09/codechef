    }
        return ResponseEntity.ok("Product deleted successfully");

        products.remove(product);

        }
                    .body("Product not found");
            return ResponseEntity.status(404)
        if (product == null) {

        Product product = findById(id);

            @PathVariable int id) {
    public ResponseEntity<String> deleteProduct(
    // 5. DELETE - Delete a product
    @DeleteMapping("/{id}")
        if (product == null) {
            return ResponseEntity.status(404)
                    .body("Product not found");
        }

        product.setName(updatedProduct.getName());
        product.setPrice(updatedProduct.getPrice());

        return ResponseEntity.ok(product);
    }



        Product product = findById(id);
            @RequestBody Product updatedProduct) {
            @PathVariable int id,
    public ResponseEntity<?> updateProduct(
    @PutMapping("/{id}")
    // 4. PUT - Update an existing product

    }
        return ResponseEntity.status(201).body(product);

        products.add(product);

        product.setId(getNextId());