fn main() {
    let mut s = String::from("hello");
    
    let r1 = &s;  // Référence immuable à s

    // Utilisation de r1 pour accéder à s (valide)
    println!("{}", r1);  // Lecture via r1

    let r2 = &mut s;  // Référence mutable à s

    // Utilisation de r2 pour modifier s
    r2.push_str(", world");

    // Utilisation de r2 après utilisation de r1
    println!("{}", r2);  // Lecture via r2
}
