import Transport from "./Transport";
import Bicycle from "./vehicles/Bicycle";
import IVehicle from "./vehicles/interface/iVehicle";

export default class MotorcycleTransport extends Transport {
    protected createTransport(): IVehicle {
        return new Bicycle();
    }
}