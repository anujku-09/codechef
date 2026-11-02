# SPRINGPR02

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Vehicle Insurance Strategy API

 **Instructions:** 

- Complete your code first.
- Click on "Run" to start the server and make sure it runs correctly.
- If you make any changes to the code after running, you must run the server again.
- Only after running the server with the latest changes, your submission will reflect the updated solution.
- Do not submit if the server is not running; otherwise, your solution will fail.

 **Goal :** 

Understand how to implement the  **Strategy design pattern**  in Spring Boot. Each insurance type (`CarInsurance`, `BikeInsurance`, `TruckInsurance`) is a Spring bean. All of them are injected into a `Map`, and the correct one is selected at runtime based on the vehicle type sent in the request body. No database is used.

 **Available Endpoints** 
The following endpoint needs to be implemented in the application:

- Calculate insurance premium

```
POST /api/insurance/calculate

```

 **Request Body :** 

```
{
  "vehicleType": "car",
  "vehicleValue": 500000
}

```

Field	Type	Description
vehicleType	String	Type of vehicle: `car`, `bike` or `truck`
vehicleValue	double	Current value of the vehicle

 **Insurance Rules :** 

Vehicle Type	Strategy Bean	Premium Formula
`car`	`CarInsurance`	5% of vehicle value
`bike`	`BikeInsurance`	3% of vehicle value
`truck`	`TruckInsurance`	8% of vehicle value

 **Your Task :** 

- Create an InsuranceStrategy interface with a method that calculates the premium for a given vehicle value.
- Create three classes, CarInsurance, BikeInsurance and TruckInsurance, that implement InsuranceStrategy.
- Register each class as a Spring bean with @Component and give it a bean name: car, bike and truck.
- Inject all strategies into a Map<String, InsuranceStrategy> in the service class, where the key is the bean name.
- Use @RestController and @PostMapping to create the endpoint, and @RequestBody to read the request data.
- Select the strategy from the map using vehicleType at runtime. Do not use if-else or switch to choose the strategy.
- Return the following HTTP status codes:
Scenario	Status Code	Response
Valid vehicle type	`200 OK`	JSON with `vehicleType`, `vehicleValue` and `premium`
Unknown vehicle type	`400 Bad Request`	"Unsupported vehicle type"
Missing `vehicleType`	`400 Bad Request`	"Unsupported vehicle type"

 **Sample Request and Response :** 

Request:

```
POST /api/insurance/calculate

```

```
{
  "vehicleType": "bike",
  "vehicleValue": 100000
}

```

Response (200 OK):

```
{
  "vehicleType": "bike",
  "vehicleValue": 100000.0,
  "premium": 3000.0
}

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-02T17:37:14.120Z  

```cpp
public class InsuranceService {

    // TODO: declare a Map<String, InsuranceStrategy> field named strategies
    private final Map<String, InsuranceStrategy> strategies;

    // TODO: add a constructor that receives the map so Spring can inject all strategy beans
    public InsuranceService(Map<String, InsuranceStrategy> strategies) {
        this.strategies = strategies;
    }

    public boolean isSupported(String vehicleType) {
        // TODO: return true only if vehicleType is not null and the map contains it (ignore case)
        return vehicleType != null && strategies.containsKey(vehicleType.trim().toLowerCase());
    }

    public double calculatePremium(String vehicleType, double vehicleValue) {
        // TODO: get the strategy from the map (ignore case) and return its premium
        InsuranceStrategy strategy = strategies.get(vehicleType.trim().toLowerCase());
        return strategy.calculatePremium(vehicleValue);
// TODO: register this class as a Spring service
@Service
import java.util.Map;


        if (!isSupported(vehicleType)) {
            throw new IllegalArgumentException("Unsupported vehicle type");
        }
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/SPRINGPR02)