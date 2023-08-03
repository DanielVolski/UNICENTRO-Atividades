package com.example.meus_gastos.domain.dto.dashboard;

import java.util.List;

import com.example.meus_gastos.domain.dto.titulo.TituloResponseDTO;

public class DashboardResponseDTO {
    private double totalPagar;
    private double totalReceber;
    private double saldo;
    private List<TituloResponseDTO> titulosPagar;
    private List<TituloResponseDTO> titulosReceber;

    // Como não há model, essa classe precisa de um construtor
    public DashboardResponseDTO() {
        
    }

    public DashboardResponseDTO(double totalPagar, double totalReceber, double saldo,
            List<TituloResponseDTO> titulosPagar, List<TituloResponseDTO> titulosReceber) {
        this.totalPagar = totalPagar;
        this.totalReceber = totalReceber;
        this.saldo = saldo;
        this.titulosPagar = titulosPagar;
        this.titulosReceber = titulosReceber;
    }
    
    public double getTotalPagar() {
        return totalPagar;
    }
    public void setTotalPagar(double totalPagar) {
        this.totalPagar = totalPagar;
    }
    public double getTotalReceber() {
        return totalReceber;
    }
    public void setTotalReceber(double totalReceber) {
        this.totalReceber = totalReceber;
    }
    public double getSaldo() {
        return saldo;
    }
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }
    public List<TituloResponseDTO> getTitulosPagar() {
        return titulosPagar;
    }
    public void setTitulosPagar(List<TituloResponseDTO> titulosPagar) {
        this.titulosPagar = titulosPagar;
    }
    public List<TituloResponseDTO> getTitulosReceber() {
        return titulosReceber;
    }
    public void setTitulosReceber(List<TituloResponseDTO> titulosReceber) {
        this.titulosReceber = titulosReceber;
    }
    
}
