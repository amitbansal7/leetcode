//Runtime: 1156 ms
object Solution {
    def reverseStr(s: String, k: Int): String = {
        if(s == "") return ""
        s.slice(0, k).reverse + s.slice(k, 2*k) + reverseStr(if(s.size > 2*k)s.substring(2*k) else "", k)
    }
}