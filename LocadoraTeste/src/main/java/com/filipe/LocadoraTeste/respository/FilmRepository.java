package com.filipe.LocadoraTeste.respository;

import com.filipe.LocadoraTeste.entity.Film;
import org.springframework.data.jpa.repository.JpaRepository;

public interface FilmRepository extends JpaRepository<Film,Long> {
}
