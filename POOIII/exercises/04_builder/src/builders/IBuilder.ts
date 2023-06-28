import SandwichType from "../components/SandwichType";
import Sandwich from "../products/Sandwich";
import Salad from "../components/Salad";
import Bread from "../components/Bread";
import Protein from "../components/Protein";
import Sauce from "../components/Sauce";

export default interface IBuilder {
    reset(): void;
    getSandwich(): Sandwich;
    setSanduicheType(st: SandwichType);
    setBread(bread: Bread);
    setProtein(protein: Protein[]);
    setSalad(salad: Salad);
    addSauce(sauce: Sauce[]);
}