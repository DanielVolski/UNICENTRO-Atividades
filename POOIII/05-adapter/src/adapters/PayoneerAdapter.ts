import Payoneer from "../payoneer/Payoneer";
import IPayPalPayment from "../paypal/IPayPalPayment";
import Token from "../utils/Token";

export default class PayoneerAdapter implements IPayPalPayment {
    private _token: Token;

    constructor(private payoneer: Payoneer) {
        console.log("Adaptando payoneer no Paypal");
    }
    
    authToken(): Token {
        return new Token();
    }
    paypalPayment(): void {
        return this.payoneer.sendPayment();
    }
    paypalReceive(): void {
        return this.payoneer.receivePayment();
    }
}