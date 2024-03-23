// 1. Implement an address book application, where each entry represents a person's contact information(name, email and phone no), 
// use structure to represent each entry.

struct AddressBook{
    name : String,
    email : String,
    ph_no : i32
}
fn main(){
    let Book1 = AddressBook{
        name : String::from("Computer Network "),
        email : String::from("xyz@gmail.com"),
        ph_no : 12345
    };
    println!("Book name is {}. Email is {}. Phone Number is {}", Book1.name, Book1.email, Book1.ph_no);
}