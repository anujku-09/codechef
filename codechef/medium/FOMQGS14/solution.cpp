      }
    }, 50);
  }
  
  function getWeatherCallback(city) {
    fetchWeatherWithCallback(city, (err, data) => {
      if (err) {
        console.error("Callback Error:", err);
      } else {
        console.log("Callback:", data);
        callback(`Error: Could not fetch weather for ${city}`, null);
      }
    });
  }
  
  // ✅ Example usage
  getWeatherAsync("Delhi");
  getWeatherPromise("Mumbai");
  getWeatherCallback("Bangalore");
  