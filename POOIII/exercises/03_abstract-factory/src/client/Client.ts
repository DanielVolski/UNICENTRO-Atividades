import IDeliveryFactory from "../delivery/interfaces/IDeliveryFactory";
import ProductType from "../products/consts/ProductType";
import IDrink from "../products/drink/interfaces/IDrink";
import IFood from "../products/food/interfaces/IFood";

export default class Client {
    private drink: IDrink;
    private food: IFood;

    constructor(factory: IDeliveryFactory, type: String, productType: String)
    {
        this.drink = factory.createDeliveryDrink(type);
        this.food = factory.createDeliveryFood(type);
    }
    startDelivery(): void {
        if (this.drink != null)
            this.drink.startDelivery();
        if (this.food != null)
            this.food.startDelivery();
    }
}