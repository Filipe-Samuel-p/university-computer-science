package com.filipe.LocadoraTeste.respository;

import com.filipe.LocadoraTeste.entity.Registry;
import org.springframework.data.jpa.repository.JpaRepository;

public interface RegistryRepository extends JpaRepository<Registry, Long> {
}
