import IDrink from "./interfaces/IDrink";

export default class SoftDrink implements IDrink {
    startDelivery(): void {
        console.log("Começando entrega de SoftDrink");
    }
    
}