package com.example.projectOOP.repositories;

import com.example.projectOOP.entities.Rental;
import org.springframework.data.jpa.repository.JpaRepository;

public interface RentalRepository extends JpaRepository<Rental,Long> {
}
