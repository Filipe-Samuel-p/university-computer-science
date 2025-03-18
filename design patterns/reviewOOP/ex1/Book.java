
public class Book{

    private String author;
    private String tittle;
    private String date;

    public Book(){}

    public Book(String author, String tittle, String date) {
        this.author = author;
        this.tittle = tittle;
        this.date = date;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getTittle() {
        return tittle;
    }

    public void setTittle(String tittle) {
        this.tittle = tittle;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    @java.lang.Override
    public java.lang.String toString() {
        return "Book{" +
                "author='" + author + '\'' +
                ", tittle='" + tittle + '\'' +
                ", date='" + date + '\'' +
                '}';
    }
}