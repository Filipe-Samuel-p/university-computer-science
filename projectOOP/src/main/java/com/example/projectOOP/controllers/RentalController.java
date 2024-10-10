package com.example.projectOOP.controllers;

import com.example.projectOOP.entities.Film;
import com.example.projectOOP.entities.Rental;
import com.example.projectOOP.service.RentalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;

import java.net.URI;
import java.util.List;

@RestController
@RequestMapping(value = "/rentals")
public class RentalController {

    @Autowired
    private RentalService service;

    @GetMapping
    public ResponseEntity<List<Rental>> findAll(){
        List<Rental> rentalList = service.findAll();
        return ResponseEntity.ok().body(rentalList);
    }

    @GetMapping(value = "/{id}")
    public ResponseEntity<Rental> findById(@PathVariable Long id){
        Rental obj = service.findById(id);
        return ResponseEntity.ok().body(obj);
    }

    @PostMapping
    public ResponseEntity<Rental> insert(@RequestBody Rental obj){
        obj = service.insert(obj);
        URI uri = ServletUriComponentsBuilder.fromCurrentRequestUri()
                .path("/{id}")
                .buildAndExpand(obj.getId()).toUri();
        return ResponseEntity.created(uri).body(obj);
    }

    @DeleteMapping(value = "/{id}")
    public ResponseEntity<Void> delete(@PathVariable Long id){
        service.delete(id);
        return ResponseEntity.noContent().build();
    }

    @PutMapping(value = "/{id}")
    public ResponseEntity<Rental> update(@PathVariable Long id, @RequestBody Rental obj){
        obj = service.update(id,obj);
        return ResponseEntity.ok().body(obj);
    }
}

