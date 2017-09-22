package components;

@SuppressWarnings("rawtypes")
public class OneAnime implements Comparable{
	
	private int animeID;
	
	private int animeHossz;
	
	private int animeAllapot;
	
	private  String animeNev;
	
	private String animeMegjegyzes;
	
	private String animeTartalom;

	public OneAnime(int animeID, int animeHossz, 
			int animeAllapot, String animeNev,
			String animeMegjegyzes, String animeTartalom) {
		setAnimeID(animeID);
		setAnimeHossz(animeHossz);
		setAnimeAllapot(animeAllapot);
		setAnimeMegjegyzes(animeMegjegyzes);
		setAnimeNev(animeNev);
		setAnimeTartalom(animeTartalom);
	}
	
	@Override
	public String toString() {
		return getAnimeNev();
	}
	
	public int getAnimeID() {
		return animeID;
	}

	public void setAnimeID(int animeID) {
		this.animeID = animeID;
	}

	public int getAnimeHossz() {
		return animeHossz;
	}

	public void setAnimeHossz(int animeHossz) {
		this.animeHossz = animeHossz;
	}

	public int getAnimeAllapot() {
		return animeAllapot;
	}

	public void setAnimeAllapot(int animeAllapot) {
		this.animeAllapot = animeAllapot;
	}

	public String getAnimeNev() {
		return animeNev;
	}

	public void setAnimeNev(String animeNev) {
		this.animeNev = animeNev;
	}

	public String getAnimeMegjegyzes() {
		return animeMegjegyzes;
	}

	public void setAnimeMegjegyzes(String animeMegjegyzes) {
		this.animeMegjegyzes = animeMegjegyzes;
	}

	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		return this.toString().toLowerCase().compareTo(o.toString().toLowerCase());
	}

	public String getAnimeTartalom() {
		return animeTartalom;
	}

	public void setAnimeTartalom(String animeTartalom) {
		this.animeTartalom = animeTartalom;
	}
	
	

}