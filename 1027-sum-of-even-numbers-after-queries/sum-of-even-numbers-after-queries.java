class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        List<Integer> answer = new ArrayList<>();
        int sum = 0;

        for (int num : nums) {
            if (num % 2 == 0) {
                sum += num;
            }
        }

        for (int[] query : queries) {
            int valuei = query[0];
            int indexi = query[1];
            int initValue = nums[indexi];

            if (initValue % 2 == 0) {
                // even
                sum -= initValue;
            }

            nums[indexi] = nums[indexi] + valuei;

            if (nums[indexi] % 2 == 0) {
                sum += nums[indexi];
            }

            answer.add(sum);
        }

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}