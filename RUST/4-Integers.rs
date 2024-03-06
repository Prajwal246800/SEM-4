/*
    Sl No.      Size         Signed         Unsigned
    1           8 bit         i8               u8
    2           16 bit        i16              u16
    3           32 bit        i32              u32
    4           64 bit        i64              u64
    5           128 bit       i128             u128
    6           Arch          isize            usize
*/

fn main()
{
    let int1 = 22; // i32 by default
    let int2:u32 = 15;
    let int3:i32 = 10-20;
    let int4:isize = -40;
    let int5:usize = 40;
    println!("int1 is {}",int1);
    println!("int2 is {}",int2);
    println!("int3 is {}",int3);
    println!("int4 is {}",int4);
    println!("int5 is {}",int5);
}

/*
    OUTPUT:
    int1 is 22
    int2 is 15
    int3 is -10
    int4 is -40
    int5 is 40
*/