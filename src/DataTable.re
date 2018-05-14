type t;

type kind(_) =
  | Float: kind(float)
  | Int: kind(int)
  | String: kind(string);

[@bs.new] external make : unit => t = "google.visualization.DataTable";

[@bs.send] external addColumn : (t, string, string) => int = "";

[@bs.send]
external addRows :
  (t, [@bs.ignore] (kind('a), kind('b)), array(('a, 'b))) => t =
  "";

/* let dt = make(); */

/* dt |> addColumn(_, "foo", "bar"); */

/* dt |> addColumn(_, "ding", "dang"); */

/* dt |> addRows(_, (String, Int), [("ding", 4), ("dang", 4)]); */
