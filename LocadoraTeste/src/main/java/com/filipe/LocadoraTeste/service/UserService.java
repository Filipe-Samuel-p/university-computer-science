package com.filipe.LocadoraTeste.service;

import com.filipe.LocadoraTeste.domain.User;
import com.filipe.LocadoraTeste.respository.UserRepository;
import org.springframework.stereotype.Service;
import org.springframework.web.client.ResourceAccessException;

import java.util.List;
import java.util.Optional;

@Service
public class UserService {

    private UserRepository userRepository;

    public List<User> findAll(){
        return userRepository.findAll();
    }

    public User findById(Long id){
        Optional<User> obj = userRepository.findById(id);
        return obj.orElseThrow(() -> new ResourceAccessException("Não encontrado"))
    }
}
