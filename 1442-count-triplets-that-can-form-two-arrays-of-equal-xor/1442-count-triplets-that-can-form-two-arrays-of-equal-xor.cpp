class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n= arr.size();
        vector<int> prexor (n+1, 0);
        
        for(int i=1; i<=n; i++)
            prexor[i]= prexor[i-1] ^ arr[i-1];
        
        // prexor = 0 2 1 0 6 1
        //          0 1 2 3 4 5
        
        // prexor[i] = xor of all elements from (0... (i-1))
        // prexor[1]= xor of ist element, prexor[2] = xor of ist 2 elements,....
        int cnt=0;
        for(int prei=0; prei<n; prei++)
            for(int k=prei+2; k<=n; k++){ // (i,j, k) must span atleast 2 elements , thats y i did k=(prei+2)
                // a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
                // b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

                // Assume a == b, thus
                // a ^ b b ^ b, thus
                // a ^ b = 0, thus
                // arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] = 0
                // prefix[k+1] = prefix[i]
                // We only need to find out how many pair (i, k) of prefix value are equal.
                
                // xor(0,..., prei) == xor(i,... k) implies
                // xor(i,...., k) = 0
                if( prexor[prei] == prexor[k])
                    cnt+= (k-(prei+1));
            }
        
        return cnt;
        
    }
};