package com.example.projectOOP.entities;


import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonManagedReference;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

import java.util.Date;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

@Entity
@Table(name = "tb_rental")
@NoArgsConstructor
@AllArgsConstructor
public class Rental {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Getter @Setter
    private Long id;

    @Getter @Setter
    private Date rentalDate;

    @ManyToOne
    @JoinColumn(name = "client_id")
    @Getter @Setter
    private User client;

    @Getter
    @OneToMany(mappedBy = "id.rental", fetch = FetchType.EAGER)
    @JsonManagedReference
    private Set<RentalItems> items = new HashSet<>();

    public Rental(User client, Long id, Date rentalDate) {
        this.client = client;
        this.id = id;
        this.rentalDate = rentalDate;
    }

}
