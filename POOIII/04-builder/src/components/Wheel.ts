export default class Wheel {
    constructor(private __rim: number) {}

    get rim(): number {
        return this.__rim;
    }
    set rim(rim: number) {
        this.__rim = rim;
    }
}