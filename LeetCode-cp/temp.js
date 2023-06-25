const person = {
    name: 'Vinit',
    age: 19,
    "real age": 20,
}


// console.log(person.name);
// console.log(person.age);
// console.log(person["real age"]);

// for(key in person)
// {
//     console.log(key, " : ", person.key);
//     console.log(key, " : ", person[key]);
// }

// console.log(Object.keys(person));
// console.log(Object.values(person));
// console.log(Object.entries(person));

let arr = [1, 2, 3, 4, 43, 2];
const [x, y] = arr;
const [a, b, c, ...d] = arr;

// console.log(x);
// console.log(y);

// console.log("----------------");
// console.log(arr);
// console.log("----------------");

// console.log(a);
// console.log(b);
// console.log(c);
// console.log(d);

const newPerson = {
    Name: "sidhu",
    age: 35,
    // song: "295",
    // dad: "baapu"
}

function fn() {
    const { Name, age } = newPerson;

    console.log(Name);
    console.log(age);
}

// fn();

const sum = function(a,b) {
    return a+b;
}

const sum2 = (a,b) => {
    return a+b;
}

const sum3 = (a,b) => a+b;

const sum4 = (a) => a+3;
const sum5 = a => a+3;

// console.log(sum(1,2));
// console.log(sum2(1,2));
// console.log(sum3(1,2));
// console.log(sum4(5));
// console.log(sum5(45));

// hoisting
console.log(num);
var num = 3;
console.log(num);