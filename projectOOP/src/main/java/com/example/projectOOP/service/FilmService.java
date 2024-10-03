package com.example.projectOOP.service;

import com.example.projectOOP.entities.Film;
import com.example.projectOOP.repositories.FilmRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class FilmService {

    @Autowired
    private FilmRepository repository;

    public List<Film> findAll(){
        return repository.findAll();
    }

}
