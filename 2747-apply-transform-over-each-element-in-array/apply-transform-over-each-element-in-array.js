/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newArr = [];
    arr.forEach((value, idx)=>{
        newArr.push(fn(value, idx));
    })
    return newArr;
};