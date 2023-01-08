#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn square(size: u32) -> Self {
        return Self {
            width: size,
            height: size,
        };
    }

    fn width(self: &Self) -> bool {
        return self.width > 0;
    }

    fn area(self: &Self) -> u32 {
        return self.width * self.height;
    }

    fn can_hold(self: &Self, rectangle: &Rectangle) -> bool {
        return self.width > rectangle.width && self.height > rectangle.height;
    }
}

fn main() {
    let rect1: Rectangle = Rectangle {
        width: 30,
        height: 50,
    };

    if rect1.width() {
        println!(
            "The area of the rectangle is {} square pixels.",
            rect1.area()
        )
    }

    let rect2: Rectangle = Rectangle {
        width: 10,
        height: 40,
    };
    let rect3: Rectangle = Rectangle {
        width: 60,
        height: 45,
    };

    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));

    println!("Square with size 5: {:#?}", Rectangle::square(5));
}
