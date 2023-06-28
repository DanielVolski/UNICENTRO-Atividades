import SandwichBuilder from "./builders/SandwichBuilder";
import Directors from "./directors/Directors";
import Sandwich from "./products/Sandwich";

const builder: SandwichBuilder = new SandwichBuilder();
const director: Directors = new Directors(builder);

director.constructCheeseburguer()
const c: Sandwich = builder.getSandwich();
director.constructNatural()
const n: Sandwich = builder.getSandwich();

console.log(c);
console.log(n);