package com.filipe.LocadoraTeste.service;

import com.filipe.LocadoraTeste.entity.Userr;
import com.filipe.LocadoraTeste.respository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.ResourceAccessException;

import java.util.List;
import java.util.Optional;

@Service
public class UserService {

    @Autowired
    private UserRepository userRepository;

    public List<Userr> findAll(){
        return userRepository.findAll();
    }

    public Userr findById(Long id){
        Optional<Userr> obj = userRepository.findById(id);
        return obj.orElseThrow(() -> new ResourceAccessException("Não encontrado"));
    }


}
