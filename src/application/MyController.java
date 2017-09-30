package application;

import java.awt.GraphicsEnvironment;
import java.io.BufferedReader;
import java.io.File;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URI;
import java.net.URL;
import java.nio.file.FileSystem;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.ResourceBundle;
import java.util.Stack;
import java.util.stream.Stream;

import components.DoubleString;
import components.TextNode;
import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.ListChangeListener;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.ColorPicker;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Hyperlink;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.Slider;
import javafx.scene.control.TextArea;
import javafx.scene.control.Tooltip;
import javafx.scene.effect.DropShadow;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundImage;
import javafx.scene.layout.BackgroundPosition;
import javafx.scene.layout.BackgroundRepeat;
import javafx.scene.layout.BackgroundSize;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.text.TextFlow;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;

public class MyController implements Initializable {

    @FXML
    private TextArea textArea;

    @FXML
    private CheckBox editable;
    
    
    final WebView browser = new WebView();
    final WebEngine webEngine = browser.getEngine();

    @FXML
    private ColorPicker colorPicker;
    
    private ScrollPane scrollPane = new ScrollPane();
    
    private TextFlow textFlow;
    
    @FXML
    private ComboBox<Integer> slider;
    
    @FXML
    private ComboBox<String> fonts;
    
    @FXML
    private GridPane gridPane;
    
    private HashMap<String, DoubleString> hashMap = new HashMap<String, DoubleString>();
    
    
    final String[] images = {"alert.gif",
    		"rar.gif",
    		"info.gif",
    		"icon_mad.gif",
    		"wav.gif",
    		"mov.gif",
    		"icon_e_sad.gif",
    		"netscape.gif",
    		"txt.gif",
    		"radioactive.gif",
    		"icon_eek.gif",
    		"icon_rolleyes.gif",
    		"doc.gif",
    		"zip.gif",
    		"html.gif",
    		"mp3.gif",
    		"icon_cool.gif",
    		"icon_razz.gif",
    		"icon_e_confused.gif",
    		"heart.gif",
    		"icon_e_ugeek.gif",
    		"fire.gif",
    		"icon_e_surprised.gif",
    		"xls.gif",
    		"icon_cry.gif",
    		"bmp.gif",
    		"mid.gif",
    		"mpg.gif",
    		"star.gif",
    		"jpg.gif",
    		"icon_evil.gif",
    		"icon_question.gif",
    		"avi.gif",
    		"pdf.gif",
    		"flash.gif",
    		"icon_e_wink.gif",
    		"icon_exclaim.gif",
    		"icon_idea.gif",
    		"icon_mrgreen.gif",
    		"icon_twisted.gif",
    		"icon_e_smile.gif",
    		"icon_arrow.gif",
    		"icon_redface.gif",
    		"mrgreen.gif",
    		"icon_e_biggrin.gif",
    		"ppt.gif",
    		"gif.gif",
    		"exe.gif",
    		"thinking.gif",
    		"question.gif",
    		"redface.gif",
    		"icon_neutral.gif",
    		"icon_e_geek.gif",
    		"icon_lol.gif"};

	private ResourceBundle tr;

    @FXML
    void bOnAction(ActionEvent event) {
    	int caretCurent = textArea.getCaretPosition();
    	
    	String text = textArea.getText();
    	String str1 = text.substring(0, caretCurent);
    	String str2 = text.substring(caretCurent, text.length());
    	
    	String newText = str1 + "[b]";
    	caretCurent = newText.length();
    	newText += "[/b]" + str2;
    	
    	textArea.setText(newText);
    	textArea.positionCaret(caretCurent);
    	textArea.requestFocus();
    	textArea.positionCaret(caretCurent);
    	
    	

    }

