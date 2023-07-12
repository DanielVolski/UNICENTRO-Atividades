import IConsole from "./IConsole";

export default class XBox implements IConsole {
    constructor() {
        console.log("Iniciando XBox");
        this.authToken();
        this.configureGame();
    }
    
    configureGame(): void {
        console.log("XBox: configurando jogo");
    }
    authToken(): void {
        console.log("XBox: autenticando token");
    }
}