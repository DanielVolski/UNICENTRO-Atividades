import IDrink from "../../products/drink/interfaces/IDrink";
import IFood from "../../products/food/interfaces/IFood";

export default interface IDeliveryFactory {
    createDeliveryDrink(drink: String): IDrink;
    createDeliveryFood(food: String): IFood;
}