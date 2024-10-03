package com.example.projectOOP.repositories;

import com.example.projectOOP.entities.Film;
import org.springframework.data.jpa.repository.JpaRepository;

public interface FilmRepository extends JpaRepository<Film,Long> {
}
