/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let newArr = [];
    arr.forEach((value, idx)=>{
        if(fn(value, idx))
            newArr.push(value);
    })
    return newArr;
};