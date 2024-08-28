package libraryExemple.domain;

import enuns.UserType;

public class Employee extends User {

    private String department;

    public Employee(String department) {
        this.department = department;
    }

    public Employee(String email, String name, String password, String userType, String department) {
        super(email, name, password, userType);
        this.department = department;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    @Override
    public String toString() {
        return super.toString() +
                "Departamento: " + department + "\n";
    }
}
