package com.filipe.LocadoraTeste.service;


import com.filipe.LocadoraTeste.entity.Registry;
import com.filipe.LocadoraTeste.respository.RegistryRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.ResourceAccessException;

import java.util.List;
import java.util.Optional;

@Service
public class RegistryService {

    @Autowired
    private RegistryRepository repository;

    public List<Registry> findAll(){
        return repository.findAll();
    }

    public Registry findById(Long id){
        Optional<Registry> obj = repository.findById(id);
        return obj.orElseThrow(() -> new ResourceAccessException("Registro não encontrado"));
    }
}
