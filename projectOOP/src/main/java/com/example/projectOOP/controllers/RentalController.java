package com.example.projectOOP.controllers;

import com.example.projectOOP.entities.Rental;
import com.example.projectOOP.service.RentalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(value = "/rentals")
public class RentalController {

    @Autowired
    private RentalService service;

    public ResponseEntity<List<Rental>> findAll(){
        List<Rental> rentalList = service.findAll();
        return ResponseEntity.ok().body(rentalList);
    }

}