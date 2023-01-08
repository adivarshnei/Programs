struct User {
    active: bool,
    email: String,
    sign_in_count: u64,
    username: String,
}

fn main() {
    let mut user1: User = User {
        active: true,
        email: String::from("someone@example.com"),
        sign_in_count: 1,
        username: String::from("someusername123"),
    };

    user1.email = String::from("anotheremail@example.com");

    let user2 = user1.clone();

    println!("{}", user2.active);
}
