      {/* STEP 1: Add product information here */}
      {/* Show product name in <h3> */}
      {/* Show price in <p> with text "Price: $X" */}
      <h3>{props.product.name}</h3>
      {/* STEP 2: Add button that triggers handleClick */}
      {/* <button onClick={...}>Select</button> */}
    </div>
  );
}

      <p>Price: ${props.product.price}</p>
      <button onClick={handleClick}>Select</button>
function App() {
  return (
    <div className="container">
      <h1>Product List</h1>
      <div className="product-list">
        {/* STEP 4: Display all products */}
        {/* Use .map() to create ProductCards for all products */}
        {/* Don't forget to add unique 'key' prop */}
        {products.map((product) => (
          <ProductCard key={product.id} product={product} />
        ))}