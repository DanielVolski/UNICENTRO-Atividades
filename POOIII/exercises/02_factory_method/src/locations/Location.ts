import IItem from "./items/interfaces/iItem";

export default abstract class Location
{
    startItem(): void {
        const item = this.createItem();
        item.start();
    }
    protected abstract createItem(): IItem;
} 