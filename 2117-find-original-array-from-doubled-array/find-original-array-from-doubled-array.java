class Solution {
    public int[] findOriginalArray(int[] changed) {
        if( changed.length % 2 != 0) return new int[]{};
        int[] original = new int[changed.length/2];
        Map<Integer,Integer> mp = new HashMap<>();
        Arrays.sort(changed);
        for(int num: changed)
        {
            mp.put(num , mp.getOrDefault(num ,0 )+1);
        }
        int index = 0;
        for(int it: changed)
        {
            if( mp.get(it) == 0)
            {
                //doubled value may be 
                continue;
            }
            int doubled = it*2;
            if( !mp.containsKey(doubled) || mp.get(doubled)<=0 )
            {
                return new int[]{};
            }
            original[index++] = it;
            mp.put(it, mp.get(it)-1);
            mp.put(doubled,mp.get(doubled)-1);
        }
        return original;
    }
}