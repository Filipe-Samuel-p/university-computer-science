package com.example.projectOOP.config;

import com.example.projectOOP.entities.Film;
import com.example.projectOOP.entities.Rental;
import com.example.projectOOP.entities.RentalItems;
import com.example.projectOOP.entities.User;
import com.example.projectOOP.repositories.FilmRepository;
import com.example.projectOOP.repositories.RentalItemsRepository;
import com.example.projectOOP.repositories.RentalRepository;
import com.example.projectOOP.repositories.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Profile;

import java.util.Date;

@Configuration
@Profile("test")
public class TestConfig implements CommandLineRunner {

        @Autowired
        private UserRepository userRepository;

        @Autowired
        private FilmRepository filmRepository;

        @Autowired
        private RentalRepository rentalRepository;

        @Autowired
        private RentalItemsRepository rentalItemsRepository;

        @Override
        public void run(String... args) throws Exception{


            Film film1 = new Film(true,"Christopher Nolan","Ficção cientifica",null,2014,
             "As reservas naturais da Terra estão chegando ao fim e um grupo de astronautas recebe a missão de verificar possíveis planetas para receberem a população mundial, possibilitando a continuação da espécie.",
                 "Interestellar", "https://br.web.img3.acsta.net/pictures/14/10/31/20/39/476171.jpg");
            filmRepository.save(film1);


            User user1 = new User(null,"Filipe","1234","filipe@gmail.com",null);
            Rental rental1 = new Rental(user1,null,new Date());

            userRepository.save(user1);
            rentalRepository.save(rental1);

            RentalItems ri1 = new RentalItems(rental1,film1,1);
            rentalItemsRepository.save(ri1);

        }
}
