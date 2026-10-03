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