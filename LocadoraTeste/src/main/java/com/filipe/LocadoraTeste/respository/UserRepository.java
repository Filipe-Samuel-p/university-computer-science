package com.filipe.LocadoraTeste.respository;

import com.filipe.LocadoraTeste.domain.User;
import org.springframework.data.jpa.repository.JpaRepository;

public interface UserRepository extends JpaRepository<User,Long> {
}
