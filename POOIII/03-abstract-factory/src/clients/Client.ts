import ITransportFactory from "../transport/interfaces/iTransportFactory";
import ILandVehicle from "../vehicles/land/interfaces/iLandVehicle";
import IAircraft from "../vehicles/aerial/interfaces/iAircraft";
import VehicleType from "../vehicles/consts/VehicleKind";

export default class Client {
    private vehicle: ILandVehicle;
    private aircraft: IAircraft;

    constructor(factory: ITransportFactory, vehicleType: String) {
        switch (vehicleType)
        {
            case (VehicleType.LAND):
                this.vehicle = factory.createTransportVehicle();
                break;
            case (VehicleType.AERIAL):
                this.aircraft = factory.createTransportAircraft();
                break;
        }
    }

    startRoute(): void {
        if (this.vehicle != null)
            this.vehicle.startRoute();
        else if (this.vehicle != null)
            this.aircraft.startRoute();
    }
}