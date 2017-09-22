
package data;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import components.OneAnime;

final public class FileAdministrator {
	private static File file;
	private static File container;
	
	public static void setFileName(File f) {
		file = f;
		System.out.println(file + " has open");
		
		  try {
				
				BufferedWriter br = new BufferedWriter(new FileWriter("series.conf"));
				
				br.write(file.toString());
				
				System.out.println("series created");
				
				
				br.close();
		} catch (Exception ex) {}
	}
	
	
	public static void newFIle(File filek)  {
		  try {

				DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();
				DocumentBuilder docBuilder = docFactory.newDocumentBuilder();

				// root elements
				Document doc = docBuilder.newDocument();
				Element rootElement = doc.createElement("Animek");
				doc.appendChild(rootElement);

				// staff elements
				Element staff = doc.createElement("anime");
				rootElement.appendChild(staff);

				// set attribute to staff element
				

				// shorten way
				// staff.setAttribute("id", "1");

				// ID
				Element id = doc.createElement("animeID");
				id.appendChild(doc.createTextNode("1"));
				staff.appendChild(id);

				// name
				Element name = doc.createElement("animeNev");
				name.appendChild(doc.createTextNode("Empty"));
				staff.appendChild(name);

				// change
				Element nickname = doc.createElement("nezem");
				nickname.appendChild(doc.createTextNode("1"));
				staff.appendChild(nickname);

				// salary elements
				Element salary = doc.createElement("reszek");
				salary.appendChild(doc.createTextNode("0"));
				staff.appendChild(salary);
				
				Element resz = doc.createElement("megjegyzes");
				resz.appendChild(doc.createTextNode("---"));
				staff.appendChild(resz);
				
				Element tartalom = doc.createElement("tartalom");
				tartalom.appendChild(doc.createTextNode("..."));
				staff.appendChild(tartalom);
				
				

				// write the content into xml file
				
				TransformerFactory transformerFactory = TransformerFactory.newInstance();
				Transformer transformer = transformerFactory.newTransformer();
				DOMSource source = new DOMSource(doc);
				StreamResult result = new StreamResult(filek);
				file = filek;

				// Output to console for testing
				// StreamResult result = nElement id = (Element)elem.getElementsByTagName("animeID").item(0);ew StreamResult(System.out);

				transformer.transform(source, result);

				System.out.println("File saved!");

			  } catch (ParserConfigurationException pce) {
				pce.printStackTrace();
			  } catch (TransformerException tfe) {
				tfe.printStackTrace();
			  }
		  
		  
		  /*configurációs fájl létrehozása*/
		  
		  
		  try {
				
				BufferedWriter br = new BufferedWriter(new FileWriter("series.conf"));
				
				br.write(file.toString());
				
				System.out.println("series created");
				
				
				br.close();
		} catch (Exception ex) {}
	}
	
	
	
