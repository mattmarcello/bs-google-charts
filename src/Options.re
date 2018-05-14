module Legend = {
  type t;
  [@bs.obj] external make : (~position: string=?, unit) => t = "";
};

type t;

[@bs.obj]
external make :
  (
    ~legend: Legend.t=?,
    ~title: string=?,
    ~width: int=?,
    ~height: int=?,
    ~bars: string=?,
    unit
  ) =>
  t =
  "";
