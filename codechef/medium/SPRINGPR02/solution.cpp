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