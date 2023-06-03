import Cliente from "./Cliente";
import Endereco from "./Endereco";
import Telefone from "./Telefone";
import { TipoTelefone } from "./Telefone";
import { sexo } from "./Cliente"
import Produto from "./Produto";
import Venda from "./Venda";

let t1 : Telefone = new Telefone('(99)', 989899898, TipoTelefone.MOVEL);
let t2 : Telefone = new Telefone('(99)', 36229222, TipoTelefone.RESIDENCIAL);
let ts : Telefone[] = [t1, t2];
let e : Endereco = new Endereco('Rua', 2000, 'Cidade', 'Estado');
let c : Cliente = new Cliente('Pedro', 30082000, e, sexo.INDEFINIDO, ts);
let p1 : Produto = new Produto(1000, 'Produto1', 20.00);
let p2 : Produto = new Produto(1001, 'Produto2', 15.99);
let p3 : Produto = new Produto(1002, 'Produto2', 9.99);
let ps : Produto[] = [p1, p2, p3];
let v : Venda = new Venda(2000, 20052023, c, ps);

console.log(v);