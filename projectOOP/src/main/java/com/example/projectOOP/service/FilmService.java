package com.example.projectOOP.service;

import com.example.projectOOP.entities.Film;
import com.example.projectOOP.repositories.FilmRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.ResourceAccessException;

import java.util.List;
import java.util.Optional;

@Service
public class FilmService {

    @Autowired
    private FilmRepository repository;

    public List<Film> findAll(){
        return repository.findAll();
    }

    public Film findById(Long id){
        Optional<Film> film = repository.findById(id);
        return film.orElseThrow(() -> new ResourceAccessException("Filme não encontrado"));
    }

}
