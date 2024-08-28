package domain;

public class Book {

    private String title;
    private String year;
    private String author;
    private String gender;
    private Integer quantity;

    public Book(){}

    public Book(String author, String gender, String title, Integer quantity, String year) {
        this.author = author;
        this.gender = gender;
        this.title = title;
        this.quantity = quantity;
        this.year = year;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public Integer getQuantity() {
        return quantity;
    }

    public void setQuantity(Integer quantity) {
        this.quantity = quantity;
    }

    public String getYear() {
        return year;
    }

    public void setYear(String year) {
        this.year = year;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
}
