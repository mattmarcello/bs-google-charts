type node;

type chart;

/* [@bs.val] */
/* external listToDataTable : list((string, int)) => dataTable = */
/*   "google.visualization.arrayToDataTable"; */
[@bs.val] external getElementById : string => node = "document.getElementById";

[@bs.new] external createChart : node => chart = "google.charts.Bar";

[@bs.send]
external drawChart : (chart, DataTable.t, Options.t) => unit = "draw";

let component = ReasonReact.statelessComponent("BarChart");

let make = (~id: string, _children) => {
  ...component,
  didMount: self => {
    let dt = DataTable.make();
    dt |> DataTable.addColumn(_, "string", "callstack");
    dt |> DataTable.addColumn(_, "number", "count");
    dt
    |> DataTable.addRows(
         _,
         (String, Int),
         [|
           ("city", 2010),
           ("city", 2011),
           ("city", 2013),
           ("city", 2014),
           ("city", 2015),
         |],
       );
    let node = getElementById(id);
    createChart(node)
    |> drawChart(_, dt, Options.make(~bars="horizontal", ()))
    |> ignore;
  },
  render: _self => <div id />,
};
