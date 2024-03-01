public class Solution {
    private String generateKey(String word) {
        int[] freq = new int[26];
        for (char ch : word.toCharArray()) {
            freq[ch - 'a']++;
        }
        String key ="";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                char ch = (char) ('a' + i);
                for (int j = 0; j < freq[i]; j++) {
                    key +=ch;
                }
            }
        }
        return key;
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();

        int n = strs.length;
        for (int i = 0; i < n; i++) {
            String key = generateKey(strs[i]);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(strs[i]);
        }

        for (List<String> group : map.values()) {
            result.add(group);
        }
        return result;
    }

}