package com.filipe.LocadoraTeste.controllers;


import com.filipe.LocadoraTeste.entity.Userr;
import com.filipe.LocadoraTeste.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(value = "/users")
public class UserController {

    @Autowired
    private UserService service;

    @GetMapping
    public ResponseEntity<List<Userr>> findAll(){
        List<Userr> obj = service.findAll();
        return ResponseEntity.ok().body(obj);
    }

    @GetMapping(value = "/{id}")
    public ResponseEntity<Userr> findById(@PathVariable Long id){
        Userr obj = service.findById(id);
        return ResponseEntity.ok().body(obj);
    }
}