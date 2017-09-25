package components;

public class DoubleString {
	public String writer;
	public String shower;
	
	public String getWriter() {
		return writer;
	}
	
	public void setWriter(String writer) {
		this.writer = writer;
	}
	
	public String getShower() {
		return shower;
	}
	
	public void setShower(String shower) {
		this.shower = shower;
	}
	
	public DoubleString(String writer, String shower) {
		setWriter(writer);
		setShower(shower);
	}
	

}
