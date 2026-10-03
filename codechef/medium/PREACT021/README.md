# PREACT021

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### GreetingCard Component

Create personalized greeting cards that show each person's name, age, greeting message, and  **favorite color**  using React components.

 **Steps to Follow:** 

- Show Favorite Color in Greeting Card Modify the GreetingCard component to display the person's favorite color in a new paragraph (<p> tag) below their age. Use the existing favoriteColor prop to display this information. Example format: <p> My favorite color is {favoriteColor}.</p>
- Render Cards for All People In the App component, display a GreetingCard for every person in the people array. Pass all required information (name, age, greeting message, favorite color) as props to each card. Use the map() method to loop through the people array.

 **At the end your app should look like this**

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-03T18:45:38.115Z  

```cpp
    verticalAlign: 'middle'
  }

  return (
    <div style={cardStyle}>
      <h2 style={headingStyle}>{greeting}</h2>

      <p style={{ ...baseParagraphStyle, fontWeight: 500 }}>
        Hello, my name is <span style={{ fontWeight: 'bold' }}>{name}</span>.
      </p>
      <p style={{ ...baseParagraphStyle, fontWeight: 500 }}>
        I am {age} years old.
      </p>

      {/* STEP 1: Display the person's favorite color below this line */}
      <p style={{ ...baseParagraphStyle, fontWeight: 500 }}>
        My favorite color is <span style={favoriteColorTextStyle}>{favoriteColor}</span>.
      </p>

      <p style={footerStyle}>Year: {new Date().getFullYear()}</p>
      <p style={{ ...footerStyle, marginTop: '0' }}>
          Have a great day! <span style={emojiStyle}>🎉</span>
      </p>
```

---

[View on CodeChef](https://www.codechef.com/problems/PREACT021)