//Runtime: 6 ms
class Solution {

    void solve(List<List<Integer> >res, List<Integer> t, boolean[] cache, int[] nums) {
        if (t.size() == nums.length) {
            res.add(new ArrayList(t));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (cache[i] == false) {
                cache[i] = true;
                t.add(nums[i]);
                solve(res, t, cache, nums);
                cache[i] = false;
                t.remove(t.size() - 1);
            }
        }
    }

    public List<List<Integer>> permute(int[] nums) {

        List<List<Integer > >res = new ArrayList();
        boolean[] cache = new boolean[nums.length];
        List<Integer> t = new ArrayList();
        solve(res, t, cache, nums);
        return res;
    }
}
