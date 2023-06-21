import IFood from "./interfaces/IFood";

export default class HogDog implements IFood {
    startDelivery(): void {
        console.log("Inicando entrega de HotDog");
    }
}