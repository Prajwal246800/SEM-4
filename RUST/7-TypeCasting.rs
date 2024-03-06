fn main()
{
    let flo1:f32 = 2;  // integer assigned to float variable
    println!("flo1 is {}",flo1);
}

/*
    OUTPUT:
    error[E0308]: mismatched types
    --> src/main.rs:2:20
        |
    2   |     let flo1:f32 = 2;  // integer assigned to float variable
        |              ---   ^
        |              |     |
        |              |     expected `f32`, found integer
        |              |     help: use a float literal: `2.0`
        |              expected due to this

    For more information about this error, try `rustc --explain E0308`.
    error: could not compile `playground` (bin "playground") due to 1 previous error
*/