    @FXML
    void colorButtonOnAction(ActionEvent event) {
    	String color = this.toRgbString(colorPicker.getValue());
    	
    	int caretCurent = textArea.getCaretPosition();
    	
    	String text = textArea.getText();
    	String str1 = text.substring(0, caretCurent);
    	String str2 = text.substring(caretCurent, text.length());
    	
    	//System.out.println(str1);
    	//System.out.println(str2);
    	
    	String newText = str1 + "[c=" + color + "]";
    	caretCurent = newText.length();
    	newText += "[/c]" + str2;
    	
    	textArea.setText(newText);
    	textArea.positionCaret(caretCurent);
    	textArea.requestFocus();
    	textArea.positionCaret(caretCurent);
    	
    	//textArea.setText(textArea.getText() + "[color = " + color + "][/color]");
    	//textArea.positionCaret(6);
    	//textArea.positionCaret(textArea.getText().length() );
    	//textArea.requestFocus();
    	//textArea.positionCaret(textArea.getCaretPosition() - 8);
    }

    @FXML
    void iOnAction(ActionEvent event) {
    	
    	int caretCurent = textArea.getCaretPosition();
    	
    	String text = textArea.getText();
    	String str1 = text.substring(0, caretCurent);
    	String str2 = text.substring(caretCurent, text.length());
    	
    	String newText = str1 + "[i]";
    	caretCurent = newText.length();
    	newText += "[/i]" + str2;
    	
    	
    	textArea.setText(newText);
    	textArea.positionCaret(caretCurent);
    	textArea.requestFocus();
    	textArea.positionCaret(caretCurent);
    	

    }
    
    
    private static void getAllFiles(File curDir) {

        File[] filesList = curDir.listFiles();
        for(File f : filesList){
            if(f.isFile()){
                System.out.println(f.getName());
            }
        }
        

    }
    
    
    @FXML
    void linkOnAction(ActionEvent e) {
    	int caretCurent = textArea.getCaretPosition();
    	
    	String text = textArea.getText();
    	String str1 = text.substring(0, caretCurent);
    	String str2 = text.substring(caretCurent, text.length());
    	
    	String newText = str1 + "[h=http://???]";
    	caretCurent = newText.length();
    	newText += "[/h]" + str2;
    	
    	textArea.setText(newText);
    	textArea.positionCaret(caretCurent);
    	textArea.requestFocus();
    	textArea.positionCaret(caretCurent);
    }
    
    @FXML
    void iconOnAction(ActionEvent e) {
    //	Alert alert = new Alert(Alert.AlertType.INFORMATION);
    	//alert.showAndWait();
    	String args = "";
   	
    	
    	try {
   	Alert alert = new Alert(Alert.AlertType.INFORMATION);
    	
    	ImageView view= new ImageView();
   	   // view.setImage(new Image(Series.class.getResource("favicon-96x96.png").toExternalForm()));
  // 	    alert.setGraphic(view);
  
   	    GridPane grid = new GridPane();
	   	grid.setHgap(10);
	   	grid.setVgap(10);
	   	grid.setPadding(new Insets(20, 150, 10, 10));
	   	
	   	
	    URL curURL = Series.class.getResource("/smiles/");
	   File curlFile = new File(curURL.getFile());
	  // System.out.println(curURL);
	   //System.out.println(curlFile.getName());
	   //File []files = curlFile.listFiles();
	   //System.out.println("files: " + files);
	   int szamlalo = 0;
	   int nevezo = 0;
	   Button btn = null;
	   Image img = null;
	   BackgroundImage backgroundImage = null;
	   Background background  = null;
	   int length = images.length;
	   
		   
	 //  for (int i = 0; i < length; ++i) {
	   
	   for (String object: hashMap.keySet()) {
		   btn = new Button();
		  // System.out.println("\"" + f.getName() + "\",");
		   
		//  System.out.println("/smiles/" + object);
		 
		   
		 backgroundImage = new BackgroundImage( new Image( getClass().getResource((args="/smiles/" + object)).toExternalForm()), BackgroundRepeat.NO_REPEAT, BackgroundRepeat.NO_REPEAT, BackgroundPosition.DEFAULT, BackgroundSize.DEFAULT);
		   //System.out.println(args);  
		// System.out.println("/smiles/" + object);
		  background = new Background(backgroundImage);
		   btn.setBackground(background);
		   
		   btn.setOnAction(new EventHandler<ActionEvent>() {
	            @Override
	            public void handle(ActionEvent event) {
	            //    System.out.println(((Button)event.getSource()).getId());
	                
	                String color = ((Button)event.getSource()).getId();
	            	
	            	int caretCurent = textArea.getCaretPosition();
	            	
	            	String text = textArea.getText();
	            	String str1 = text.substring(0, caretCurent);
	            	String str2 = text.substring(caretCurent, text.length());
	            	

	            	
	            	String newText = str1 + color  + str2;
	            	caretCurent = newText.length();
	            	//newText += "[/m]" + str2;
	            	
	            	textArea.setText(newText);
	            	textArea.positionCaret(caretCurent);
	            	textArea.requestFocus();
	            	textArea.positionCaret(caretCurent);
	            	
	                
	                
	                
	                
	                
	            }
	        });
		   
		   
		   
		   DropShadow shadow = new DropShadow();
		   
		   
		   Tooltip tt = new Tooltip();
		   tt.setText(hashMap.get(object).getShower());
		   tt.setFont(Font.font(null , FontWeight.BOLD, FontPosture.ITALIC, 16));
			  
		  
		 tt.setPrefSize(200, 50);
		  btn.setTooltip(tt);
		   
		   btn.addEventHandler(MouseEvent.MOUSE_ENTERED,
			        new EventHandler<MouseEvent>() {
			          @Override
			          public void handle(MouseEvent e) {
			            ((Button)e.getSource()).setEffect(shadow);
			          }
			        });

			   btn.addEventHandler(MouseEvent.MOUSE_EXITED,
			        new EventHandler<MouseEvent>() {
			          @Override
			          public void handle(MouseEvent e) {
			        	  ((Button)e.getSource()).setEffect(null);
			          }
			        });

		   
		   
		   btn.setId(hashMap.get(object).getWriter());
		  
		   if (szamlalo < 15) {
			  szamlalo++;
		   } else {
			   szamlalo = 0;
			   nevezo++;
		   }
		   grid.add(btn, szamlalo, nevezo);
		   
	   } 
	  // getAllFiles(curlFile);
	   
	 
	   	alert.getDialogPane().setContent(grid);
	   	
	    alert.showAndWait();
    	} catch (Exception ex) {System.out.println("dasd");}
    }

