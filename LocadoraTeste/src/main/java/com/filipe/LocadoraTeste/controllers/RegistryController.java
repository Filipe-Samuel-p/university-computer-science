package com.filipe.LocadoraTeste.controllers;


import com.filipe.LocadoraTeste.entity.Registry;
import com.filipe.LocadoraTeste.service.RegistryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(value = "/registry")
public class RegistryController {

    @Autowired
    private RegistryService service;

    @GetMapping
    public ResponseEntity<List<Registry>> findAll(){
        List<Registry> obj = service.findAll();
        return ResponseEntity.ok().body(obj);
    }

    @GetMapping(value = "/{id}")
    public ResponseEntity<Registry> findById(@PathVariable Long id){
        Registry obj = service.findById(id);
        return ResponseEntity.ok().body(obj);
    }
}
