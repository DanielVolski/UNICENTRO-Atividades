export enum TipoTelefone
{
    RESIDENCIAL = 'R',
    COMERCIAL = 'C',
    MOVEL = 'M',
}

export default class Telefone
{
    private _ddd : string;
    private _numero : number;
    private _tipo : TipoTelefone;

    constructor(ddd : string, numero : number, tipo : TipoTelefone)
    {
        this._ddd = ddd;
        this._numero = numero;
        this._tipo = tipo;
    }

    get ddd() {
        return this._ddd;
    }

    get numero() {
        return this._numero;
    }

    get tipo() {
        return this._tipo;
    }

    set ddd(ddd : string) {
        this._ddd = ddd;
    }

    set numero(numero : number) {
        this._numero = numero;
    }

    set tipo(tipo : TipoTelefone) {
        this._tipo = tipo;
    }
}