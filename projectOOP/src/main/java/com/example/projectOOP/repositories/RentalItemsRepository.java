package com.example.projectOOP.repositories;

import com.example.projectOOP.entities.RentalItems;
import org.springframework.data.jpa.repository.JpaRepository;

public interface RentalItemsRepository extends JpaRepository<RentalItems,Long> {
}
