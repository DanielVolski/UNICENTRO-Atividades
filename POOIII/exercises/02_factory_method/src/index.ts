import GameLocation from "./locations/GameLocation";
import MovieLocation from "./locations/MovieLocation";
import Location from "./locations/Location";

declare var process;
let location: Location;

if (process.argv.includes("game"))
{
    location = new GameLocation();
    location.startItem();
}
else if (process.argv.includes("movie"))
{
    location = new MovieLocation();
    location.startItem();
}
else
    console.log("Invalid");