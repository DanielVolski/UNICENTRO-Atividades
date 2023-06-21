import Beer from "../products/drink/Beer";
import SoftDrink from "../products/drink/SoftDrink";
import DrinkEnum from "../products/drink/consts/DrinkEnum";
import IDrink from "../products/drink/interfaces/IDrink";
import Hamburguer from "../products/food/Hamburguer";
import HogDog from "../products/food/HotDog";
import FoodEnum from "../products/food/consts/FoodEnum";
import IFood from "../products/food/interfaces/IFood";
import IDeliveryFactory from "./interfaces/IDeliveryFactory";

export default class IFoodDelivery implements IDeliveryFactory {
    createDeliveryDrink(drink: String): IDrink {
        return new SoftDrink();
    }
    createDeliveryFood(food: String): IFood {
        return new HogDog();
    }
}