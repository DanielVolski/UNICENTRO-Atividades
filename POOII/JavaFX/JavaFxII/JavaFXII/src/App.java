import javafx.application.*;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.*;

public class App extends Application {
    private Label lblTypeName = new Label();
    private Label lblName = new Label();
    private TextField txfName = new TextField();
    private Button btnHello = new Button();
    private Button btnExit = new Button();

    public static void main(String[] args) throws Exception {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        lblTypeName.setText("Digite o seu nome!");
        btnHello.setText("Olá!");
        btnExit.setText("Sair");

        btnHello.setOnAction(e -> showGreetingMsg());
        btnExit.setOnAction(e -> exit());
        
        VBox vbox = new VBox(10);
        vbox.getChildren().addAll(lblTypeName, txfName, lblName, btnHello, btnExit);
        vbox.setPadding(new Insets(10));
        Scene scene = new Scene(vbox, 300, 300);
        stage.setScene(scene);
        stage.setTitle("Exercício 1 JavaFX");
        stage.show();
    }

    private void showGreetingMsg() {
        String name = txfName.getText();
        if (!name.isEmpty())
            lblName.setText("Olá " + name + "!");
    }

    private void exit() {
        Platform.exit();
    }
}