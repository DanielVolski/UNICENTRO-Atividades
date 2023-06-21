import IFood from "./interfaces/IFood";

export default class Hamburguer implements IFood {
    startDelivery(): void {
        console.log("Iniciando entrega de Hamburguer");
    }
}