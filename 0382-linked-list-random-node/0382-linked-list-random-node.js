/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 */
var Solution = function(head) {
    this.arr = []
    let node = head;
    
    while( node){
        this.arr.push(node.val)
        node= node.next;
    }
    
    this.length = this.arr.length
};

/**
 * @return {number}
 */
Solution.prototype.getRandom = function() {
    return this.arr[Math.floor(Math.random() * this.length)]
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(head)
 * var param_1 = obj.getRandom()
 */