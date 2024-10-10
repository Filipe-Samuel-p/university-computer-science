package com.example.projectOOP.service;

import com.example.projectOOP.entities.Film;
import com.example.projectOOP.entities.Rental;
import com.example.projectOOP.repositories.RentalRepository;
import com.example.projectOOP.service.Exceptions.DatabaseException;
import com.example.projectOOP.service.Exceptions.ResourceNotFoundException;
import jakarta.persistence.EntityNotFoundException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.dao.EmptyResultDataAccessException;
import org.springframework.stereotype.Service;
import org.springframework.web.client.ResourceAccessException;

import java.util.List;
import java.util.Optional;

@Service
public class RentalService {

    @Autowired
    private RentalRepository repository;

    public List<Rental> findAll(){
        return repository.findAll();
    }

    public Rental findById(Long id){
        Optional<Rental> film = repository.findById(id);
        return film.orElseThrow(() -> new ResourceAccessException("Aluguel não encontrado"));
    }

    public Rental insert(Rental rental){
        return repository.save(rental);
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

    public Rental update(Long id,Rental rental){
        try{
           Rental entity = repository.getReferenceById(id);
            udpateData(entity,rental);
            return repository.save(entity);
        }catch (EntityNotFoundException e){
            throw new ResourceAccessException("Entidade não encontrada");
        }
    }

    private void udpateData(Rental entity, Rental obj){
        entity.setClient(obj.getClient());
        entity.setRentalDate(obj.getRentalDate());
    }

}
