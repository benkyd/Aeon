use rand::Rng;

fn main() {
    let set: [i32; 6] = [1, 2, 3, 4, 5, 6];

    for num in set.iter() {
        print(num.to_string());
    }
    linebreak();

    let x = rand::thread_rng().gen_range(1, 101);

    if x < 50 {
        print("Less than 50".to_string());
    }

    let string: String = x.to_string();

    print(string);
}

fn print(ln: String) {
    println!("{}", ln);
}

fn linebreak() {
    println!("");
}
