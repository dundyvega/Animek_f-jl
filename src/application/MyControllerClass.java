package application;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Optional;
import java.util.ResourceBundle;

import com.sun.glass.ui.MenuBar;
import com.sun.media.jfxmedia.logging.Logger;

import components.OneAnime;
import data.FileAdministrator;
import javafx.application.Platform;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.CheckBox;
import javafx.scene.control.ComboBox;
import javafx.scene.control.ContextMenu;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Text;
import javafx.scene.text.TextFlow;
import javafx.scene.web.HTMLEditor;
import javafx.scene.web.WebView;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class MyControllerClass implements Initializable {
	
	public Locale locale = Locale.getDefault();
	public ResourceBundle tr;
	
    @FXML
    private Label commentLabel;

    @FXML
    private MenuItem suspendedMenu;

    @FXML
    private Label titleLabel;

    @FXML
    private Menu searchMenu;

    @FXML
    private TextField searchField;

    @FXML
    private TextField title;

    @FXML
    private MenuItem closeMenu;

    @FXML
    private MenuItem finishedMenu;

    @FXML
    private MenuItem activeMenu;

    @FXML
    private ListView<OneAnime> listView;

    @FXML
    private ComboBox<String> comboBox;

    @FXML
    private Menu fileMenu;

    @FXML
    private MenuItem openMenu;

    @FXML
    private TextField adElement;

    @FXML
    private MenuItem plannedMenu;
    
    @FXML
    private MenuItem searchMenuItem;

    @FXML
    private MenuItem newMenu;

    @FXML
    private TextField length;

    @FXML
    private Menu helpMenu;

    @FXML
    private MenuItem aboutMenu;

    @FXML
    private Menu editMenu;

    @FXML
    private Menu a1;

    @FXML
    private MenuBar menubar;

    @FXML
    private MenuItem a2;

    @FXML
    private MenuItem a3;

    @FXML
    private Label lengthLabel;

    @FXML
    private MenuItem a4;
    
    @FXML
    private MenuItem addMenuItem;

    @FXML
    private Menu a5;

    @FXML
    private Menu a6;

    @FXML
    private MenuItem thrownMenu;
    
    
    @FXML
    private MenuItem otherMenu;

    @FXML
    private TextField comment;

    @FXML
    private MenuItem allMenu;
    
    
    
    private int nrCat;
    
    private boolean cat; 
    
    private String animeSTR;
    
    private Stage stage;
    private Series series;
    private ContextMenu cmenu = new ContextMenu();

	
    @FXML
    void NewOnAction(ActionEvent event) {
    	FileChooser fileChooser = new FileChooser();
    	  
        //Set extension filter
        FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("XML files (*.xml)", "*.xml");
        fileChooser.getExtensionFilters().add(extFilter);
        fileChooser.setInitialFileName("uknown.xml");
        
        //Show save file dialog
        File file = fileChooser.showSaveDialog(null);
        
        if(file != null){
            try {
            	if(file != null){
                   FileAdministrator.newFIle(file);
                   a1.disableProperty().set(false);
               	a2.disableProperty().set(false);
               	a3.disableProperty().set(false);
               	a4.disableProperty().set(false);
               	a5.disableProperty().set(false);
               	a6.disableProperty().set(false);
               	betolt(0);
                }
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }

    }

    @FXML
    void OpenOnAction(ActionEvent event) {
    	try {
    	FileChooser fileChooser = new FileChooser();
    	fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("xml", "*.xml"),
                new FileChooser.ExtensionFilter("XML", "*.XML")
              
            );
    	File file = fileChooser.showOpenDialog(null);
    	if (file != null) {
	    	a1.disableProperty().set(false);
	    	a2.disableProperty().set(false);
	    	a3.disableProperty().set(false);
	    	a4.disableProperty().set(false);
	    	a5.disableProperty().set(false);
	    	a6.disableProperty().set(false);
	    	listView.disableProperty().set(false);
	    	
	    	
	    	FileAdministrator.setFileName(file);
	    	if (!FileAdministrator.isContentAnime()) {
				FileAdministrator.makeContentAnime();
			} 
	
	    	betolt(2);
    	}
    	} catch (Exception ex) {}
    }

    @FXML
    void CloseOnAction(ActionEvent event) {
    	Platform.exit();
    	System.exit(0);
    }

    @FXML
    void SaveOnAction(ActionEvent event) {
    	int leng = -1;
    	try {
    		leng = Integer.parseInt(length.getText());
    	} catch (NumberFormatException ex) {
    		Alert alert = new Alert(Alert.AlertType.ERROR);
        	alert.setTitle(tr.getString("key.error"));
       	 ImageView view= new ImageView();
       	 view.setImage(new Image(Series.class.getResource("flipedIcon.png").toExternalForm()));
       	 alert.setGraphic(view);
        	alert.setHeaderText(null);
        	alert.setContentText(tr.getString("key.failedlength"));
        	alert.showAndWait();
        	length.setText(listView.getSelectionModel().getSelectedItem().getAnimeHossz() + "");
        	return;
    		
        	
    	}
    	
	   FileAdministrator.modositAnimeXML(listView.getSelectionModel().getSelectedItem().getAnimeID(),
	    			title.getText(), comment.getText(), leng,
	    			comboBox.getSelectionModel().getSelectedIndex());
	    	 Alert alert = new Alert(Alert.AlertType.INFORMATION);
	    	 ImageView view= new ImageView();
	    	 view.setImage(new Image(Series.class.getResource("flipedIcon.png").toExternalForm()));
	    	 alert.setGraphic(view);
	    	 alert.setTitle(tr.getString("key.save"));
	         alert.setHeaderText(null);
	         alert.setContentText(tr.getString("key.the") + title.getText() +" " +  tr.getString("key.saved"));
	         alert.showAndWait();
	         
	         int index = listView.getSelectionModel().getSelectedIndex();
	         //kanime.setAnimeHossz(leng);
	         //System.out.println(kanime);
	         
	         
	        
	         try {
	        	// OneAnime kanime = listView.getSelectionModel().getSelectedItem();
	        	 //listView.fireEvent(new ListView.EditEvent<OneAnime>(listView, ListView.editCommitEvent(), kanime, index));
	        	 
	        	//	 listView.fireEvent(new ListView.EditEvent<OneAnime>(listView, ListView.editCommitEvent(), kanime, index));
	        		 setListElements(leng);
	        		 
	        		 
	        		 if (listView.getItems().isEmpty()) {
	        			 listView.disableProperty().set(true);
	        			 title.disableProperty().set(true);
	            		 comment.disableProperty().set(true);
	            		 title.disableProperty().set(true);
	            		 length.disableProperty().set(true);
	            		 comboBox.disableProperty().set(true);
	        		 } else {
	        			 listElementSelected();
	        			 OneAnime kanime = listView.getSelectionModel().getSelectedItem();
	       	             kanime.setAnimeNev(title.getText());
	       	             
	       	             if (listView.getItems().size() > 1) {
	        			    listView.fireEvent(new ListView.EditEvent<OneAnime>(listView,
	        			    		ListView.editCommitEvent(), kanime, index));
	       	             } else betoltes();
	        			listElementSelected();
	        		 }
	    
	         } catch (Exception e) {}
	         betoltes();
	         
    }
    
    void betoltes() {
    	if (cat) {
    		betolt(nrCat);
    	} else {
    		betolt(animeSTR);
    	}
    }

    @FXML
    void DeleteOnAction(ActionEvent event) {
    	
    	int n = FileAdministrator.animekSzamaXML(0);
    	if (n > 1) {
    	 Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
    	 alert.setTitle(tr.getString("key.delete"));
    	 int removed = listView.getSelectionModel().getSelectedIndex();
    	 ImageView view= new ImageView();
    	 view.setImage(new Image(Series.class.getResource("android-icon-144x144.png").toExternalForm()));
    	 alert.setGraphic(view);
    	 alert.setHeaderText(tr.getString("key.deleting"));
    	 
    	 Optional<ButtonType> result = alert.showAndWait();
    	 if (result.get() == ButtonType.OK){
    	     // ... user chose OK
    		 FileAdministrator.torolAnimeXML(listView.getSelectionModel().getSelectedItem().getAnimeID());
    		 listView.getItems().remove(removed);
    		 int listElements = listView.getItems().size();
    		 if (listElements < 1) {
    			 listView.getItems().clear();
    			 title.setText("");
    			 comment.setText("");
    			 length.setText("");
    			 
    			 listView.disableProperty().set(true);
    			 title.disableProperty().set(true);
        		 comment.disableProperty().set(true);
        		 title.disableProperty().set(true);
        		 length.disableProperty().set(true);
        		 comboBox.disableProperty().set(true);
        
        
    			 
    		 }
    	 } else {
    	     // ... user chose CANCEL or closed the dialog
    	 }
    	} else {
    		 Alert alert = new Alert(Alert.AlertType.INFORMATION);
	    	 alert.setTitle(tr.getString("key.error"));
	    	 ImageView view= new ImageView();
	    	 view.setImage(new Image(Series.class.getResource("flipedIcon.png").toExternalForm()));
	    	 alert.setGraphic(view);
	         alert.setHeaderText(null);
	         alert.setContentText(tr.getString("key.errore"));
	         alert.showAndWait();
    	}
    }

    @FXML
    void nameOnAction(ActionEvent event) {

    }

    @FXML
    void categoryOnAction(ActionEvent event) {

    }
    
    private void textAreaShow() {
    	Alert area = new Alert(Alert.AlertType.CONFIRMATION);
    	String name = listView.getSelectionModel().getSelectedItem().getAnimeNev();
    	area.setTitle(tr.getString("key.Content"));
    	area.setHeaderText(name);
    	Parent root = null;
    	 MyController control = null;
    	try {
    		//root = FXMLLoader.load(getClass().getResource("Kutya.fxml"));
    		 FXMLLoader loader = new FXMLLoader(getClass().getResource("MyTextArea.fxml"));
    		 root = loader.load();
    		//root.setStyle("applocation.css");
    		 control = loader.getController();
    		 control.setText(listView.getSelectionModel().getSelectedItem().getAnimeTartalom());
    		 control.setTR(tr);
    		 control.setSelectable(true);
    		 
    	} catch(Exception ex) {
    		System.out.println(ex);
    		Alert alert = new Alert(Alert.AlertType.ERROR);
        	alert.setTitle("Hiba");
        	alert.setHeaderText(null);
        	alert.setContentText(ex.toString());
        	System.exit(1);

    	}
        
       // Scene scene = new Scene(root, 800, 800);
    	area.getDialogPane().setContent(root);
    	 Optional<ButtonType> result = area.showAndWait();
    	 if (result.get() == ButtonType.OK){
    		 String tartalm = control.getText();
    		 listView.getSelectionModel().getSelectedItem().setAnimeTartalom(tartalm);
    		 FileAdministrator.setTartalom(listView.getSelectionModel().getSelectedItem().getAnimeID(), tartalm);
    	 }
    	
    	
    	 
    	
    }

    @FXML
    void statOnAction(ActionEvent event) {
    	
    	Label osszes_label = new Label();
    	Label befejezett_label = new Label();
    	Label aktiv_label = new Label();
    	Label dobott_label = new Label();
    	Label tervezett_label = new Label();
    	Label felf_label = new Label();
    	Label egyeb_label = new Label();
    	int szam = 0;
    	
    	szam = FileAdministrator.animekSzamaXML(0);
    	osszes_label.setText(tr.getString("key.all") + tr.getString("key.series")+ szam);
    	
    	szam = FileAdministrator.animekSzamaXML(1);
    	befejezett_label.setText(tr.getString("key.finished") + tr.getString("key.series") + szam);
    	
    	
     	szam = FileAdministrator.animekSzamaXML(2);
    	aktiv_label.setText(tr.getString("key.active") + tr.getString("key.series") + szam);
    	
     	szam = FileAdministrator.animekSzamaXML(4);
    	felf_label.setText(tr.getString("key.suspended") + tr.getString("key.series") + szam);
    	
     	szam = FileAdministrator.animekSzamaXML(5);
    	dobott_label.setText(tr.getString("key.throwed") + tr.getString("key.series") + szam);
    	
     	szam = FileAdministrator.animekSzamaXML(3);
    	tervezett_label.setText(tr.getString("key.planned") + tr.getString("key.series") + szam);
    	
    	szam = FileAdministrator.animekSzamaXML(6);
    	egyeb_label.setText(tr.getString("key.other") + tr.getString("key.series") + szam);
    	
    	
    	Alert alert = new Alert(Alert.AlertType.INFORMATION);
    	
    	ImageView view= new ImageView();
   	    view.setImage(new Image(Series.class.getResource("favicon-96x96.png").toExternalForm()));
   	    alert.setGraphic(view);
   	 alert.setTitle(tr.getString("key.stat"));
   	 alert.setHeaderText(tr.getString("key.stati"));
   	    GridPane grid = new GridPane();
	   	grid.setHgap(10);
	   	grid.setVgap(10);
	   	grid.setPadding(new Insets(20, 150, 10, 10));
	   	
	   	grid.add(osszes_label, 1, 1);
	   	grid.add(aktiv_label, 1,  2);
	   	grid.add(befejezett_label, 1, 3);
	   	grid.add(felf_label, 1, 4);
	   	grid.add(tervezett_label, 1, 5);
	   	grid.add(dobott_label, 1, 6);
	   	grid.add(egyeb_label, 1, 7);
	   	alert.getDialogPane().setContent(grid);
	   	
	    alert.showAndWait();
	   
   	
   	
   	
    	

    }

    @FXML
    void aboutOnAction(ActionEvent event) {
    	 Alert alert = new Alert(Alert.AlertType.INFORMATION);
    	 ImageView view= new ImageView();
    	 view.setImage(new Image(Series.class.getResource("flipedIcon.png").toExternalForm()));
    	 alert.setGraphic(view);
    	 alert.setContentText(tr.getString("key.about"));
         alert.setTitle(tr.getString("key.nv"));
         alert.setHeaderText(null);
         alert.showAndWait();
         
        
    
         
         
         
    }
    
    
    @FXML
    void createContentAnimeOnAction(ActionEvent event) {
    	FileAdministrator.makeContentAnime();
    }
    
    
    @FXML
    void onAllItems(ActionEvent event) {
    	betolt(0);
    }
    
    
    @FXML
    void finishOnAction(ActionEvent event) {
    	betolt(1);

    }

    @FXML
    void activeOnAction(ActionEvent event) {
    	betolt(2);
    }

    @FXML
    void plannedOnAction(ActionEvent event) {
    	betolt(3);
    }

    @FXML
    void suspendOnAction(ActionEvent event) {
    	betolt(4);
    }
    
    
    @FXML
    void otherOnAction(ActionEvent event) {
    	betolt(6);
    }
    
    
    @FXML
    void elementAddAction(ActionEvent event) {
    	 FileAdministrator.ujAnimeXML(adElement.getText());
         Alert alert = new Alert(Alert.AlertType.INFORMATION);
         alert.setTitle(tr.getString("key.data"));
         alert.setHeaderText(null);
         alert.setContentText(tr.getString("key.the") + adElement.getText() + tr.getString("key.elem"));
    	 ImageView view= new ImageView();
    	 view.setImage(new Image(Series.class.getResource("flipedIcon.png").toExternalForm()));
    	 alert.setGraphic(view);
         alert.showAndWait();
         searchField.setText(adElement.getText());
         listView.disableProperty().set(false);
         title.disableProperty().set(false);
         comboBox.disableProperty().set(false);
   		 title.visibleProperty().set(true);
   		 comment.disableProperty().set(false);
   		 comment.visibleProperty().set(true);
   		 title.disableProperty().set(false);
   		 title.visibleProperty().set(true);
   		 length.disableProperty().set(false);
   		 length.visibleProperty().set(true);
   		 listView.setVisible(true);
   		 comboBox.setVisible(true);
   		titleLabel.setVisible(true);
		 lengthLabel.setVisible(true);
		 commentLabel.setVisible(true);
         adElement.setText("");
         searchOnAction(event);
    }

    @FXML
    void thorwnOnAction(ActionEvent event) {
    	betolt(5);
    }
    
    @FXML
    void searchOnAction(ActionEvent event) {
    	betolt(searchField.getText());
    	
    	
    }
    
    private void betolt(String s) {
    	animeSTR = s;
    	cat = false;
    	ArrayList<OneAnime> animek = FileAdministrator.keresAnimekXML(s);
    	if (animek.size() >= 1 && animek != null) {
        	listView.getItems().clear();
        	listView.getItems().addAll(animek);
        	listView.getSelectionModel().select(2);
        	listView.getSelectionModel().select(0);
        	listView.disableProperty().set(false);
        	
        	if (!listView.getSelectionModel().isEmpty()) {
        		listView.disableProperty().set(false);
        		comboBox.disableProperty().set(false);
        		listView.getItems().clear();
        		listView.getItems().addAll(animek);
        		listView.getSelectionModel().select(0);
        		listView.requestFocus();
        		title.disableProperty().set(false);
       		 title.visibleProperty().set(true);
       		 comment.disableProperty().set(false);
       		 comment.visibleProperty().set(true);
       		 title.disableProperty().set(false);
       		 title.visibleProperty().set(true);
       		 length.disableProperty().set(false);
       		 length.visibleProperty().set(true);
       		 listView.setVisible(true);
       		 comboBox.setVisible(true);
       		titleLabel.setVisible(true);
    		 lengthLabel.setVisible(true);
    		 commentLabel.setVisible(true);
        		listElementSelected();
        	} 
        	searchField.setText("");
        	} else {
        		 title.setText("");
    			 comment.setText("");
    			 length.setText("");
        		listView.getItems().clear();
        		listView.disableProperty().set(true);
        	}
    }
    
    @FXML
    void onKeyPressedList(KeyEvent event) {
    	try {
    	listElementSelected();
    	} catch (Exception e) {}
    }

    @FXML
    void onKeyReleasedList(KeyEvent event) {
    	try {
        	listElementSelected();
        	} catch (Exception e) {}
    }

    @FXML
    void onClickedList(MouseEvent event) {
    	try {
        	listElementSelected();
        	} catch (Exception e) {}
    	
    		if (event.getButton() == MouseButton.SECONDARY && event.getClickCount() == 1) {
    			//System.out.println("kettp");
    			listView.getContextMenu().show(listView,  event.getScreenX(), event.getScreenY());
    		} else {
    			if (event.getButton() == MouseButton.PRIMARY && event.getClickCount() == 2) {
    				this.textAreaShow();
    			}
    		}
    }
    	

    
    
    private void betolt(int i) {
    	nrCat = i;
    	cat = true;
    	ArrayList<OneAnime> animek = FileAdministrator.animekXML(i);
    	if (animek.size() > 0 && animek != null) {
    		listView.disableProperty().set(false);
    		comboBox.disableProperty().set(false);
    		listView.getItems().clear();
    		listView.getItems().addAll(animek);
    		listView.getSelectionModel().select(0);
    		listView.requestFocus();
    		title.disableProperty().set(false);
   		 title.visibleProperty().set(true);
   		 comment.disableProperty().set(false);
   		 comment.visibleProperty().set(true);
   		 title.disableProperty().set(false);
   		 title.visibleProperty().set(true);
   		 length.disableProperty().set(false);
   		 length.visibleProperty().set(true);
   		 listView.setVisible(true);
   		 comboBox.setVisible(true);
   		titleLabel.setVisible(true);
		 lengthLabel.setVisible(true);
		 commentLabel.setVisible(true);
    		listElementSelected();
    	} else {
    		 title.setText("");
    		 title.disableProperty().set(true);
    		 comment.disableProperty().set(true);
    		 title.disableProperty().set(true);
    		 length.disableProperty().set(true);
    		 comboBox.disableProperty().set(true);
			 
    		 comment.setText("");
			 length.setText("");
    		listView.getItems().clear();
    		listView.disableProperty().set(true);
    	}
    }
    

	@Override
	public void initialize(URL location, ResourceBundle resources) {
		//locale = new Locale("hu", "H");
		tr = ResourceBundle.getBundle("application/MessageBundle", locale);
		// TODO Auto-generated method stub
		//System.out.println(locale);
		comboBox.getItems().add(tr.getString("key.finished"));
		comboBox.getItems().add(tr.getString("key.active"));
		comboBox.getItems().add(tr.getString("key.planned"));
		comboBox.getItems().add(tr.getString("key.suspended"));
		comboBox.getItems().add(tr.getString("key.throwed"));
		comboBox.getItems().add(tr.getString("key.other"));
		
		
		fileMenu.setText(tr.getString("key.fileMenu"));
		editMenu.setText(tr.getString("key.editMenu"));
		searchMenu.setText(tr.getString("key.searchMenu"));
		helpMenu.setText(tr.getString("key.helpMenu"));
		newMenu.setText(tr.getString("key.newMenu"));
		openMenu.setText(tr.getString("key.openMenu"));
		closeMenu.setText(tr.getString("key.CloseMenu"));
		a1.setText(tr.getString("key.addMenu"));
		addMenuItem.setText(tr.getString("key.addMenuItem"));
		a2.setText(tr.getString("key.saveMenu"));
		a3.setText(tr.getString("key.deleteMenu"));
		searchMenu.setText(tr.getString("key.searchMenu"));
		searchMenuItem.setText(tr.getString("key.searchMenuItem"));
		a5.setText(tr.getString("key.searchByName"));
		a6.setText(tr.getString("key.searchByCategory"));
		allMenu.setText(tr.getString("key.all"));
		finishedMenu.setText(tr.getString("key.finished"));
		plannedMenu.setText(tr.getString("key.planned"));
		activeMenu.setText(tr.getString("key.active"));
		suspendedMenu.setText(tr.getString("key.suspended"));
		thrownMenu.setText(tr.getString("key.throwed"));
		otherMenu.setText(tr.getString("key.other"));
		a4.setText(tr.getString("key.stat"));
		aboutMenu.setText(tr.getString("key.nv"));
		titleLabel.setText(tr.getString("key.titleLabel"));
		lengthLabel.setText(tr.getString("key.lenthLabel"));
		commentLabel.setText(tr.getString("key.commentLabel"));
		//resources.getLocale();
		
		if (FileAdministrator.configFileCreated()) {
			//this.OpenOnAction(null);
			a1.disableProperty().set(false);
	    	a2.disableProperty().set(false);
	    	a3.disableProperty().set(false);
	    	a4.disableProperty().set(false);
	    	a5.disableProperty().set(false);
	    	a6.disableProperty().set(false);
	    	listView.disableProperty().set(false);
	    	if (!FileAdministrator.isContentAnime()) {
				FileAdministrator.makeContentAnime();
			} 
	    	betolt(2);
			
			
		}
		
		
		
		MenuItem print1 = new MenuItem(tr.getString("key.deleteC"));
		
		print1.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent t) {
			 DeleteOnAction(t);
		
			}
			});
		
		
		
     MenuItem print3 = new MenuItem(tr.getString("key.content") + " igazi");
		
		print3.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent t) {
			  System.out.println("igazi tartalom kiiratása");
			  System.out.println(listView.getSelectionModel().getSelectedItem().getAnimeTartalom());
			  textAreaShow();
			  
		
			}
			});
		
		cmenu.getItems().addAll(print1, print3);
		listView.setContextMenu(cmenu);
		
		
		
	}
	
	public void setStage(Stage stage) {
		this.stage = stage;
		//this.series = series;
	}
	
	public void listElementSelected() {
		title.setText(listView.getSelectionModel().getSelectedItem().getAnimeNev());
    	comment.setText(listView.getSelectionModel().getSelectedItem().getAnimeMegjegyzes());
    	length.setText(listView.getSelectionModel().getSelectedItem().getAnimeHossz() + "");
    	comboBox.getSelectionModel().select(listView.getSelectionModel().
    			getSelectedItem().getAnimeAllapot());
	}
	
	 @SuppressWarnings("unused")
	private void setListElements(int leng) {
		 //leng = 75;
	    	if (listView.getSelectionModel().getSelectedItem().getAnimeAllapot() == comboBox.getSelectionModel().getSelectedIndex()) {
		    	listView.getSelectionModel().getSelectedItem().setAnimeAllapot(comboBox.getSelectionModel().getSelectedIndex());
		        listView.getSelectionModel().getSelectedItem().setAnimeNev(title.getText());
		        listView.getSelectionModel().getSelectedItem().setAnimeMegjegyzes(comment.getText());
		        listView.getSelectionModel().getSelectedItem().setAnimeHossz(leng);
	    	} else {
	    		listView.getItems().remove(listView.getSelectionModel().getSelectedIndex());
	    	}
	    }

}
