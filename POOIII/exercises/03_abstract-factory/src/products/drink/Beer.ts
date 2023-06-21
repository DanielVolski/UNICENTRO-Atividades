import IDrink from "./interfaces/IDrink";

export default class Beer implements IDrink {
    startDelivery(): void {
        console.log("Começando entrega de cerveja");
    }
}