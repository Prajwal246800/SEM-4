fn main()
{
    let overflow1:u8= 255; //Can Store 255
    // 0 to 255 only allowed for u8
    let overflow2:u8=256;//overflow value is 0
    let overflow3:u8=257;//overflow value is 1
    let overflow4:u8=258;//overflow value is 2
    
    println!("overflow1 is {} ",overflow1);
    println!("overflow2 is {}",overflow2);
    println!("overflow3 is {}",overflow3);
    println!("overflow4 is {}",overflow4);
}

/*
    OUTPUT:
            error: literal out of range for `u8`
        --> src/main.rs:4:22
            |
        4   |     let overflow2:u8=256;//overflow value is 0
            |                      ^^^
            |
        = note: the literal `256` does not fit into the type `u8` whose range is `0..=255`
        = note: `#[deny(overflowing_literals)]` on by default

        error: literal out of range for `u8`
        --> src/main.rs:5:22
            |
        5   |     let overflow3:u8=257;//overflow value is 1
            |                      ^^^
            |
        = note: the literal `257` does not fit into the type `u8` whose range is `0..=255`

        error: literal out of range for `u8`
        --> src/main.rs:6:22
            |
        6   |     let overflow4:u8=258;//overflow value is 2
            |                      ^^^
            |
        = note: the literal `258` does not fit into the type `u8` whose range is `0..=255`

        error: could not compile `playground` (bin "playground") due to 3 previous errors
*/