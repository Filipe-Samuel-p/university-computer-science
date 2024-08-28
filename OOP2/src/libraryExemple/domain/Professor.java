package libraryExemple.domain;

import enuns.UserType;

public class Professor extends User{

    private String department;
    private String researchArea;

    public Professor(String department, String researchArea) {
        this.department = department;
        this.researchArea = researchArea;
    }

    public Professor(String email, String name, String password, String userType, String department, String researchArea) {
        super(email, name, password, userType);
        this.department = department;
        this.researchArea = researchArea;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public String getResearchArea() {
        return researchArea;
    }

    public void setResearchArea(String researchArea) {
        this.researchArea = researchArea;
    }

    public void authorialBooks(){

    }

    @Override
    public String toString() {
        return super.toString() +
                "Departamento: " + department + "\n" +
                "Area De pesquisa: " + researchArea + "\n";
    }
}
