use std::io;
use rand::Rng;

fn main() 
{
    // let mut x = String::new();

    // io::stdin().read_line(&mut x)
    //            .expect("Failed to read line");
    
    let x = rand::thread_rng().gen_range(1, 101);

    println!("{}", x);

}
 