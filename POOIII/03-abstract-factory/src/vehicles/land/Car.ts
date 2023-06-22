import ILandVehicle from "./interfaces/iLandVehicle";

export default class Car implements ILandVehicle {
    startRoute(): void {
        this.getCargo();
        console.log("Carro: iniciando trajeto!");
    }
    getCargo(): void {
        console.log("Carro: embarcando passageiros!");
    }
    
}