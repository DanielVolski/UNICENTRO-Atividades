import VehicleBuilder from "./builders/VehicleBuilder";
import Directors from "./directors/Directors";
import Vehicle from "./products/Vehicle";

const builder: VehicleBuilder = new VehicleBuilder();
const director: Directors = new Directors(builder);

director.constructSedanCar();
const sedan: Vehicle = builder.getVehicle();
director.constructTruck();
const truck: Vehicle = builder.getVehicle();

console.log(sedan);
console.log(truck);