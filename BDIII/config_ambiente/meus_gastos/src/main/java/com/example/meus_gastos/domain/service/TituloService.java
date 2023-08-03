package com.example.meus_gastos.domain.service;

import java.util.Date;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Service;

import com.example.meus_gastos.domain.dto.titulo.TituloRequestDTO;
import com.example.meus_gastos.domain.dto.titulo.TituloResponseDTO;
import com.example.meus_gastos.domain.exception.BadRequestException;
import com.example.meus_gastos.domain.exception.ResourceNotFoundException;
import com.example.meus_gastos.domain.model.Usuario;
import com.example.meus_gastos.domain.model.Titulo;
import com.example.meus_gastos.domain.repository.TituloRepository;

@Service
public class TituloService implements ICRUDServices<TituloRequestDTO, TituloResponseDTO> {
    @Autowired
    private TituloRepository tituloRepository;

    @Autowired
    private ModelMapper mapper;

    @Override
    public List<TituloResponseDTO> obterTodos() {
        Usuario usuario = (Usuario) SecurityContextHolder.getContext().getAuthentication().getPrincipal();
        List<Titulo> titulos = tituloRepository.findByUsuario(usuario);

        return titulos.stream().map(titulo -> mapper.map(titulo, TituloResponseDTO.class)).collect(Collectors.toList());
    }

    @Override
    public TituloResponseDTO obterPorId(Long id) {
        Optional<Titulo> optTitulo = tituloRepository.findById(id);
        
        if (optTitulo.isEmpty())
            throw new ResourceNotFoundException("Não foi possível encontrar o titulo com id " + id);

        return mapper.map(optTitulo.get(), TituloResponseDTO.class);
    }

    @Override
    public TituloResponseDTO cadastrar(TituloRequestDTO dto) {
        validarTitulo(dto);
        
        Titulo titulo = mapper.map(dto, Titulo.class);
        Usuario usuario = (Usuario) SecurityContextHolder.getContext().getAuthentication().getPrincipal();

        titulo.setUsuario(usuario);
        titulo.setId(null);
        titulo.setDataCadastro(new Date());
        titulo = tituloRepository.save(titulo);

        return mapper.map(titulo, TituloResponseDTO.class);
    }

    @Override
    public TituloResponseDTO atualizar(Long id, TituloRequestDTO dto) {
        TituloResponseDTO tituloBanco = obterPorId(id);
        
        obterPorId(id);
        validarTitulo(dto);
        
        Titulo titulo = mapper.map(dto, Titulo.class);
        Usuario usuario = (Usuario) SecurityContextHolder.getContext().getAuthentication().getPrincipal();

        titulo.setUsuario(usuario);
        titulo.setId(null);
        titulo.setDataCadastro(tituloBanco.getDataCadastro());
        titulo = tituloRepository.save(titulo);

        return mapper.map(titulo, TituloResponseDTO.class);
    }

    @Override
    public void deletar(Long id) {
        obterPorId(id);
        tituloRepository.deleteById(id);
    }
    
    private void validarTitulo(TituloRequestDTO dto) {
        System.out.println(dto);
        if (dto.getTipo() == null ||
            dto.getDataVencimento() == null || 
            dto.getValor() == null || 
            dto.getDescricao() == null
        )
            throw new BadRequestException("Título inválido - campos obrigatórios");
    }

    public List<TituloResponseDTO> obterPorDataVencimento(String periodoInicial, String periodoFinal) {
        List<Titulo> titulos = tituloRepository.obterFluxoCaixaPorDataVencimento(periodoInicial, periodoFinal);
        return titulos.stream().map(titulo -> mapper.map(titulo, TituloResponseDTO.class)).collect(Collectors.toList());
    }
}
