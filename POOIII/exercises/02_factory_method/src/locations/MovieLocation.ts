import Location from "./Location";
import IItem from "./items/interfaces/iItem";
import Movie from "./items/Movie";

export default class MovieLocation extends Location
{
    protected createItem(): IItem {
        return new Movie();
    }
}