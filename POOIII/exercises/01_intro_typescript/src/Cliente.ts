import Endereco from "./Endereco";
import Telefone from "./Telefone";

export enum sexo { MASCULINO = 'M', FEMININO = 'F', INDEFINIDO = 'I' };

export default class Cliente
{
    private _nome : string;
    private _data_nascimento : number;
    private _endereco : Endereco;
    private _sexo : sexo;
    private _telefones : Telefone[];

    constructor(nome : string, data_nascimento : number,
        endereco : Endereco, sexo : sexo, telefones : Telefone[])
    {
        this._nome = nome;
        this._data_nascimento = data_nascimento;
        this._endereco = endereco;
        this._sexo = sexo;
        this._telefones = telefones;
    }

    get nome() {
        return this._nome;
    }

    get data_nascimento() {
        return this._data_nascimento;
    }

    get endereco() {
        return this._endereco;
    }

    get sexo() {
        return this._sexo;
    }

    get telefones() {
        return this._telefones;
    }

    set nome(novo_nome : string) {
        this._nome = novo_nome;
    }

    set data_nascimento(nova_data : number) {
        this._data_nascimento = nova_data;
    }

    set endereco(novo_endereco : Endereco) {
        this._endereco = novo_endereco;
    }

    set sexo(novo_sexo : sexo) {
        this._sexo = novo_sexo;
    }

    set telefones(novos_telefones : Telefone[]) {
        this._telefones = novos_telefones;
    }
}