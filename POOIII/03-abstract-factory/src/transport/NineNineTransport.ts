import Helicopter from "../vehicles/aerial/Helicopter";
import Aircraft from "../vehicles/aerial/interfaces/iAircraft";
import Motorcycle from "../vehicles/land/Motorcycle";
import ILandVehicle from "../vehicles/land/interfaces/iLandVehicle";
import ITransportFactory from "./interfaces/iTransportFactory";

export default class NineNineTransport implements ITransportFactory {
    createTransportVehicle(): ILandVehicle {
        return new Motorcycle();
    }
    createTransportAircraft(): Aircraft {
        return new Helicopter();
    }
}