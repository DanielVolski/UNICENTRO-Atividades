import Drone from "../vehicles/aerial/Drone";
import Scooter from "../vehicles/land/Scooter";
import Aircraft from "../vehicles/aerial/interfaces/iAircraft";
import ILandVehicle from "../vehicles/land/interfaces/iLandVehicle";
import ITransportFactory from "./interfaces/iTransportFactory";

export default class LimeTransport implements ITransportFactory {
    createTransportVehicle(): ILandVehicle {
        return new Scooter();
    }
    createTransportAircraft(): Aircraft {
        return new Drone();
    }
    
}