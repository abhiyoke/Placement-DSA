Find the number of subarrays such that their maximum is K - 

[8 2 1 3 4 5 1 10] 

K = 3

Output = 3. [3],[1 3],[2 1 3] 

Brute Force :- O(N^2) - generate all the subarrays and check whose maximum is K -> increment the count 

f(i=0;i<n;i++){
max = b[i]
f(j=i;j<n;j++){
    max = maximum(b[j],max) //max = [i……….j]
    if(max==K){
       count = count + 1
       }  
}
}

print(count)

TC - O(N*N)

Takes O(1) size. 

Optimal - Special trick taught by Kumar K sir in hashing 

If your current number is “K” :- number of valid subarrays :- x + y + x*y + 1 

At index “i” if b[i] = K find the number of subarrays whose max = K and also this K is the last K of that subarray 


For the left hand side ; stop only when you find a bigger element 

For the right hand side ; stop if you find same element or bigger element 


Hence O(N) solution is possible. Like this we will calculate all subarrays whose max is K 
