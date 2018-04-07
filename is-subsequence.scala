//Runtime: 396 ms
object Solution {
    def isSubsequence(s: String, t: String): Boolean = {

        def look(c:Char, t:String, idx:Int):Int = {
            if(idx >= t.size) -1
            else if(c == t(idx)) idx
            else look(c, t, idx+1)
        }

        def solve(s:String , t:String, i:Int, idx:Int):Boolean = {
            if(i >= s.size) true
            else{
                val idx2 = look(s(i), t, idx+1)
                if(idx2 == -1) false
                else solve(s, t, i+1, idx2)
            }
        }
        solve(s, t, 0, -1)
    }
}