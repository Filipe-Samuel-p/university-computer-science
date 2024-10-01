package com.filipe.LocadoraTeste.respository;

import com.filipe.LocadoraTeste.entity.Userr;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UserRepository extends JpaRepository<Userr,Long> {
}
