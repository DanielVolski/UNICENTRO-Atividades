import Transport from "./Transport";
import Motorcycle from "./vehicles/Motorcycle";
import IVehicle from "./vehicles/interface/iVehicle";

export default class MotorcycleTransport extends Transport {
    protected createTransport(): IVehicle {
        return new Motorcycle();
    }
}