	@SuppressWarnings("unchecked")
	public static ArrayList<OneAnime> animekXML(int allapot) {
		ArrayList<OneAnime> animk = new ArrayList<OneAnime>();
		try {
			File fXmlFile = file;
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(fXmlFile);
			NodeList nlist = doc.getElementsByTagName("nezem");
			if (allapot > 0) {
			for (int i = 0; i < nlist.getLength(); ++i) {
				Element id = (Element)nlist.item(i);
				String idS = id.getTextContent();
				//System.out.println(idS);
				if (idS.equals(""+(allapot - 1))) {
					Element parent = (Element)id.getParentNode();
					//parent.getParentNode().removeChild(parent);
					parent.getElementsByTagName("animeNev").item(0).getTextContent();
					int animeID = Integer.parseInt(parent.getElementsByTagName("animeID").item(0).getTextContent());
					//int animeAllapot = Integer.parseInt(parent.getElementsByTagName("nezem").item(0).getTextContent());
					int animeReszek = Integer.parseInt(parent.getElementsByTagName("reszek").item(0).getTextContent());
					String animeNev = parent.getElementsByTagName("animeNev").item(0).getTextContent();
					String megjegyzes = parent.getElementsByTagName("megjegyzes").item(0).getTextContent();
					String tartalom = parent.getElementsByTagName("tartalom").item(0).getTextContent();
					animk.add(new OneAnime(animeID, animeReszek, allapot - 1, animeNev, megjegyzes, tartalom));
				}
			}
			} else {
				
				for (int i = 0; i < nlist.getLength(); ++i) {
					Element id = (Element)nlist.item(i);
					@SuppressWarnings("unused")
					String idS = id.getTextContent();
					//System.out.println(idS);
					Element parent = (Element)id.getParentNode();
					//parent.getParentNode().removeChild(parent);
					parent.getElementsByTagName("animeNev").item(0).getTextContent();
					int animeID = Integer.parseInt(parent.getElementsByTagName("animeID").item(0).getTextContent());
					int animeAllapot = Integer.parseInt(parent.getElementsByTagName("nezem").item(0).getTextContent());
					int animeReszek = Integer.parseInt(parent.getElementsByTagName("reszek").item(0).getTextContent());
					String animeNev = parent.getElementsByTagName("animeNev").item(0).getTextContent();
					String megjegyzes = parent.getElementsByTagName("megjegyzes").item(0).getTextContent();
					String tartalom = parent.getElementsByTagName("tartalom").item(0).getTextContent();
					//System.out.println("tartalom: " + tartalom);
					animk.add(new OneAnime(animeID, animeReszek, animeAllapot, animeNev, megjegyzes, tartalom));
				}
				
				
				
			}
			Collections.sort(animk);
		} catch(Exception ex) {};
		return animk;
	}
	
	
	
	@SuppressWarnings("unchecked")
	public static ArrayList<OneAnime> keresAnimekXML(String karakterLanc) {
		ArrayList<OneAnime> animk = new ArrayList<OneAnime>();
		try {
			File fXmlFile = file;
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(fXmlFile);
			NodeList nlist = doc.getElementsByTagName("animeNev");
			for (int i = 0; i < nlist.getLength(); ++i) {
				Element id = (Element)nlist.item(i);
				String idS = id.getTextContent();
				//System.out.println(idS);
				if (idS.toLowerCase().contains(karakterLanc.toLowerCase())) {
					Element parent = (Element)id.getParentNode();
					//parent.getParentNode().removeChild(parent);
					parent.getElementsByTagName("animeNev").item(0).getTextContent();
					int animeID = Integer.parseInt(parent.getElementsByTagName("animeID").item(0).getTextContent());
					//int animeAllapot = Integer.parseInt(parent.getElementsByTagName("nezem").item(0).getTextContent());
					int animeReszek = Integer.parseInt(parent.getElementsByTagName("reszek").item(0).getTextContent());
					int animeAllapot = Integer.parseInt(parent.getElementsByTagName("nezem").item(0).getTextContent());
					String animeNev = parent.getElementsByTagName("animeNev").item(0).getTextContent();
					String megjegyzes = parent.getElementsByTagName("megjegyzes").item(0).getTextContent();
					String tartalom = parent.getElementsByTagName("tartalom").item(0).getTextContent();
					animk.add(new OneAnime(animeID, animeReszek, animeAllapot, animeNev, megjegyzes, tartalom));
				}
			}
			Collections.sort(animk);
			} catch (Exception ex) {}
			return animk;
		
		}
	
	
	
