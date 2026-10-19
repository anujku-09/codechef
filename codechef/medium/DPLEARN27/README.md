# DPLEARN27

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Typing Speed Test Project

⌨️ Welcome to the  **Typing Speed Test project**.

In this project, you’ll build a small interactive typing application that measures how fast a user types, calculated in  **Words Per Minute**  (WPM).

By the end of this project, users will have a complete typing test app with:

- A typing interface
- Real-time WPM calculation
- Accuracy measurement (to be added in later parts).
- Score storage and retrieval with a backend (Express + MongoDB, in later parts).

 **Project Breakdown** 
The project is divided into  **three main parts** :

- Part 1: Building the Typing UI with WPM Calculation
- Part 2: Adding Accuracy Measurement and Enhanced Feedback
- Part 3: Storing and Retrieving Scores with Express + MongoDB
### Part 1: Building the Typing UI with WPM Calculation

✨  **Build the Core Typing Experience!** 

The UI structure is already set up for you, but many parts of the logic and state initialization are missing. Your job is to fill in those blanks to make the app work.

 **Overview** 
Your page already contains:

- A sample text string that the user must type exactly.
- A partially written React component (App) with placeholders (_____).
- Basic UI to show the sample text, an input box, and a Start button.

You need to complete the logic so that:

- The user can start a test by clicking the Start Test button.
- Typing begins inside the input box.
- On the first keystroke, a timer starts.
- When the user finishes typing the sample text correctly, the app calculates and displays the WPM (Words Per Minute).

 **Note:**  All required libraries are already installed. There’s  **no need**  to install anything—just focus on completing the functionality.

 **Your Tasks** 

- Initialize States Correctly
- Think about what initial values would make sense for: The user input before typing starts. The timer before the user begins - initially should be null. The result message before any calculation. Whether the test has started or not. Docs: React useState Hook
- Handle Typing Input Inside the provided handleInput function, complete the logic: Start the timer on the first keystroke. Docs: Date Compare the user input to the sample text to know when the test is finished. When the text matches completely: Record the end time. Calculate the elapsed time (in minutes) - Using formula: $timeTaken = \frac{endTime - startTime}{1000 \times 60}$ Count Words in Sample Text Split the sample text appropriately and determine the total. Docs: String.prototype.split() Calculate WPM as Divide words by time taken and round it.. Docs: Math.round() Store the final result message in state. Stop the test.
- Complete the startTest function: This will initialize and start the typing test. This function should:
- Reset the user input so the input box is empty.
- Reset the timer to start fresh when the user begins typing.
- Clear any previous result messages.
- Set the test state to "started" so the input box is shown and the timer can begin.
- Render UI Ensure the UI behaves correctly: Always display the sample text. If the test has not started, show a Start Test button. If the test has started, show an input box bound to the input state. After completion, display the result message.

 **Expected Output** 
If implemented correctly, the app will look like this:

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-19T18:33:55.160Z  

```cpp
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
```

---

[View on CodeChef](https://www.codechef.com/problems/DPLEARN27)