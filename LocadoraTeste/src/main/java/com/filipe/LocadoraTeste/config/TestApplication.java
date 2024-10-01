package com.filipe.LocadoraTeste.config;


import com.filipe.LocadoraTeste.entity.Film;
import com.filipe.LocadoraTeste.entity.Registry;
import com.filipe.LocadoraTeste.entity.Userr;
import com.filipe.LocadoraTeste.respository.FilmRepository;
import com.filipe.LocadoraTeste.respository.RegistryRepository;
import com.filipe.LocadoraTeste.respository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Profile;

@Configuration
@Profile("test")
public class TestApplication implements CommandLineRunner {

    @Autowired
    private FilmRepository filmRepository;

    @Autowired
    private UserRepository userRepository;

    @Autowired
    private RegistryRepository registryRepository;


    @Override
    public void run(String... args) throws Exception {


        Film film1 = new Film(true,"Christopher Nolan",
               "ficcão científica",null,"Interestelar",
                "As reservas naturais da Terra estão chegando ao fim e um grupo de astronautas recebe a missão de verificar possíveis planetas para receberem a população mundial, possibilitando a continuação da espécie.",
                2014,"https://cdn.oantagonista.com/uploads/2024/04/size_960_16_9_interstellar-023.webp");


       // filmRepository.saveAll(Arrays.asList(film1));

       Userr user1 = new Userr("felipepires.p@gmail.com",null,"Filipe Samuel","123","998581484");
       user1.getFilmList().add(film1);

       userRepository.save(user1);

        Registry registry = new Registry(null,"30/12/2024 - 20:00",user1);
        registryRepository.save(registry);

    }
}
