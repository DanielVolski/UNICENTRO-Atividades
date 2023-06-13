import IVehicle from "./interface/iVehicle";

export default class Car implements IVehicle {
    
    startRoute(): void {
        this.getCargo();
        console.log("Iniciando o trajeto!");
    }
    getCargo(): void {
        console.log("Carro: passageiros embarcados!");
    }
    

}