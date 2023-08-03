package com.example.meus_gastos.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.example.meus_gastos.domain.dto.dashboard.DashboardResponseDTO;
import com.example.meus_gastos.domain.service.DashboardService;

@CrossOrigin("*")
@RestController
@RequestMapping("/api/dashboard")
public class DashboardController {
    @Autowired
    private DashboardService dashboardService;

    @GetMapping
    public ResponseEntity<DashboardResponseDTO> obterFluxoDeCaixa(
        @RequestParam(name = "periodoInicial") String periodoIncial,
        @RequestParam(name = "periodoFinal") String periodoFinal
    ) {
        return ResponseEntity.ok(dashboardService.obterFluxoDeCaixa(periodoIncial, periodoFinal));
    }
}
