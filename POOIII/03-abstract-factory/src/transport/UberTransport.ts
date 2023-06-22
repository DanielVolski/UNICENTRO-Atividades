import Airplane from "../vehicles/aerial/Airplane";
import Aircraft from "../vehicles/aerial/interfaces/iAircraft";
import Car from "../vehicles/land/Car";
import ILandVehicle from "../vehicles/land/interfaces/iLandVehicle";
import ITransportFactory from "./interfaces/iTransportFactory";

export default class UberTransport implements ITransportFactory {
    createTransportVehicle(): ILandVehicle {
        return new Car();
    }
    createTransportAircraft(): Aircraft {
        return new Airplane();
    }
    
}