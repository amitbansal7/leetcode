//Runtime: 5240 ms
object Solution {
  def licenseKeyFormatting(S: String, K: Int): String = {
    S.collect {
        case a: Char if a != '-' => a.toUpper
      }
      .toString
      .reverse
      .grouped(K)
      .mkString("-")
      .reverse
  }
}
