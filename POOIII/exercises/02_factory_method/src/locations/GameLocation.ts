import Location from "./Location";
import IItem from "./items/interfaces/iItem";
import Game from "./items/Game";

export default class GameLocation extends Location
{
    protected createItem(): IItem {
        return new Game();
    }
}