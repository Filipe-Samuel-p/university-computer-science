package com.filipe.LocadoraTeste.respository;

import com.filipe.LocadoraTeste.domain.Film;
import org.springframework.data.jpa.repository.JpaRepository;

public interface FilmRepository extends JpaRepository<Film,Long> {
}
