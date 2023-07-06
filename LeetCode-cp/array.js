function f(arr)
{
    for(let i=0; i<arr.length; i++)
    {
        arr[i] = 2*arr[i];
    }

    return arr;
}

let arr = [1,2,3,4,5];
console.log(arr);
// console.log(f(arr));


let newarr = arr.map((value) => 3*value);

// console.log(newarr);

function callback(value) {
    console.log(value);
    return 5*value;
}

let arr2 = arr.map(callback);

console.log(arr2);