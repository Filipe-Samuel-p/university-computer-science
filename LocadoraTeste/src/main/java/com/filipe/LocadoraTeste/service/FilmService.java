package com.filipe.LocadoraTeste.service;

import com.filipe.LocadoraTeste.domain.Film;
import com.filipe.LocadoraTeste.respository.FilmRepository;
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
    public Film finById(Long id){
        Optional<Film> obj = repository.findById(id);
        return obj.orElseThrow(() -> new ResourceAccessException("Não encontrado"));
    }


    public Film insert(Film obj){
        return repository.save(obj);
    }

}
