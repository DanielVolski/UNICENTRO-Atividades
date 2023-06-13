import IVehicle from "./interface/iVehicle";

export default class Bicycle implements IVehicle {
    
    startRoute(): void {
        this.getCargo();
        console.log("Iniciando o trajeto!");
    }
    getCargo(): void {
        console.log("Bicicleta: encomenda retirada");
    }
    

}