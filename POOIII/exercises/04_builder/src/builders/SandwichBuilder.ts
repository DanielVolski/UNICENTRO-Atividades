import Bread from "../components/Bread";
import Protein from "../components/Protein";
import Salad from "../components/Salad";
import SandwichType from "../components/SandwichType";
import Sauce from "../components/Sauce";
import Sandwich from "../products/Sandwich";
import IBuilder from "./IBuilder";

export default class SandwichBuilder implements IBuilder {
    private sandwich = new Sandwich();
    
    reset(): void {
        this.sandwich = new Sandwich();
    }
    getSandwich(): Sandwich {
        const r = this.sandwich;
        this.reset();
        return r;
    }
    setSanduicheType(st: SandwichType) {
        this.sandwich.sandwichType = st;
    }
    setBread(bread: Bread) {
        this.sandwich.bread = bread;
    }
    setProtein(protein: Protein[]) {
        this.sandwich.protein = protein;
    }
    setSalad(salad: Salad) {
        this.sandwich.salad = salad;
    }
    addSauce(sauce: Sauce[]) {
        this.sandwich.sauce = sauce;
    }
    
}