	public static void modositAnimeXML(int index, String nev, String megjegyzes, int reszek, int allapot) {
		try {
			File fXmlFile = file;
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(fXmlFile);
			
			
			NodeList nlist = doc.getElementsByTagName("animeID");
			
			boolean b = true;
			for (int i = 0; i < nlist.getLength() && b; ++i) {
				Element id = (Element)nlist.item(i);
				String idS = id.getTextContent();
				//System.out.println(idS);
				if (idS.equals(""+index)) {
					Element parent = (Element)id.getParentNode();
					//parent.getParentNode().removeChild(parent);
					parent.getElementsByTagName("animeNev").item(0).setTextContent(nev);
					parent.getElementsByTagName("nezem").item(0).setTextContent(allapot+"");
					parent.getElementsByTagName("megjegyzes").item(0).setTextContent(megjegyzes);
					parent.getElementsByTagName("reszek").item(0).setTextContent(reszek+"");
					
					b = false;
				}
			}
			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();
			DOMSource source = new DOMSource(doc);
			StreamResult result = new StreamResult(file);

			// Output to console for testing
			// StreamResult result = nElement id = (Element)elem.getElementsByTagName("animeID").item(0);ew StreamResult(System.out);

			transformer.transform(source, result);

			//System.out.println("File saved!");
			
			
			
		}catch (Exception ex) {}
	}
	
	
	public static boolean isContentAnime() {
		try {
			File fXmlFile = file;
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(fXmlFile);
			
			
			NodeList nlist = doc.getElementsByTagName("animeID");
			
			Element parent = (Element)nlist.item(0).getParentNode();
			parent.getElementsByTagName("tartalom").item(0).getTextContent();
		
			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();
			DOMSource source = new DOMSource(doc);
			StreamResult result = new StreamResult(file);

			// Output to console for testing
			// StreamResult result = nElement id = (Element)elem.getElementsByTagName("animeID").item(0);ew StreamResult(System.out);

			transformer.transform(source, result);

			//System.out.println("File saved!");
			
			return true;
			
			
			
		}catch (Exception ex) {
			//System.out.println(ex);
			//System.exit(0);
			return false;
		}
		
	}
	
	
	
	
	public static void ujAnimeXML(String animeNev) {
		ujAnimeXML(0, 1, animeNev, "-----");
	}
	
	
	public static void ujAnimeXML(int reszek, int allapot, String animeNevS, String megjegyzesS) {
		try{
			File fXmlFile = file;
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(fXmlFile);
					
			//optional, but recommended
			//read this - http://stackoverflow.com/questions/13786607/normalization-in-dom-parsing-with-java-how-does-it-work
			doc.getDocumentElement().normalize();
			
			Element rootElement = doc.getDocumentElement();
			
			// staff elements
			Element staff = doc.createElement("anime");
			rootElement.appendChild(staff);
			
			//int id = doc.getElementsByTagName("animeID").getLength()+1;
			
			NodeList nlist = doc.getElementsByTagName("animeID");
			Element elementes = (Element)nlist.item(nlist.getLength() - 1);
			String idS = elementes.getTextContent();
			int id = Integer.parseInt(idS) + 1;
			
			
			Element animeId = doc.createElement("animeID");
			animeId.appendChild(doc.createTextNode(id+""));
			
			staff.appendChild(animeId);


			// shorten way
			// staff.setAttribute("id", "1");

			// firstname elements
			Element animeNev = doc.createElement("animeNev");
			animeNev.appendChild(doc.createTextNode(animeNevS));
			staff.appendChild(animeNev);

			// lastname elements
			Element lastname = doc.createElement("nezem");
			lastname.appendChild(doc.createTextNode(allapot+""));
			staff.appendChild(lastname);

			// nickname elements
			Element nickname = doc.createElement("reszek");
			nickname.appendChild(doc.createTextNode(reszek+""));
			staff.appendChild(nickname);
			
			Element megjegyzes = doc.createElement("megjegyzes");
			megjegyzes.appendChild(doc.createTextNode(megjegyzesS));
			staff.appendChild(megjegyzes);
			
			Element tartalom = doc.createElement("tartalom");
			tartalom.appendChild(doc.createTextNode(megjegyzesS));
			staff.appendChild(tartalom);
			
			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();
			DOMSource source = new DOMSource(doc);
			StreamResult result = new StreamResult(file);

			// Output to console for testing
			// StreamResult result = new StreamResult(System.out);

			transformer.transform(source, result);

			//System.out.println("File saved!");

			
			
			
		} catch (Exception ex) {}
	}
	
	
	public static void makeContentAnime() {
		try {
		File fXmlFile = file;
		DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
		DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
		Document doc = dBuilder.parse(fXmlFile);
		
		
		NodeList nlist = doc.getElementsByTagName("animeID");
		
		String tartalomS = "...";
		for (int i = 0; i < nlist.getLength(); ++i) {
				Element id = (Element)nlist.item(i);
				Element parent = (Element)id.getParentNode();
				Element tartalom = doc.createElement("tartalom");
				tartalom.appendChild(doc.createTextNode(tartalomS));
				parent.appendChild(tartalom);
		}
		TransformerFactory transformerFactory = TransformerFactory.newInstance();
		Transformer transformer = transformerFactory.newTransformer();
		DOMSource source = new DOMSource(doc);
		StreamResult result = new StreamResult(file);

		// Output to console for testing
		// StreamResult result = nElement id = (Element)elem.getElementsByTagName("animeID").item(0);ew StreamResult(System.out);

		transformer.transform(source, result);

		//System.out.println("File saved!");
		} catch(Exception ex) {}
		
	}
	
	
	
