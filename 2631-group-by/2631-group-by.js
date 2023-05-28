/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    let ans={};
    for(let ele of this){
        const key=fn(ele);
        if(!(key in ans))
            ans[key]=[];
        ans[key].push(ele);
    }
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */