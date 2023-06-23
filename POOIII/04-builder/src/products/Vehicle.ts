import Engine from "../components/Engine";
import Transmission from "../components/Transmission";
import VehicleType from "../components/VehicleType";
import Wheel from "../components/Wheel";

export default class Vehicle {    
    private _vehicleType: VehicleType;
    private _seats: number;
    private _engine: Engine;
    private _transmission: Transmission;
    private _wheels: Wheel[] = [];

    /**
     * Getter vehicleType
     * @return {VehicleType}
     */
	public get vehicleType(): VehicleType {
		return this._vehicleType;
	}

    /**
     * Setter vehicleType
     * @param {VehicleType} value
     */
	public set vehicleType(value: VehicleType) {
		this._vehicleType = value;
	}

    /**
     * Getter seats
     * @return {number}
     */
	public get seats(): number {
		return this._seats;
	}

    /**
     * Setter seats
     * @param {number} value
     */
	public set seats(value: number) {
		this._seats = value;
	}

    /**
     * Getter engine
     * @return {Engine}
     */
	public get engine(): Engine {
		return this._engine;
	}

    /**
     * Setter engine
     * @param {Engine} value
     */
	public set engine(value: Engine) {
		this._engine = value;
	}

    /**
     * Getter transmission
     * @return {Transmission}
     */
	public get transmission(): Transmission {
		return this._transmission;
	}

    /**
     * Setter transmission
     * @param {Transmission} value
     */
	public set transmission(value: Transmission) {
		this._transmission = value;
	}

    public addWheel(wheel: Wheel) {
        this._wheels.push(wheel);
    }
}