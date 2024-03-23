// 2. create a simple employee management system where each employee has a name, age and department. 
// use a structure to represent each employee.

struct EmployeeDetails{
    name : String,
    age : i32,
    department : String
}
fn main(){
    let employee1 = EmployeeDetails{
        name : String::from("Person 1"),
        age : 26,
        department : String::from("maintanence")
    };
    let employee2 = EmployeeDetails{
        name : String::from("Person 2"),
        age : 32,
        department : String::from("Head")
    };
    println!("Employee 1 Name: {}. Employee 1 Age: {}. Employee 1 Department: {}", employee1.name, employee1.age, employee1.department);
    println!("Employee 2 Name: {}. Employee 2 Age: {}. Employee 2 Department: {}", employee2.name, employee2.age, employee2.department);
}