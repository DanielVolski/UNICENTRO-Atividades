import Database from "../server/Databases";
import PermissionType from "../server/PermissionType";
import Middleware from "./Middleware";

export default class CheckPermissionMiddleware extends Middleware {
    public check(email: string, password: string) {
        const user = Database.filter(item => item.email === email);

        if (user[0].permission === PermissionType.ADMIN) {
            console.log("Logado como administrador");
        } else {
            console.log("Logado como usuário");
        }

        return this.checkNext(email, password);
    }
    
}