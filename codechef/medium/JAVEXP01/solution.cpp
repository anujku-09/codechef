
import com.example.controller.MovieController;
import com.example.util.DatabaseInitializer;
import com.example.view.MovieView;

public class Main {

    public static void main(String[] args) {

        DatabaseInitializer.initialize();

        MovieController controller = new MovieController();

        MovieView view = new MovieView(controller);

        view.start();
    }
}