package com.filipe.LocadoraTeste.controllers;


import com.filipe.LocadoraTeste.domain.Film;
import com.filipe.LocadoraTeste.service.FilmService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping(value = "/films")
public class FilmController {

    @Autowired
    private FilmService filmService;

    @GetMapping
    public ResponseEntity<List<Film> >getAll(){ //ResponseEntity permite eu retornar o status HTTP adequado com cada situação.
        List<Film> filmList = filmService.findAll();
        return ResponseEntity.ok().body(filmList);
    }

    @GetMapping(value = "/{id}")
    public ResponseEntity<Film> findById(@PathVariable Long id){
        Film obj = filmService.finById(id);
        return ResponseEntity.ok().body(obj);
    }
}
