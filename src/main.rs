use std::env;

fn intentional_panic(msg: &str) {
    panic!("{}", msg);
}

fn main() {
    intentional_panic(&env::args().nth(1).unwrap_or(String::from("yikes")));
}
