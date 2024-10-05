package com.example.projectOOP.service;

import com.example.projectOOP.entities.Film;
import com.example.projectOOP.repositories.FilmRepository;
import com.example.projectOOP.service.Exceptions.DatabaseException;
import com.example.projectOOP.service.Exceptions.ResourceNotFoundException;
import jakarta.persistence.EntityNotFoundException;
import org.hibernate.exception.DataException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataAccessException;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.dao.EmptyResultDataAccessException;
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

    public Film insert(Film film){
        return repository.save(film);
    }

    public void delete(Long id){
        try {
            repository.deleteById(id);
        } catch (EmptyResultDataAccessException e) {
            throw new ResourceNotFoundException("Elemento não encontrado: " + id);
        } catch (DataIntegrityViolationException e) {
            throw new DatabaseException("Violação de integridade: Não é possível deletar o elemento com id " + id);
        }
    }


    public Film update(Long id,Film film){
        try{
            Film entity = repository.getReferenceById(id);
            udpateData(entity,film);
            return repository.save(entity);
        }catch (EntityNotFoundException e){
            throw new ResourceAccessException("Entidade não encontrada");
        }
    }

    private void udpateData(Film entity, Film obj){
        entity.setTitle(obj.getTitle());
        entity.setDirector(obj.getDirector());
        entity.setAvailable(obj.getAvailable());
        entity.setGender(obj.getGender());
        entity.setSynopsis(obj.getSynopsis());
        entity.setUrlImage(obj.getUrlImage());
        entity.setReleaseYear(obj.getReleaseYear());

    }

}
