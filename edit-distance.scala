//Runtime: 725 ms
object Solution {
    def minDistance(word1: String, word2: String): Int = {

        val m : Int = word1.length
        val n : Int = word2.length
        if(m == 0)
            return n

        if(n == 0)
            return m

        var dp =  Array.ofDim[Int](m+1, n+1)

        for(i <- 0 to m)
            dp(i)(0) = i

        for(i <- 0 to n)
            dp(0)(i) = i

        for(i <- 1 to m; j <- 1 to n){
            if(i == 0){
                dp(i)(j) = j
            }else if(j == 0){
                dp(i)(j) = i;
            }else if(word1(i-1) == word2(j-1)){
                dp(i)(j) = dp(i-1)(j-1)
            }else{
                dp(i)(j) = 1 + Math.min(dp(i-1)(j), Math.min(dp(i-1)(j-1), dp(i)(j-1)));
            }
        }
        return dp(m)(n)
    }
}
