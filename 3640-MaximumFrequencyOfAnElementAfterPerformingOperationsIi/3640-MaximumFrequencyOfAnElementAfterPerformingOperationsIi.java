// Last updated: 19/12/2025, 19:23:05
class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int n = nums.length;
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        List<int[]> eventList = new ArrayList<>();

        for (int num : nums) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
            eventList.add(new int[] { num - k, 1 });
            eventList.add(new int[] { num + k + 1, -1 });

        }

        Set<Integer> uniquePoints = new TreeSet<>();
        for (int[] event : eventList) {
            uniquePoints.add(event[0]);
        }

        for (int num : frequencyMap.keySet()) {
            uniquePoints.add(num);
        }

        eventList.sort(Comparator.comparingInt(a -> a[0]));
        int eventIndex = 0;
        int currentOverlap = 0;
        int maxFrequency = 0;
        int currentCount = 0;

        for (int point : uniquePoints) {
            while (eventIndex < eventList.size() && eventList.get(eventIndex)[0] <= point) {
                currentOverlap += eventList.get(eventIndex)[1];

                eventIndex++;
            }

            currentCount = frequencyMap.getOrDefault(point, 0);
            int possibleFrequency = currentCount + Math.min(numOperations, currentOverlap - currentCount);

            maxFrequency = Math.max(maxFrequency, possibleFrequency);
        }
        return maxFrequency;
    }
}