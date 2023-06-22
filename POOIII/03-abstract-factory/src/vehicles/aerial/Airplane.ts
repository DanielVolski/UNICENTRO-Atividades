import IAircraft from "./interfaces/iAircraft";

export default class Airplane implements IAircraft {
    startRoute(): void {
        this.getCargo();
        this.checkWind();
        console.log("Avião: iniciando decolagem!");
    }
    getCargo(): void {
        console.log("Avião: passageiros embarcados!");
    }
    checkWind(): void {
        console.log("Avião: ventos a 25km, ok!");
    }
}