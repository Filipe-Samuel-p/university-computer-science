package com.example.projectOOP.controllers;


import com.example.projectOOP.entities.Film;
import com.example.projectOOP.service.FilmService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.support.ServletUriComponentsBuilder;

import java.net.URI;
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

    @PostMapping
    public ResponseEntity<Film> insert(@RequestBody Film obj){
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
    public ResponseEntity<Film> update(@PathVariable Long id, @RequestBody Film obj){
        obj = service.update(id,obj);
        return ResponseEntity.ok().body(obj);
    }
}
