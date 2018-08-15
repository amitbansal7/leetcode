//Runtime: 312 ms
object Solution {
  def uncommonFromSentences(A: String, B: String): Array[String] = {
    def util(l: List[String], mp: Map[String, Int]): Map[String, Int] = l match {
        case Nil => mp
        case x :: xs => {
          val c: Int = mp.getOrElse(x, 0)
          util(xs, mp + (x -> (c + 1)))
        }
      }

    val mp =
      util(B.split(" ").toList ++ A.split(" ").toList, Map[String, Int]())

    mp.filter(_._2 == 1)
      .keys
      .toArray

  }
}
