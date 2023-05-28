pub fn bissec(mut a: f64, mut b: f64, delta: f64, it: u32, fx: fn(f64) -> f64) -> f64 {
    let (mut epsilon, mut f1, mut f2) : (f64, f64, f64);
    let k: u32 = 0;
    
    if (b - a).abs() < delta {
        return (b + a)/2.0
    }

    loop {
        f1 = fx(a);
        epsilon = (a + b)/2.0;
        f2 = fx(b);

        if f1 * f2 < 0.0 {
            b = epsilon;
        } else {
            a = epsilon;
        }

        if (b - a).abs() < delta || k > it {
            return epsilon;
        }
    }
}