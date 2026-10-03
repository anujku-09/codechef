  }

  for (let i = start; i < end; i += step) {
    result.push(i);
  }

  return result;
};

// update this function 
function NumberBoxes({ count }) {  
  return (  
    <ul>
      {range(count).map((num) => (  
    </ul>
        <li key={num}>  
          {num + 1}  
        </li>  
      ))}  
  if (typeof end === 'undefined') {
    end = start;
    start = 0;
  );  