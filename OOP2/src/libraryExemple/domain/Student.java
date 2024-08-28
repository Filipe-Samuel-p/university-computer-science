package libraryExemple.domain;

import enuns.UserType;

public class Student extends User{

    private String course;
    private Double cr;

    public Student(String course, Double cr) {
        this.course = course;
        this.cr = cr;
    }

    public Student(String email, String name, String password, String userType, String course, Double cr) {
        super(email, name, password, userType);
        this.course = course;
        this.cr = cr;
    }

    public String getCourse() {
        return course;
    }

    public void setCourse(String course) {
        this.course = course;
    }

    public Double getCr() {
        return cr;
    }

    public void setCr(Double cr) {
        this.cr = cr;
    }

    @Override
    public String toString() {
        return  super.toString() +
                "Curso: " + course + "\n" +
                "CR: " + cr + "\n";
    }
}
