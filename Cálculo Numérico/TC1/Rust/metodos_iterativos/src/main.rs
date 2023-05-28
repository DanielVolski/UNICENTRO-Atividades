use metodos_iterativos::bissec;

fn main() {
    let (a, b, delta, it): (f64, f64, f64, u32);
    a = 2.0;
    b = 3.0;
    delta = 10.0_f64.powf(-1.0);
    it = 1;

    let resultado: f64 = bissec(a, b, delta, it, f);

    println!("{}", resultado);
}

fn f(x: f64) -> f64 {
    x * x.log(x) - 1.0
}
