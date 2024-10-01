package com.filipe.LocadoraTeste.entity;

import jakarta.persistence.*;
import org.apache.catalina.User;

@Entity
@Table(name = "Films")
public class Film {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;
    private String gender;
    private String synopsis;
    private String director;
    private Integer year;
    private Boolean available;
    private String image;

    @ManyToOne
    @JoinColumn(name = "client_id")
    private Userr client;

    public Film(){}
    public Film(Boolean available, String director, String gender, Long id, String name, String synopsis, Integer year,String image) {
        this.available = available;
        this.director = director;
        this.gender = gender;
        this.id = id;
        this.name = name;
        this.synopsis = synopsis;
        this.year = year;
        this.image = image;

    }


    public Boolean getAvailable() {
        return available;
    }

    public void setAvailable(Boolean available) {
        this.available = available;
    }

    public String getDirector() {
        return director;
    }

    public void setDirector(String director) {
        this.director = director;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSynopsis() {
        return synopsis;
    }

    public void setSynopsis(String synopsis) {
        this.synopsis = synopsis;
    }

    public Integer getYear() {
        return year;
    }

    public void setYear(Integer year) {
        this.year = year;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public void setClient(Userr userr) {
    }
}
