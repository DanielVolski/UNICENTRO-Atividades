import IPlatform from "./IPlatform";

export default class Twitch implements IPlatform {
    constructor() {
        this.configureRMTP();
        console.log("Plataforma configurada: Twitch");
    }
    
    configureRMTP(): void {
        this.authToken();
        console.log("Confgurando broadcasting: Twitch");
    }
    authToken(): void {
        console.log("Autenticando token: Twitch");
    }
}