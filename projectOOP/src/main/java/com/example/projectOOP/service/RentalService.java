package com.example.projectOOP.service;

import com.example.projectOOP.entities.Rental;
import com.example.projectOOP.repositories.RentalRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class RentalService {

    @Autowired
    private RentalRepository repository;

    public List<Rental> findAll(){
        return repository.findAll();
    }
}
