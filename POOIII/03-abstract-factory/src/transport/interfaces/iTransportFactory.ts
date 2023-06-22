import ILandVehicle from "../../vehicles/land/interfaces/iLandVehicle";
import IAircraft from "../../vehicles/aerial/interfaces/iAircraft";

export default interface ITransportFactory {
    createTransportVehicle(): ILandVehicle;
    createTransportAircraft(): IAircraft;
}