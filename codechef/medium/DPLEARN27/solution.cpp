          style={{
            padding: "10px 20px",
            fontSize: "16px",
            cursor: "pointer",
            marginBottom: "20px",
          }}
        >
          Start Test
        </button>
      ) : (
        // Show input box when test starts
        <input
          type="text"
          value={input}
          onChange={handleInput}
          onClick={startTest}
        <button
      {!isStarted ? (
      {/* Show Start button if test is not started */}

      <p>{sampleText}</p>
    <div style={{ textAlign: "center", marginTop: "30px" }}>
      <h1>Typing Speed Test</h1>
  return (

  };
    setResult("");          // clear result
    setIsStarted(true);     // enable typing mode
    setStartTime(null);     // reset timer
    setInput("");           // clear input box
  // Function to start the typing test
  const startTest = () => {

  };
    }
      setIsStarted(false); 