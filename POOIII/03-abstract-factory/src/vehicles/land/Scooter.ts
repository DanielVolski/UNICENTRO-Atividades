import ILandVehicle from "./interfaces/iLandVehicle";

export default class Scooter implements ILandVehicle {
    startRoute(): void {
        this.getCargo();
        console.log("Scooter: iniciando rota!");
    }
    getCargo(): void {
        console.log("Embarcando passageiros");
    }
    
}