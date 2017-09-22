package application;
	
import java.util.Locale;
import java.util.ResourceBundle;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.image.Image;
import javafx.stage.Stage;


@SuppressWarnings("unused")
public class Series extends Application  {
	private static Locale locale = Locale.getDefault();
	private static ResourceBundle rb;
	//private static Locale locale = Locale.getDefault();
	@Override
	public void start(Stage stage) {
		Parent root = null;
    	try {
    		//root = FXMLLoader.load(getClass().getResource("Kutya.fxml"));
    		 FXMLLoader loader = new FXMLLoader(getClass().getResource("Kutya.fxml"));
    		 root = loader.load();
    		//root.setStyle("applocation.css");
    		 MyControllerClass control = loader.getController();
    	    control.setStage(stage);
    	   // System.out.println(control);
    		 
    	} catch(Exception ex) {
    		System.out.println(ex);
    		Alert alert = new Alert(Alert.AlertType.ERROR);
        	alert.setTitle("Hiba");
        	alert.setHeaderText(null);
        	alert.setContentText(ex.toString());
        	System.exit(1);

    	}
    	
        stage.setTitle(rb.getString("key.titleBar"));
        
        Scene scene = new Scene(root, 800, 800);
        
        stage.setScene(scene);
        stage.getIcons().add(new Image(Series.class.getResource("favicon-96x96.png").toExternalForm()));
        stage.getIcons().add(new Image(Series.class.getResource("favicon-32x32.png").toExternalForm()));
        stage.getIcons().add(new Image(Series.class.getResource("favicon-16x16.png").toExternalForm()));
       
       
       
       stage.show();
  
        
    }
		
		
	
	public static void main(String[] args) {
		rb = ResourceBundle.getBundle("application/MessageBundle", locale);
		launch(args);
	}



	
}
