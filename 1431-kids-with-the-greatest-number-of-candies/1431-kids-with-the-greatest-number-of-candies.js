/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    const ans =[]
    
    let maxcandy =0;
    for(let candy of candies)
        if( candy > maxcandy)
            maxcandy = candy;
    
    for(let candy of candies)
        ans.push(candy+extraCandies >= maxcandy);
    
    return ans;
};