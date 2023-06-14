import IItem from "./interfaces/iItem";

export default class Movie implements IItem
{
    start(): void {
        console.log("Starting a new Movie...")
    }
    getDescription(): void {
        throw new Error("This is a movie instance");
    }
    
}