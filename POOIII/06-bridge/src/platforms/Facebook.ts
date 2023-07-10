import IPlatform from "./IPlatform";

export default class Facebook implements IPlatform {
    constructor() {
        this.configureRMTP();
        console.log("Plataforma configurada: Facebook");
    }
    
    configureRMTP(): void {
        this.authToken();
        console.log("Configurando broadcasting: Facebook");
    }
    authToken(): void {
        console.log("Autenticando token: Facebook");
    }
}