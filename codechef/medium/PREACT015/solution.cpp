      {/* Displaying the user's name from props */}
      {/* Displaying the user's age from props */}
    </div>
  );
}

// App component: Renders multiple UserProfile components with different data
function App() {
  return (
    <div>
      {/* Passing different names and ages to the UserProfile component */}
        <UserProfile name = "Alice" age ={25}/>
        <UserProfile name = "Bob" age ={30}/>
      
    </div>
  );
}

export default App; // Exporting the App component for use in the application
      <h1>User Profile : </h1>
      <p>Name: {props.name}</p>
      <p>Name: {props.age}</p>
