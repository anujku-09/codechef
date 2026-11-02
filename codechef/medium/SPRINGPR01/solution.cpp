
public class ProductController {
@RequestMapping("/api/products")
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.List;

// TODO: mark this class as a REST controller
@RestController
import org.springframework.http.ResponseEntity;
    private final List<Product> products = new ArrayList<>();

    public ProductController() {
        products.add(new Product(1, "Laptop", 55000.0));