import IItem from "./interfaces/iItem";

export default class Game implements IItem
{
    start(): void {
        console.log("Starting game...")
    }
    getDescription(): void {
        console.log("A game instance");
    }
}