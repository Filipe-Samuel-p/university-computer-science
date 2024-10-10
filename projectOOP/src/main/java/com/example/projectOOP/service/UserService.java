package com.example.projectOOP.service;

import com.example.projectOOP.entities.Film;
import com.example.projectOOP.entities.Rental;
import com.example.projectOOP.entities.User;
import com.example.projectOOP.repositories.UserRepository;
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
public class UserService {

    @Autowired
    private UserRepository repository;

    public List<User> findAll(){
        return repository.findAll();
    }

    public User insert(User user){
        return repository.save(user);
    }

    public User findById(Long id){
        Optional<User> obj = repository.findById(id);
        return obj.orElseThrow(() -> new ResourceAccessException("Usuário não encontrado"));
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


    public User update(Long id,User user){
        try{
            User entity = repository.getReferenceById(id);
            udpateData(entity,user);
            return repository.save(entity);
        }catch (EntityNotFoundException e){
            throw new ResourceAccessException("Entidade não encontrada");
        }
    }

    private void udpateData(User entity, User obj){

        entity.setName(obj.getName());
        entity.setEmail(obj.getEmail());
        entity.setPassword(obj.getPassword());

    }
}
