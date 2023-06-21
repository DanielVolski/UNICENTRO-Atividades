import Company from "./delivery/consts/Company"
import IDeliveryFactory from "./delivery/interfaces/IDeliveryFactory";
import AiQueFomeDelivery from "./delivery/AiQueFomeDelivery";
import IFoodDelivery from "./delivery/IFoodDelivery";
import Client from "./client/Client";
import ProductType from "./products/consts/ProductType";
import FoodEnum from "./products/food/consts/FoodEnum";

let currentCompany = Company.AIQUEFOME;
let factory!: IDeliveryFactory;

switch (currentCompany)
{
    case Company.AIQUEFOME:
        factory = new AiQueFomeDelivery();
        break;
    case Company.IFOOD:
        factory = new IFoodDelivery();
        break;
}

console.log(factory)
const client = new Client(factory, FoodEnum.HAMBURGUER, ProductType.FOOD);
client.startDelivery();