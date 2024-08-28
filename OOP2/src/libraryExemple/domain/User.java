package libraryExemple.domain;

import enuns.UserType;

public class User {

    private String name;
    private String email;
    private String userType;
    private String password;

    public User(){}

    public User(String email, String name, String password, String userType) {
        this.email = email;
        this.name = name;
        this.password = password;
        this.userType = userType;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUserType() {
        return userType;
    }

    public void setUserType(String userType) {
        this.userType = userType;
    }

    @Override
    public String toString() {
        return "Name: " + name + "\n" +
                "Email: " + email + "\n" +
                "Tipo de usuário: " + userType + "\n" +
                "Senha: " + password + "\n";
    }
}
