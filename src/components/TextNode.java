package components;

import java.util.ArrayList;
import java.util.List;

public class TextNode {
	
	private String text;
	
	private boolean bold;
	
	private boolean italic;
	
	private boolean icon;
	
	private String iconText;
	
	private int size;
	
	private String color;
	
	private String family;
	
	private boolean link;
	
	private String hyperlink;
	
	private ArrayList<TextNode> children;
	private TextNode parent;
	private int id;
	
	
	public TextNode(String family, String color, int size) {
		setSize(size);
		setColor(color);
		setFamily(family);
		setBold(false);
		setItalic(false);
		children = null;
		parent = null;
	}
	
	public TextNode(String family, String color, int size, boolean bold, boolean italic, TextNode parent) {
		setSize(size);
		setColor(color);
		setFamily(family);
		setBold(bold);
		setItalic(italic);
		children = null;
		setParent(parent);
	}
	



	public String getText() {
		return text;
	}
	
	public void setSize(int size) {
		this.size = size;
	}
	
	public int getSize() {
		return size;
	}

	public void setText(String text) {
		this.text = text;
	}

	public boolean isBold() {
		return bold;
	}

	public void setBold(boolean bold) {
		this.bold = bold;
	}

	public boolean isItalic() {
		return italic;
	}

	public void setItalic(boolean italic) {
		this.italic = italic;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public String getFamily() {
		return family;
	}

	public void setFamily(String family) {
		this.family = family;
	}

	public ArrayList<TextNode> getNode() {
		return children;
	}

	public void setAsChildren(TextNode node) {
		if (children == null)
			children = new ArrayList<TextNode>();
		this.children.add(node);
		//System.out.println("szöveg: " + node.getId() + " csatlakoztatva " + getId() + "-hez");
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public TextNode getParent() {
		return parent;
	}

	public void setParent(TextNode parent) {
		this.parent = parent;
	}

	public void setLink(boolean link) {
		// TODO Auto-generated method stub
		this.link = link;
		
	}
	
	public boolean isLink() {
		return link;
	}

	public boolean isIcon() {
		return icon;
	}



	public String getIconText() {
		return iconText;
	}

	public void setIconText(String iconText) {
		this.iconText = iconText;
	}

	public void setIcon(boolean icon2) {
		// TODO Auto-generated method stub
		icon = icon2;
		
	}

	public String getHyperlink() {
		return hyperlink;
	}

	public void setHyperlink(String hyperlink) {
		this.hyperlink = hyperlink;
	}

}
