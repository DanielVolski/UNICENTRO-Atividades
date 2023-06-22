import Aircraft from "./interfaces/iAircraft";

export default class Helicopter implements Aircraft {
    startRoute(): void {
        this.checkWind();
        this.getCargo();
        console.log("Helicoptero: iniciando decolagem!");
    }
    getCargo(): void {
        console.log("Helicóptero: passageiros embarcados!");
    }
    checkWind(): void {
        console.log("Helicóptero: ventos a 25km, sudoeste, ok!");
    }
    
}