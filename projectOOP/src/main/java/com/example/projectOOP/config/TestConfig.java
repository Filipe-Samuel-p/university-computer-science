package com.example.projectOOP.config;

import com.example.projectOOP.entities.Film;
import com.example.projectOOP.entities.User;
import com.example.projectOOP.repositories.FilmRepository;
import com.example.projectOOP.repositories.RentalRepository;
import com.example.projectOOP.repositories.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Profile;

@Configuration
@Profile("test")
public class TestConfig implements CommandLineRunner {

        @Autowired
        private UserRepository userRepository;

        @Autowired
        private FilmRepository filmRepository;

        @Autowired
        private RentalRepository rentalRepository;

        @Override
        public void run(String... args) throws Exception{

            User user1 = new User(null,"Filipe","1234","filipe@gmail.com");
            userRepository.save(user1);

            Film film1 = new Film(null,"Interestellar",2014,"Christopher Nolan","Ficção cientifica",
                    "As reservas naturais da Terra estão chegando ao fim e um grupo de astronautas recebe a missão de verificar possíveis planetas para receberem a população mundial, possibilitando a continuação da espécie.",
                    "https://br.web.img3.acsta.net/pictures/14/10/31/20/39/476171.jpg", true);
            filmRepository.save(film1);
        }
}
