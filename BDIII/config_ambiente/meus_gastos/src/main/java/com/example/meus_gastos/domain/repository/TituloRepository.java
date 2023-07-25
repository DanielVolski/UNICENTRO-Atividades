package com.example.meus_gastos.domain.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import com.example.meus_gastos.domain.model.Titulo;
import com.example.meus_gastos.domain.model.Usuario;

import java.util.List;

public interface TituloRepository extends JpaRepository<Titulo, Long> {
    List<Titulo> findByUsuario(Usuario usuario);
    
}
