import IAircraft from "./interfaces/iAircraft";

export default class Drone implements IAircraft {
    startRoute(): void {
        this.checkWind();
        this.getCargo();
        console.log("Drone: iniciando rota!");
    }
    getCargo(): void {
        console.log("Drone: embarcando passageiros!");
    }
    checkWind(): void {
        console.log("Vento ok!");
    }

}