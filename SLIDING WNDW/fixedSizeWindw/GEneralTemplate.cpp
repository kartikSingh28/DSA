/*for(int i=0;i<n;i++){
    // 1. ADD     nums[i] enters the window
    ...

    // 2. REMOVE  once the window is too big, nums[i-k] leaves
    if(i>=k){
        ...
    }

    // 3. RECORD  once the window has reached size k
    if(i>=k-1){
        ans = ...;
    }
}

return ans; 
FREQ WINDOW:
- remove = freq-- FIRST, then if(freq==0) distinct--
- freq size = max VALUE + 1 from constraints (not n+1, not 128 for ints)
- "if none valid return 0" -> start ans at 0

    // after the loop*/
