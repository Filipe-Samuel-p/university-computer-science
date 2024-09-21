package com.filipe.LocadoraTeste.config;


import com.filipe.LocadoraTeste.domain.Film;
import com.filipe.LocadoraTeste.respository.FilmRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Profile;

import java.util.Arrays;

@Configuration
@Profile("test")
public class TestApplication implements CommandLineRunner {

    @Autowired
    private FilmRepository filmRepository;


    @Override
    public void run(String... args) throws Exception {

        //Film film1 = new Film(true,"Christopher Nolan",
            //    "ficcão científica",null,"Interestelar",
            //    "As reservas naturais da Terra estão chegando ao fim e um grupo de astronautas recebe a missão de verificar possíveis planetas para receberem a população mundial, possibilitando a continuação da espécie.",
              //  2014,"https://cdn.oantagonista.com/uploads/2024/04/size_960_16_9_interstellar-023.webp");


       // filmRepository.saveAll(Arrays.asList(film1));


    }
}
