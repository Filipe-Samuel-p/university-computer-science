package com.example.projectOOP.controllers;


import com.example.projectOOP.entities.Film;
import com.example.projectOOP.service.FilmService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(value = "/films")
public class FilmController {

    @Autowired
    private FilmService service;

    @GetMapping
    public ResponseEntity<List<Film>> findAll(){
        List<Film> filmList = service.findAll();
        return ResponseEntity.ok().body(filmList);
    }

    @GetMapping(value = "/{id}")
    public ResponseEntity<Film> findById(@PathVariable Long id){
        Film film = service.findById(id);
        return ResponseEntity.ok().body(film);
    }

}
