/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let arr = [init];
    for(let i = 0; i < nums.length ; i++){
        arr.push(fn(arr[arr.length-1],nums[i]))
    }
    return arr.pop()
};