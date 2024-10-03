package com.example.projectOOP.repositories;

import com.example.projectOOP.entities.User;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UserRepository extends JpaRepository<User,Long> {
}
