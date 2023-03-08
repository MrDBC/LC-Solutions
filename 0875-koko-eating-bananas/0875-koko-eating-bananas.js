/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function(piles, h) {
    
    let low=1, high = Math.max(...piles)
    
    const feasible = (mid )=>{
        return piles.reduce((totalHr, currPile)=>{
            return totalHr + Math.ceil((currPile)/mid);
        }, 0)
    }
    
    // const feasible = speed => piles.reduce((sum, pile) => sum + Math.ceil(pile/speed), 0)
    while(low < high){
        let mid= Math.floor((low + high)/2);
        
        if( feasible(mid) <=h)
            high =mid;
        else
            low = mid+1;
    }
    
    return low;
};