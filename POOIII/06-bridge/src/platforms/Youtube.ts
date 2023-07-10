import IPlatform from "./IPlatform";

export default class Youtube implements IPlatform {
    constructor() {
        this.configureRMTP();
        console.log("Plataforma configurada: Youtube");
    }
    
    configureRMTP(): void {
        this.authToken();
        console.log("Confgurando broadcasting: Youtube");
    }
    authToken(): void {
        console.log("Autenticando token: Youtube");
    }
}