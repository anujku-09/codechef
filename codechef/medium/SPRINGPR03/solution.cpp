    @GetMapping("/{id}")
    public ResponseEntity<?> getAlertById(@PathVariable Long id) {
    
        return alertRepository.findById(id)
                .<ResponseEntity<?>>map(alert -> ResponseEntity.ok(alert))
                .orElseGet(() -> ResponseEntity.status(HttpStatus.NOT_FOUND)
                        .body("Alert not found"));
    }

    // DELETE /api/alerts/{id}
    @DeleteMapping("/{id}")
    // GET /api/alerts/{id}

    public ResponseEntity<?> deleteAlert(@PathVariable Long id) {
