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