    @FXML
    void sizeOnAction(ActionEvent event) {
    	int size = slider.getSelectionModel().getSelectedItem();
    	
    	int caretCurent = textArea.getCaretPosition();
    	
    	String text = textArea.getText();
    	String str1 = text.substring(0, caretCurent);
    	String str2 = text.substring(caretCurent, text.length());
    	
    	//System.out.println(str1);
    	//System.out.println(str2);
    	
    	String newText = str1 + "[s=" + size + "]";
    	caretCurent = newText.length();
    	newText += "[/s]" + str2;
    	
    	textArea.setText(newText);
    	textArea.positionCaret(caretCurent);
    	textArea.requestFocus();
    	textArea.positionCaret(caretCurent);
    	
 

    }
    
    
    @FXML
    void fontOnAction(ActionEvent event) {
    	String family = fonts.getSelectionModel().getSelectedItem();
    	
    	int caretCurent = textArea.getCaretPosition();
    	
    	String text = textArea.getText();
    	String str1 = text.substring(0, caretCurent);
    	String str2 = text.substring(caretCurent, text.length());
    	
    	//System.out.println(str1);
    	//System.out.println(str2);
    	
    	String newText = str1 + "[f=" + family + "]";
    	caretCurent = newText.length();
    	newText += "[/f]" + str2;
    	
    	textArea.setText(newText);
    	textArea.positionCaret(caretCurent);
    	textArea.requestFocus();
    	textArea.positionCaret(caretCurent);
    }
    
    
    String colorToHex(Color color) {
        String hex1;
        String hex2;

        hex1 = Integer.toHexString(color.hashCode()).toUpperCase();

        switch (hex1.length()) {
        case 2:
            hex2 = "000000";
            break;
        case 3:
            hex2 = String.format("00000%s", hex1.substring(0,1));
            break;
        case 4:
            hex2 = String.format("0000%s", hex1.substring(0,2));
            break;
        case 5:
            hex2 = String.format("000%s", hex1.substring(0,3));
            break;
        case 6:
            hex2 = String.format("00%s", hex1.substring(0,4));
            break;
        case 7:
            hex2 = String.format("0%s", hex1.substring(0,5));
            break;
        default:
            hex2 = hex1.substring(0, 6);
        }
        return hex2;
    }
    
    
    private String toRgbString(Color c) {
        return "rgb("
                          + to255Int(c.getRed())
                    + "," + to255Int(c.getGreen())
                    + "," + to255Int(c.getBlue())
             + ")";
    }
    
    
    private Color fromString(String color) {
    	String substring = color.substring(4, color.length() - 1);
    	String[] subs = substring.split(",");
    	System.out.print("színek: ");
    	for (int i = 0; i < 3; ++i) {
    		System.out.print(subs[i]);
    	}
    	System.out.println("");
    	
    			
    			return Color.rgb(Integer.parseInt(subs[0]), Integer.parseInt(subs[1]), Integer.parseInt(subs[2]));
    }

