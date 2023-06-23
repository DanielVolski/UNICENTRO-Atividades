export default class Engine {
    constructor(private __power: number) {

    }

    get power(): number {
        return this.__power;
    }
    set power(power: number) {
        this.__power = power;
    }
}