import IConsole from "../consoles/IConsole";
import IPlay from "./IPlay";

export default class Play implements IPlay {
    constructor(private console: IConsole) {}
    
    playing(): void {
        console.log("Jogando")
    }
    result(): void {
        console.log("Apresentando resultado");
    }
}