    private int to255Int(double d) {
        return (int) (d * 255);
        }


	@Override
	public void initialize(URL location, ResourceBundle resources) {
		
		//createHashMap();
		// TODO Auto-generated method stub
		for (int i = 16; i < 80; i += 4) {
			
			slider.getItems().add(new Integer(i));
		}
		slider.getSelectionModel().select(0);
		
		
		// String font[] = 
			  //    GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
		 
		List<String> font = javafx.scene.text.Font.getFamilies();
		
		 
		 for (int i = 0; i < font.size(); ++i) {
			 fonts.getItems().add(font.get(i));
		 }
		 
		 fonts.getSelectionModel().select(27);
		 
		 colorPicker.setValue(Color.BLACK);
		 
		 int width = slider.getSelectionModel().getSelectedItem();
		 String family = fonts.getSelectionModel().getSelectedItem();
		 
		 textArea.setFont(Font.font(family, FontWeight.NORMAL, width)); 
		 textArea.setStyle(
	              "-fx-text-fill: " + toRgbString(Color.BLACK) + ";"
	            );
		 
		 
		 String strElol = "[family=" + family + "]"  +
 	        	"[color=" + toRgbString(Color.BLACK) + "]" +
 	        	"[size=" + width + "]";
 	        	
 	        	String strHatul = 
 	        			"[/size]"
 	        			+ "[/color]"
 	        			+ "[/family]";
		 
		 editable.selectedProperty().addListener(new ChangeListener<Boolean>() {
	    	    @Override
	    	    public void changed(ObservableValue<? extends Boolean> observable, Boolean oldValue, Boolean newValue) {
	    	        if (newValue) {
	    	        	//scrollPane.getChildrenUnmodifiable().remove(textArea);
	    	        	//scrollPane.getChildrenUnmodifiable().add(textFlow);
	    	        	//System.out.println("pipa");
	    	        	gridPane.getChildren().remove(textArea);
	    	        	textFlow = new TextFlow();
	    	        	textFlow.setPrefWidth(800);
	    	        	
	    	       
	    	        	VBox vb = new VBox();
	    	        	vb.getChildren().addAll(textFlow);
	    	        	scrollPane.setContent(vb);
	    	        	
	    	        	String text = textArea.getText();
	    	        	
	    	        	text = emotionText(text);
	    	        	
	    	        	ArrayList<TextNode> nodes =  getModifydTexts(text, family, toRgbString(Color.BLACK), width);
	    	        	
	    	        	int nodeSize = nodes.size() - 1;
	    	        	
	    	        	Text txt;
	    	        	
	    	        	Hyperlink linker;
	    	        	
	    	        	for (int i = 0; i <= nodeSize; ++i) {
	    	        		if (!nodes.get(i).getText().equals("")) {
	    	        		//System.out.println(nodes.get(i).getText());
	    	        		if (!nodes.get(i).isLink() && !nodes.get(i).isIcon()) {	
	    	        			
	    	                    //ImageView imageView = new ImageView("http://files.softicons.com/download/web-icons/network-and-security-icons-by-artistsvalley/png/16x16/Regular/Friend%20Smiley.png");
	    	
	    	                    //text = (nodes.get(i).getText().replace(":)"," "));
	    	                    
	    	                  
	    	                    
	    	                    
	    	                   // txt = new Text(nodes.get(i).getText().replace(":)"," "));
	    	        			txt = new Text(nodes.get(i).getText());
	    	        			
	    	        			
	    	                    textFlow.getChildren().addAll(txt);
	    	                   
	    	        			//txt.setFill(Color.RED);
	    	        			
	    	        			
	    	        			txt.setFill(fromString(nodes.get(i).getColor()));
	    	        			//textFlow.getChildren().add(txt);
	    	        			if (!nodes.get(i).isBold() && !nodes.get(i).isItalic()) {
	    	        			 txt.setFont(Font.font(nodes.get(i).getFamily(), nodes.get(i).getSize()));
	    	        			} else if (nodes.get(i).isBold() && nodes.get(i).isItalic()) {
	    	        				txt.setFont(Font.font(nodes.get(i).getFamily(), FontWeight.EXTRA_BOLD, FontPosture.ITALIC, nodes.get(i).getSize()));
	    	        				  
	    	        			}
	    	        			else if (nodes.get(i).isBold()) {
	    	        				txt.setFont(Font.font(nodes.get(i).getFamily(), FontWeight.BOLD, nodes.get(i).getSize()));
	    	        				  
	    	        			} else {
	    	        				txt.setFont(Font.font(nodes.get(i).getFamily(), FontPosture.ITALIC, nodes.get(i).getSize()));
	    	        				  
	    	        			}
	    	        			
	    	        		}
	    	        		else {
	    	        			
	    	        			if (nodes.get(i).isLink()) {
	    	        			
	    	        			linker = new Hyperlink(nodes.get(i).getText());
	    	        			
	    	        			
	    	        			 DropShadow shadow = new DropShadow();
	    	        			   
	    	        			   
	    	        			   Tooltip tt = new Tooltip();
	    	        			   tt.setText(nodes.get(i).getHyperlink());
	    	        			   tt.setFont(Font.font(null , FontWeight.BOLD, FontPosture.ITALIC, 16));
	    	        				  
	    	        			  
	    	        			 tt.setPrefSize(300, 50);
	    	        			  linker.setTooltip(tt);
	    	        			   
	    	        			   linker.addEventHandler(MouseEvent.MOUSE_ENTERED,
	    	        				        new EventHandler<MouseEvent>() {
	    	        				          @Override
	    	        				          public void handle(MouseEvent e) {
	    	        				            ((Hyperlink)e.getSource()).setEffect(shadow);
	    	        				          }
	    	        				        });

	    	        				   linker.addEventHandler(MouseEvent.MOUSE_EXITED,
	    	        				        new EventHandler<MouseEvent>() {
	    	        				          @Override
	    	        				          public void handle(MouseEvent e) {
	    	        				        	  ((Hyperlink)e.getSource()).setEffect(null);
	    	        				          }
	    	        				        });

	    	        			   

	    	        			   
	    	        			
	    	        			
	    	        			linker.setOnAction(new myHyperLinkListener(nodes.get(i)));
	    	        			
	    	        			
	    	        			//txt.setFill(Color.RED);
	    	        			linker.setTextFill(fromString(nodes.get(i).getColor()));
	    	        			
	    	        			
	    	        			//linker.setFill(fromString(nodes.get(i).getColor()));
	    	        			textFlow.getChildren().add(linker);
	    	        			if (!nodes.get(i).isBold() && !nodes.get(i).isItalic()) {
	    	        			 linker.setFont(Font.font(nodes.get(i).getFamily(), nodes.get(i).getSize()));
	    	        			} else if (nodes.get(i).isBold() && nodes.get(i).isItalic()) {
	    	        				linker.setFont(Font.font(nodes.get(i).getFamily(), FontWeight.BOLD, FontPosture.ITALIC, nodes.get(i).getSize()));
	    	        				  
	    	        			}
	    	        			else if (nodes.get(i).isBold()) {
	    	        				linker.setFont(Font.font(nodes.get(i).getFamily(), FontWeight.BOLD, nodes.get(i).getSize()));
	    	        				  
	    	        			} else {
	    	        				linker.setFont(Font.font(nodes.get(i).getFamily(), FontPosture.ITALIC, nodes.get(i).getSize()));
	    	        				  
	    	        			}
	    	        			
	    	        			
	    	        			
	    	        		}
	    	        	  else {
	    	        			if (nodes.get(i).isIcon()) {
	    	        				try {
	    	        				ImageView imageView = new ImageView((getClass().getResource("/smiles/" + nodes.get(i).getIconText())).toExternalForm());
	    	        		    	
	    	        				imageView.setFitHeight(nodes.get(i).getSize());
	    	        				imageView.setFitWidth(nodes.get(i).getSize());
	    	        				textFlow.getChildren().add(imageView);
	    	        				} catch (Exception ex) {}
	    	        			}
	    	        	  }
	    	        		}
	    	        		}
	    	        	}
	    	        	
	    	        	//textFlow.getChildren().add(texter);
	    	        	
	    	        	
	    	        	
	    	        	gridPane.add(scrollPane, 0, 0);
	    	        	
	    	        	
	    	        	
	    	        	
	    	        	
	    	        	//Text text = new Text(textArea.getText());
	    	        	//textFlow.getChildren().add(text);
	    	        	
	    	        	
	    	        	
	    	        	
	    	        } else {
	    	        	gridPane.add(textArea, 0, 0);
	    	        	gridPane.getChildren().remove(scrollPane);
	    	        }
	    	    }
		 });
	}

