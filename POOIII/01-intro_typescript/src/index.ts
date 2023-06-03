import Person from "./Person";
import Pessoa from "./Person";

// Global variables
var n1 : number = 6;
var n2 : number = 15;

if (n1 === 6)
{
    // Local variables
    let n1 : number = 3;
    let n2 : number = 22;
    console.log(n1, n2);
}

console.log(n1, n2);

// Both declarations are the same
let list1 : number[] = [2, 3, 5, 9];
let list2 : Array<number> = [2, 3, 5, 9];

// For each
for (let item of list1)
    console.log(item);

// Enums in typescript
enum Gender
{
    MASCULINO,
    FEMININO,
    INDEFINIDO
}

let gender = Gender.MASCULINO;
console.log(gender);

// function functionName(param_name : param_type) : return_type
function f(n1 : number, n2 : number) : string
{
    return `Result of the function: ${n1 + n2}`;
}

console.log(f(1, 2));

let p : Person = new Person("Daniel", "Volski", 22082000);
console.log(p);

console.log(p.fullName());