import ILandVehicle from "./interfaces/iLandVehicle";

export default class Motorcycle implements ILandVehicle {
    startRoute(): void {
        this.getCargo();
        console.log("Moto: iniciando o trajeto!");
    }
    getCargo(): void {
        console.log("Moto: embarcando passageiros!");
    }
}