	private ArrayList<TextNode> getModifydTexts(String text, String family, String color, int size) {
					ArrayList<TextNode> myTexts = new ArrayList<TextNode>();
					
					//Stack<TextNode> stack = new Stack<TextNode>();
					
					TextNode first = new TextNode(family, color, size);
					first.setText("kacsa");
					TextNode masik = new TextNode(family, color, size);
					masik.setText("punci");
					myTexts.add(first);
					myTexts.add(masik);
					
					
					TextNode secunder = first;
					TextNode actual = first;
					//myTexts.add(first);
					first.setId(0);
					int szamlalo = 0;
					int i = 0;
					
					String atmeneti = "";
					
					while (i < text.length()) {
						if (text.charAt(i) != '[') {
							atmeneti += text.charAt(i);
							i++;
						}
					else 
					{
					   switch(text.charAt(i+1)) {
					   case 'b': 
					   {
							   /*first.setText(atmeneti);
							   atmeneti = new String("");
							   
							   TextNode secunder = new TextNode(first.getFamily(), first.getColor(), first.getSize(), true, first.isItalic());
							   first = secunder;
							   stack.push(first);
							   //myTexts.add(first);
							   i+= 3;
							   szamlalo++;
							   szamlalo2++;
							   break;
							   */
						   actual.setText(atmeneti);
						   atmeneti = "";
						   szamlalo++;
						   actual = new TextNode(secunder.getFamily(), secunder.getColor(), secunder.getSize(), true, secunder.isItalic(), secunder);
						  
						   actual.setId(szamlalo);
						//  System.out.println("jelenlegi secunder: " + secunder.getId()); 
						   secunder.setAsChildren(actual);
						  // System.out.println("jelenlegi secunder: " + secunder.getId());
						   
						   
						   secunder = actual;
						 //  System.out.println("jelenlegi secunder: " + secunder.getId());
						   
						   i+= 3;
						   break;
					   }
					 
					   
					   case 'i': 
					   {
							   actual.setText(atmeneti);
							   atmeneti = new String("");
							   szamlalo++;
							   
							    actual = new TextNode(secunder.getFamily(), secunder.getColor(), secunder.getSize(), secunder.isBold(), true, secunder);
							   
							   actual.setId(szamlalo);
							   
							   secunder.setAsChildren(actual);
							   
							   secunder = actual;
							   //myTexts.add(first);
							   i += 3;
							   break;  
						   
					   }
					   
				   case '/':
					   {
						   actual.setText(atmeneti);
						   atmeneti = new String("");
						   szamlalo++;
						   secunder = secunder.getParent();
						   actual = new TextNode(secunder.getFamily(), secunder.getColor(), secunder.getSize(), secunder.isBold(), secunder.isItalic(), secunder);
						   actual.setId(szamlalo);
						   secunder.setAsChildren(actual);
						  // secunder = actual;
						   i+= 4;
						   break;
						   
						   
					   }
					   
					   case 's': {
						   actual.setText(atmeneti);
						   atmeneti = new String("");
						   szamlalo++;
						   String csalad = "";
						   for (int j = i + 3; i < text.length() && text.charAt(j) != ']'; ++j) {
							   csalad += text.charAt(j);
						   }
						   
						   int meret = Integer.parseInt(csalad);
						   
						   actual = new TextNode(secunder.getFamily(), secunder.getColor(), meret, secunder.isBold(), secunder.isItalic(), secunder);
						   actual.setId(szamlalo);
						   secunder.setAsChildren(actual);
						   secunder = actual;
						   
						   //myTexts.add(first);
						   
						   i+= csalad.length() + 1 + 3;
						   
						   break; 
						   
					   }
					   
					   
					   case 'f': {
						   actual.setText(atmeneti);
						   atmeneti = new String("");
						   String csalad = "";
						   szamlalo++;
						   for (int j = i + 3; i < text.length() && text.charAt(j) != ']'; ++j) {
							   csalad += text.charAt(j);
						   }
						   actual = new TextNode(csalad, secunder.getColor(), secunder.getSize(), secunder.isBold(), secunder.isItalic(), secunder);
						  
						   actual.setId(szamlalo);
						   secunder.setAsChildren(actual);
						   secunder = actual;
						   
						   //myTexts.add(first);
						   i += csalad.length() + 1 + 3;
						   
						   break; 
						   
					   }
					   
					   
					   case 'c': {
						  // System.out.println("itt vagyok");
						   actual.setText(atmeneti);
						   szamlalo++;
						   atmeneti = new String("");
						   String csalad = "";
						   for (int j = i + 3; i < text.length() && text.charAt(j) != ']'; ++j) {
							   csalad += text.charAt(j);
						   }
						   actual = new TextNode(secunder.getFamily(), csalad, secunder.getSize(), secunder.isBold(), secunder.isItalic(), secunder);
							  
						   actual.setId(szamlalo);
						   secunder.setAsChildren(actual);
						   secunder = actual;
						   
						   i += csalad.length() + 1 + 3;
						  
						   break; 
						   
					   }
					   
					   
					   case 'h': {
						   
					   
					   
					   actual.setText(atmeneti);
					   atmeneti = new String("");
					   szamlalo++;
					   String csalad = "";
					   for (int j = i + 3; i < text.length() && text.charAt(j) != ']'; ++j) {
						   csalad += text.charAt(j);
					   }
					   
					    actual = new TextNode(secunder.getFamily(), secunder.getColor(), secunder.getSize(), secunder.isBold(), true, secunder);
					   
					   actual.setId(szamlalo);
					   actual.setLink(true);
					   actual.setHyperlink(csalad);
					   
					   secunder.setAsChildren(actual);
					   
					   secunder = actual;
					   //myTexts.add(first);
					   i += csalad.length() + 1 + 3;
					   break;  
					   
					  
					   }
					   
					   case 'm': {
						   actual.setText(atmeneti);
						   szamlalo++;
						   atmeneti = new String("");
						   String csalad = "";
						   for (int j = i + 3; i < text.length() && text.charAt(j) != ']'; ++j) {
							   csalad += text.charAt(j);
						   }
						   actual = new TextNode(secunder.getFamily(), secunder.getColor(), secunder.getSize(), secunder.isBold(), secunder.isItalic(), secunder);
							actual.setText("/smile");
						   actual.setIcon(true);
						   actual.setIconText(csalad);
						   actual.setId(szamlalo);
						   secunder.setAsChildren(actual);
						   //secunder = actual;
						   
						   szamlalo++;
						   actual = new TextNode(secunder.getFamily(), secunder.getColor(), secunder.getSize(), secunder.isBold(), secunder.isItalic(), secunder);
							secunder.setAsChildren(actual);
							secunder = actual;
						   
						   i += csalad.length() + 1 + 3;
						   break;
					   }
						   
						   
					   }
					
					}
						
					}
					
					actual.setText(atmeneti);
					
					//System.out.println(secunder.getText() + " " + first.getText());
					return getMyArrayListFromTextNode(first);
					
					//return myTexts;
				
				}
	
	
	private ArrayList<TextNode> getMyArrayListFromTextNode(TextNode first) {
		// TODO Auto-generated method stub
		ArrayList<TextNode> array = new ArrayList<TextNode>();
		array.add(first);
		
		if (first.getNode() != null)
		for (int i = 0; i < first.getNode().size(); ++i) {
			if (first.getNode().get(i).getNode() != null)
				array.addAll(getMyArrayListFromTextNode(first.getNode().get(i)));
			
			else
				array.add(first.getNode().get(i));
		}
		//System.out.println(first.getNode().size());
	//	if (!first.getNode().equals(null)) {
		//	for (int i = 0; i < first.getNode().size(); ++i) {
			//	System.out.println("sorozatszám: " + first.getNode().get(i).getId() + " " + first.getNode().get(i).getText());
				//ArrayList<TextNode> atmeneti = getMyArrayListFromTextNode(first.getNode().get(i));
				//array.addAll(atmeneti);
			//}
		//}
		
		
		
		return array;
		
	}

