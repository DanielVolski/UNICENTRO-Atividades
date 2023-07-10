import ICorreios from "./ICorreios";

export default class Correios implements ICorreios {
    sendCorreios(): void {
        console.log("Enviando de correios");
    }
    receiveCorreios(): void {
        console.log("Recebendo de correios");
    }
}