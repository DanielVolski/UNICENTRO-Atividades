import PayoneerAdapter from "./adapters/PayoneerAdapter";
import IPayoneerPayment from "./payoneer/IPayoneerpayment";
import Payoneer from "./payoneer/Payoneer";
import IPayPalPayment from "./paypal/IPayPalPayment";
import Paypal from "./paypal/PayPal";

const payment1: IPayPalPayment = new PayoneerAdapter(new Payoneer());
payment1.paypalPayment();
payment1.paypalReceive();

