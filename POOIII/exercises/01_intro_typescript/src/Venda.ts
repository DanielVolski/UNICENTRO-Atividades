import Cliente from "./Cliente";
import Produto from "./Produto";

export default class Venda
{
    private _codigo : number;
    private _data : number;
    private _cliente : Cliente;
    private _produto : Produto[];

    constructor(codigo : number, data : number, cliente : Cliente, produto : Produto[])
    {
        this._codigo = codigo;
        this._data = data;
        this._cliente = cliente;
        this._produto = produto;
    }

    get codigo() {
        return this._codigo;
    }

    get data() {
        return this._data;
    }

    get cliente() {
        return this._cliente;
    }

    get produto() {
        return this._produto;
    }

    set codigo(codigo : number) {
        this._codigo = codigo;
    }

    set data(data : number) {
        this._data = data;
    }

    set cliente(cliente : Cliente) {
        this._cliente = cliente;
    }

    set produto(produto : Produto[]) {
        this._produto = produto;
    }

    public calculaTotal() : number 
    {
        let total : number = 0;
        for (let produto of this._produto)
            total += produto.valor;
        return total;
    }
}