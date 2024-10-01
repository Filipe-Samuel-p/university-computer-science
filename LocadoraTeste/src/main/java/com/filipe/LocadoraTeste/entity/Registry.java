package com.filipe.LocadoraTeste.entity;


import jakarta.persistence.*;

@Entity
public class Registry {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @ManyToOne
    @JoinColumn(name= "user_Id")
    private Userr user;

    private String rentalDate;

    public Registry(){}
    public Registry(Long id, String rentalDate, Userr user) {
        this.id = id;
        this.rentalDate = rentalDate;
        this.user = user;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getRentalDate() {
        return rentalDate;
    }

    public void setRentalDate(String rentalDate) {
        this.rentalDate = rentalDate;
    }

    public Userr getUser() {
        return user;
    }

    public void setUser(Userr user) {
        this.user = user;
    }
}
