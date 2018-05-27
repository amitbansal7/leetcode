//Runtime: 592 ms
object Solution {
  def canVisitAllRooms(rooms: List[List[Int]]): Boolean = {
    def solve(rooms: List[List[Int]], src: Int, vis: List[Int]): List[Int] = {
      if (vis.contains(src)) vis
      else {
        rooms(src)
          .filterNot(vis.contains)
          .foldLeft(src :: vis)((b, a) => solve(rooms, a, b))
      }
    }
    solve(rooms, 0, List()).size == rooms.size
  }
}