	public static void torolAnimeXML(int animeID) {
		try {
			File fXmlFile = file;
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.parse(fXmlFile);
			NodeList nlist = doc.getElementsByTagName("animeID");
			boolean b = true;
			for (int i = 0; i < nlist.getLength() && b; ++i) {
				Element id = (Element)nlist.item(i);
				String idS = id.getTextContent();
				//System.out.println(idS);
				if (idS.equals(""+animeID)) {
					Element parent = (Element)id.getParentNode();
					parent.getParentNode().removeChild(parent);
					b = false;
				}
			}
			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();
			DOMSource source = new DOMSource(doc);
			StreamResult result = new StreamResult(file);

			// Output to console for testing
			// StreamResult result = nElement id = (Element)elem.getElementsByTagName("animeID").item(0);ew StreamResult(System.out);

			transformer.transform(source, result);

			//System.out.println("File saved!");

			
	} catch(Exception ex) {}
	}
	
	public static int animekSzamaXML(int allapot) {
	
	int szam = 0;
	try {
		File fXmlFile = file;
		DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
		DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
		Document doc = dBuilder.parse(fXmlFile);
		NodeList nlist = doc.getElementsByTagName("nezem");
		if (allapot > 0) {
		for (int i = 0; i < nlist.getLength(); ++i) {
			Element id = (Element)nlist.item(i);
			String idS = id.getTextContent();
			//System.out.println(idS);
			if (idS.equals(""+(allapot - 1))) {
			  szam ++;
			}
		}
		} else {
			
			for (int i = 0; i < nlist.getLength(); ++i) {
				szam ++;
			}
			
			
			
			
		}
	} catch(Exception ex) {};
	return szam;
}


	public static boolean configFileCreated() {
		{
			// TODO Auto-generated method stub
			
			File config = new File ("series.conf");
			
			try {
			
				BufferedReader br = new BufferedReader(new FileReader("series.conf"));
				
				String line = br.readLine();
				
				file = new File(line);
				
				br.close();
				
				return true;
			
			} catch (Exception ex) {
				
				return false;
			}
			
		}
	}



	
	
public static void setContainerFile(File file2) {
		
		file = file2;
		

		
		
		
		try {
		
			BufferedWriter br = new BufferedWriter(new FileWriter("wifu.conf"));
			
			br.write(file.toString());
			
			
			br.close();
	} catch (Exception ex) {}
	}


public static void setTartalom(int index, String text) {
	// TODO Auto-generated method stub
	
	
	try {
		File fXmlFile = file;
		DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
		DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
		Document doc = dBuilder.parse(fXmlFile);
		
		
		NodeList nlist = doc.getElementsByTagName("animeID");
		
		boolean b = true;
		for (int i = 0; i < nlist.getLength() && b; ++i) {
			Element id = (Element)nlist.item(i);
			String idS = id.getTextContent();
			//System.out.println(idS);
			if (idS.equals(""+index)) {
				Element parent = (Element)id.getParentNode();
				//parent.getParentNode().removeChild(parent);
				parent.getElementsByTagName("tartalom").item(0).setTextContent(text);
				
				
				b = false;
			}
		}
		TransformerFactory transformerFactory = TransformerFactory.newInstance();
		Transformer transformer = transformerFactory.newTransformer();
		DOMSource source = new DOMSource(doc);
		StreamResult result = new StreamResult(file);

		// Output to console for testing
		// StreamResult result = nElement id = (Element)elem.getElementsByTagName("animeID").item(0);ew StreamResult(System.out);

		transformer.transform(source, result);

		//System.out.println("File saved!");
		
		
		
	}catch (Exception ex) {}
	
}


}
