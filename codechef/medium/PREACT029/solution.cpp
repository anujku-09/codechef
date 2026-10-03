
  function resetScore() {
    console.log("Score reset to 0!");
  }

  return (
    <>
      <h1>Score Tracker</h1>

      {/* Create +5 Points button */}
      
      <button onClick={() => addPoints(5)}>+5 Points</button>
      {/* Create -3 Points button */}
      <button onClick={() => subtractPoints(3)}>-3 Points</button>
      
      {/* Create Resetting Score button */}
      <button onClick={() => resetScore()}>Reset</button>
      
    </>
  );
}

export default App;