package domain;

import enuns.UserType;

public class User {

    private String name;
    private String email;
    private UserType userType;
    private String password;

    public User(){}

    public User(String email, String name, String password, UserType userType) {
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

    public UserType getUserType() {
        return userType;
    }

    public void setUserType(UserType userType) {
        this.userType = userType;
    }

    public void rent(){

    }
}
