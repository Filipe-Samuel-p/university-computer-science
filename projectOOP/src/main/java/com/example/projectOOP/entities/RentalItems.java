package com.example.projectOOP.entities;


import com.fasterxml.jackson.annotation.JsonIgnore;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Entity
@Table(name = "tb_rental_item")
@AllArgsConstructor
@NoArgsConstructor
public class RentalItems {

    @EmbeddedId
    protected RentalItemsPk id = new RentalItemsPk();

    @Getter @Setter
    private Integer quantity;

    public RentalItems(Rental rental, Film film, Integer quantity){
        id.setRental(rental);
        id.setFilm(film);
        this.quantity = quantity;
    }

    @JsonIgnore
    public  Rental getRental() {
        return id.getRental();
    }

    public void setId(Rental rental) {
        id.setRental(rental);
    }

    public Film getFilm(){
        return id.getFilm();
    }

}
