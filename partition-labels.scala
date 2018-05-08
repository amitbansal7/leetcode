//Runtime: 428 ms
object Solution {
  def partitionLabels(S: String): List[Int] = {
    def lastChar(S: String): Map[Char, Int] = {
      S.zipWithIndex
        .groupBy(a => a._1)
        .mapValues(_.max)
        .values
        .toMap
    }

    def solve(S: String, i: Int, j: Int, part: Int, res: List[Int], last: Map[Char, Int]): List[Int] = {
      if (i >= S.length) res
      else {
        val nj: Int = j max last(S(i))
        if (i == nj) solve(S, i + 1, nj, i + 1, res ::: List((i - part + 1)), last)
        else solve(S, i + 1, nj, part, res, last)
      }
    }
    solve(S, 0, 0, 0, Nil, lastChar(S))
  }
}
