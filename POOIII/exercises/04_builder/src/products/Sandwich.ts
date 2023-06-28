import SandwichType from "../components/SandwichType";
import Bread from "../components/Bread";
import Protein from "../components/Protein";
import Salad from "../components/Salad";
import Sauce from "../components/Sauce";

export default class Sandwich {
    private _sandwichType: SandwichType;
    private _bread: Bread;
    private _protein: Protein[] = [];
    private _salad: Salad;
    private _sauce: Sauce[] = [];


    /**
     * Getter sauce
     * @return {Sauce[] }
     */
	public get sauce(): Sauce[]  {
		return this._sauce;
	}

    /**
     * Setter sauce
     * @param {Sauce[] } value
     */
	public set sauce(value: Sauce[] ) {
		this._sauce = value;
	}
    

    /**
     * Getter sandwichType
     * @return {SandwichType}
     */
	public get sandwichType(): SandwichType {
		return this._sandwichType;
	}

    /**
     * Setter sandwichType
     * @param {SandwichType} value
     */
	public set sandwichType(value: SandwichType) {
		this._sandwichType = value;
	}

    /**
     * Getter bread
     * @return {Bread}
     */
	public get bread(): Bread {
		return this._bread;
	}

    /**
     * Setter bread
     * @param {Bread} value
     */
	public set bread(value: Bread) {
		this._bread = value;
	}

    /**
     * Getter protein
     * @return {Protein[]}
     */
	public get protein(): Protein[] {
		return this._protein;
	}

    /**
     * Setter protein
     * @param {Protein[]} value
     */
	public set protein(value: Protein[]) {
		this._protein = value;
	}

    /**
     * Getter salad
     * @return {Salad}
     */
	public get salad(): Salad {
		return this._salad;
	}

    /**
     * Setter salad
     * @param {Salad} value
     */
	public set salad(value: Salad) {
		this._salad = value;
	}
}