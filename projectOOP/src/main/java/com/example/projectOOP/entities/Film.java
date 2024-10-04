package com.example.projectOOP.entities;


import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonManagedReference;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

@Entity
@Table(name = "tb_films")
@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class Film {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String title;
    private Integer releaseYear;
    private String director;
    private String gender;
    private String synopsis;
    private String urlImage;
    private Boolean available;

    @OneToMany(mappedBy = "id.film")
    @JsonIgnore
    private Set<RentalItems> items = new HashSet<>();

    public Film(Boolean available, String gender, String director, Long id, Integer releaseYear, String synopsis, String title, String urlImage) {
        this.available = available;
        this.gender = gender;
        this.director = director;
        this.id = id;
        this.releaseYear = releaseYear;
        this.synopsis = synopsis;
        this.title = title;
        this.urlImage = urlImage;
    }

    @JsonIgnore
    public Set<Rental> getRentals(){
        Set<Rental> set = new HashSet<>();
        for(RentalItems x : items){
            set.add(x.getRental());
        }
        return set;
    }

}
