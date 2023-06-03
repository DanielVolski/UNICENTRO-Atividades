// Export default enables other classes to import this class
export default class Person
{
    private _name : string;
    private _surname : string;
    private _birth_date : number;

    constructor(name : string, surname : string, birth_date : number)
    {
        this._name = name;
        this._surname = surname;
        this._birth_date = birth_date;
    }

    get name() : string
    {
        return this._name;
    }

    get surname() : string
    {
        return this._surname;
    }

    get birth_date() : number
    {
        return this.birth_date;
    }

    set name(name : string)
    {
        this._name = name;
    }

    set surname(surname : string)
    {
        this._surname = surname;
    }

    set birth_date(birth_date : number)
    {
        this._birth_date = birth_date;
    }

    fullName() : string {
        return `${this._name} ${this._surname}`;
    }
}