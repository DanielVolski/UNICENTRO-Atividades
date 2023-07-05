import TransportadoraAdapter from "./Adapters/TrasportadoraAdapter";
import Correios from "./Correios/Correios";
import ICorreios from "./Correios/ICorreios";
import Transportadora from "./Transportadora/Transportadora";

const correios: ICorreios = new Correios()
const adapter: TransportadoraAdapter = new TransportadoraAdapter(new Transportadora())

correios.sendCorreios();
correios.receiveCorreios();

adapter.receiveCorreios();
adapter.sendCorreios();