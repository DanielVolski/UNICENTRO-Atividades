import Token from "../utils/Token";
import IPayoneerPayment from "./IPayoneerpayment";

export default class Payoneer implements IPayoneerPayment {
    private token: Token;

    authToken(): Token {
        return new Token();
    }
    sendPayment(): void {
        this.token = this.authToken();
        console.log("Token: " + this.token.token);
        console.log("Enviando pagamento Payoneer");
    }
    receivePayment(): void {
        this.token = this.authToken();
        console.log("Token: " + this.token.token);
        console.log("Recebendo pagamento Payoneer");
    }
}