	int meretes (char egy, char ketto) {
		String s = egy + ketto + "";
		
		return Integer.parseInt(s);
		
			
	}

	
	
	class myHyperLinkListener implements EventHandler<ActionEvent> {
		private TextNode node;
		 VBox root = new VBox();

		public myHyperLinkListener(TextNode node) {
			this.node = node;
		}
		

	
			 @Override
             public void handle(ActionEvent t) {
				 
				 Application a = new Application() {

	                    @Override
	                    public void start(Stage stage)
	                    {
	                    }
	                };
				 
                 a.getHostServices().showDocument(node.getHyperlink());
         }
			
		}



	public void setText(String animeTartalom) {
		// TODO Auto-generated method stub
		textArea.setText(animeTartalom);
		
	}

	public String getText() {
		// TODO Auto-generated method stub
		System.out.println("Meghivás");
		return textArea.getText();
	}
	
	public void setSelectable (boolean select) {
		editable.setSelected(select);
	}

	public void setTR(ResourceBundle tr) {
		// TODO Auto-generated method stub
		this.tr = tr;
		createHashMap();
		
	}
	
	
	
	public String emotionText(String text) {
		
		boolean is = false;
		// TODO Auto-generated method stub
		if (text != "" && text != null) {
			//text = text.replaceAll(")", "/)");
	
		for (String o: hashMap.keySet()) {
			//System.out.println(hashMap.get(o).getWriter());
			if (text.contains(hashMap.get(o).getWriter())) {
				
			is = true;
			//System.out.println(hashMap.get(o).getWriter());
				
			text = text.replaceAll(paranthese(hashMap.get(o).getWriter()), "[m=" + o + "]");
			
			}
		}
		
		
		}

		return text;
	}

	private void createHashMap() {
		// TODO Auto-generated method stub
		try {
			File f = new File(getClass().getResource("/data/smiles.dat").getFile());
			
		    InputStream is = getClass().getResourceAsStream("/data/smiles.dat");
		    InputStreamReader isr = new InputStreamReader(is);
			
		    BufferedReader inputF = new BufferedReader(isr);
			
			String readString;
			String splitter[] = null;
			String tre = "";
			
			while ((readString = inputF.readLine()) != null) {
				
				splitter = readString.split("#");
				tre = tr.getString(splitter[2]);
				
				System.out.println(tre);
				hashMap.put(splitter[0], new DoubleString(splitter[1], tr.getString(splitter[2])));
				//System.out.println(readString);
			}
			
			inputF.close();
		    isr.close();
		    is.close();
		} catch (Exception ex) {
			System.out.println(ex);
			System.exit(0);
		}
		
	}
	
	
	public String paranthese(String s) {
		String k = "";
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == '(' || s.charAt(i) == ')' || s.charAt(i) == '?' || s.charAt(i) == '\\' || s.charAt(i) == '|') {
				k+= "\\" + s.charAt(i);
			} else {
				k+= s.charAt(i);
			}
		}
		return k;
	}

		
}
