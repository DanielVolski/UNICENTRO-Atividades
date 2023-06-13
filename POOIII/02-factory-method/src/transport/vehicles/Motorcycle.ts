import IVehicle from "./interface/iVehicle";

export default class Motorcycle implements IVehicle {
    startRoute(): void {
        this.getCargo();
        console.log("Moto: inciando a entrega");
    }
    getCargo(): void {
        console.log("Moto: encomenda retirada!")
    }
    
}