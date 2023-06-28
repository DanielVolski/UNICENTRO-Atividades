import IBuilder from "../builders/IBuilder";
import Bread from "../components/Bread";
import Protein from "../components/Protein";
import Salad from "../components/Salad";
import SandwichType from "../components/SandwichType";
import Sauce from "../components/Sauce";

export default class Directors {
    constructor(private builder: IBuilder) {}
    
    constructNatural() {
        this.builder.setSanduicheType(SandwichType.NATURAL);
        this.builder.setBread(Bread.INTEGRAL);
        this.builder.setProtein([Protein.CHEESE]);
        this.builder.setSalad(Salad.LETTUCE);
        this.builder.addSauce([Sauce.MAYO]);
    }

    constructCheeseburguer() {
        this.builder.setSanduicheType(SandwichType.CHEESEBURGUER);
        this.builder.setBread(Bread.WATER);
        this.builder.setProtein([Protein.BEEF]);
        this.builder.setSalad(Salad.LETTUCE);
        this.builder.addSauce([Sauce.MAYO, Sauce.PEPPER]);
    }
}