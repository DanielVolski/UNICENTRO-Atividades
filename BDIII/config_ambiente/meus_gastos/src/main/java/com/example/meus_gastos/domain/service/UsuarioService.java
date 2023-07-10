package com.example.meus_gastos.domain.service;

import java.util.Date;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.example.meus_gastos.domain.dto.usuario.UsuarioRequestDTO;
import com.example.meus_gastos.domain.dto.usuario.UsuarioResponseDTO;
import com.example.meus_gastos.domain.exception.BadRequestException;
import com.example.meus_gastos.domain.exception.ResourceNotFoundException;
import com.example.meus_gastos.domain.model.Usuario;
import com.example.meus_gastos.domain.repository.UsuarioRepository;

@Service
public class UsuarioService implements ICRUDServices<UsuarioRequestDTO, UsuarioResponseDTO> {

    @Autowired
    private UsuarioRepository usuarioRepository;

    @Autowired
    private ModelMapper mapper;
    
    @Override
    public List<UsuarioResponseDTO> obterTodos() {
        List<Usuario> usuarios = usuarioRepository.findAll();
        //Converte a lista de usuários da model em uma lista de UsuarioResponseDTO
        return usuarios.stream()
        .map(usuario -> mapper.map(usuario, UsuarioResponseDTO.class))
        .collect(Collectors.toList());
    }

    @Override
    public UsuarioResponseDTO obterPorId(Long id) {
        Optional<Usuario> optUsuario = usuarioRepository.findById(id);
        if (optUsuario.isPresent()) {
            throw new ResourceNotFoundException("Não foi possível encontrar o usuário com o id " + id);
        }
        return mapper.map(optUsuario.get(), UsuarioResponseDTO.class);
    }

    @Override
    public UsuarioResponseDTO cadastrar(UsuarioRequestDTO dto) {
        if (dto.getEmail() == null || dto.getSenha() == null)
            throw new BadRequestException("Email e Senha são obrigatórios!");
        
        Optional<Usuario> optUsuario = usuarioRepository.findByEmail(dto.getEmail());

        if (!optUsuario.isPresent())
            throw new BadRequestException("Email " + dto.getEmail() + " já cadastrado");

        Usuario usuario = mapper.map(dto, Usuario.class);
        usuario.setDataCadastro(new Date());
        // Criptografar senha
        usuario = usuarioRepository.save(usuario);

        return mapper.map(usuario, UsuarioResponseDTO.class);
    }

    @Override
    public UsuarioResponseDTO atualizar(Long id, UsuarioRequestDTO dto) {
        UsuarioResponseDTO usuarioBanco = obterPorId(id);

        if (dto.getEmail() == null || dto.getSenha() == null)
            throw new BadRequestException("Email e senha são obrigatórios!");
        
        Usuario usuario = mapper.map(dto, Usuario.class);
        usuario.setDataCadastro(usuarioBanco.getDataCadastro());
        usuario.setId(id);
        usuario = usuarioRepository.save(usuario);

        return mapper.map(usuario, UsuarioResponseDTO.class);
    }

    @Override
    public void deletar(Long id) {
        // Apaga um usuário do banco de dados
        // obterPorId(id);
        // usuarioRepository.deleteById(id);
        Optional<Usuario> optUsuario = usuarioRepository.findById(id);

        if (!optUsuario.isPresent())
            throw new ResourceNotFoundException("Não foi possível encontrar o usuário com o id " + id);
        
        Usuario usuario = optUsuario.get();
        usuario.setDataInativacao(new Date());
        usuarioRepository.save(usuario);
    }
    
}
