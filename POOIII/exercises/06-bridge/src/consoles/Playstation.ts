import IConsole from "./IConsole";

export default class Playstation implements IConsole {
    constructor() {
        console.log("Iniciando Playstation");
        this.authToken();
        this.configureGame();
    }
    
    configureGame(): void {
        console.log("Playstation: configurando jogo");
    }
    authToken(): void {
        console.log("Playstation: autenticando token");
    }
}